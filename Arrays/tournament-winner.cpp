/*!
 * @brief Tournament Winner
 *        From https://www.algoexpert.io/questions/Tournament%20Winner
 */

#include <vector>
#include <map>

template < typename T >
using V = std::vector<T>;

std::string tournamentWinner(V<V<std::string>> in,
                             V<int>            res) {
    std::map< std::string, int > arr;
    
    for ( size_t i = 0; i < std::size(in); ++i )
        arr[ in[i][ res[i] ? 0 : 1 ] ] += 3;
    
    auto pr = std::max_element( std::begin(arr), std::end(arr),
    [] (const auto& p1, const auto& p2) { return p1.second < p2.second; } );
  return pr->first;
}
