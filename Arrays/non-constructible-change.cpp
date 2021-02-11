/*!
 * @brief Non-constructible change
 *        From https://www.algoexpert.io/questions/Non-Constructible%20Change
 */

#include <vector>
#include <algorithm>

int nonConstructibleChange(std::vector<int> coins) {
    std::sort( std::begin(coins), std::end(coins) );
    int curChange{0};
    
    for ( const int& coin : coins ) {
        if ( coin > curChange + 1 ) return curChange + 1;
        curChange += coin;
    }
  return curChange + 1;
}