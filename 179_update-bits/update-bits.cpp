/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/update-bits
@Language: C++
@Datetime: 16-10-01 08:17
*/

/*
1.得到第i位到第j位的比特位为0，而其他位均为1的掩码mask。
2.使用mask与 N 进行按位与，清零 N 的第i位到第j位。
3.对 M 左移i位，将 M 放到 N 中指定的位置。
4.返回 N | M 按位或的结果。
先获得掩码(1111...000...111)的左边部分，
然后获得掩码的右半部分，最后左右按位或即为最终结果
*/
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int  ones = ~0;
        int mask = 0;
        
        if (j < 31) {
            int left = ones << (j + 1);
            int right = ((1 << i) - 1);
            mask = left | right;
        } else {
            mask = (1 << i) - 1; //j>=31;left is great than the 32;Only right remains;
        }
        
        //使用mask与 N 进行按位与，清零 N 的第i位到第j位
        //对 M 左移i位，将 M 放到 N 中指定的位置
        //返回 N | M 按位或的结果
        
        return (n & mask) | (m<<i) ; 
    }
};