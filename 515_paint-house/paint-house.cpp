/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/paint-house
@Language: C++
@Datetime: 16-09-25 22:01
*/

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int m = costs.size();
        if(m == 0) return 0;
        
        int red = 0, green = 0, blue = 0;
        for(int i=0;i<m;i++)
        {
            int r = red;
            int g = green;
            int b = blue;
            
            red = costs[i][0] + min(g,b);
            //Last time the red position can't be red,add min green and blue from last time;
            green = costs[i][1] + min(r,b);
            //Last time the green position can't be green,add min red and blue from last time;
            blue = costs[i][2] + min(r,g);
            //Last time the blue position can't be blue,add min red and green from last time;
        }
        
        return min(red,min(green,blue));
    }
};