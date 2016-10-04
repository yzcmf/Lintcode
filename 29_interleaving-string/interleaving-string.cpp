/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: C++
@Datetime: 16-09-22 23:16
*/

/*
题解3 - 动态规划
看过题解1 和 题解2 的思路后动规的状态和状态方程应该就不难推出了。
按照经典的序列规划，不妨假设状态 f[i1][i2][i3] 为 s1的前i1个字符和 s2的前 i2个字符是否能交叉构成 s3的前 i3个字符，那么根据 s1[i1], s2[i2], s3[i3]的匹配情况可以分为8种情况讨论。咋一看这似乎十分麻烦，但实际上我们注意到其实还有一个隐含条件：len3 == len1 + len2, 故状态转移方程得到大幅简化。

新的状态可定义为 f[i1][i2], 含义为s1的前i1个字符和 s2的前 i2个字符是否能交叉构成 s3的前 i1 + i2 个字符。根据 s1[i1] == s3[i3] 和 s2[i2] == s3[i3] 的匹配情况可建立状态转移方程为：

f[i1][i2] = (s1[i1 - 1] == s3[i1 + i2 - 1] && f[i1 - 1][i2]) ||
            (s2[i2 - 1] == s3[i1 + i2 - 1] && f[i1][i2 - 1])
            
// s3 = "cbcac"
// s1 = "cba"
// s2 = "cc"
// s1[0] - s1[2]
// s2[0] - s2[1]
// f[3][2] = ( (s1[2] == s3[4]) && f[2][2] ) || ((s2[1] == s3[4]) && f[3][1]); 
// s3's last can form from s1 and s2 : 
// 1. s1's last character equals to s3's last character 
// and  then s3 - (last char) can form from s1 - (last char) with s2;
// or 2. s2's last character equals to s3's last character 
// and  then s3 - (last char) can form from s2 - (last char) with s1;

这道题的初始化有点 trick, 考虑到空串的可能，需要单独初始化 f[*][0] 和 f[0][*].

Note: The order of the characters of the strings should be same order        
      --interleaving or intersection;
*/
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if(l3 != l1 + l2) return false;
        vector<vector<bool>>DP(l1+1,vector<bool>(l2+1,true));
        
        for(int i=1;i<=l1;i++)
        {
            DP[i][0] = (s1[i-1] == s3[i-1]) && DP[i-1][0]; 
        }
        for(int j=1;j<=l2;j++)
        {
            DP[0][j] = (s2[j-1] == s3[j-1]) && DP[0][j-1]; 
        }
        
        for(int i=1;i<=l1;i++)
        {
          for(int j=1;j<=l2;j++)
          {
          DP[i][j] =((s1[i-1] == s3[i+j-1]) && DP[i-1][j])
                     ||((s2[j-1] == s3[i+j-1]) && DP[i][j-1]); 
          }
        }
        return DP[l1][l2];
    }
};