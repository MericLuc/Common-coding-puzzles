/*!
 * \brief Compute the minimum number of passes required to convert all negative
 * numbers in a Matrix into positive integers.
 * \description This problem comes from
 * https://www.algoexpert.io/questions/Minimum%20Passes%20Of%20Matrix
 */

#include <vector>

template<typename T>
using Mat = std::vector< std::vector<T>>;

bool isPositive(const Mat<int>& m, 
                const int&      x, 
                const int&      y) {
	return (x >= 0) && (x < std::size( m )    ) && 
	       (y >= 0) && (y < std::size( m[0] ) ) &&
	       (m[x][y] > 0);
}

bool convert(const Mat<int>&  m,
             Mat<int>& 	      cpy,
             const int&       x, 
             const int&       y) {
    if ( (m[x][y] < 0) &&
        ( isPositive(m, x - 1, y    ) || isPositive(m, x + 1, y    ) || 
          isPositive(m, x    , y - 1) || isPositive(m, x    , y + 1) ) ) {
        cpy[x][y] *= -1;
	    return true;
	}
	return false;
}

int minimumPassesOfMatrix(Mat<int> m) {
    int  l_res      { 0 };
    bool l_keepGoing{ true };
	
    while( l_keepGoing ) {
        auto m_cpy = m;
        l_keepGoing = false;
        for     ( auto i = 0; i < std::size( m    ); ++i )
            for ( auto j = 0; j < std::size( m[0] ); ++j ) {
                l_keepGoing |= convert( m, m_cpy, i, j );
                if ( l_keepGoing ) continue;
            }
        std::swap(m, m_cpy);
        if ( l_keepGoing ) { ++l_res; }
    }
    
    for      ( auto i = 0; i < std::size( m    ); ++i )
        for ( auto j = 0; j < std::size( m[0] ); ++j )
            if ( m[i][j] < 0 ) return -1;
    return l_res;
}
