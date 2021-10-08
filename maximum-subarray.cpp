// Problem statement : https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Given
	vector<int> nums = {5,4,-1,7,8};

	int max_sum = nums[0];
	int running_sum = 0;

	for(int i=0; i<nums.size(); i++){
		running_sum = running_sum + nums[i];
		max_sum = max(max_sum, running_sum);
		// if(running_sum < 0){
		// 	running_sum = 0;
		// }
		running_sum = running_sum < 0 ? 0 : running_sum;
	}

	cout << max_sum << "\n";

	return 0;
}