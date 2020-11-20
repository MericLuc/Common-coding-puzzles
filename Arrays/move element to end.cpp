#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> m, int toMove) {
	sort( m.begin(), m.end() );
	
	int cnt = count( m.begin(), m.end(), toMove );
	auto it = find ( m.begin(), m.end(), toMove );
	
	rotate(it, it + cnt, m.end() );
  return m;
}
