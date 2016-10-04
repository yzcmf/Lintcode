/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: C++
@Datetime: 16-09-27 03:20
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        
        int n=A.size();
        
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], A[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return dp[n - 1] >= 0;
        
    }
};

//Reference:http://www.cnblogs.com/grandyang/p/4371526.html
/*
Dynamic Programming来解，我们维护一个一位数组dp，其中dp[i]表示走道i位置时剩余的\还能走的最大步数，那么递推公式为：dp[i] = max(dp[i - 1], A[i - 1])-1; 如果当某一个时刻dp数组的值为负了，说明无法抵达当前位置，则直接返回false，最后我们判断dp数组最后一位是否为非负数即可知道是否能抵达该位置
*/