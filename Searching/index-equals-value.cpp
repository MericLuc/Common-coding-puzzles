/*!
 * @brief Find - in a sorted array m - the first index i such that m[i] = i.
 *        Naive solution is O(n) time but there is a better way using 
 *        binarySearch in O(nlog(n)).
 */

#include <vector>

// O(log(n)) time | O(1) space
int indexEqualsValue(std::vector<int> m) {
  int lft{ 0 }, rht{ static_cast<int>(std::size(m)) - 1 };
    
    while ( lft <= rht ) {
        int mid{ lft + (rht - lft)/2 };
        if ( m[mid] < mid ) { lft = mid + 1; }
        else if ( m[mid] == mid && ( mid == 0 || m[mid - 1] < mid - 1 ) ) return mid;
        else { rht = mid - 1; }
    }
  return -1;
}
