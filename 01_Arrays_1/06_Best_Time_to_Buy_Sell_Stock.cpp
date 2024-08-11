int maxProfit(vector<int>& prices) {
    int mxProfit = 0;
    int currentMinimum = prices[0];
    for(auto x:prices){
        currentMinimum = min(x,currentMinimum);
        int currentprofit = x - currentMinimum;
        mxProfit = max(mxProfit,currentprofit);
    }
    return mxProfit;
}
