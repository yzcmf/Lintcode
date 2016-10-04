/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays-ii
@Language: C++
@Datetime: 16-09-15 02:12
*/

//return as many duplicated numbers as possible;

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
// -- hash map;     
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     // Write your code here
        
    //     map<int,int>ht;
    //     vector<int>res;
        
    //     for(int i=0;i<nums1.size();i++)
    //     {
    //         ht[nums1[i]]++;
    //     }
        
    //     for(int i=0;i<nums2.size();i++)
    //     {
    //         if(ht[nums2[i]]>0)
    //         res.push_back(nums2[i]);
    //         ht[nums2[i]]--;
    //     }
        
    //     return res;
    // }
    
// Two pointers 
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>res;
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])  i++;
            else if(nums1[i]>nums2[j]) j++;
            else
            {
                res.push_back(nums1[i]);
                i++;j++;
            }
        }
        
        return res;
    }
};