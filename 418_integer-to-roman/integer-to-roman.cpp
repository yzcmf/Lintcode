/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/integer-to-roman
@Language: C++
@Datetime: 16-09-22 22:55
*/

//http://bangbingsyb.blogspot.com/2014/11/leetcode-integer-to-roman.html
/*
思路：
这题需要一些背景知识，首先要知道罗马数字是怎么表示的：
http://en.wikipedia.org/wiki/Roman_numerals
I: 1
V: 5
X: 10
L: 50
C: 100
D: 500
M: 1000
字母可以重复，但不超过三次，当需要超过三次时，用与下一位的组合表示：
I: 1, II: 2, III: 3, IV: 4
C: 100, CC: 200, CCC: 300, CD: 400
s = 3978
3978/1000 = 3: MMM
978>(1000-100), 998/900 = 1: CM
78<(100-10), 78/50 = 1 :L
28<(50-10), 28/10 = XX
8<(100-1), 8/5 = 1: V
3<(5-1), 3/1 = 3: III
ret = MMMCMLXXVIII
所以可以将单个罗马字符扩展成组合形式，来避免需要额外处理类似IX这种特殊情况。
I: 1
IV: 4
V: 5
IX: 9
X: 10
XL: 40
L: 50
XC: 90
C: 100
CD: 400
D: 500
CM: 900
M: 1000
*/
class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        string dict[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ret;
        for(int i=0;i<13;i++)
        {
            if(n>=val[i])
            {
             int cnt = n/val[i];
             n %= val[i];
             for(int j=0;j<cnt;j++)
             ret += dict[i];
            }
        }
        return ret;
        
        // for(int i=0; i<13; i++) {
        //     if(num>=val[i]) {
        //         int count = num/val[i];
        //         num %= val[i];
        //         for(int j=0; j<count; j++) {
        //             //ret.append(dict[i]);
        //             ret += dict[i];
        //         }
        //     }
        // }
        // return ret;
    }
};