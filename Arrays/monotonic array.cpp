using namespace std;

bool isMonotonic(vector<int> m) {
	int cmpt1(0), cmpt2(0);
	
	for ( int i = 1; i < m.size(); i++ )
	{
		if ( m.at(i-1) <= m.at(i) ) { cmpt1++; }
		if ( m.at(i-1) >= m.at(i) ) { cmpt2++; }
	}
	
  return (m.size() <= 2 || cmpt1 == m.size()-1 || cmpt2 == m.size()-1);
}
