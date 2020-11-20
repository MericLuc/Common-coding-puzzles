#include <vector>

int numberOfWaysToMakeChange(int n, std::vector<int> m) 
{
	std::vector<int> ways(n+1, 0);
	ways[0] = 1;
	
	for    ( auto& it : m ) 
		for  ( int i = 1; i <= n; i++ )
			if ( it <= i ) { ways[i] += ways[i-it]; }
	
  return ways[n];
}
