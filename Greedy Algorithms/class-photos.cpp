/*!
 * @brief Class Photos
 *        From https://www.algoexpert.io/questions/Class%20Photos
 */

#include <vector>
#include <algorithm>

// O(n.log(n)) time | O(1) space - with n the number of students
bool classPhotos(std::vector<int> red, std::vector<int> blue) {
    std::sort( std::begin(red ), std::end(red ) );
    std::sort( std::begin(blue), std::end(blue) );
    
    int res{0};
    for ( size_t i = 0; i < std::size(red); ++i )
        if      ( red[i] == blue[i] ) return false;
        else if ( red[i]  > blue[i] ) ++res;
    
  return ( res == 0 || res == std::size(red) );
}
