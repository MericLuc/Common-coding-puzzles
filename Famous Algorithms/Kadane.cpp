#include <vector>
#include <climits>

int kadanesAlgorithm(std::vector<int> m) 
{
  int curS(0), maxS(INT_MIN);
	for ( int i = 0; i < m.size(); i++ )
	{
		curS = max(curS + m[i], m[i]);
		if ( curS > maxS ) { maxS = curS; }
	}
  return maxS;
}
