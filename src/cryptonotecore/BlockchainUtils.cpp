// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2020, The TurtleCoin Developers // Copyright (c) 2020, TRRXITTE inc.
//
// Please see the included LICENSE file for more information.

#include "BlockchainUtils.h"

namespace CryptoNote
{
    namespace Utils
    {
        bool restoreCachedTransactions(
            const std::vector<BinaryArray> &binaryTransactions,
            std::vector<CachedTransaction> &transactions)
        {
            transactions.reserve(binaryTransactions.size());

            for (auto binaryTransaction : binaryTransactions)
            {
                Transaction transaction;
                if (!fromBinaryArray(transaction, binaryTransaction))
                {
                    return false;
                }

                transactions.emplace_back(std::move(transaction));
            }

            return true;
        }

    } // namespace Utils
} // namespace CryptoNote
