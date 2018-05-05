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
- Select connecting master node
- Custom remote node connection
- Custom local node connection

## How to use

**1. Download the latest release of [Worktips Lite wallet](https://github.com/Vordas/worktips-lite-wallet/releases/)**

**2. Unpack the release package**

**3. Backup your CLI wallet file (skip this step if creating a new wallet)**

**4. Run `Worktips` and open your wallet file (or create a new one)**

**5. Synchronize with the network**

**6. Use the wallet**


## How to compile

### Compile on Ubuntu 16.04 (64 bit)

**1. Install dependencies**

- run an update

``
sudo apt-get update
``

- get all dependencies

``
sudo apt-get install build-essential python-dev gcc g++ git cmake libboost-all-dev librocksdb-dev qt5-default qttools5-dev-tools software-properties-common autotools-dev libicu-dev libbz2-dev zip unzip libsnappy-dev zlib1g-dev libbz2-dev
``

- Remove old boost (if boost version too low)

``
sudo apt-get remove -y libboost-dev libboost-all-dev
``

- Install Boost 1.65.0

``
wget https://dl.bintray.com/boostorg/release/1.65.0/source/boost_1_65_0.tar.bz2
``

``
tar xvjf boost_1_65_0.tar.bz2
``

``
cd boost_1_65_0
``

``
./bootstrap.sh --prefix=/usr/local
``

``
./b2
``

``
sudo ./b2 install
``

- Install Rocksdb

``
git clone https://github.com/facebook/rocksdb.git
``

``
cd rocksdb
``

``
make all
``

**2. Get the source**

``
git clone https://github.com/Vordas/worktips-lite-wallet.git worktips-wallet-lite
``

**3. Set permissions**

- navigate to:

``
cd worktips-wallet-lite/cryptonote/external/rocksdb/build_tools
``

``
chmod +x build_detect_platform version.sh
``

**4. Prepare the build**

- Navigate back to source folder

``
cd && cd worktips-wallet-lite
``

- Prepare the build

``
mkdir build && cd build
``

``
cmake -DSTATIC=ON -DCMAKE_BUILD_TYPE=RELEASE ..
``

**5. Get Rocksdb library**

- Navigate to `lib` folder

``
cd && cd worktips-wallet-lite/lib
``

- Unzip the unzip _rocksdb.lib_ library to `build` folder

``
sudo unzip rocksdb.zip -d ~/worktips-wallet-lite/build
``

**6. Build**

- Navigate to `build` folder

``
cd && cd worktips-wallet-lite/build
``

- Export flags

``
export CXXFLAGS="-std=gnu++11"
``

- Build

``
make
``

_Your executables will be located in `build/src` folder._



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
- confirm the creation of the `build` folder at the specified build folder location
- select _Visual Studio 15 2017 Win64_ option.
- click the _Finish_ button to run the configuration
- after the configuration is done, click the _Generate_ button to generate your project files
- after successfull generation click the button _Open project_ to start building the binaries

**4. Get rocksdb library**

- IMPORTANT: Unzip the _rocksdb.zip_ located in the `lib` folder and put the unzipped file _rocksdb.lib_ inside the folder `build` that was specified during step 3.

**5. Build**

- CMake GUI will open the project in the Microsoft Visual Studio you selected for the configuration
- wait for the Microsoft Visual Studio to scan and prepare all of the files for the project
- the scan is finished when the message _Ready_ appears
- Switch solution to `release`
- click the _Build_ button from the main menu

_Your binaries will be located in the `src/release` folder._
