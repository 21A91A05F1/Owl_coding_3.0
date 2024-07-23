121. Best Time to Buy and Sell Stock
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

  int maxProfit(vector<int>& prices) {
        int profit=0,maxi=0;
        for(int i=1;i<prices.size();i++)
        {
            profit+=prices[i]-prices[i-1];
            if(profit<0) profit=0;
            maxi=max(maxi,profit);

        }
        return maxi;
    }


122. Best Time to Buy and Sell Stock II
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

   int maxProfit(vector<int>& prices) {
        int s=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1]) s+=prices[i]-prices[i-1];

        }
        return s;
    }


123. Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

   int maxProfit(vector<int>& prices) {
        int fb=INT_MAX,fp=0,sb=INT_MAX,sp=0;;
        for(int i=0;i<prices.size();i++)
        {
            //first person buys with minimum cost
            fb=min(fb,prices[i]);
            //first persons maximum proffit
            fp=max(fp,prices[i]-fb);
            //second person minimum cost to buy from first person
            sb=min(sb,prices[i]-fp);
            //second person maximum profit
            sp=max(sp,prices[i]-sb);
        }
        return sp;
        
    }


Buy sell stock-4
  Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int buy[k+1],profit[k+1];
        std::fill_n(buy, k+1, INT_MAX);
        std::fill_n(profit, k+1, 0);
        
        for(int currPrice: prices) {
            for(int i=1;i<k+1;i++){
                buy[i] = min(buy[i], currPrice-profit[i-1]);
                profit[i] = max(profit[i], currPrice - buy[i]);
            }    
        }
        return profit[k];
    }
};
