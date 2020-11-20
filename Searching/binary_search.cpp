#include <vector>
using namespace std;

int binarySearch( vector<int> m, int trgt ) {
	int l_ret(-1);
	int l_min(0), l_max(m.size() - 1);
	
	if (  m.empty() || ( m.at(l_min) > trgt ) || ( m.at(l_max) < trgt )) { return l_ret; }
	
	while( l_min <= l_max )
	{
		int l_med = l_min + ceil((l_max - l_min) / 2.f);
		
		if      ( m.at(l_med) == trgt ) { return l_med     ; }
		else if ( m.at(l_med)  > trgt ) { l_max = l_med - 1; }
		else							{ l_min = l_med + 1; }
	}
	return l_ret;
}
