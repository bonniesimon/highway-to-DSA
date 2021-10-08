// Problem statement : https://leetcode.com/problems/maximum-product-subarray/

#include <bits/stdc++.h>
using namespace std;

/*
	Attempt 1 
*/

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	// Given
// 	vector<int> nums = {0, 2};

// 	// Solution code
// 	int max_product = nums[0];
// 	int running_product = 1;

// 	for(int i=0; i<nums.size(); i++){
// 		running_product = running_product * nums[i];
// 		max_product = max(max_product, running_product);
// 		running_product = running_product == 0 ? 1 : running_product;
// 	}

// 	cout << max_product<< '\n';

// 	return 0;
// }






/*

	Attempt 2 : Brute Force Method

*/

int find_product(vector<int> &arr, int start, int end){
	int product = 1;
	for(int i = start; i<end+1; i++){
		product = product * arr[i];	
	}
	return product;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Given
	vector<int> nums = {0, 2};

	// Solution code
	int max_product = nums[0];

	for(int i=0; i<nums.size(); i++){
		for(int j=0; j<i+1; j++){
			max_product = max(max_product, find_product(nums,j,i));
		}
	}	

	cout << max_product<< '\n';

	return 0;
}