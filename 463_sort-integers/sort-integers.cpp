/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-09-13 05:06
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
     
    // // Bubble sort 
    // void sortIntegers(vector<int>& A) {
    //     // Write your code here
        
    //     for(int i=0;i<A.size();i++)
    //     {
    //         for(int j=i+1;j<A.size();j++)
    //         {
    //             if(A[i] > A[j])
    //             swap(A[i],A[j]);
    //         }
    //     }
    // }
    
    //Selection sort
    // void sortIntegers(vector<int>& A) {
    //     // Write your code here
    //     for(int i=0;i<A.size();i++)
    //     {
    //         int min_idx = i;
    //         for(int j=i+1;j<A.size();j++)
    //         {
    //             if(A[j] < A[min_idx])
    //             {
    //                 min_idx = j; //Find the minium one's index;
    //             }
    //         }
    //          swap(A[i],A[min_idx]);//Swap the minium with i; Push the minium into the very front 
    //     }
    // }
    
    
    //Insertion sort
    void sortIntegers(vector<int>& A) {
        // Write your code here

        for(int i=1;i<A.size();i++)
        {
            for(int j=i-1; j>=0;j--)
            {
                if(A[j+1] < A[j])
                swap(A[j+1],A[j]);
            }
        }
        
    }
};