/*!
 * @description: Find the longest substring without any
 *               repeating character.
 */

// Temporal complexity O(n) | spatial complexity O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cache(256, -1);
        int l(-1), res(0);
        for (int i = 0; i < s.size(); i++) {
            l   = max( l   , cache[s[i]] );
            res = max( res , i - l       );
            cache[s[i]] = i;
        }
        return res;
    }
};