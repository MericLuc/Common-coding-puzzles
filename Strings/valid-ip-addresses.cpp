#include <vector>
#include <regex>

template < typename T > 
using V = std::vector<T>;

V<std::string> validIPAddresses(std::string p_in) {
    static std::regex st_ipv4{
        "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}"
            "([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$" };
	
    V<std::string> l_ret{};
    
    for         ( int i = 1    ; i <     std::min((int)p_in.length()    , 4); ++i )
        for     ( int j = i + 1; j < i + std::min((int)p_in.length() - i, 4); ++j )
            for ( int k = j + 1; k < j + std::min((int)p_in.length() - j, 4); ++k ) {
                auto l_curStr = 
                      p_in.substr(0 , i    ) + "."
                    + p_in.substr(i , j - i) + "."
                    + p_in.substr(j , k - j) + "."
                    + p_in.substr(k);
                
                if ( std::regex_search(l_curStr, st_ipv4) )
                    l_ret.push_back(l_curStr);
            }
    return l_ret;
}
