/*
	Problem statement: https://leetcode.com/problems/missing-number/
*/

// better solution in Logseq interview prep using XOR

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int len = nums.size();

		sort(nums.begin(), nums.end());

		if(nums[0] != 0) return 0;

		for(int i=1; i<len; i++){
			if(nums[i] != nums[i-1] + 1){
				return nums[i-1] + 1;
			}
		}

		return len;
    }
};

int main(){
	vector<int> nums = {9,6,4,2,3,5,7,0,1};
	Solution sol;
	cout << sol.missingNumber(nums);
	cout << "\n";
	return 0;
}