/*!
 * @description Given an input array, find a pair of indexes
 *              whose elements sums up to a target number.
 */
 
// Bruteforce solution (O(n²) time | O(1) space)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() -1; i++ )
            for ( int j = i + 1; j < nums.size(); j++ )
                if ( nums[i] + nums[j] == target ) { return {i, j}; }
        return {};
    }
};

// 1 pass HasMap (O(n*log(n)) time | O(n) time)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++ ) {
            if ( m.find(target - nums[i]) != m.end() ) { return {m[target - nums[i]],i}; }
            m[nums[i]] = i;
        }
        return {};
    }
};