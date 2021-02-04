/*!
 * @brief Continuous Median
 *        Puzzle from AlgoExpert.io
 */

#include <queue>

class ContinuousMedianHandler {
  public:
    double                                                            median;
        std::priority_queue<int, std::vector<int>>                    max_heap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    void insert(int nb) {
            if (empty(max_heap)) {
                max_heap.emplace(nb);
                median = nb;
                return;
            } 
            else {
                if ( nb < max_heap.top() ) max_heap.emplace(nb);
                else                       min_heap.emplace(nb);
                
                if ( min_heap.size() - max_heap.size() == 2 ) {
                    max_heap.emplace(min_heap.top());
                    min_heap.pop();
                } 
                else if ( max_heap.size() - min_heap.size() == 2 ) {
                    min_heap.emplace(max_heap.top());
                    max_heap.pop();
                }
                
                if ( std::size(min_heap) == std::size(max_heap) ) {
                    median = static_cast<double>(min_heap.top() + max_heap.top()) / 2.0;
                } 
                else if (min_heap.size() < max_heap.size())median = static_cast<double>(max_heap.top());
                else median = static_cast<double>(min_heap.top());
                return;
            }
    }

    double getMedian() { return median; }
};