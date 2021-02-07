/*!
 * @brief Valid Start City
 *        From https://www.algoexpert.io/questions/Valid%20Starting%20City
 */

#include <vector>

int validStartingCity(std::vector<int> dst, std::vector<int> fuel, int mpg) {
    for ( int stIdx = 0; stIdx < std::size(dst); ++stIdx ) {
        int remain{ 0 };
        for ( int curIdx = stIdx; curIdx < stIdx + std::size(dst); ++curIdx ) {
            if ( remain < 0 ) continue;
            
            int curRot = curIdx % std::size(dst);
            int fuelFr{ fuel[curRot] };
            int dstNxt{ dst[curRot]  };
            remain += fuelFr * mpg - dstNxt;
        }
        if ( remain >= 0 ) return stIdx;
    }
  return 0xDEAD;
}
