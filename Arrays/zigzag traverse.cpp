#include <vector>

using namespace std;

bool inRange( int row, int col, const vector<vector<int> >& m )
{
	return ( row >= 0 && col >= 0 && row < m.size() && col < m.at(0).size() );
}

vector<int> zigzagTraverse(vector<vector<int>> m) {
  vector<int> l_res;
	int         i(0), j(0);
	bool				goDown(true);
	
	while( inRange(i, j, m) )
	{
		l_res.push_back( m.at(i).at(j) );
		if ( goDown ) {
			if ( i == m.size() - 1 || j == 0 ) {
				goDown = false;
				( i == m.size() - 1 ) ? j++ : i++;
			}
			else { i++; j--; }
		}
		else {
			if ( i == 0 || j == m.at(0).size() - 1 ) {
				goDown = true;
				( j == m.at(0).size() - 1 ) ? i++ : j++;
			}
			else { i--; j++; }
		}
	}
	
  return l_res;
}
