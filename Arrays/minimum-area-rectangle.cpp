/*!
 * @brief Minimum Area rectangle from a list of points.
 *        Question from AlgoExpert.
 */

#include <vector>
#include <limits>
#include <algorithm>
#include <set>
#include <cmath>

template < typename T >
using V = std::vector<T>;

std::set<std::string> createPointSet( V<V<int>> pts ) {
    std::set<std::string> ret;
    
    for ( const auto& pt : pts ) ret.insert( std::to_string(pt[0]) + ":" + std::to_string(pt[1]) );
    return ret;
}

int minimumAreaRectangle( V<V<int>> pts ) {
    std::set<std::string> ptSet{ createPointSet(pts) };
    int minArea{ std::numeric_limits<int>::max() };
    
    for ( int curIdx = 0; curIdx < std::size(pts); ++curIdx ) {
        int p2x{ pts[curIdx][0] }, p2y{ pts[curIdx][1] };
        for ( int prvIdx = 0; prvIdx < curIdx; ++prvIdx ) {
            int p1x { pts[prvIdx][0] }, p1y{ pts[prvIdx][1] };
            
            if ( p1x == p2x || p1y == p2y ) continue;
            
            bool b1 = ptSet.find( std::to_string(p1x) + ":" + std::to_string(p2y) ) != std::end(ptSet);
            bool b2 = ptSet.find( std::to_string(p2x) + ":" + std::to_string(p1y) ) != std::end(ptSet);
            
            if ( b1 && b2 ) { minArea = std::min( minArea, abs(p2x - p1x) * abs(p2y - p1y) ); }
        }
    }
    return minArea != std::numeric_limits<int>::max() ? minArea : 0;
}
