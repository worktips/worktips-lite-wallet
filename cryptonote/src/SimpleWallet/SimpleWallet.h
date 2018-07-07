// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// 
// Please see the included LICENSE file for more information.

#ifdef _WIN32
/* Prevents windows.h redefining min/max which breaks compilation */
#define NOMINMAX
#include <windows.h>
#endif

#include <Common/SignalHandler.h>

#include <CryptoNoteCore/Account.h>
#include <CryptoNoteCore/Currency.h>

#include <Logging/FileLogger.h>
#include <Logging/LoggerManager.h>

#include <Mnemonics/electrum-words.h>

#include <NodeRpcProxy/NodeRpcProxy.h>

#include <SimpleWallet/Transfer.h>
#include <SimpleWallet/ParseArguments.h>

#include <boost/thread/thread.hpp>

enum Action {Open, Generate, Import, SeedImport, ViewWallet};

Action getAction(Config &config);

void logIncorrectMnemonicWords(std::vector<std::string> words);

void promptSaveKeys(CryptoNote::WalletGreen &wallet);

void printPrivateKeys(CryptoNote::WalletGreen &wallet, bool viewWallet);

void balance(CryptoNote::INode &node, CryptoNote::WalletGreen &wallet,
             bool viewWallet);

void welcomeMsg();

void help(bool viewWallet);

void inputLoop(std::shared_ptr<WalletInfo> &walletInfo,
               CryptoNote::INode &node);

void exportKeys(std::shared_ptr<WalletInfo> &walletInfo);

void run(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node,
         Config &config);

void blockchainHeight(CryptoNote::INode &node, CryptoNote::WalletGreen &wallet);

void listTransfers(bool incoming, bool outgoing, 
                   CryptoNote::WalletGreen &wallet, CryptoNote::INode &node);

void findNewTransactions(CryptoNote::INode &node, 
                         std::shared_ptr<WalletInfo> &walletInfo);

void reset(CryptoNote::INode &node, std::shared_ptr<WalletInfo> &walletInfo);

void printOutgoingTransfer(CryptoNote::WalletTransaction t,
                           CryptoNote::INode &node);

void printIncomingTransfer(CryptoNote::WalletTransaction t,
                           CryptoNote::INode &node);

void checkForNewTransactions(std::shared_ptr<WalletInfo> &walletInfo);

void confirmPassword(std::string);

void connectingMsg();

void viewWalletMsg();

bool isValidMnemonic(std::string &mnemonic_phrase, 
                     Crypto::SecretKey &private_spend_key);

bool shutdown(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node,
              bool &alreadyShuttingDown);

std::string getInputAndDoWorkWhileIdle(std::shared_ptr<WalletInfo> &walletInfo);

std::string getNewWalletFileName();

std::string getExistingWalletFileName(Config &config);

std::string getWalletPassword(bool verifyPwd);

std::string getBlockTime(CryptoNote::BlockDetails b);

std::shared_ptr<WalletInfo> importFromKeys(CryptoNote::WalletGreen &wallet, 
                                           Crypto::SecretKey privateSpendKey,
                                           Crypto::SecretKey privateViewKey);

Maybe<std::shared_ptr<WalletInfo>> openWallet(CryptoNote::WalletGreen &wallet,
                                              Config &config);

std::shared_ptr<WalletInfo> importWallet(CryptoNote::WalletGreen &wallet);

std::shared_ptr<WalletInfo> createViewWallet(CryptoNote::WalletGreen &wallet);

std::shared_ptr<WalletInfo> mnemonicImportWallet(CryptoNote::WalletGreen 
                                                 &wallet);

std::shared_ptr<WalletInfo> generateWallet(CryptoNote::WalletGreen &wallet);

Maybe<std::shared_ptr<WalletInfo>> handleAction(CryptoNote::WalletGreen &wallet,
                                                Action action, Config &config);

Crypto::SecretKey getPrivateKey(std::string outputMsg);

ColouredMsg getPrompt(std::shared_ptr<WalletInfo> &walletInfo);

CryptoNote::BlockDetails getBlock(uint32_t blockHeight,
                                  CryptoNote::INode &node);
