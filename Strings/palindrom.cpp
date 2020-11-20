using namespace std;

bool isPalindrome(string s) { return equal(s.begin(), s.begin() + s.size()/2, s.rbegin()); }
