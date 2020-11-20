#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> m) {
	vector<int> l_ret(3, INT_MIN);
	
	if ( m.size() < 3 ) { return {}; }
	
	for ( auto& it : m )
	{
		if      ( it < l_ret.at(0) ) { continue; }
		else if ( it > l_ret.at(2) ) { l_ret[0] = l_ret[1]; l_ret[1] = l_ret[2]; l_ret[2] = it; }
		else if ( it > l_ret.at(1) ) { l_ret[0] = l_ret[1]; l_ret[1] = it;                      }
		else						 { l_ret[0] = it;											}
	}
	
  return l_ret;
}