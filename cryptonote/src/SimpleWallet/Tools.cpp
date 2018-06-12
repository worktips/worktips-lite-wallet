/*
Copyright (C) 2018, The Worktips developers
Copyright (C) 2018, The TurtleCoin developers

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <SimpleWallet/Tools.h>

void confirmPassword(std::string walletPass)
{
    /* Password container requires an rvalue, we don't want to wipe our current
       pass so copy it into a tmp string and std::move that instead */
    std::string tmpString = walletPass;
    Tools::PasswordContainer pwdContainer(std::move(tmpString));

    while (!pwdContainer.read_and_validate())
    {
        std::cout << "Incorrect password! Try again." << std::endl;
    }
}

std::string formatAmount(uint64_t amount)
{
    uint64_t dollars = amount / 100000000;
    uint64_t cents = amount % 100;

    return formatDollars(dollars) + "." + formatCents(cents) + " WTIP";
}

std::string formatDollars(uint64_t amount)
{
    class comma_numpunct : public std::numpunct<char>
    {
      protected:
        virtual char do_thousands_sep() const
        {
            return ',';
        }

        virtual std::string do_grouping() const
        {
            return "\03";
        }
    };

    std::locale comma_locale(std::locale(), new comma_numpunct());
    std::stringstream stream;
    stream.imbue(comma_locale);
    stream << amount;
    return stream.str();
}


std::string formatCents(uint64_t amount)
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(8) << amount;
    return stream.str();
}

bool confirm(std::string msg)
{
    while (true)
    {
        std::cout << InformationMsg(msg + " (Y/n): ");

        std::string answer;
        std::getline(std::cin, answer);

        char c = std::tolower(answer[0]);

        /* Lets people spam enter in the transaction screen */
        if (c == 'y' || c == '\0')
        {
            return true;
        }
        else if (c == 'n')
        {
            return false;
        }
        /* Don't loop forever on EOF */
        else if (c == std::ifstream::traits_type::eof())
        {
            return false;
        } 
        else
        {
            std::cout << WarningMsg("Bad input: ") << InformationMsg(answer)
                      << WarningMsg(" - please enter either Y or N.")
                      << std::endl;
        }
    }
}

std::string getPaymentID(std::string extra)
{
    std::string paymentID;

    if (extra.length() > 0)
    {
        std::vector<uint8_t> vecExtra;

        for (auto it : extra)
        {
            vecExtra.push_back(static_cast<uint8_t>(it));
        }

        Crypto::Hash paymentIdHash;

        if (CryptoNote::getPaymentIdFromTxExtra(vecExtra, paymentIdHash))
        {
            return Common::podToHex(paymentIdHash);
        }
    }

    return paymentID;
}
