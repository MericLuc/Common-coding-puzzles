/*!
 * @brief Cycle in graph
 *        From https://www.algoexpert.io/questions/Cycle%20In%20Graph
 */

#include <vector>

template < typename T >
using V = std::vector<T>;

bool helper(int n, V<V<int>>& edges, V<bool>& vis, V<bool>& cur) {
    vis[n] = true;
    cur[n] = true;
    for ( auto& neighbor : edges[n] ) {
        if ( !vis[neighbor] && helper( neighbor, edges, vis, cur ) ) return true;
        else if ( cur[neighbor] ) return true;
    }
    cur[n] = false;
    return false;
}

bool cycleInGraph(V<V<int>> edges) {
  int nb = std::size( edges );
    V<bool> vis( nb, false ), cur{ vis };
    
    for ( int n = 0; n < nb; ++n )
        if ( !vis[n] && helper( n, edges, vis, cur ) ) return true;
  return false;
}
