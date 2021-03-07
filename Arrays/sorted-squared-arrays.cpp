/*!
 * @bref Output a sorted array of squarred elements from sorted input array 
 *       From https://www.algoexpert.io/questions/Sorted%20Squared%20Array
 */

#include <vector>
#include <algorithm>

// O(nlog(n)) time | O(n) space
/*
std::vector<int> sortedSquaredArray(std::vector<int> in) {
    std::sort( std::begin(in),
               std::end  (in),
               [](const int& a, const int& b){ 
               return abs(a) < abs(b); } );
    std::transform( std::begin(in),
                    std::end  (in),
                    std::begin(in),
                    [](auto& elm) { return elm * elm; } );
  return in;
}
*/

// O(n) time | O(n) space
std::vector<int> sortedSquaredArray(std::vector<int> in) {
    std::vector<int> res( std::size(in), 0 );
    int minIdx( 0 ), maxIdx( std::size(res) - 1 );
    
    for ( int i = std::size(res) - 1; i >= 0; --i ) {
        if ( abs(in[minIdx]) > abs(in[maxIdx]) ) {
            res[i] = in[minIdx] * in[minIdx];
            ++minIdx;
        }
        else {
            res[i] = in[maxIdx] * in[maxIdx];
            --maxIdx;
        }
    }
  return res;
}