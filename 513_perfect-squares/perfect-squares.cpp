/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/perfect-squares
@Language: C++
@Datetime: 16-09-25 19:49
*/

//At most there are four perfect numbers that can form a number;
// class Solution {
// public:
//     /**
//      * @param n a positive integer
//      * @return an integer
//      */
//     int numSquares(int n) {
//         // Write your code here
//         while(n%4 == 0) n /=4; 
//         while(n%8 == 7) return 4;
        
//         for(int a=0;a*a<=n;a++)
//         {
//          int b = sqrt(n-a*a);    
//          if(a*a + b*b == n) return !!a + !!b;
//         //一个正整数逻辑取反为0，再取反为1;
//         //所以用两个感叹号!!的作用就是看a和b是否为正整数
//         //都为正整数的话返回2，只有一个是正整数的话返回1
//         }
//         return 3;
//     }
// };

// --DP solution
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
       vector<int>DP(n+1,INT_MAX);
       DP[0] = 0;
       
       for(int i=0;i<=n;i++)
       {
           for(int j=1;i+j*j<=n;j++)
           {
               DP[i+j*j] = min(DP[i+j*j],DP[i]+1);
           }
       }
       
       return DP.back();
    }
};
