/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 16-09-17 04:39
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        
        //sort method;
        // vector<int>numbers =nums ; 
        
        // int l=0,r=numbers.size()-1;
        // vector<int> res;
        // sort(numbers.begin(),numbers.end());
        
        // while(l<=r)
        // {
        //     if(numbers[l]+numbers[r]==target)
        //     {
        //         for(int i = 0; i<nums.size();i++)
        //         {  
        //             if(nums[i] == numbers[l])  
        //             {  
        //                 res.push_back(i+1);
        //             }  
        //             else if(nums[i] == numbers[r])  
        //             {  
        //                 res.push_back(i+1);
        //             }  
        //         }  
        //         break;  
        //     }
        //     else if (numbers[l]+numbers[r] < target)
        //     {
        //         l++;
        //     }
            
        //     else if (numbers[l]+numbers[r] > target)
        //     {
        //         r--;
        //     }
            
        //     while(numbers[l] == numbers[l+1] && (l+1)<numbers.size()-1) l++;
        //     while(numbers[r] == numbers[r-1] && (r-1)>0) r--;
        // }
        
        // return res;
        
        
        //Map Method;
        
        map<int,int>has;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
            if(has.find(target-nums[i])!=has.end())
            {
                res.push_back(has[target-nums[i]]+1);
                res.push_back(i+1);
                break;
            }
            else
            {
             has[nums[i]] = i;
            }
        }
        
        return res;
    }
};
