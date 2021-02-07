/*!
 * @brief Task assignment
 *        From https://www.algoexpert.io/questions/Task%20Assignment
 */

#include <vector>
#include <algorithm>
#include <unordered_map>

template < typename T >
using V = std::vector<T>;

std::unordered_map<int, V<int>> getDur(V<int> tasks) {
    std::unordered_map<int, V<int>> ret;
    
    for ( int i = 0; i < std::size(tasks); ++i ) {
        if ( ret.find( tasks[i] ) != std::end(ret) ) ret[ tasks[i] ].push_back(i);
        else                                         ret[ tasks[i] ] = std::vector<int>{i};
    }
    return ret;
}

// O(nlog(n)) time | O(n) space
V<V<int>> taskAssignment(int k, V<int> tasks) {
  V<V<int>>                         ret;
    std::unordered_map<int, V<int>> dur{ getDur(tasks) };
    V<int>                          sorted{ tasks }; 
    
    std::sort( std::begin(sorted), std::end(sorted) );
    
    for ( int i = 0; i < k; ++i ) {
        auto d1{ sorted[i]  };
        auto i1{ &dur[d1]   };
        auto t1{ i1->back() };
        i1->pop_back();
        
        auto a2{ std::size(tasks) - 1 - i };
        auto d2{ sorted[a2] };
        auto i2{ &dur[d2]   };
        auto t2{ i2->back() };
        i2->pop_back();
        
        ret.push_back( V<int>{t1, t2} );
    }
    return ret;
}
