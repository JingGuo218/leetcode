/*************************************************************************************** 
Source : 
Author : Jing Kuo

Description:
    Say you have an array for which the ith element is the price of a given stock on day i.
    Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
    Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example:
    Input: [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
                Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
                
Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach:1. less efficent, 1st version
            to locate buy point and sell point
         2. more efficient, 2nd version
            just add the raising gap

***************************************************************************************/
int maxProfit(int* prices, int pricesSize) {
    int profit=0;

    for(int i=1;i<pricesSize;i++){
        if(prices[i]>prices[i-1]){
            profit+=prices[i]-prices[i-1];
        }
    }
        
    return profit;
}

/*int maxProfit(int* prices, int pricesSize) {
    int profit=0;
    int prePrice=0;
    int buyPrice=0;
    int selPrice=0;
    int j;
    
    for(int i=0;i<pricesSize;i=j){
        prePrice =prices[i];
        selPrice=0;
        buyPrice=0;

        for(j=i;j<pricesSize;j++){
            if (prices[j] > prePrice){
                buyPrice=prePrice;
                break;
            } 
            prePrice = prices[j];
        }
        
        for(;j<pricesSize;j++){
            if (prices[j] < prePrice){
                break;
            }else{
                selPrice=prices[j];
            }
            prePrice = prices[j];
        }

        if(selPrice!=0) profit+= selPrice - buyPrice;
    }
    
    return profit;
}*/