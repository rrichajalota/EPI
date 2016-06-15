/* WAP that takes an array denoting the daily stock price, and returns the maximum profit that could be made by buying and selling one share 
** of that stock.
** Input- <310, 315, 275, 295, 260, 270, 290, 230, 255, 250>
** Expected output- 30
** Optimized solution. 
** array of min. values seen so far- <310, 310, 275, 275, 260, 260, 260, 230, 230, 230>
** Maximum profit for each day can be obtained by computing the difference between the current entry and the minimum value seen so far. 
** max profit each day- <0,5,0,20,0,10,30,0,25,20>
** Time complexity- O(n) Space complexity- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

double buyAndSellStockOnce(vector<double> &prices);

int main() {
	// your code goes here
	int n, key;
    cin >> n;
    
    vector<double> prices(n);
    for(int i = 0; i < n; i++){
     	cin >> prices[i];
    }
    
	double profit= buyAndSellStockOnce(prices);
	cout<<profit<<endl;
	
	return 0;
}


double buyAndSellStockOnce(vector<double> &prices){

	double min_price_so_far = prices[0], maxProfit=0;

	for (int i=0; i< prices.size(); i++){
		double max_profit_sell_today= prices[i]- min_price_so_far;
		maxProfit= max(maxProfit, max_profit_sell_today);
		min_price_so_far= min(min_price_so_far, prices[i]);
	}

	return maxProfit;
}
	