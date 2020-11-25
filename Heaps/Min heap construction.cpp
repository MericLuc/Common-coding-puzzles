#include <vector>

class MinHeap {
public:
  std::vector<int> heap;

  MinHeap(std::vector<int> v) : heap(buildHeap(v)) {}

  // O(n) time | O(1) space (Naive approach using insert - O(n*log(n)))
  std::vector<int> buildHeap(std::vector<int> &v) {
		for ( int i = (v.size()-2)/2; i >= 0; i-- ) { siftDown(i, v.size()-1, v); }
    return v;
  }

  // O(log(n)) time | O(1) space
  void siftDown(int cIdx, int dstIdx, std::vector<int> &heap) {
		int c1Idx((cIdx << 1) + 1);
		while ( c1Idx <= dstIdx ) {
			int c2Idx = (cIdx << 1) + 2 <= dstIdx ? (cIdx << 1) + 2 : -1;
			int idxS = ( c2Idx != -1 && heap[c2Idx] < heap[c1Idx] ) ? c2Idx : c1Idx;
			if ( heap[idxS] < heap[cIdx] ) {
				std::swap( heap[cIdx], heap[idxS] );
				cIdx  = idxS;
				c1Idx = (cIdx << 1) + 1;
			}
			else { return; }
		}
  }

  // O(log(n)) time | O(1) space
  void siftUp(int cIdx) {
		int pIdx( (cIdx-1) >> 1 );
		while ( cIdx && heap[cIdx] < heap[pIdx] ) {
			std::swap( heap[cIdx], heap[pIdx] );
			cIdx = pIdx;
			pIdx = (cIdx-1) >> 1;
		}
  }

  int peek() { return heap[0]; }

  // O(log(n)) time | O(1) space
  int remove() {
    swap(heap[0], heap[heap.size()-1]);
		int toRemove = heap.back();
		heap.pop_back();
		siftDown(0, heap.size() -1, heap);
		return toRemove;
  }

  // O(log(n)) time | O(1) space
  void insert(int val) {
		heap.push_back(val);
		siftUp(heap.size()-1);
  }
};
