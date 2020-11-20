#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> m, int sum) 
{
	vector<vector<int>> l_ret;
	sort(m.begin(), m.end() );
	
	for ( int i = 0; i < m.size() - 2; i++ )
	{
		int j(i + 1), k(m.size() - 1);
		while( j < k )
		{
			int curSum = m.at(i) + m.at(j) + m.at(k);
			if 	     ( curSum == sum ) { l_ret.push_back({m.at(i), m.at(j), m.at(k)}); j++; k--; }
			else if  ( curSum < sum  ) { j++; }
			else                       { k--; }
		}
	}
  return l_ret;
}
