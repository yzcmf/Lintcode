/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 16-09-21 05:15
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        
        int n = S.size();
        int m = T.size();
        vector<int>dp(n+1,1);
        
        for(int i=1;i<=m;i++)
        {
            int upleft = dp[0];
            dp[0] = 0;
            for(int j=1;j<=n;j++)
            {
                int temp = dp[j];
                dp[j] = dp[j-1];
                if(S[j-1] == T[i-1])dp[j] += upleft;
                upleft = temp;
            }
        }
        
        return dp[n];
    }
};
/*
i<j; j++; j is incresed each time in the S[j];
For one specific i:
1. No matter(S[j]==T[i]);DP[i][j] = DP[i][j-1];
2. If(S[j]==T[i])DP[i][j] += DP[i-1][j-1]; 
   Supposed S[j] and T[i] are getting rid of;
   Calculate the DP;
*/
/*
思路：

一看要求解的个数，然后又是string匹配，而且形式上和Minimum Edit Distance那题很像，基本就是DP题跑不了了。DP题惯例的三步走：定义状态，推导递推公式，确定状态计算方向和起始状态。

1. 状态：i, j分别表示T中长度为i的prefix：T[0:i-1]，和S中长度为j的prefix：S[0:j-1]。
DP[i][j]：S[0:j-1]中存在T[0:i-1]作为distinct subsequence的个数。显然如果j<i，DP[i][j] = 0。

2. 递推公式：
(a) T[i]!=s[j]:

T = r a b
S = r c a c b c

DP[i+1][j+1] = DP[i+1][j]

(b) T[i] = s[j]: 

T = r a b b
S = r a b b b  - DP[i+1][j] = 1
S = r a b b b  - DP[i][j] = 2
S = r a b b b  /

DP[i+1][j+1] = DP[i][j] + DP[i+1][j]

公式总结：
S[j-1]!= T[i-1]：DP[i][j] = DP[i][j-1]
S[j-1]==T[i-1]：DP[i][j] = DP[i-1][j-1] + DP[i][j-1]


3. 计算方向和起始状态：
DP[i][j]
DP[i+1][j]   DP[i+1][j+1]

所以从上向下，从左到右的顺序可以计算。

根据计算顺序，需要先设置第0行、0列的值。
第0列：DP[i][0] = 0，i>0。因为T的长度大于S的长度，不可能成为S的subsequence。
第0行：DP[0][j] = 1，j>=0。这是为了保证第1行的计算正确：

T = r
S = r a r b r c

      r a  r b r  c  
  1 1 1 1 1 1 1
r 0 1 1 2 2 3 3


4. 计算优化：用滚动数组减少内存消耗。
*/