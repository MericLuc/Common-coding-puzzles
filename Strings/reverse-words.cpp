/*!
 * @brief Reverse words in string
 *        Keep the right number of whitespaces.
 */

#include <sstream>
#include <vector>

std::string reverseWordsInString(std::string s) {
    std::vector<std::string> l_res;
    std::string              l_cur, l_out;
    std::istringstream       l_stream(s);
    
    if ( std::empty(s)     ) { return ""; }
    if ( std::size(s) == 1 ) { return s;  }
    
    while ( std::getline( l_stream, l_cur, ' ') ) l_res.push_back(l_cur);
    
    for ( auto it = std::rbegin(l_res); it != std::rend(l_res); ++it ) { l_out += *it + " "; }
    l_out.pop_back();
    if ( s.back() == ' ' ) { l_out = " " + l_out; }
    return l_out;
}
