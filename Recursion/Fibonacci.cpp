#include<vector>

int getNthFib(int n) 
{
	static std::vector<int> v(100,-1);
	v[1] = 0; v[2] = 1;
	
	if ( v.at(n) == -1 ) { v[n] = getNthFib(n-1) + getNthFib(n-2); }
  return v.at(n);
}
