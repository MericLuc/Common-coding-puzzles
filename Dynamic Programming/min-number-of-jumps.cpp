/*!
 * @brief Minimal number of jumps.
 *        From https://www.algoexpert.io/questions/Min%20Number%20Of%20Jumps
 */

#include <vector>
#include <climits>

// O(n^2) time | O(n) space
int minNumberOfJumps(std::vector<int> in) {
    std::vector<int> res( std::size(in), INT_MAX );
    res.back() = 0;
    
    for ( int i = std::size(res) - 2; i >= 0; --i ) {
        for ( int j = 1; j <= in[i]; ++j ) {
            int nextIdx =  min((size_t)i + j, std::size(in) - 1);
            if ( 1 + res[ nextIdx ] < res[i] ) res[ i ] = 1 + res[ nextIdx ];
        }
    }
    return res[0];
}
