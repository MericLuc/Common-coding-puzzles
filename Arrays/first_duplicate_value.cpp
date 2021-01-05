// O(N) time and space using hash
/*
int firstDuplicateValue( std::vector<int> m ) { 
    std::vector<int> hash(m.size() + 1, 0);
    
    for ( const auto& elm : m ) { 
        ++hash[elm]; 
        if ( hash[elm] > 1 ) { return elm; }
    }
    return -1; 
}
*/

// O(N) time and O(1) space using input array
int firstDuplicateValue( std::vector<int> m ) {     
    for ( auto& elm : m ) { 
        int absElm{ abs(elm) };
        if ( m[absElm - 1] < 0 ) { return absElm; }
        m[absElm - 1] *= -1;
    }
    return -1; 
}