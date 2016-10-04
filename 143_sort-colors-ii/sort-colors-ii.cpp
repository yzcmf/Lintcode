/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/sort-colors-ii
@Language: C++
@Datetime: 16-09-30 07:44
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        vector<int>ht(k+1);
        
        for(int i=0;i<colors.size();i++) ht[colors[i]]++;
        int pos=0;
        for(int i=1;i<=k;i++)
        {
            while(ht[i]>0)
            {
            colors[pos++] = i;
            ht[i]--;
            }
        }
        return;
    }
};