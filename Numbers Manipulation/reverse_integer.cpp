/*!
 * @description Reverse digits of an integer (int32_t)
 * @restriction Returns 0 if the reversed integer overflows int32_t
 */

class Solution {
public:
    int reverse(long long x) {
        int res=0;
        while(x){
            if(res>INT_MAX/10 || res<INT_MIN/10) return 0; 
            res=res*10+x%10;
            x/=10;
        }
        return res;
    }
};