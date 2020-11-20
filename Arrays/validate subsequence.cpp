using namespace std;

bool isValidSubsequence(vector<int> m, vector<int> seq) {
	int lastPos(-1);
	vector<int>::iterator cpyIt(m.begin()-1);
	
	if      ( seq == m || ( seq.size() == 1 && 
					  find(m.begin(), m.end(), seq.at(0)) != m.end() ) ) { return true;  }
	else if ( seq.size() >= m.size() )                           { return false; }
	
  for ( int i = 0; i < seq.size(); i++ )
	{
		vector<int>::iterator it  = find( cpyIt+1, m.end(), seq.at(i) );
		if ( it == m.end() ) { return false; }
		lastPos = distance(m.begin(), it);
		cpyIt = it;
	}
  return true;
}
