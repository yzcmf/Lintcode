/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/paint-fence
@Language: C++
@Datetime: 16-09-15 04:46
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        
        if(n==0) return 0;
        int same = 0, diff = k;
        
        for(int i=2;i<=n;i++)
        {
           int t = diff;
           diff = (same + diff)*(k-1);
           same = t;
        }
        
        return same+diff;
    }
};

/*
一种是相邻部分没有相同的，一种相同部分有相同的颜色，

那么对于没有相同的，对于第一个格子，我们有k种填法，
对于下一个相邻的格子，由于不能相同，所以我们只有k-1种填法。

而有相同部分颜色的刷法只能和和上一个格子的不同颜色刷法相同，
相同的部分颜色不能和上一个格子相同颜色刷法相同，否则会出现3个相同的颜色格子;

最后总共的刷法就是把不同和相同两个刷法加起来
*/