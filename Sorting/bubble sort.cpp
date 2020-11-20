#include <vector>

template< class T >
std::vector<T> bubbleSort( const std::vector<T>& m )
{
	  std::vector<T> v(m);
    bool keep(true);
    while( keep )
    {
        keep = false;
        for ( int i = 0; i < v.size() - 1; i++ )
            if ( v[i] > v[i+1] ) { swap(v[i], v[i+1]); keep = true; }
    }
	return v;
}
