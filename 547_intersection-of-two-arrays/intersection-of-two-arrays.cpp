/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: C++
@Datetime: 16-09-15 01:56
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
     
// -- two pointers
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     // Write your code here
    //     sort(nums1.begin(),nums1.end());
    //     sort(nums2.begin(),nums2.end());
    //     vector<int> res;
    //     int i=0,j=0;
        
    //     while (i < nums1.size() && j < nums2.size()) {
    //         if (nums1[i] < nums2[j]) i++;
    //         else if (nums1[i] > nums2[j]) j++;
    //         else {
    //             if (res.empty() || res.back() != nums1[i]) {
    //                 res.push_back(nums1[i]);
    //             }
    //             i++; j++;
    //         }
    //     }
    //     return res;
    // }
// -- hash set

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        set<int> s(nums1.begin(),nums1.end());
        set<int> res;
        for(auto a: nums2)
        {
            if(s.count(a))//returns the numbers of matches(set: 1 or 0);
            res.insert(a); 
        }
        return vector<int>(res.begin(),res.end());
    }
    
// Binary Search    
     
    //  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     // Write your code here
    //     set<int> res;
    //     sort(nums2.begin(),nums2.end());
    //     for(auto a: nums1)
    //     {
    //         if(binarySearch(nums2,a))
    //         res.insert(a);
    //     }
    //     return vector<int>(res.begin(),res.end());
    // }
  
    //  bool binarySearch(vector<int> &nums, int target) {
    //     int left = 0, right = nums.size();
    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] == target) return true;
    //         else if (nums[mid] < target) left = mid + 1;
    //         else right = mid;
    //     }
    //     return false;
    // }
  
};