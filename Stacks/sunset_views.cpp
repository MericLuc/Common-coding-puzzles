/*!
 * @brief: "Medium" interview question from AlgoExpert.io
 * Find it here : https://www.algoexpert.io/questions/Sunset%20Views
 */

std::vector<int> sunsetViews(std::vector<int> arr, std::string dirStr) {
    std::vector<int> res;
    int curMax{0}, stIdx, endIdx, incr;

    if ( dirStr[0] == 'W' ) { stIdx = 0; endIdx = std::size(arr); incr =  1;    }
    else                    { stIdx = std::size(arr)-1; endIdx = -1; incr = -1; }
    
    while ( stIdx != endIdx ) {
        if ( arr[stIdx] > curMax ) { res.push_back(stIdx); curMax = arr[stIdx]; }
        stIdx += incr;
    }
    if ( endIdx == -1 ) std::reverse( std::begin(res), std::end(res) );
  return  res;
}