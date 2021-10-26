// Copyright (c) 2013-2019 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2019 The Titancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"

#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"
#include "arith_uint256.h"

#include <assert.h>

#include "chainparamsseeds.h"

//TODO: Take these out
extern double algoHashTotal[16];
extern int algoHashHits[16];


static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << CScriptNum(0) << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Money Reimagined Hey Elon Bitcoin Can Green the Grid";
    const CScript genesisOutputScript = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

void CChainParams::TurnOffSegwit() {
	consensus.nSegwitEnabled = false;
}

void CChainParams::TurnOffCSV() {
	consensus.nCSVEnabled = false;
}

void CChainParams::TurnOffBIP34() {
	consensus.nBIP34Enabled = false;
}

void CChainParams::TurnOffBIP65() {
	consensus.nBIP65Enabled = false;
}

void CChainParams::TurnOffBIP66() {
	consensus.nBIP66Enabled = false;
}

bool CChainParams::BIP34() {
	return consensus.nBIP34Enabled;
}

bool CChainParams::BIP65() {
	return consensus.nBIP34Enabled;
}

bool CChainParams::BIP66() {
	return consensus.nBIP34Enabled;
}

bool CChainParams::CSVEnabled() const{
	return consensus.nCSVEnabled;
}


class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = false; // Enable later.
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        consensus.nPowTargetSpacing = 2.5 * 60;
		consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1814; // Approx 90% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;  //Assets (RIP2)
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1540944000; // Oct 31, 2018
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1600624800; // Oct 20, 2020
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nStartTime = 1568641754; // Oct 16, 2019
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nTimeout = 1600624800; // Oct 20, 2020
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nOverrideMinerConfirmationWindow = 2016; // ~1.4 days
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nOverrideRuleChangeActivationThreshold = 1612; // ~80%

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0x43; // C
        pchMessageStart[1] = 0xe4; // N
        pchMessageStart[2] = 0x54; // T
        pchMessageStart[3] = 0x54; // T
        nDefaultPort = 48144;
        nPruneAfterHeight = 100000;

        genesis = CreateGenesisBlock(1621636680, 1411687, 0x1e00ffff, 2, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x000000ff35a1929fab806243dc60334ecf7d68616e20dac47f7d425af11d272a"));
        assert(genesis.hashMerkleRoot == uint256S("0xd4f89a5146f6a4bd086de858c67a5728c061c77d31a8fbfd1e0f66223e51cee3"));

        vSeeds.emplace_back("seed1.titanexplorer.co", false);
        vSeeds.emplace_back("seed2.titanexplorer.co", false);
        vSeeds.emplace_back("seed3.titanexplorer.co", false);

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,65);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,105);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,139);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x05, 0x34, 0xE7, 0xCA};
        base58Prefixes[EXT_SECRET_KEY] = {0x05, 0x34, 0x7E, 0xAC};

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fMiningRequiresPeers = true;

        // When adding a checkpoint. Update the default assume valid hash above to speed up sync times
        checkpointData = (CCheckpointData) {
            {
                    { 0, uint256S("0x000000ff35a1929fab806243dc60334ecf7d68616e20dac47f7d425af11d272a") },
            }
        };

        chainTxData = ChainTxData{
            // Update as we know more about the contents of the Titancoin chain
            1621636680, // * UNIX timestamp of last known number of transactions
            1,          // * total number of transactions between genesis and that timestamp
                        //   (the tx=... number in the SetBestChain debug.log lines)
            3.1         // * estimated number of transactions per second after that timestamp
        };

        /** TTN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 32 * COIN;
        nReissueAssetBurnAmount = 16 * COIN;
        nIssueSubAssetBurnAmount = 8 * COIN;
        nIssueUniqueAssetBurnAmount = 2 * COIN;

        // Burn Addresses
        strIssueAssetBurnAddress = "TTNissueMainAssetxxxxxxxxxxxbGuFVF";
        strReissueAssetBurnAddress = "TTNreissueMainAssetxxxxxxxxxWGEWXQ";
        strIssueSubAssetBurnAddress = "TTNissueSubAssetxxxxxxxxxxxxygYtLx";
        strIssueUniqueAssetBurnAddress = "TTNissueUniqueAssetxxxxxxxxxygpRdo";

        //Global Burn Address
        strGlobalBurnAddress = "TTNcommonBurnAddressxxxxxxxxud6Mwm";

        // DGW Activation
        nDGWActivationBlock = 1;

        nMaxReorganizationDepth = 60; // 60 at 1 minute block timespan is +/- 60 minutes.
        nMinReorganizationPeers = 4;
        nMinReorganizationAge = 60 * 60 * 12; // 12 hours
        /** TTN End **/

    }

};

/**
 * Testnet (v6)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1310; // Approx 65% for testchains
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 5;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1533924000; // GMT: Friday, August 10, 2018 6:00:00 PM
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1538351999; // GMT: Sunday, September 30, 2018 11:59:59 PM
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nStartTime = 1568641754; // Oct 16, 2019
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nTimeout = 1600624800; // Oct 20, 2020
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nOverrideMinerConfirmationWindow = 2016; // ~1.4 days
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nOverrideRuleChangeActivationThreshold = 1612; // ~80%

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0x74; // t
        pchMessageStart[1] = 0x74; // t
        pchMessageStart[2] = 0x6e; // n
        pchMessageStart[3] = 0x63; // c
        nDefaultPort = 48145;
        nPruneAfterHeight = 1000;

        uint32_t nGenesisTime = 1621640280;
        genesis = CreateGenesisBlock(nGenesisTime, 15393309, 0x1e00ffff, 2, 5000 * COIN);

        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000009f60050c39808a4c154d8527fc173fb6edebd086d4aeaa63c25b5258f"));
        assert(genesis.hashMerkleRoot == uint256S("d4f89a5146f6a4bd086de858c67a5728c061c77d31a8fbfd1e0f66223e51cee3"));

        vFixedSeeds.clear();
        vSeeds.clear();        

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,127);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCD};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x91};

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fMiningRequiresPeers = true;

        checkpointData = (CCheckpointData) {
            {
            }
        };

        chainTxData = ChainTxData{
            // Update as we know more about the contents of the Titancoin chain
            1621640280, // * UNIX timestamp of last known number of transactions
            1,          // * total number of transactions between genesis and that timestamp
                        //   (the tx=... number in the SetBestChain debug.log lines)
            3.1         // * estimated number of transactions per second after that timestamp
        };

        /** TTN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 500 * COIN;
        nReissueAssetBurnAmount = 100 * COIN;
        nIssueSubAssetBurnAmount = 100 * COIN;
        nIssueUniqueAssetBurnAmount = 5 * COIN;

        // Burn Addresses
        strIssueAssetBurnAddress = "tESTissueMainAssetXXXXXXXXXXUkEx9j";
        strReissueAssetBurnAddress = "tESTreissueMainAssetXXXXXXXXVN5aCo";
        strIssueSubAssetBurnAddress = "tESTissueSubAssetXXXXXXXXXXXRVMErP";
        strIssueUniqueAssetBurnAddress = "tESTissueUniqueAssetXXXXXXXXRRpLX2";

        // Global Burn Address
        strGlobalBurnAddress = "tESTcommonBurnAddressXXXXXXXXGGd3D";

        // DGW Activation
        nDGWActivationBlock = 200;

        nMaxReorganizationDepth = 60; // 60 at 1 minute block timespan is +/- 60 minutes.
        nMinReorganizationPeers = 4;
        nMinReorganizationAge = 60 * 60 * 12; // 12 hours
        /** TTN End **/
 
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.nSubsidyHalvingInterval = 150;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nOverrideMinerConfirmationWindow = 0; // ~1.4 days
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSET_FIX].nOverrideRuleChangeActivationThreshold = 0; // ~80%

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0x72; // r
        pchMessageStart[1] = 0x65; // e
        pchMessageStart[2] = 0x67; // g
        pchMessageStart[3] = 0x74; // t
        nDefaultPort = 48146;
        nPruneAfterHeight = 1000;
        

        uint32_t nGenesisTime = 1621726680;
        genesis = CreateGenesisBlock(nGenesisTime, 0, 0x207259FF, 2, 500 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x13a4b5961039087d9e04278d27786dd9e0974d4e0a710ee2edcb83e55a505b57"));
        assert(genesis.hashMerkleRoot == uint256S("c3cd38bb2fa036e6d69caa43a0f4a6eb5513be2b67c52741cbc308a137d602a5"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;

        checkpointData = (CCheckpointData) {
            {
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,122);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,197);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,240);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x85, 0xCD};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x33, 0x92};


        /** TTN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 500 * COIN;
        nReissueAssetBurnAmount = 100 * COIN;
        nIssueSubAssetBurnAmount = 100 * COIN;
        nIssueUniqueAssetBurnAmount = 5 * COIN;

        // Burn Addresses
        strIssueAssetBurnAddress = "rEGTreissueMainAssetXXXXXXXXXivQxE";
        strReissueAssetBurnAddress = "rEGTreissueMainAssetXXXXXXXXXivQxE";
        strIssueSubAssetBurnAddress = "rEGTissueSubAssetXXXXXXXXXXXUSXu7p";
        strIssueUniqueAssetBurnAddress = "rEGTissueUniqueAssetXXXXXXXXSG1F2J";

        // Global Burn Address
        strGlobalBurnAddress = "rEGTcommonBurnAddressXXXXXXXUFtc7p";

        // DGW Activation
        nDGWActivationBlock = 200;

        nMaxReorganizationDepth = 60; // 60 at 1 minute block timespan is +/- 60 minutes.
        nMinReorganizationPeers = 4;
        nMinReorganizationAge = 60 * 60 * 12; // 12 hours
        /** TTN End **/
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}

void TurnOffSegwit(){
	globalChainParams->TurnOffSegwit();
}

void TurnOffCSV() {
	globalChainParams->TurnOffCSV();
}

void TurnOffBIP34() {
	globalChainParams->TurnOffBIP34();
}

void TurnOffBIP65() {
	globalChainParams->TurnOffBIP65();
}

void TurnOffBIP66() {
	globalChainParams->TurnOffBIP66();
}
