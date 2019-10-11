// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2019 The Titancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "bench.h"
#include "crypto/sha256.h"
#include "key.h"
#include "validation.h"
#include "util.h"
#include "random.h"

int
main(int argc, char **argv)
{
    SHA256AutoDetect();
    RandomInit();
    ECC_Start();
    SetupEnvironment();
    fPrintToDebugLog = false; // don't want to write to debug.log file

    benchmark::BenchRunner::RunAll();

    ECC_Stop();
}
