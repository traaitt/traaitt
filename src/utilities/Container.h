// Portions Copyright (c) 2018-2019 Galaxia Project Developers
// Copyright (c) 2018-2020, The TurtleCoin Developers // Copyright (c) 2020, TRRXITTE inc.
//
// Please see the included LICENSE file for more information.

#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>

namespace Utilities
{
    template<typename T, typename Function> std::vector<T> filter(const std::vector<T> &input, Function predicate)
    {
        std::vector<T> result;

        std::copy_if(input.begin(), input.end(), std::back_inserter(result), predicate);

        return result;
    }

    /* Verify that the items in a collection are all unique */
    template<typename T> bool is_unique(T begin, T end)
    {
        std::unordered_set<typename T::value_type> set {};

        for (; begin != end; ++begin)
        {
            if (!set.insert(*begin).second)
            {
                return false;
            }
        }

        return true;
    }

} // namespace Utilities
