#include <sstream>
using namespace std;

// O(N) time | O(N) space - with N the length of the path 
std::string shortenPath(std::string p_path) {
    std::string              cur;
    std::vector<std::string> tokens, stack;
    std::istringstream       iss(p_path); // Parse input tokens
    std::ostringstream       oss;         // Write output path
    
    while ( std::getline(iss, cur, '/') )
        if ( !std::empty(cur) && cur != "." ) tokens.push_back(cur);
    
    if ( p_path.rfind( '/', 0) == 0 ) stack.push_back("");
    for ( const auto& tok : tokens ) {
    if ( tok == ".." ) {
            if ( std::empty(stack) || stack.back() == ".." ) stack.push_back(tok);
            else if ( stack.back() != "" ) stack.pop_back();
        }
        else {
            stack.push_back(tok);
        }
    }
    
    if ( std::size(stack) == 1 && stack[0] == "" ) return "/";
    
    oss << stack[0];
    for ( size_t i = 1; i < std::size(stack); ++i ) oss << "/" << stack[i];
    
    return oss.str();
}
