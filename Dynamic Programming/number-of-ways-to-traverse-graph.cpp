/*!
 * @brief Number of ways to traverse a graph 
 *        from topleft to botright cell going only DOWN and RIGHT.
 *        From https://www.algoexpert.io/questions/Number%20Of%20Ways%20To%20Traverse%20Graph
 */

#include <vector>

// O(w * h) time and space
// w and h respectively the widht and height of the graph
int numberOfWaysToTraverseGraph(int w, int h) {
	if ( w <= 0 || h <= 0 ) return -1;
  std::vector< std::vector<int> > grid( h+1, std::vector<int>(w+1, 0) );

	for ( int i = 1; i <= w; ++i )
		for ( int j = 1; j <= h; ++j )
			grid[j][i] = ( i == 1 || j == 1 ) ? 1 :
			                                    grid[j][i-1] + grid[j-1][i];
	
  return grid[h][w];
}
