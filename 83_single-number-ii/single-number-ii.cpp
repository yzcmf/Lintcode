/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 16-09-30 20:09
*/

/*
求出每个比特位的数目，然后%3，如果这个比特位只出现1次，那么这比特位就会余1，否则就会整除。
把每个余下的比特位求出来，就知道是哪个数只出现1次了。
*/
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer 
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int count[32] = {0};
        int res = 0;
        for (int i = 0; i < 32; i++) {
            for (auto v : A) {
                count[i] += (v >> i) & 1;
            }
            res |= ((count[i] % 3) << i);
        }
        return res;
    }
};
//http://www.wengweitao.com/lintcode-single-number-i-ii-iii-luo-dan-de-shu.html