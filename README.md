![N|Solid](https://titanprojects.co/images/logo.svg)

* Copyright (c) 2009-2021 The Bitcoin Core developers
* Copyright (c) 2017-2021 The Raven Core developers
* Copyright (c) 2018-2021 The Rito Core Developers
* Copyright (c) 2021 The Titancoin Core Developers

What is Titancoin?
----------------
https://www.titanprojects.co

Titan Coin is an experimental new digital currency that enables instant payments to anyone, 
anywhere in the world. Titan Coin uses state of the art scientific ASIC proof "X21s" algorithm. Titancoin's 
blockchain can be used to deploy assets within few clicks, easier than ever. 

 - 2.5 minute block target
 - 5 Billion total supply
 - Block Reward: 75 TTN
 - Reward Maturity: 100 blocks
 - Concensus Algorithm: X21s
 - Difficulty Retargeting: Dark Gravity Wave
 - Asset Activation Height: 86400
 - P2P Port: 48144
 - RPC Port: 42812


License
-------

Titancoin is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.


Get Started
-----------

1. For Linux: You can use both GUI and CLI version of Titancoin depending upon your needs.

We recommend any stable version of Ubuntu 16.04 or 18.04


 1.1 Installing Dependencies 

Open the terminal and run following commands one by one:


sudo apt-get install git

sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils

sudo apt-get install libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev

sudo apt-get install libboost-all-dev

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libminiupnpc-dev

sudo apt-get install libzmq3-dev

sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler 

sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler


 1.2 Cloning titancoin

git clone  https://github.com/titancoinproject/Titan



 1.3 Giving Permissions

Once you have installed all dependencies and cloned the repository, next step is to give proper permissions to Titan folder. For that, go to the directory where Titan folder is located and then run:

$ chmod +x Titan/*.sh



 1.4 Compilation

After sucessfully giving all permissions, go inside Titan folder and run:

./autogen.sh && ./configure && make && make install

It will take a while depending upon your system's hardware configuration (RAM and Processor)



 1.5 Running Titancoin CLI

Once compilation successfully ends, you can run Titancoin daemon with following steps:

a) Make sure you are in src folder of Titan ( your_directory/Titan/src )
b) Run: ./titancoind -daemon
h) Run: ./Titancoind getinfo (To check conenction status, blocks and other information)

You have a running CLI wallet now



 1.6 Running GNU Linux GUI Wallet

If you are using a GNU Linux GUI distribution like ubuntu or debian, you can run the GUI wallet:

a) Make sure you are in src/qt folder of Titan ( your_directory/Titan/src/qt )
b) Run: ./titancoin-qt


Enjoy your GUI wallet



2. For Windows: GUI client is available.

2.1 Use the QT Executable file (titancoin-qt.exe) to run Titancoin GUI Wallet on your PC.

2.2 Data Directory is located at: Users/your_windows_user/AppData/Roaming/titancoin


3. CLI Commands

### Addressindex 

- getaddressbalance
- getaddressdeltas
- getaddressmempool
- getaddresstxids
- getaddressutxos


### Assets

- getassetdata "asset_name"
- getcacheinfo 
issue "asset_name" qty "( to_address )" "( change_address )" ( units ) ( reissuable ) ( has_ipfs ) "( ipfs_hash )"
- issueunique "root_name" [asset_tags] ( [ipfs_hashes] ) "( to_address )" "( change_address )"
- listassets "( asset )" ( verbose ) ( count ) ( start )
- listmyassets "( asset )" ( verbose ) ( count ) ( start )
- reissue "asset_name" qty "to_address" "change_address" ( reissuable ) ( new_unit) "( new_ipfs )" 
- transfer "asset_name" qty "to_address"


### Blockchain

- getbestblockhash
- getblock "blockhash" ( verbosity ) 
- getblockchaininfo
- getblockcount

- getblockhash height
- getblockhashes timestamp
- getblockheader "hash" ( verbose )
- getchaintips
- getchaintxstats ( nblocks blockhash )
- getdifficulty
- getmempoolancestors txid (verbose)
- getmempooldescendants txid (verbose)
- getmempoolentry txid
- getmempoolinfo
- getrawmempool ( verbose )
- getspentinfo
- gettxout "txid" n ( include_mempool )
- gettxoutproof ["txid",...] ( blockhash )
- gettxoutsetinfo
- preciousblock "blockhash"
- pruneblockchain
- savemempool
- verifychain ( checklevel nblocks )
- verifytxoutproof "proof"


### Control

- getinfo
- getmemoryinfo ("mode")
- help ( "command" )
- stop
- uptime


### Generating

- generate nblocks ( maxtries )
- generatetoaddress nblocks address (maxtries)
- getgenerate
- setgenerate generate ( genproclimit )


### Mining

- getblocktemplate ( TemplateRequest )
- getmininginfo
- getnetworkhashps ( nblocks height )
- prioritisetransaction <txid> <dummy value> <fee delta>
- submitblock "hexdata"  ( "dummy" )


### Network

- addnode "node" "add|remove|onetry"
- clearbanned
- disconnectnode "[address]" [nodeid]
- getaddednodeinfo ( "node" )
- getconnectioncount
- getnettotals
- getnetworkinfo
- getpeerinfo
- listbanned
- ping
- setban "subnet" "add|remove" (bantime) (absolute)
- setnetworkactive true|false


### Rawtransactions

- combinerawtransaction ["hexstring",...]
- createrawtransaction [{"txid":"id","vout":n},...] {"address":(amount or object),"data":"hex",...} ( locktime ) ( replaceable )
- decoderawtransaction "hexstring"
- decodescript "hexstring"
- fundrawtransaction "hexstring" ( options )
- getrawtransaction "txid" ( verbose )
- sendrawtransaction "hexstring" ( allowhighfees )
- signrawtransaction "hexstring" ( [{"txid":"id","vout":n,"scriptPubKey":"hex","redeemScript":"hex"},...] ["privatekey1",...] sighashtype )


### Util

- createmultisig nrequired ["key",...]
- estimatefee nblocks
- estimatesmartfee conf_target ("estimate_mode")
- signmessagewithprivkey "privkey" "message"
- validateaddress "address"
- verifymessage "address" "signature" "message"

### Wallet

- abandontransaction "txid"
- abortrescan
- addmultisigaddress nrequired ["key",...] ( "account" )
- addwitnessaddress "address"
- backupwallet "destination"
- bumpfee has been deprecated on the TTN Wallet.
- dumpprivkey "address"
- dumpwallet "filename"
- encryptwallet "passphrase"
- getaccount "address"
- getaccountaddress "account"
- getaddressesbyaccount "account"
- getbalance ( "account" minconf include_watchonly )
- getrawchangeaddress
- getreceivedbyaccount "account" ( minconf )
- getreceivedbyaddress "address" ( minconf )
- gettransaction "txid" ( include_watchonly )
- getunconfirmedbalance
- getwalletinfo
- importaddress "address" ( "label" rescan p2sh )
- importmulti "requests" ( "options" )
- importprivkey "privkey" ( "label" ) ( rescan )
- importprunedfunds
- importpubkey "pubkey" ( "label" rescan )
- importwallet "filename"
- keypoolrefill ( newsize )
- listaccounts ( minconf include_watchonly)
- listaddressgroupings
- listlockunspent
- listreceivedbyaccount ( minconf include_empty include_watchonly)
- listreceivedbyaddress ( minconf include_empty include_watchonly)
- listsinceblock ( "blockhash" target_confirmations include_watchonly include_removed )
- listtransactions ( "account" count skip include_watchonly)
- listunspent ( minconf maxconf  ["addresses",...] [include_unsafe] [query_options])
- listwallets
- lockunspent unlock ([{"txid":"txid","vout":n},...])
- move "fromaccount" "toaccount" amount ( minconf "comment" )
- removeprunedfunds "txid"
- rescanblockchain ("start_height") ("stop_height")
- sendfrom "fromaccount" "toaddress" amount ( minconf "comment" "comment_to" )
- sendmany "fromaccount" {"address":amount,...} ( minconf "comment" ["address",...] replaceable conf_target "estimate_mode")
- sendtoaddress "address" amount ( "comment" "comment_to" subtractfeefromamount replaceable conf_target "estimate_mode")
- setaccount "address" "account"
- settxfee amount
- signmessage "address" "message"
