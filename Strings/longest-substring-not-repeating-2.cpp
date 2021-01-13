// Temporal complexity O(n) | spatial complexity O(min(n,a))
std::string longestSubstringWithoutDuplication(std::string s) {
    std::vector<int> cache(256, -1);
    int l0{0}, l1{1}, l{0};
    for (int i = 0; i < std::size(s); i++) {
        l   = max( l   , cache[s[i]] + 1 );
        if ( l1 - l0 < i + 1 -l ) { l0 = l; l1 = i + 1; }
        cache[s[i]] = i;
    }
    return s.substr(l0, l1 - l0);
}