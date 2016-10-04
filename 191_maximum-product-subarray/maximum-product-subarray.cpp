/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 16-09-24 07:21
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& A) {
        // write your code here
        if(A.empty()) return 0;
        int n = A.size();
        if(n == 1) return A[0];
        vector<int>max_product(n+1,1);
        vector<int>min_product(n+1,1);
        int ret = A[0];
        max_product[0] = A[0];
        min_product[0] = A[0];
        for(int i=1;i<n;i++)
        {
         int t =  max_product[i];
         max_product[i] = max(max(max_product[i-1]*A[i], min_product[i-1]*A[i]),A[i]); 
         min_product[i] = min(min(max_product[i-1]*A[i], min_product[i-1]*A[i]),A[i]);
         ret = max(ret,max_product[i]);
        }
        
        return ret;
    }
};