/*!
 * @brief Staircase Traversal
 *        From https://www.algoexpert.io/questions/Staircase%20Traversal
 */

#include <algorithm>

int helper(int h, int maxS) {
    if ( h <= 1 ) return 1;
    int ret{ 0 };
    for ( int i = 1; i < std::min(maxS, h) + 1; ++i ) ret += helper( h - i, maxS );
    return ret;
}

int staircaseTraversal(int h, int maxS) {
    return helper(h, maxS);
}
