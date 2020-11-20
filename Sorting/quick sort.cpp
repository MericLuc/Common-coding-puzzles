#include <vector>
using namespace std;

void _qsort( vector<int>& m, int st, int ed )
{
	if ( st >= ed ) { return; }
	
	int pvt(st), L(st+1), R(ed);
	
	while( R >= L )
	{
		if ( m.at(L) >  m.at(pvt) && 
			   m.at(R) <  m.at(pvt)  ) { std::swap( m[L], m[R] ); }
		if ( m.at(L) <= m.at(pvt)  ) { L++; }
		if ( m.at(R) >= m.at(pvt)  ) { R--; }
	}
	std::swap( m[pvt], m[R] );
	
	if ( R - 1 - st < ed - R - 1 ) 
	{ 
		_qsort(m, st , R-1); 
		_qsort(m, R+1, ed );
	}
	else
	{
		_qsort(m, R+1, ed );
		_qsort(m, st , R-1);
	}
}

vector<int> quickSort(vector<int> array) {
	_qsort( array, 0, array.size() - 1 );
  return array;
}
