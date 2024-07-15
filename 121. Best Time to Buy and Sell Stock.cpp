// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = prices[0];
        for(auto x:prices){
            minPrice = min(minPrice,x);
            maxPro = max(x-minPrice,maxPro);
        }
        return maxPro;
    }
};