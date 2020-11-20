#include <vector>
#include <set>
using namespace std;

vector<int> largestRange(vector<int> array) 
{
	set<int> s( array.begin(), array.end() );
	
	set<int>::iterator it   (s.begin());	
	int curRange(0), maxRange(0), stIdx(0);
	for ( ; it != s.end(); it++ )
	{
		if ( (next(it) != s.end())&& (*next(it) - *it == 1) ) { curRange++; }
		else 
		{ 
			if ( curRange > maxRange ) { maxRange = curRange; stIdx = distance(s.begin(), it) - curRange; }
			curRange = 0; 
		}
	}
	it = s.begin(); advance(it, stIdx);
	return {*it, *it + maxRange};
}
