#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <climits>

using namespace std;

int getMin(string                   pi, 
           set<string>              table,
           unordered_map<int, int>& cache,
           int                      i)
{
    int l_min(INT_MAX), l_minSuffix;
    
    if ( i == pi.length()             ) { return -1;          }
    if ( cache.find(i) != cache.end() ) { return cache.at(i); }
    
    for ( int ii = i; ii < pi.length(); ii++ ) {
        string p = pi.substr(i, ii + 1 - i);
        
        if ( table.find(p) != table.end() ) {
          l_minSuffix = getMin(pi, table, cache, ii + 1);
          l_min       = ( l_minSuffix == INT_MAX ) ? 
              min(l_min, l_minSuffix) : min(l_min, l_minSuffix + 1);
        }
    }
    cache.insert({i, l_min});
    return cache.at(i);
}

// O(n^3 + m) time | O(n + m) space 
// n : number of digits in pi
// m : number of favorite numbers
int numbersInPi(std::string pi, vector<std::string> nb) {
    set<string>             table( std::begin(nb), std::end(nb) );
    unordered_map<int, int> cache;
    
    for ( int i = pi.length() -1; i >= 0; i-- ) { getMin(pi, table, cache, i); }
  return (cache.at(0) == INT_MAX) ? -1 : cache.at(0);
}