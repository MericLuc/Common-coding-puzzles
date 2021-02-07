/*!
 * @brief Quick Select
 *        From https://www.algoexpert.io/questions/Quickselect
 */

#include <vector>

int helper(std::vector<int> in, int stIdx, int edIdx, int pos) {
    while ( true ) {
        int pIdx{ stIdx }, lIdx{ stIdx + 1 }, rIdx{ edIdx };
        while ( lIdx <= rIdx ) {
            if ( in[lIdx] > in[pIdx] && in[rIdx] < in[pIdx] ) std::swap( in[lIdx], in[rIdx] );
            if ( in[lIdx] <= in[pIdx] ) lIdx++;
            if ( in[rIdx] >= in[pIdx] ) rIdx--;
        }
        std::swap( in[pIdx], in[rIdx] );
        if      ( rIdx == pos ) return in[rIdx];
        else if ( rIdx <  pos ) stIdx = rIdx + 1;
        else                                      edIdx = rIdx - 1;
    }
}

int quickselect(std::vector<int> in, int k) {
  return helper( in, 0, std::size(in) - 1, k - 1 );
}
