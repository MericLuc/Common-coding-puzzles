#include <vector>

template< class T > 
std::vector<T> insertionSort( const std::vector<T>& m )
{
	std::vector<T> v(m);
	for ( int i = 0; i < v.size(); i++ )
	{
		int j(i);
		while( j > 0 && v[j-1] > v[j] ) { swap( v[j], v[j-1] ); --j; }
	}
	return v;
}
