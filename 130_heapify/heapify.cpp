/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/heapify
@Language: C++
@Datetime: 16-09-22 04:03
*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        
        //left child and right child is: 2*k+1 or 2*k+2;From the half second;
        for(int i=(A.size()-2)/2;i>=0;i--)
        {
            min_heap(A,i);
        }
    }
    
private:

    // The parent is less than children
    
    void min_heap(vector<int> &nums,int k)
    {
        int len = nums.size();
        
        while(k<len)
        {
        int min_index = k;
        
        //Left leaf node search
        if(k*2+1<len && nums[k*2+1]<nums[min_index])
        min_index = k*2 +1;
        
        //Right leaf node search
        if(k*2+2<len && nums[k*2+2]<nums[min_index])
        min_index = k*2 +2;
        
        if(k == min_index) break;
        
        //Swap with the minimal
        swap(nums[k],nums[min_index]);
        
        //Not only current index;
        k = min_index;
        }
    }
    
};

//Good reference:
//https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/heapify.cpp
//http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73101