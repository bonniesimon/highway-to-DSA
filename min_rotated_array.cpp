/*
	problem statement : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin1(vector<int>& nums) {
		if(nums.size() == 1) return nums[0];
		int front, back;
		front = 0; back = nums.size() - 1;
		int max_if_sorted = nums[front] < nums[back] ? nums[front] : nums[back];
		int length = nums.size();
		while(front <= back){
			cout << front << "  " << back << "\n";
			// cout << nums[front] << "  " << nums[back] << "\n";
			if(front+1 < length && nums[front+1] > nums[front]){ 
				front++;
				// cout << nums[front+1] << " > " << nums[front] << "\n";
			}
			else return nums[++front];
			if(back-1 > -1 && nums[back-1] < nums[back]){ 
				back--;
			}
			else return nums[back];
		}
		if(front == back && nums[front] > max_if_sorted) return nums[front];
		return max_if_sorted;
    }
	int findMin2(vector<int>& nums){

		return 0;
	}
};

int main(){
	vector<int> nums = {1,2,3,4,5};
	Solution sol;
	cout << sol.findMin1(nums);
	cout << "\n";
	return 0;
}