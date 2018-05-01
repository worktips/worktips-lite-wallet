## Worktips lite wallet for Windows

This is the reference code for [Worktips](https://worktips.info) cryptocurrency.

* Official homepage: [Worktips](http://worktips.info)
* Official repository: [Worktips GitHub](https://github.com/Vordas/worktips)
* Official Announcement thread: [Worktips BitcoinTalk](https://bitcointalk.org/index.php?topic=3086019.0)
* Official Discord: [Worktips Discord](https://discord.gg/UmZExyz)
* Official Facebook: [Worktips Facebook](https://www.facebook.com/worktipscoin)
* Official Twitter: [Worktips Twitter](https://twitter.com/wtipscoin)
* Official Telegram: [Worktips Telegram](https://t.me/joinchat/HOvygRE-6UnWOzoh72NVMA)
* Official Whitepaper: [Worktips Whitepaper](http://worktips.info/whitepaper_worktips.zip)
* Official Block explorer: [Worktips Block explorer](http://blockexplorer.worktips.info)

## Features

- Lite
- CPU miner
- Remote node sync
- No local blockchain storing
- Send Worktips
- Receive Worktips
- Address book
- CSV export
- Transactions history
- Open wallet
- Backup wallet
- Import keys
- Export keys
- Create wallet
- Encrypt wallet

## How to use (tested on Windows 7/10 - 32/64 bit)

**1. Backup your CLI wallet file (create a copy for safety)**

**2. Start Worktips lite wallet for Windows and open your wallet file**

**3. Synchronize with the network**

**4. Use**


## How to compile

### Compile on Windows 7/10 (64 bit)

**1. Get sources & libs**

1. Create an account on [GitHub.com](github.com) or log in to an existing one
2. Fork [Worktips lite wallet](https://github.com/Vordas/worktips-lite-wallet.git) or/and download it
3. Unzip the _rocksdb.zip_ located in `lib` folder

**2. Install dependencies**

Recommended: Microsoft Visual Studio 15 2017, CMake 3.1.x or later, Boost 1.58 or later and and Qt 5.10.

Get dependencies:
- http://www.microsoft.com
- http://www.cmake.org
- http://www.boost.org
- https://www.qt.io


**3. Configure and generate the project files**

- start CMake GUI and navigate to the repository folder using the field _Where is the source code:_
- in the field _Where to build the binaries:_ specify the build folder location
- click the _Configure_ button to start the configuration
- select _Visual Studio 15 2017 Win64_ option.
- click the _Finish_ button to run the configuration
- after the configuration is done, click the _Generate_ button to generate your project files
- after successfull generation click the button _Open project_ to start building the binaries

**5. Build**

- CMake GUI will open the project in the Microsoft Visual Studio you selected for the configuration
- wait for the Microsoft Visual Studio to scan and prepare all of the files for the project
- the scan is finished when the message _Ready_ appears
- click the _Build_ button from the main menu

_your binaries are located in either the `src/release` or the `src/debug` sub folders depending on your MSVC configuration_
