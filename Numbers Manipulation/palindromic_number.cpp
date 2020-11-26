/*!
 * @description: Determine whether an integer is a palindrome.
 *               An integer is a palindrome when it reads the same backward as forward.
 * @restriction: You are not allowed to convert the input to std::string
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;

        long y(0);
        int  z(x);
        while(z) { y = y*10 + z%10; z/=10; }
        return x == y;
    }
};