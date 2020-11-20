#include <any>
#include <vector>

using namespace std;

int productSum(vector<any> v, int m = 1) {
	int l_ret(0);
  for ( auto& it : v ) {
		l_ret += ( it.type() == typeid(vector<any>) ) ? productSum(any_cast<vector<any>>(it), m+1) : any_cast<int>(it);
	} 
  return l_ret * m;
}