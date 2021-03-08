/*!
 * @brief Check if a string can be generated from
 *        the characters of another string.
 *        From https://www.algoexpert.io/questions/Generate%20Document
 */

#include <unordered_map>

// O(n + m) time | O(u) space
// n : number of chars
// m : size of the document
// u : number of unique chars in chars
bool generateDocument(std::string chars, std::string doc) {
  std::unordered_map<char, int> dic;
	
	if ( std::size(doc) > std::size(chars) ) { return false; }
	
	for (const char& c : chars ) { ++dic[c]; }
	for (const char& c : doc   )
		if ( --dic[c] < 0 ) { return false; }
	
  return true;
}
