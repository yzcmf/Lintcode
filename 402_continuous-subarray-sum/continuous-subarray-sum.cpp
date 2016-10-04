/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/continuous-subarray-sum
@Language: C++
@Datetime: 16-09-19 21:35
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int len = A.size();
        vector<int>res(2,0);
        if(len == 0) return res;
        int start=0,end=0,lastMax=A[0];
        int maxV = lastMax;
        
        for(int i=1;i<len;i++)
        {
            if(lastMax<0)
            {
                lastMax = A[i];
                start = i;
            }
            else
            lastMax += A[i];
            end = i;
            
            if(lastMax > maxV)
            {
                maxV = lastMax;
                res[0]=start;
                res[1]=end;
            }
        }
        return res;
    }
};