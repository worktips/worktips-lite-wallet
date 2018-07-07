// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// 
// Please see the included LICENSE file for more information.

#include "version.h"
#include "CryptoNoteConfig.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

struct Config
{
    bool exit;

    bool walletGiven;
    bool passGiven;

    std::string host;
    int port;

    std::string walletFile;
    std::string walletPass;
};

char* getCmdOption(char ** begin, char ** end, const std::string & option);

bool cmdOptionExists(char** begin, char** end, const std::string& option);

Config parseArguments(int argc, char **argv);

void helpMessage();

void versionMessage();
