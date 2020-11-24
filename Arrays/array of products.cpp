#include <vector>
#include <algorithm>

int multFn(int x, int y) { return (x && y) ? x*y : 1; }

vector<int> arrayOfProducts(vector<int> m) {
    int zeros = std::count(std::begin(m), std::end(m), 0 );
    int mult  = std::accumulate(std::begin(m), std::end(m), 1, multFn );

    if      ( zeros >  1 ) { return vector<int>(m.size(), 0); }
    else if ( zeros == 1 ) { 
          std::transform( std::begin(m), std::end(m), std::begin(m), 
                                 [mult](int elm){ return !elm ? mult : 0; } );
    }
    else {
          std::transform( std::begin(m), std::end(m), std::begin(m), 
                                 [mult](int elm){ return mult/elm; } );
    }

  return m;
}