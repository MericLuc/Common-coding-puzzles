/*!
 * @brief Give the list of every mnemonics
 *        associated to a phone number.
 */

#include <vector>
#include <unordered_map>
#include <numeric>

std::unordered_map<int, std::vector<char>> mem {
    {0, {'0'}}, {1, {'1'}}, {2, {'a', 'b', 'c'}},
    {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}},
    {9, {'w', 'x', 'y', 'z'}}
};

void helper(int                       idx, 
            std::string               nb, 
            std::vector<char>&        cur,
            std::vector<std::string>& found) {
    if ( idx == std::size(nb) ) {
        std::string memonic = std::accumulate( std::begin(cur), std::end(cur), std::string{} );
        found.push_back(memonic);
    }
    else
    {
        std::vector<char>& letters( mem[nb[idx] - '0'] );
        for ( const auto& l : letters ) { cur[idx] = l; helper(idx+1, nb, cur, found); }
    }
}

std::vector<std::string> phoneNumberMnemonics(std::string phoneNumber) {
    std::vector<std::string> ret;
    std::vector<char>        cur(std::size(phoneNumber), '0');
    helper(0, phoneNumber, cur, ret);
  return ret;
}
