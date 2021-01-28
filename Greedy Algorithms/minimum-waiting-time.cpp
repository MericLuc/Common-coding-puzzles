/*!
 * @brief Solution to the "Minimum waiting time" problem from AlgoExpert.
 *        Can be found here : https://www.algoexpert.io/questions/Minimum%20Waiting%20Time
 */

int minimumWaitingTime(std::vector<int> queries) {
    if ( std::size(queries) < 2 ) return 0;
    
  std::sort( std::begin(queries), std::end(queries) );
    
    int wait{ 0 }, res{ 0 };
    for ( const auto& q : queries ) {
        res += wait;
        wait += q;
    }
    return res;
}

