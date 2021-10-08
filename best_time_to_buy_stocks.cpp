// Question : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;



// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	// Inputs
// 	vector<int> prices = {8,6,4,7,9,2,3};

// 	int max_profit = 0;

// 	for(int i=0; i<prices.size()-1; i++){
// 		for(int j=i+1; j<prices.size(); j++){
// 			if(prices[j] - prices[i] > max_profit){
// 				max_profit = prices[j] - prices[i];
// 			}
// 		}
// 	}	

// 	cout << max_profit << '\n';


// 	return 0;
// }


// More Optimal Solution


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Inputs
	vector<int> prices = {8,6,4,7,9,2,3};

	int min_price = INT_MAX;
	int new_profit, price;
	int max_profit = 0;

	for(int i=0; i<prices.size(); i++){
		price = prices[i];
		if(price < min_price){
			min_price = price;
		}
		new_profit = price - min_price;
		if(new_profit > max_profit){
			max_profit = new_profit;
		}
	}

	cout << max_profit << '\n';


	return 0;
}