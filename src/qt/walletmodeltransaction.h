// Copyright (c) 2013-2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Titancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TTN_QT_WALLETMODELTRANSACTION_H
#define TTN_QT_WALLETMODELTRANSACTION_H

#include "walletmodel.h"

#include <QObject>

class SendCoinsRecipient;
class SendAssetsRecipient;

class CReserveKey;
class CWallet;
class CWalletTx;

/** Data model for a walletmodel transaction. */
class WalletModelTransaction
{
public:
    explicit WalletModelTransaction(const QList<SendCoinsRecipient> &recipients);
    ~WalletModelTransaction();

    QList<SendCoinsRecipient> getRecipients() const;

    CWalletTx *getTransaction() const;
    unsigned int getTransactionSize();

    void setTransactionFee(const CAmount& newFee);
    CAmount getTransactionFee() const;

    CAmount getTotalTransactionAmount() const;

    void newPossibleKeyChange(CWallet *wallet);
    CReserveKey *getPossibleKeyChange();

    void reassignAmounts(int nChangePosRet); // needed for the subtract-fee-from-amount feature

private:
    QList<SendCoinsRecipient> recipients;
    CWalletTx *walletTransaction;
    CReserveKey *keyChange;
    CAmount fee;
};

#endif // TTN_QT_WALLETMODELTRANSACTION_H
