/*!
 * @description: Write a function that takes in an array of strings and
 * returns the smallest array of characters needed to form all the words.
 */

// Example
// Input: ["this", "that", "did", "deed", "them!", "a"]
// Expected answer: ["!", "a", "d", "d", "e", "e", "h", "i", "m", "s", "t", "t"]

// Temporal complexity O(n*l) | spatial complexity O(c)
// - n the number of words
// - l the length of the longest word
// - c the number of unique character among every word

#include <vector>

std::vector<char> minimumCharactersForWords(std::vector<std::string> w) {
    std::map<char, long> l_cache;
    std::vector<char>    l_ret{};
	
	std::for_each( std::cbegin(w), 
                   std::cend(w), 
                  [&l_cache](const std::string& s){
                      std::for_each( std::cbegin(s),
                                     std::cend(s),
                                     [&l_cache, &s](const char& c){
                                         l_cache[c] = std::max(l_cache[c], 
                                                               std::count( std::cbegin(s),
                                                                           std::cend(s),
                                                                           c));
                                     });
                  });
    
    for(const auto& [c, nb]: l_cache )
        l_ret.insert( std::end(l_ret), nb, c);
    
  return l_ret;
}
