/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: C++
@Datetime: 16-09-22 05:19
*/

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    static bool comp(int a, int b)
    {
        string x=to_string(a),y=to_string(b);
        return x+y>y+x;
    }
    
    string largestNumber(vector<int>&nums) {
        // write your code here
        //sort the nums according to the self made comparison;
        sort(nums.begin(),nums.end(),comp);

        //After sorting : (8,4,23,20,1);
        //convert to string
        string res="";
        
        for(int i=0;i<nums.size();i++)
        {
            res+=to_string(nums[i]);
        }
        
        if(res[0] == '0') res = '0';//If the case : (0,0,0,0)
        return res;
    }
};