/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 16-09-30 20:10
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        
        // int res=0;
        
        // for(int i=0;i<A.size();i++)
        // {
        //     res ^=A[i];
        // }
        
        // return res;
        
        int count[32] = {0};
        int res = 0;
        for (int i = 0; i < 32; i++) {
            for (auto v : A) {
                count[i] += (v >> i) & 1;
            }
            res |= ((count[i] % 2) << i);
        }
        return res;
    }
};
