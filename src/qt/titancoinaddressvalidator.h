// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Titancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TTN_QT_TTNADDRESSVALIDATOR_H
#define TTN_QT_TTNADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TitancoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TitancoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Titancoin address widget validator, checks for a valid titancoin address.
 */
class TitancoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TitancoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // TTN_QT_TTNADDRESSVALIDATOR_H
