/*!
 * @brief Interweaving strings
 *        From https://www.algoexpert.io/questions/Interweaving%20Strings
 */

#include <vector>

bool helper(std::string s1, std::string s2, std::string s3, int i, int j,
                      std::vector<std::vector<int>>& cache) {
    if ( cache[i][j] != -1      ) return cache[i][j];
    if ( std::size(s3) == i + j ) return true;
    if ( i < std::size(s1) && s1[i] == s3[i + j] ) {
        cache[i][j] = helper( s1, s2, s3, i + 1, j, cache );
        if ( cache[i][j] == true ) return true;
    }
    if ( j < std::size(s2) && s2[j] == s3[i + j] ) {
        cache[i][j] = helper( s1, s2, s3, i, j + 1, cache );
        return cache[i][j];
    }
    cache[i][j] = false;
    return false;
}

bool interweavingStrings(std::string s1, std::string s2, std::string s3) {
  if ( std::size(s3) != std::size(s1) + std::size(s2) ) return false;
    
    std::vector<std::vector<int>> cache;
    for ( int i = 0; i < std::size(s1) + 1; ++i ) {
        cache.push_back({});
        for ( int j = 0; j < std::size(s2) + 1; ++j ) cache[i].push_back(-1);
    }
    return helper( s1, s2, s3, 0, 0, cache );
}

/*
#include <map>
#include <algorithm>
#include <utility>

bool interweavingStrings(std::string s1, std::string s2, std::string s3) {
  std::map<char, int> dic;
    for ( const auto& c : s1 ) { --dic[c]; }
    for ( const auto& c : s2 ) { --dic[c]; }
    for ( const auto& c : s3 ) { ++dic[c]; }
    for ( const auto& [c, i] : dic ) { }
  return std::find_if( std::begin(dic), 
                                             std::end  (dic), [](auto& val){ return val.second < 0; }) == std::end(dic);
}
*/