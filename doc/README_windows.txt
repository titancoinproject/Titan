Copyright (c) 2009-2019 The Bitcoin Core developers
Copyright (c) 2017-2019 The Raven Core developers
Copyright (c) 2018-2019 The Rito Core Developers
Copyright (c) 2019 The Titancoin Core Developers

What is Titancoin?
----------------
https://www.titanprojects.co

Titan Coin is an experimental new digital currency that enables instant payments to anyone, 
anywhere in the world. Titan Coin uses state of the art scientific ASIC proof "X21s" algorithm. Titancoin's 
blockchain can be used to deploy assets within few clicks, easier than ever. 

 - 1 minute block target
 - 5 Billion total supply
 - Block Reward: 30 TTN
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

1. Both CLI & GUI clients is available for both windows 32 bit and 64 bit platforms.

2. Default location of the Data Directory is: Users/your_windows_user/AppData/Roaming/titancoin

This can be changed by passing -datadir="path to your custom data directory" flag while starting the QT or CLI wallet from the command prompt.



3. You can use following commands for interating with titancoin-cli wallet or you run them in the debug window of titancoin-qt


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
