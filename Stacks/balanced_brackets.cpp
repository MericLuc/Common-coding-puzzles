#include <stack>
using namespace std;

bool balancedBrackets(string str) {
	stack<char> pile;
	static const map<char, char> mp = { {')', '('}, {']', '['}, {'}', '{'} };
	
	for ( auto& c : str )
	{
		switch ( c )
		{
			case '(': case '[': case '{': pile.push(c); break;
			case ')': case ']': case '}': 
				if ( pile.empty() || pile.top() != mp.at(c) ) { return false; }
				else 										  { pile.pop()  ; }
				break;
			default: break;
		}
	}
  return pile.empty();
}