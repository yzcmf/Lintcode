/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii
@Language: C++
@Datetime: 16-09-19 10:28
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty()) return 0;
        int n=prices.size();
        vector<int>leftProfit(n,0);
        
        //计算A[0:i]的收益最大值
        int maxLeftProfit=0,minPrice = prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<minPrice)
              minPrice = prices[i];
            else
              maxLeftProfit = max(maxLeftProfit,prices[i]-minPrice);
            leftProfit[i] = maxLeftProfit;  
        }
        
        //计算A[i:n-1]的收益最大值
        //最后这两个收益之和便是以i为分割的最大收益
        int ret = leftProfit[n-1];
        int maxRightProfit = 0,maxPrice = prices[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]>maxPrice)
              maxPrice = prices[i];
            else 
              maxRightProfit = max(maxRightProfit,maxPrice-prices[i]);
        //（当然第一次的卖出时间和第二次的买入时间可以是同一天)。
            ret = max(ret,maxRightProfit+leftProfit[i]); 
        // Calculate the same day for selling 
        }
        
        return ret;
    }
};