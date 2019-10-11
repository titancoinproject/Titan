// Copyright (c) 2014-2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Titancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TTN_ZMQ_ZMQPUBLISHNOTIFIER_H
#define TTN_ZMQ_ZMQPUBLISHNOTIFIER_H

#include "zmqabstractnotifier.h"

class CBlockIndex;

class CZMQAbstractPublishNotifier : public CZMQAbstractNotifier
{
private:
    uint32_t nSequence; //!< upcounting per message sequence number

public:

    /* send zmq multipart message
       parts:
          * command
          * data
          * message sequence number
    */
    bool SendMessage(const char *command, const void* data, size_t size);

    bool Initialize(void *pcontext) override;
    void Shutdown() override;
};

class CZMQPublishHashBlockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyBlock(const CBlockIndex *pindex) override;
};

class CZMQPublishHashTransactionNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransaction(const CTransaction &transaction) override;
};

class CZMQPublishRawBlockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyBlock(const CBlockIndex *pindex) override;
};

class CZMQPublishRawTransactionNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransaction(const CTransaction &transaction) override;
};

#endif // TTN_ZMQ_ZMQPUBLISHNOTIFIER_H
