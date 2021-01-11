// Question from https://www.algoexpert.io/questions/Remove%20Islands

#include <vector>
#include <deque>
#include <set>

using namespace std;

struct Point { 
    int x, y; 
    friend bool operator<( const Point& p1, const Point& p2 ) {
        return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
    }
};

vector<Point> getNeighbours( const Point&  p, 
                             const int&    X, 
                             const int&    Y ) 
{
    vector<Point> res;
    res.reserve(4);
    if ( p.x > 0 )     { res.emplace_back( Point{p.x - 1, p.y} ); }
    if ( p.x < X - 1 ) { res.emplace_back( Point{p.x + 1, p.y} ); }
    if ( p.y > 0 )     { res.emplace_back( Point{p.x, p.y - 1} ); }
    if ( p.x < Y - 1 ) { res.emplace_back( Point{p.x, p.y + 1} ); }
    
    return res;
}

vector<vector<int>> removeIslands( vector<vector<int>> m ) 
{
    if ( std::empty(m) || std::size(m) < 3 || std::size(m.at(0)) < 3 ) return m;
    
    // Initialization
    int  X( std::size(m) ), Y( std::size( m.at(0) ) );
    vector<vector<bool>> g( X , vector<bool>( Y, false) );
    std::deque< Point >  toAnalyse;
    std::set<Point>      visited;
    for ( int j = 0; j < Y; ++j ) 
    {
        if ( m[0  ][j] ) {
            toAnalyse.emplace_back( Point{0, j  } );
            g[0][j] = true;
        }
        if ( m[X-1][j] ) {
            toAnalyse.emplace_back( Point{X-1, j} );
            g[X-1][j] = true;
        }
    }
    
    for ( int i = 1; i < X; ++i ) 
    {
        if ( m[i][0  ] ) {
            toAnalyse.emplace_back( Point{i, 0  } );
            g[i][0] = true;
        }
        if ( m[i][Y-1] ) {
            toAnalyse.emplace_back( Point{i, Y-1} );
            g[i][Y-1] = true;
        }
    }
    
    // Algorithm (just a BFS)
    while ( !std::empty(toAnalyse) ) 
    {
        Point curPt { toAnalyse.front() };
        toAnalyse.pop_front();
        visited.insert(curPt);
        
        for ( auto& pt : getNeighbours(curPt, X, Y) )
        {
            if ( m[pt.x][pt.y] && !visited.count(pt) )
            {
                g[pt.x][pt.y] = true;
                toAnalyse.push_back(pt);
            }
        }
    }
    
    // Apply results to m
    for ( int i = 0; i < X; ++i )
        for ( int j = 0; j < Y; ++j )
            if ( !g[i][j] ) { m[i][j] = 0; }
    
  return m;
}
