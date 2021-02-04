/*!
 * @brief Powerset of an array of unique integers.
 *        A powerset is the set of all subsets of an array.
 *
 * Example : [1, 2, 3] -> [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
 */

#include <vector>

template< typename T >
using V = std::vector<T>;

V<V<int>> powerset(V<int> in) {
     V<V<int>> ret{ {} };
    for ( const auto& elm : in ) {
        size_t length { std::size(ret) };
        for ( size_t i = 0; i < length; ++i ) {
            V<int> cur { ret[i] };
            cur.push_back(elm);
            ret.push_back(cur);
        }
    }
  return ret;
}
