/*!
 * @description
 *  Knuth Morris Pratt algorithm
 *  Finding substring.
 */

#include <iostream>
#include <algorithm>
#include <string>

bool knuthMorrisPrattAlgorithm(const std::string& str, 
                              const std::string& pattern ) {
    if( std::empty(str) || std::empty(pattern) ) return false;

    int failure[std::size(pattern)];
    std::fill( failure, failure + std::size(pattern), -1);

    for( int r{1}, l{-1}; r < std::size(pattern); ++r ) {
        while( l != -1 && pattern[l+1] != pattern[r] ) l = failure[l];
        if( pattern[l+1] == pattern[r] ) failure[r] = ++l;
    }

    int tail{-1};
    for( int i{0}; i < std::size(str); ++i ) {
        while( tail != -1 && str[i] != pattern[tail+1]) tail = failure[tail];
        if( str[i] == pattern[tail+1] ) tail++;
        if( tail == std::size(pattern) - 1 ) return true;
    }

    return false;
}