/*************************************************************************************** 
Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
Author : Jing Kuo

Description:
    Say you have an array for which the ith element is the price of a given stock on day i.
    If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
    Note that you cannot sell a stock before you buy one.

Example:
    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                Not 7-1 = 6, as selling price needs to be larger than buying price.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
int maxProfit(int* prices, int pricesSize) {
    int bestProfit=0;
    int condidateBuyPrice=prices[0];
    
    for(int i=1;i<pricesSize;i++){
        if (prices[i]<condidateBuyPrice) condidateBuyPrice=prices[i];
        if ((prices[i]-condidateBuyPrice) > bestProfit){
            bestProfit=prices[i]-condidateBuyPrice;
        } 
    }
    
    return bestProfit;
}