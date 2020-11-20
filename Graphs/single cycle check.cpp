using namespace std;

bool hasSingleCycle(vector<int> m) {
	int idx(0), cmpt(0);
	vector<int> vis(m.size(), 0);

	while ( vis.at(idx) == 0 )
	{
		vis[idx] = 1;
		cmpt++;
		idx = ( idx + m[idx] )  % (int)m.size();
		if ( idx < 0 ) idx += (int)m.size();
	}
	
  return !idx && cmpt == m.size();
}
