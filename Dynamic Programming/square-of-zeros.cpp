/*!
 * @brief Find if a matrix of 1s and 0s contains a square of 0s.
 *        From https://www.algoexpert.io/questions/Square%20of%20Zeroes
 */

template < typename T >
using V = std::vector<T>;

struct Infos { int nBelow, nRight; };

bool isSquare(V<V<Infos>> infos, int r1, int c1, int r2, int c2) {
    int l{ c2 - c1 + 1 };
    return (infos[r1][c1].nRight >= l) && (infos[r1][c1].nBelow >= l) &&
           (infos[r2][c1].nRight >= l) && (infos[r1][c2].nBelow >= l);
}

V<V<Infos>> preprocess(V<V<int>> m) {
    V<V<Infos>> infos;
    for ( int i = 0; i < std::size(m); ++i ) {
        V<Infos> in;
        for ( int j = 0; j < std::size(m[i]); ++j ) {
            int num = m[i][j] == 0 ? 1 : 0;
            in.push_back( Infos{ num, num } );
        }
        infos.push_back(in);
    }
    
    for ( int r = std::size(m) - 1; r >= 0; --r ) {
        for ( int c = std::size(m) - 1; c >= 0; --c ) {
            if ( m[r][c] == 1 ) continue;
            if ( r < std::size(m) - 1 ) infos[r][c].nBelow += infos[r+1][c  ].nBelow;
            if ( c < std::size(m) - 1 ) infos[r][c].nRight += infos[r  ][c+1].nRight;
        }
    }
    
    return infos;
}

bool squareOfZeroes(V<V<int>> m) {
    V<V<Infos>> infos{ preprocess(m) };
    for ( int topR = 0; topR < std::size(m); ++topR ) {
        for ( int lftC = 0; lftC < std::size(m); ++lftC ) {
            int l{ 2 };
            while ( l <= std::size(m) - lftC && l <= std::size(m) - topR ) {
                if ( isSquare(infos, topR, lftC, topR + l - 1, lftC + l - 1) ) return true;
                ++l;
            }
        }
    }
    return false;
}
