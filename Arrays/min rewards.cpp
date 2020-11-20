#include <vector>
#include <algorithm>

using namespace std;

bool checkOrder( int i, const vector<int>& s, vector<int>& r )
{
	bool l_ret(false);
	if      ( i == 0            ) 
	{ 
		if ( (s.at(i) > s.at(i + 1)) && (r.at(i) <= r.at(i + 1)) ) { r[i] = r[i+1] + 1; l_ret = true; }
	}
	else if ( i == r.size() - 1 ) 
	{ 
		if ( (s.at(i) > s.at(i - 1)) && (r.at(i) <= r.at(i - 1)) ) { r[i] = r[i-1] + 1; l_ret = true; }
	}
	else
	{
		if ( (s.at(i) > s.at(i + 1)) && (r.at(i) <= r.at(i + 1)) ) { r[i] = r[i+1] + 1; l_ret = true; }
		if ( (s.at(i) > s.at(i - 1)) && (r.at(i) <= r.at(i - 1)) ) { r[i] = r[i-1] + 1; l_ret = true; }
	}
	return l_ret;
}

int minRewards(vector<int> s) {
	bool l_keep(true);
	
	vector<int> rwds( s.size(), 1 );
	
	if      ( s.empty()     ) { return 0; }
	else if ( s.size() == 1 ) { return 1; }
	
	int j = 0;
	while( l_keep )
	{
		l_keep = false;
		for ( int i = 0; i < s.size(); i++ )
		{
			l_keep |= checkOrder(i, s, rwds);
		}
	}
  return accumulate( rwds.begin(), rwds.end(), 0 );
}
