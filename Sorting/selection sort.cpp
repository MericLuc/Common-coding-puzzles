#include <vector>

template< class T > 
std::vector<T> selectionSort( const std::vector<T>& m )
{
	std::vector<T> v(m);
	for ( int i = 0; i < v.size() - 1; i++ )
	{
		int min(i);
		for ( int j = i + 1; j < v.size(); j++ ) 
			if ( v[j] < v[min] ) { min = j; }
		if ( min != i ) { swap( v[i], v[min] ); }
	}
	return v;
}