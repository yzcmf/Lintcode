/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 16-09-16 09:00
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        // sort method; brute force;
        
        // -- Hash Map
    
         map<int,int> has;
         int sum = 0;
         has[0] = -1;
         vector<int>res;
        
        // has[sum]: add from nums[0] to nums[i];
        // if has[sum] be found;
        // The sum add from nums[0] to nums[i] 
        // equals the sume add from nums[0] to nums[j]
        // suppose j>i;
        // Then from nums[i+1] to nums[j];sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(has.find(sum)!= has.end())
            {
                res.push_back(has[sum]+1);
                res.push_back(i);
                return res;
            }else
            {
                has[sum]=i;
            }
        }
        
        return res;
       
    }
};