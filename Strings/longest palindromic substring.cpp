#include <iterator>
using namespace std;

string longestPalindromicSubstring(string s) {
  if      ( s.empty()     ) { return ""; }
	else if ( s.size() == 1 ) { return s;  }
	
	string res;
	int		 rsize(0);
	
	for   ( int i = 0; i < s.size(); i++ )
	{
		for ( int j = 0; j < s.size()-i; j++ )
		{
			string s1(s.begin()+i, s.end()-j), s2(s1.rbegin(), s1.rend());
			if ( s1 == s2 && s1.size() > rsize ) { res = s1; rsize = s1.size(); }
		}
	}
  return res;
}
