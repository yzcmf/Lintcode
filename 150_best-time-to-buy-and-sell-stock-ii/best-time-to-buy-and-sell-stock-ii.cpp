/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-ii
@Language: C++
@Datetime: 16-09-19 10:16
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty() || prices.size() == 1) return 0;
        
        int CurProfit =0,LastProfit =0,min_price =prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min_price) min_price = prices[i];
            
            LastProfit = prices[i]-min_price;
            
            if(LastProfit !=0 ) 
            {
            CurProfit += LastProfit;
            //if(i+1<prices.size())
            min_price = prices[i];
            }
        }
        
        return CurProfit;
    }
};