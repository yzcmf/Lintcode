/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 16-09-22 05:41
*/

//Method one:QuickSort: 
//Time:O(n);
//Space:O(1);
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
int kthLargestElement(int k, vector<int> nums) {
      
    return quickselect(nums,0,nums.size()-1,k);
}
private:
int quickselect(vector<int> nums, int left,int right, int k)
{
    //Note : i and pivot here are just for the index operations for the program
    int pivot=right;
    int i=left;
    for(int j=left;j<right;j++)
    {
        
        if(nums[j]>nums[pivot])
        {
        swap(nums[i],nums[j]);
        i++;
        }
    }
    // After that , the elements before the index pivot is greater then pivot 
    // Which is for left - (i-1);
    if(nums[i]<nums[pivot]) swap(nums[i],nums[pivot]);
    // Compare the nums[i] with the nums[pivot] as well;
    // Now from left - i ; the elements are greatest than the other right ones;
    // The numbers that are greatest than the other right ones are i-left+1;
    if(i-left+1==k) return nums[i];
    if (i-left+1<k)  return quickselect(nums,i+1,right,k-(i-left+1));
    if (i-left+1>k)  return quickselect(nums,left,i-1,k);
    
}
};

//Method two: priority queue
//Time:O(n);
//Space:O(1);
// class Solution {
// public:
//     /*
//      * param k : description of k
//      * param nums : description of array and index 0 ~ n-1
//      * return: description of return
//      */
// int kthLargestElement(int k, vector<int> nums) {
//   struct compare  
//   {  
//   bool operator()(const int& l, const int& r)  
//   {  
//       return l > r;//  front -> end : large -> small
//   }  
//   }; 
//   priority_queue<int,vector<int>,compare>queue;
//   for(int i=0;i<nums.size();i++)
//   {
//       if(queue.size()<k) queue.push(nums[i]);//when less than k members
//       else if(queue.top()<nums[i])
//       {
//           queue.pop();
//           queue.push(nums[i]);
//       }
//   }
//   return queue.top();
//   }
// };