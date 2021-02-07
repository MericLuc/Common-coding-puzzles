/*!
 * @brief Search For Range
 *        From https://www.algoexpert.io/questions/Search%20For%20Range
 */

#include <vector>

template < typename T >
using V = std::vector<T>;

void binSearch(V<int> in, int target, int lft, int rht, V<int>& endRng, bool goLft) {
    if ( lft > rht ) return;
    int mid{ (lft + rht) / 2 };
    if      ( in[mid] < target ) binSearch( in, target, mid + 1, rht, endRng, goLft );
    else if ( in[mid] > target ) binSearch( in, target, lft, mid - 1, endRng, goLft );
    else {
        if ( goLft ) {
            if ( mid == 0 || in[mid - 1] != target ) endRng[0] = mid;
            else binSearch( in, target, lft, mid - 1, endRng, goLft );
        }
        else {
            if ( mid == std::size(in) - 1 || in[mid + 1] != target ) endRng[1] = mid;
            else binSearch( in, target, mid + 1, rht, endRng, goLft );
        }
    }
}

V<int> searchForRange(V<int> in, int target) {
  V<int> res{ -1, -1 };
    binSearch( in, target, 0, std::size(in) - 1, res, true  );
    binSearch( in, target, 0, std::size(in) - 1, res, false );
  return res;
}
