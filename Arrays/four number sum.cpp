#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> m, int sum) {
	map< pair<int, int>, int > dic;
	vector<vector<int>>        res;
	
	for ( int i = 0; i < m.size() -1; i++ )
		for ( int j = i + 1; j < m.size(); j++ )
			dic[ {i,j} ] = m.at(i) + m.at(j);

	for ( int i = 0; i < m.size() -1; i++ )
	{
		for ( int j = i + 1; j < m.size(); j++ )
		{
			int diff = sum - m.at(i) - m.at(j);
			for ( auto& [key, val] : dic )
			{
				vector<int> cndt( {m.at(key.first), m.at(key.second), m.at(i), m.at(j)} );
				sort( cndt.begin(), cndt.end() );
				if ( (val == diff) && 
						 (key.first != i && key.second != j) &&
						 (key.first != j && key.second != i) &&
					    find( res.begin(), res.end(), cndt ) == res.end() )
				{
					res.emplace_back( cndt );
				}
			}
		}
	}
  return res;
}
