/*!
 * @brief Compute all the permutations of an input array.
 *        From https://www.algoexpert.io/questions/Permutations
 */

#include <vector>

template < typename T >
using V = std::vector<T>;

void helper(int i, V<int>& in, V<V<int>>& out) {
    if ( i == std::size(in) - 1 ) out.push_back(in);
    else {
        for ( int j = i; j < std::size(in); ++j ) {
            std::swap( in[i], in[j] );
            helper( i + 1, in, out );
            std::swap( in[j], in[i] );
        }
    }
}

V<V<int>> getPermutations(V<int> array) {
  V<V<int>> res;
  helper(0, array, res);
  return res;
}
