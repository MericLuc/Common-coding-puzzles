#include <vector>
#include <algorithm>

std::vector<int> threeNumberSort(std::vector<int> m, std::vector<int> o) {
	std::vector<int> ret; 
	ret.reserve(m.size());
	
	for ( auto& elm : o ) {
		int nb = std::count( std::begin(m), std::end(m), elm );
		while( nb-- ) { ret.push_back(elm); }
	}
  return ret;
}
