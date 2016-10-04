/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 16-09-14 06:45
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        
        
        for(int i=triangle.size()-2;i>=0;i--)
        //From the bottom to the top;
        //Each time you will get the min sum values and it covers the original values
        {   
            for(int j=0;j<=i;j++) //For the triangle traversal;
            {
             triangle[i][j] += min(triangle[i+1][j+1],triangle[i+1][j]);
            }
        }
        
        return triangle[0][0];
    }
};
