/* Buy and sell stock twice
** WAP that computes the max profit that can be made by buying and selling a share at most twice.
** The second buy must be made after first sale.
** Solution has Time complexity- O(n) Space complexity- O(n)
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

	double maxtotalprofit= 0;
	vector<double> first_buy_sell_profits(prices.size(), 0); //initialize profit array with 0
	double min_price_so_far= prices[0];
	
	//Forward phase. For each day, we record the max profit if we sell on that day
	for (int i=0; i< prices.size(); ++i){
		min_price_so_far= min(min_price_so_far, prices[i]);
		maxtotalprofit= max(maxtotalprofit, prices[i]-min_price_so_far);
		first_buy_sell_profits[i]= maxtotalprofit;
	}
	
	//Backward phase. For each day, find the max profit if we make the second buy on that day
	double max_price_so_far= prices[prices.size()-1];
	
	for (int i= prices.size()-1; i >= 0; --i){
		max_price_so_far= max(max_price_so_far, prices[i]);
		maxtotalprofit= max(maxtotalprofit, max_price_so_far - prices[i] + first_buy_sell_profits[i-1]);
	}
	return maxtotalprofit;
	
}
	