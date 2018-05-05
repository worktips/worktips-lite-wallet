# Worktips lite wallet

_This is the reference code for lite GUI wallet for the [Worktips](https://worktips.info) cryptocurrency._

## Features

- CPU miner
- Remote node sync
- No local blockchain storage
- Send WTIP
- Receive WTIP
- Address book
- CSV export
- Transactions history
- Create wallet
- Open wallet
- Backup wallet
- Import keys
- Export keys
- Encrypt wallet

## How to use

**1. Download the latest release of [Worktips Lite wallet](https://github.com/Vordas/worktips-lite-wallet/releases/)**

**2. Unpack the release package**

**3. Backup your CLI wallet file (skip this step if creating a new wallet)**

**4. Run `Worktips.exe` and open your wallet file (or create a new one)**

**5. Synchronize with the network**

**6. Use the wallet**


## How to compile

### Compile on Windows 7/10 (64 bit)

**1. Install dependencies**

Recommended: Microsoft Visual Studio 15 2017, CMake 3.1.x or later, Boost 1.65 or later and Qt 5.10.x

Get dependencies:
- http://www.microsoft.com
- http://www.cmake.org
- http://www.boost.org
- https://www.qt.io

**2. Get sources & libs**

1. Create an account on [GitHub.com](github.com) or log in to an existing one
2. Fork [Worktips lite wallet](https://github.com/Vordas/worktips-lite-wallet.git) or/and download it

**3. Configure and generate the project files**

- start CMake GUI and navigate to the repository folder using the field _Where is the source code:_
- in the field _Where to build the binaries:_ specify the build folder location
- click the _Configure_ button to start the configuration
- confirm the creation of the 'build' folder at the specified build folder location
- select _Visual Studio 15 2017 Win64_ option.
- click the _Finish_ button to run the configuration
- after the configuration is done, click the _Generate_ button to generate your project files
- after successfull generation click the button _Open project_ to start building the binaries

**4. Get rocksdb library**

- IMPORTANT: Unzip the _rocksdb.zip_ located in the `lib` folder and put the unzipped file _rocksdb.lib_ inside the folder 'build' that was specified during step 3.

**5. Build**

- CMake GUI will open the project in the Microsoft Visual Studio you selected for the configuration
- wait for the Microsoft Visual Studio to scan and prepare all of the files for the project
- the scan is finished when the message _Ready_ appears
- Switch solution to 'release'
- click the _Build_ button from the main menu

_your binaries will be located in the `src/release` folder._
