class Solution {
    public int maxProfit(int[] prices) {
        int left = 0;
        int right = 1;
        int max_profit = 0;
        while(left < prices.length) {
            if(right < prices.length && prices[left] < prices[right]) {
                int res = prices[right] - prices[left];
                if(res >= max_profit) {
                    max_profit = res;
                }
                right++;
            } else {
                left = right;
                right = left + 1;
            }
        }
        return max_profit;
    }
}
