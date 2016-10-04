/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 16-09-30 05:26
*/

/*
思路是将给定数组从最后一个开始,用二分法插入到一个新的数组;
这样新数组就是有序的，那么此时该数字在新数组中的坐标就是
原数组中其右边所有较小数字的个数;
*/
class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        long long res = 0;
        vector<int> V;
        
        for(int i=A.size()-1;i>=0;i--)
        {
            int left = 0; 
            int right = V.size();
            while(left < right)
            {
                int mid = (left + right)/2;
                if(A[i] > V[mid]) left = mid+1;
                else
                right = mid;
            }
            V.insert(V.begin() + right , A[i]);
            res += right;
        }
        
        return res;
    }
};