using namespace std;

int longestPeak(vector<int> m) {
	if ( m.size() < 3 ) { return 0; }
	
	bool ascending(true);
	int  cur(1), max(0);
	
	for ( int i = 0; i < m.size() - 1; i++ )
	{
		if      ( m.at(i+1) == m.at(i) )
		{
			if ( (cur > max) && !ascending ) { max = cur; }
			cur = 1;
			ascending = true;
		}
		else if ( m.at(i+1) >  m.at(i) )
		{
			if ( ascending ) { cur++; }
			else 
			{
				if ( cur > max ) { max = cur; }
				cur = 2;
				ascending = true;
			}
		}
		else
		{
			ascending = false; 
			if ( cur > 1 ) cur++;
		}
	}
	
	if ( cur > max && !ascending ) { max = cur; }
  return max >= 3 ? max : 0;
}
