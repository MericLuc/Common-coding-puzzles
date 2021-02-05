/*!
 * @brief Sort an input array using Heap sort.
 *        From https://www.algoexpert.io/questions/Heap%20Sort
 */

#include <vector>

void siftDown(int idx, int last, std::vector<int>& in) {
    int c1{ (idx << 1) + 1 }, c2, swapIdx;
    while ( c1 <= last ) {
        c2      = ((idx + 1) << 1) <= last ? ((idx + 1) << 1) : -1;
        swapIdx = ( c2 != -1 && in.at(c2) > in.at(c1) ) ? c2 : c1;
        if ( in.at(swapIdx) < in.at(idx) ) return;
        std::swap( in[idx], in[swapIdx] );
        idx = swapIdx;
        c1  = (idx << 1) + 1;
    }
}

void heapify(std::vector<int>& in) {
    for ( int cur = (std::size(in) - 2) >> 1; cur >= 0; --cur )
        siftDown( cur, std::size(in) - 1, in );
}

std::vector<int> heapSort(std::vector<int> in) {
    heapify(in);
    for ( int last = std::size(in) - 1; last > 0; --last ) {
        std::swap( in[0], in[last] );
        siftDown ( 0, last - 1, in );
    }
  return in;
}
