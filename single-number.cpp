/*
	Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		if(nums.size() == 1) return nums[0];
		sort(nums.begin(), nums.end());
		int i=0, len = nums.size();
		while(i<len){
			if(nums[i] != nums[i+1] || i+1 > len-1){
				return nums[i];	
			}
			i += 2;
		}	
		return 0;
    }

	int singleNumberUsingHashTable(vector<int>& nums){
		multiset<int> hash_table(nums.begin(), nums.end());

		for(auto it = hash_table.begin(); it != hash_table.end(); it++){
			if(hash_table.count(*it) == 1){
				return *it;
			}
		}
		return 0;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Input
	vector<int> nums = {1,3,1,4,5,6,4,5,6};

	Solution sol;
	// cout << sol.singleNumber(nums);
	cout << sol.singleNumberUsingHashTable(nums);
	cout << '\n';
	return 0;
}