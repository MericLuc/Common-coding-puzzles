#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<int> > GRID;
typedef pair<int, int>	      ELEM;

ELEM operator+(const ELEM& l,const ELEM& r) { return {l.first+r.first,l.second+r.second}; } 

const ELEM   dirs[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} }; /* NORTH, SOUTH, EAST, WEST */

bool inRange( int i, int j, const GRID& m   ) { return ( i>=0 && i<m.size() && j>=0 && j<m.at(0).size() ); }

bool isVis  ( int i, int j, const GRID& vis ) { return vis.at(i).at(j); }

bool isRiver( int i, int j, const GRID& m   ) { return m.at(i).at(j);   }

bool testCandidate( int i, int j, const GRID& vis, const GRID& m )
{
	return ( inRange(i, j, m) && !isVis(i, j, vis) && isRiver(i, j, m) );
}

bool testCandidate( ELEM pt, const GRID& vis, const GRID& m )
{
	return testCandidate( pt.first, pt.second, vis, m );
}

int computeSize( int row, int col, GRID& vis, const GRID& m, int curSize )
{
	bool stop(true)  ;
	queue<ELEM> elems;
	elems.push( {row,col} );
	
	while( !elems.empty() )
	{
		ELEM curPt = elems.front();
		elems.pop();
		
		if ( !isVis(curPt.first, curPt.second, vis) && ++curSize ) { 
			vis[curPt.first][curPt.second] = 1;
			
			for ( const auto& it : dirs )
				if ( testCandidate( curPt + it, vis, m ) ) { elems.emplace( curPt + it ); }
		}
	}
	return curSize;
}

vector<int> riverSizes( GRID m ) 
{
	vector<int> l_ret ;
	GRID        l_vis( m.size(), vector<int>(m.at(0).size(), 0) );
	
	for   ( int i = 0; i < m.size();       i++ )
		for ( int j = 0; j < m.at(0).size(); j++ )
			if ( testCandidate(i, j, l_vis, m) ) { l_ret.emplace_back( computeSize(i, j, l_vis, m, 0 ) ); }
  return l_ret;
}