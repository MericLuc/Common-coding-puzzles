#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> dijkstrasAlgorithm(int start, 
                               vector<vector<vector<int>>> edges) {
    set   <int> vis;
    vector<int> minD(edges.size(), INT_MAX);
    minD[start] = 0;
    
    while( vis.size() < edges.size() )
    {
        int curNode(-1), curD(INT_MAX);
        for ( int id = 0; id < minD.size(); id++ ) 
            if ( !vis.count(id) && minD[id] <= curD) curNode=id, curD=minD[id];
        if ( curD == INT_MAX ) break;
        
        vis.insert(curNode);
        
        for ( auto& e : edges[curNode] ) 
            if(!vis.count(e[0]) && e[1]+curD<minD[e[0]] ) minD[e[0]]=e[1]+curD;
    }
    
    std::transform(std::begin(minD), std::end(minD), std::begin(minD),
                                [](int c){ return c == INT_MAX ? -1 : c; } );
  return minD;
}