// From https://www.algoexpert.io/questions/Waterfall%20Streams

#include <vector>

std::vector<double> waterfallStreams(std::vector<std::vector<double>> m, int src) {
  std::vector<double> prev = m[0];
    prev[src] = -1;
    
    for ( size_t row = 1; row < std::size(m); ++row ) {
        std::vector<double> cur = m[row];
        for ( int col = 0; col < std::size(prev); ++col ) {
            double above { prev[col] }, split { above/2 };
            
            if ( above >= 0      ) { continue; }
            if ( cur[col] != 1.0 ) { cur[col] += above; continue; }
            
            int rightCol { col };
            while ( ++rightCol < std::size(prev) ) {
                if ( prev[rightCol] == 1.0 ) { break; }
                if ( cur [rightCol] != 1.0 ) { cur[rightCol] += split; break; }
            }
            
            int leftCol { col };
            while ( --leftCol >= 0 ) {
                if ( prev[leftCol] == 1.0 ) { break; }
                if ( cur [leftCol] != 1.0 ) { cur[leftCol] += split; break; }
            }
        }
        prev = cur;
    }
    
    std::vector<double> res;
    for ( double& num : prev )
        res.push_back( (num==0) ? num : -100*num ); 

  return res;
}