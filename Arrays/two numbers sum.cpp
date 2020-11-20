#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int res) {
	for ( auto it = array.begin(); it != array.end(); it++ )
		if ( find(it+1, array.end(), res - *it) != array.end() ) { return {*it, res - *it}; }
  return {};
}
