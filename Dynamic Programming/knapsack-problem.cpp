#include <vector>
#include <iostream>

template < typename T >
using V = std::vector<T>;

V<V<int>> buildArray(V<V<int>>& vals, V<V<int>>& items, int maxVal) {
    V<V<int>> ret{ {}, {} };
    ret[0].push_back(maxVal);
    int j = std::size(vals[0]) - 1;
    for (int i = std::size(vals) - 1; i > 0; i--) {
        if (vals[i][j] > vals[i - 1][j]) {
            ret[1].insert( std::begin(ret[1]), i - 1);
            j -= items[i - 1][1];
        }
        if (j == 0) break;
    }
    return ret;
}

V<V<int>> knapsackProblem(V<V<int>> items, int capa) {
    V<V<int>> vals( std::size(items) + 1, V<int>(capa + 1, 0) );
    for ( int i = 1; i < std::size(items) + 1; ++i ) {
        int curV{ items[i - 1][0] }, curW{ items[i - 1][1] };
        for ( int j = 1; j < capa + 1; ++j ) {
            int curCapa{ j };
            vals[i][j] = (curW > curCapa) ? vals[i-1][j] : 
                           max(vals[i - 1][j], curV + vals[i - 1][j - curW]);
        }
    }
    return buildArray(vals, items, vals[std::size(items)][capa]);
}