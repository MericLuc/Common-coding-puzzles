/*!
 * @brief Compute the common subsequence of two input strings.
 */

#include <vector>

template < typename T>
using V = std::vector<T>;

V<char> buildSeq( V<V<int>> l, std::string s) {
    V<char> seq;
    int i(std::size(l) - 1), j(std::size(l[0]) - 1);
    while ( i && j ) {
        if      ( l[i][j] == l[i - 1][j] ) i--;
        else if ( l[i][j] == l[i][j - 1] ) j--;
        else { seq.insert( std::begin(seq), s[j - 1] ); i--; j--; }
    }
    return seq;
} 

// O(nm) time | O(nm) space
V<char> longestCommonSubsequence(std::string s1, std::string s2) {
    V<V<int>> l( s2.length() + 1, V<int>(s1.length() + 1, 0));
    for ( int i = 1; i < s2.length() + 1; i++ ) {
      for ( int j = 1; j < s1.length() + 1; j++ ) {
        if ( s2[i - 1] == s1[j - 1] ) l[i][j] = l[i - 1][j - 1] + 1;
        else { l[i][j] = max( l[i - 1][j], l[i][j - 1] ); }
      }
    }
    return buildSeq(l, s1);
}
