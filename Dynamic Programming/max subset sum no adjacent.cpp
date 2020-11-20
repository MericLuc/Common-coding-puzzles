#include <vector>

int maxSubsetSumNoAdjacent(std::vector<int> m) {
	if		  ( m.empty()     ) { return 0;    }
  else if ( m.size() == 1 ) { return m[0]; }
	
	std::vector<int> maxS(m);
	maxS[1] = max( m[0], m[1] );
	for ( int i = 2; i < maxS.size(); i++ ) { maxS[i] = max( maxS[i-2]+ maxS[i], maxS[i-1] ); }
	
  return maxS[ maxS.size() - 1 ];
}