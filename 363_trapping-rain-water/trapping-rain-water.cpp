/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/trapping-rain-water
@Language: C++
@Datetime: 16-10-01 03:13
*/

//Two pointer
//Time:O(n);
//Space:O(n);
//Note: the array number is for the height of the bars;
class Solution {
public:
    int trapRainWater(vector<int> &A) {
        int n=A.size();
        if(n<3) return 0;
        vector<int> leftHeight(n,0);
        vector<int> rightHeight(n,0);
        int water = 0;
        
        for(int i=1; i<n; i++) 
            leftHeight[i] = max(leftHeight[i-1], A[i-1]);
        for(int i=n-2; i>=0; i--) 
            rightHeight[i] = max(rightHeight[i+1], A[i+1]);
        
        for(int i=n-2; i>=0; i--) {
            int minHeight = min(leftHeight[i], rightHeight[i]);
            if(minHeight>A[i]) water += (minHeight - A[i]);
        }
        
        return water;
    }
};

// --Simialr problem: Product array exculde itself;
//http://bangbingsyb.blogspot.com/2014/11/leetcode-trapping-rain-water.html