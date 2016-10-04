/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-09-13 08:31
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        
        if(array.empty()) return -1;
        
        int bgn=0,end=array.size()-1,mid;
        int min_idx=array.size();
        //When the while loop ends: bgn = end+1; 
        while(bgn<=end)
        {
            mid = (bgn+end)/2;
            if(target==array[mid])
               {
                min_idx = min(min_idx,mid);
                end=mid-1;
               }
            else if(target<array[mid])
                end=mid-1;
            else if(target>array[mid])
                bgn=mid+1;
        }
        
        if(min_idx == array.size()) return -1;
        return min_idx;
    }
    
    //  if(array.empty()) return -1;
    
    // int left=0,right=array.size()-1,mid;
    // int ans=array.size();
    
    // while(left<=right)
    // {
    //     mid=(left+right)/2;
    //     if(array[mid]==target) 
    //     {
    //     ans=min(ans,mid);
    //     right=mid-1;
    //     }
    //     if(array[mid]<target) left=mid+1;
    //     if(array[mid]>target) right=mid-1;
    // }

    // if(ans==array.size()) 
    // ans=-1;
    
    // return ans;
};