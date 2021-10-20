/*
	problem statement :https://leetcode.com/problems/find-the-duplicate-number/ 
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findDuplicateUsingHashTable(vector<int>& nums) 
	{
		unordered_set<int> hash_table;
		for(auto num: nums){
			if(hash_table.find(num) == hash_table.end()){
				hash_table.insert(num);
			}
			else{
				return num;
			}
		}
		return 0;
    }

	int findDuplicate(vector<int>& nums){
		int slow, fast;
		slow = 0;
		fast = 0;
		slow = nums[slow];
		fast = nums[nums[fast]];
		while(slow != fast){
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while(slow != fast){
			slow = nums[slow];
			fast = nums[fast];
		}
		// cout << "slow = " << slow << endl;
		// cout << "fast = " << fast << endl;
		return fast;
	}
	
};

int main(){
	vector<int> nums = {1,3,4,2,2};
	Solution sol;
	cout << sol.findDuplicate(nums);
	cout << "\n";
	return 0;
}