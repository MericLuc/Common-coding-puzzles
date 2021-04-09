/*!
 * @brief Given an input array of intervals, compute the corresponding array of
 *        non overlapping intervals.
 *        From https://www.algoexpert.io/questions/Merge%20Overlapping%20Intervals
 */

// Solution 1 - Using pointers

#include <vector>

template < typename T >
using V = std::vector<T>;

// O(nlog(n)) time | O(n) space
V<V<int>> mergeOverlappingIntervals(V<V<int>> in) {
	V<V<int>  > out;
	V<V<int>* > tmp;
	std::sort( std::begin(in), 
						 std::end  (in), 
						 [](auto v1, auto v2) { return v1[0] < v2[0]; } );
	
	V<int>* curInt = &in[0];
	tmp.push_back( curInt );
	
	for ( auto& nxt : in ) {
		if ( curInt->at(1) >= nxt[0] ) curInt->at(1) = std::max( curInt->at(1), nxt[1] );
		else { curInt = &nxt; tmp.push_back(curInt); }
	}
	
	std::transform( std::begin(tmp), 
								  std::end  (tmp), 
								  std::back_inserter(out),
								  [](auto curPtr) { return *curPtr; } );
  return out;
}


// Solution 2

#include <vector>

template < typename T >
using V = std::vector<T>;

// O(nlog(n)) time | O(n) space
V<V<int>> mergeOverlappingIntervals(V<V<int>> in) {
	std::sort( std::begin(in), 
						 std::end  (in), 
						 [](auto v1, auto v2) { return v1[0] < v2[0]; } );
	
	V<V<int>  > out{ in[0] };
	
	for ( auto& nxt : in ) {
		if ( out.back().at(1) >= nxt[0] ) { out.back().at(1) = std::max( out.back().at(1), nxt[1] ); }
		else { out.push_back(nxt); }
	}

  return out;
}
