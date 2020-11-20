using namespace std;
typedef vector<vector<int>> GRID;

const GRID dirs = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool isAvailable( int row, int col, const GRID& m, const GRID& vis )
{
	return ( (row >=0 && row < m.size()      ) &&
				   (col >=0 && col < m.at(0).size()) &&
				   !vis.at(row).at(col) );
}

vector<int> spiralTraverse(GRID m) {
	if ( m.empty() ) { return {}; }
	
  GRID        vis( m.size(), vector<int>(m.at(0).size(),0) );
	vector<int> l_res;
	int         d(0), cmpt(1);
	int				  i(0), j(0);
	
	vis[i][j] = 1;
	l_res.push_back( m.at(0).at(0) );
	
	while( cmpt < m.size() * m.at(0).size() )
	{
		if ( isAvailable(i + dirs.at(d).at(0), 
										 j + dirs.at(d).at(1), 
										 m, vis ) )
		{
			i += dirs.at(d).at(0);
			j += dirs.at(d).at(1);
			
			vis[i][j] = 1;
			cmpt++;
			l_res.push_back( {m.at(i).at(j)} );
		}
		else { d = (d+1) % 4; }
	}
	
  return l_res;
}
