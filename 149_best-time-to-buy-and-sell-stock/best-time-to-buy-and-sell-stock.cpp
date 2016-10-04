/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock
@Language: C++
@Datetime: 16-09-19 10:23
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
        int max_profit =0, min_price = prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] < min_price)
            min_price = prices[i];
            else
            max_profit = max(max_profit, prices[i]-min_price);
        }
        
        return max_profit;
    }
};
