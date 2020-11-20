#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> m, int t) {
  int x(0), y(m.at(0).size()-1);
	
	while( x < m.size() && y >= 0 )
	{
		if      ( m[x][y] > t ) { y--;          }
		else if ( m[x][y] < t ) { x++;          }
		else 					{ return {x,y}; }
	}
	return {-1, -1};
}
