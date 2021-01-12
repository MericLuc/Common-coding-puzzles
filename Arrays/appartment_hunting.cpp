// From https://www.algoexpert.io/questions/Apartment%20Hunting

#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int getIdxAtMinValue( vector<int>& m ) {
    int idxAtMinValue { 0 };
    int minValue          { INT_MAX };
    
    for ( size_t i = 0; i < std::size(m); ++i ) {
        int curValue { m[i] };
        if ( curValue < minValue ) { 
            minValue      = curValue; 
            idxAtMinValue = i;
        }
    }
    return idxAtMinValue;
}

int distanceBetween(int a, int b) { return abs( a - b ); }

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string>                      reqs) {
  vector<int> maxD( std::size(blocks), INT_MIN );
    for ( size_t i = 0; i < std::size(blocks); ++i ) {
        for ( auto& req : reqs ) {
            int closestReqD{ INT_MAX };
            for ( size_t j = 0; j < std::size(blocks); ++j )
                if ( blocks[j][req] ) closestReqD = min( closestReqD, distanceBetween(i,j) );
            maxD[i] = max( maxD[i], closestReqD );
        }
    }
  return getIdxAtMinValue( maxD );
}
