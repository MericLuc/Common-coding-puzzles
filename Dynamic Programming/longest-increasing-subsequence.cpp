/*!
 * @brief Find the longest increasing subsequence in an array.
 *        Idea from AlgoExpert.
 */

#include <vector>
#include <climits>

std::vector<int> buildSeq(const std::vector<int>& in,
                          const std::vector<int>& seq,
                          int                     idx) {
    std::vector<int> ret;
    while ( idx != INT_MIN ) { 
        ret.push_back( in[idx] );
        idx = seq.at(idx); 
    }
    return {std::rbegin(ret), std::rend(ret)};
}

int binSearch(int               stIdx, 
              int               endIdx,
              int               num,
              std::vector<int>& idxes,
              std::vector<int>& in) {
    if ( stIdx > endIdx ) return stIdx;
    int midIdx{ (stIdx + endIdx) / 2 };
    if ( in[idxes[midIdx]] < num ) { stIdx  = midIdx + 1; }
    else                           { endIdx = midIdx - 1; }
    
    return binSearch(stIdx, endIdx, num, idxes, in);
}

// O(n.log(n)) time | O(n) space
std::vector<int> longestIncreasingSubsequence(std::vector<int> m) {
    std::vector<int> seqs ( std::size(m)    , 0       );
    std::vector<int> idxes( std::size(m) + 1, INT_MIN ); // Nothing at index 0.
    int              len{ 0 };
    
    for ( int i = 0; i < std::size(m); ++i ) {
        int newL { binSearch(1, len, m[i], idxes, m) };
        seqs [i   ] = idxes[newL - 1];
        idxes[newL] = i;
        if ( newL > len ) len = newL;
    }
    return buildSeq(m, seqs, idxes[len]);
}
