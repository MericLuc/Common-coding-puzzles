using namespace std;

string runLengthEncoding(string s) {
  string ret;
  string::iterator it(s.begin()), fx(s.begin());
    
  int cur(0);
  while ( it != s.end() ) {
    if ( *it == *fx ) { cur++; ++it; }
    else { 
      while ( cur >= 10 ) { ret += string("9") + *fx;  cur -= 9; }
      ret += to_string(cur) + *fx;
      cur  = 0; 
      fx   = it;
    }
  }
        
  if ( cur ) { 
        while ( cur >= 10 ) { ret += string("9") + s[s.size()-1];  cur -= 9; }
        ret += to_string(cur) + s[s.size()-1];
  }

  return ret;
}