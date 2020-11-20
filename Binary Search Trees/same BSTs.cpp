#include <vector>

using namespace std;

void subParts( const vector<int>& m, vector<int>& l, vector<int>& r )
{
	for ( int i = 1; i < m.size(); i++ ) { ( m.at(i) < m.at(0) ) ? l.push_back(m.at(i)) : r.push_back(m.at(i)); }
}

bool sameBsts(vector<int> m1, vector<int> m2) {
	bool l_ret(false);
	vector<int> left1, right1, left2, right2;
	
	if ( m1.size() != m2.size() ) { return false; }
	if ( m1.empty()             ) { return true;  }
	if ( m1.at(0)  != m2.at(0)  ) { return false; }
	
	subParts(m1, left1, right1 );
	subParts(m2, left2, right2 );
	
	return sameBsts( left1 , left2  ) && sameBsts( right1, right2 );
}
