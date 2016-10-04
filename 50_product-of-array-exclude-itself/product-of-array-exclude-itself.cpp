/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-09-15 21:55
*/

//For A[i] : DP_L[i] = nums[0] * nums[1] *...*nums[i-1];
// DP_L[i] = DP_L[i-1] * nums[i-1];
//For A[i] : DP_R[i] = nums[len-1] * nums[len-2] *...*nums[i+1];
// DP_R[i] = DP_R[i+1] * nums[i+1]; 
// For A[i] : res = DP_L[i] * DP_R[i];
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int len=nums.size();
        
        vector<long long> res (len,1);
        vector<long long> DP_L(len,1);
        vector<long long> DP_R(len,1);
        
        for(int i=1;i<len;i++)
        {
           DP_L[i] = DP_L[i-1] * nums[i-1]; 
        }
        
        for(int i=len-2;i>=0;i--)
        {
           DP_R[i] = DP_R[i+1] * nums[i+1]; 
        }
        
        for(int i=0;i<len;i++)
        {
           res[i] = DP_L[i] * DP_R[i]; 
        }
        
        return res;
    }
};