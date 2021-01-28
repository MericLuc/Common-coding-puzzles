/*!
 * @brief C++ solution to the "Group anagrams" question on AlgoExpert.
 *        Can be found here : https://www.algoexpert.io/questions/Group%20Anagrams
 */

#include <vector>

template < typename T >
using V = std::vector<T>;

V< V<std::string> > groupAnagrams(V<std::string> words) {
    std::map< std::string, V<std::string> > m;
    V< V<std::string> >                     res;
    
  for ( const auto& w : words ) {
        std::string key{w};
        std::sort( std::begin(key), std::end(key) );
        m[key].push_back(w);
    }
    
    for ( const auto& [k, v] : m ) res.push_back(v);
    return res;
}
