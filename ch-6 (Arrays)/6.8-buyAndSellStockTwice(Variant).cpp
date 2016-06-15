/* Buy and sell stock twice
** WAP that computes the max profit that can be made by buying and selling a share at most twice.
** The second buy must be made after first sale.
** Solution has Time complexity- O(n) Space complexity- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

double buyAndSellStockTwice(vector<double> &prices);

int main() {
	// your code goes here
	int n, key;
    cin >> n; 
    
    vector<double> prices(n);
    for(int i = 0; i < n; i++){
     	cin >> prices[i];
    }
    
	double profit= buyAndSellStockTwice(prices);
	cout<<profit<<endl;
	
	return 0;
}


double buyAndSellStockTwice(vector<double> &prices){

	double min_price_so_far = prices[0], maxProfit1=0, maxProfit2=0, sell_index; 

	for (int i=0; i< prices.size(); i++){
		double max_profit_sell_today= prices[i]- min_price_so_far;
		maxProfit1 = max(max_profit_sell_today, maxProfit1);
		min_price_so_far= min(min_price_so_far,prices[i]);
		if (maxProfit1 == max_profit_sell_today){
			sell_index= i;
		}
	}
	
	double secondmin_price_so_far= prices[sell_index+1];
	
	for (int i= sell_index+1; i< prices.size(); ++i){
		double max_profit_sell_today= prices[i]- secondmin_price_so_far;
		maxProfit2 = max(max_profit_sell_today, maxProfit2);
		secondmin_price_so_far= min(secondmin_price_so_far,prices[i]);
		}
	//cout<<maxProfit2<<endl;
	return (maxProfit1+maxProfit2);
}