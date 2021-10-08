/*
	Problem statement : https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool isSorted(int low_value, int high_value){
		return low_value < high_value ? true : false;
	}

    int search(vector<int>& nums, int target) {
		int len = nums.size();
		int low, mid, high;

		low = 0; high = len-1;


		while(low < high){
			/*
			* Checking if we found the value
			* if the value doesn't exist in low or high at this point then the answer is -1
			*/
			if(low+1 == high){
				if(nums[low] == target){
					return low;
				}
				else if(nums[high] == target){
					return high;
				}
				else{
					return -1;
				}
			}

			mid = (low+high)/2;
			// cout << "before  " << low << " " << mid << " " << high << "\n" ;

			if(isSorted(nums[low], nums[mid])){
				// cout << " low to mid \n";
				if(nums[low] <= target && target <= nums[mid]){
					low = low;
					high = mid;
				}
				else{
					low = mid;
					high = high;
				}
			}else if(isSorted(nums[mid], nums[high])){
				if(nums[mid] <= target && target <= nums[high]){
					low = mid;
					high = high;
					// cout << "mid to high\n";
				}
				else{
					low = low;
					high = mid;
				}
			}else{
				// pass
			}
			// cout <<"after   " << low << " " << mid << " " << high << "\n" ;

		}
		if(nums[low] == target)
			return low;
		else return -1;
    }
};

int main(){
	vector<int> nums = {5,1,3};
	int target = 3;

	Solution sol;
	cout << sol.search(nums, target);
	cout << "\n";
	return 0;
}