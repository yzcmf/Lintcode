/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 16-10-02 00:19
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int lb=0,ub=0;
        for(auto l:L)
        {
            if(l+1>ub)
            ub=l+1;//The upper bound is 1 plus the maxium l;
        }
        
        while(lb+1<ub)//The lower bound is not more than maxium l;
        {
            int mid=lb+(ub-lb)/2;//Choose the mid as the cutten value;
            if(isValid(L,k,mid)) lb=mid;//Enlarge the cutten value;
            else ub=mid;//Smaller the cutten value;
        }
        
        return lb;
    }
    
    bool isValid(vector<int>L, int k,int mid)
    {
        int sum=0;//The number of cutten woods;
        for(auto l:L) sum += l/mid;//Calculate the sum values;
        return sum>=k; //Can be cutted more than k, we increased the mid next;
    }
    
};