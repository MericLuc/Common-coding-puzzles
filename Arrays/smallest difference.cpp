#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> a1, vector<int> a2) {
	vector<int> l_ret(2,0);
	int min(1000);
	for ( int i = 0; i < a1.size(); i++ )
	{
		for ( int j = 0; j < a2.size(); j++ )
		{
			if ( abs(a2.at(j) - a1.at(i)) < min ) 
			{ 
				min = abs(a2.at(j) - a1.at(i)); 
				l_ret[0] = a1.at(i); 
				l_ret[1] = a2.at(j); 
			}
		}
	}
  return l_ret;
}
