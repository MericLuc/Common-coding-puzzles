
#include <vector>
#include <climits>

int minNumberOfCoinsForChange(int n, std::vector<int> m) {
	std::vector<int> coins(n+1, INT_MAX); coins[0] = 0;
	
	for    ( auto& it : m ) 
		for  ( int i = 1; i <= n; i++ )
			if ( it <= i && coins[i] > coins[i-it] ) { coins[i] = 1 + coins[i-it]; }
	
  return coins[n] == INT_MAX ? -1 : coins[n];
}
