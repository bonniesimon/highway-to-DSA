/*
	problem statement : https://leetcode.com/problems/minimum-size-subarray-sum/
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int head, tail;
		int len = nums.size();
		int running_sum, min_subarray_len = len+1, min_subarray_sum = 0;

		head = 0;
		for(head=0; head < len; head++){
			running_sum = 0;
			for(tail = head; tail < len; tail++){
				// cout << "head = " << head << " tail = " << tail << endl;
				running_sum += nums[tail];
				// cout << running_sum << endl;
				if(running_sum >= target){
					min_subarray_len = min(min_subarray_len, tail - head + 1);
					// min_subarray_sum = running_sum;
					break;
				}	
			}
			// cout << "----------------------------\n";
		}
		// cout <<"Min subarray len = " << min_subarray_len << endl;
		return (min_subarray_len==len+1 ? 0 : min_subarray_len);
    }
	
};

int main(){
	// vector<int> nums = {2,3,1,2,4,3};
	vector<int> nums = {1,1,1,1};
	int target = 7;
	Solution sol;
	cout << sol.minSubArrayLen(target,nums);
	cout << "\n";
	return 0;
}