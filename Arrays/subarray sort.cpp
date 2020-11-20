#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> m) 
{
	vector<int> cpy(m);
	sort( cpy.begin(), cpy.end() );
	
	int min(m.size()), max(0);
	
	if ( cpy == m ) { return {-1, -1}; }
	
	for ( int i = 0; i < m.size(); i++ )
	{
		if ( m.at(i) != cpy.at(i) ) { 
			if ( i < min ) { min = i; } 
			if ( i > max ) { max = i; }
		}
	}
	
  return {min, max};
}
