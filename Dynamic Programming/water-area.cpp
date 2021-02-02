#include <vector>
#include <algorithm>

int waterArea(std::vector<int> v) {
    std::vector<int> maxes( std::size(v), 0 );
    int leftMax{ 0 }, rightMax{ 0 };
    
    for ( int i = 0; i < std::size(v); ++i ) {
        maxes[i] = leftMax;
        leftMax  = std::max( leftMax, v[i] );
    }
    
    for ( int i = std::size(v) - 1; i >= 0; --i ) {
        int minHeight = std::min( rightMax, maxes[i] );
        maxes[i] = ( v[i] < minHeight ) ? minHeight - v[i] : 0;
        rightMax = std::max( rightMax, v[i] );
    }
    
    return std::accumulate( std::begin(maxes), std::end(maxes), 0 );
}
