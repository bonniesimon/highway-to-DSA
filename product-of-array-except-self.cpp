/*
	problem statement : https://leetcode.com/problems/product-of-array-except-self/
*/

#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> v){
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it){
        int num = *it;
        cout << num << "  "; 
    }
    cout << "\n";
}


class Solution {
public:
	/*
	* This solution uses two arrays	
	*/
    vector<int> productExceptSelf0(vector<int>& nums) {
		vector<int> prefix;
		int running_product = 1;

		for(int num : nums){
			prefix.push_back(running_product);
			running_product *= num;
		}

		// print_vec(prefix);

		vector<int> suffix;
		running_product = 1;
		int len = nums.size();

		for(int i = len-1; i>-1; i--){
			suffix.push_back(running_product);
			running_product *= nums[i];
		}
		reverse(suffix.begin(), suffix.end());

		// print_vec(suffix);

		for(int i=0; i<len; i++){
			prefix[i] *= suffix[i];
		}

		return prefix;
    }

	/*
	* This solution uses only one array. 
	*/
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> product_array;
		int running_product = 1;

		for(int num : nums){
			product_array.push_back(running_product);
			running_product *= num;
		}

		// print_vec(prefix);

		running_product = 1;
		int len = nums.size();

		for(int i=len-1; i>-1; i--){
			product_array[i] *= running_product;
			running_product *= nums[i];
		}	

		return product_array;
    }
};

int main(){
	vector<int> nums = {1,2,3,4};
	Solution sol;
	vector<int> result;
	result = sol.productExceptSelf(nums);
	print_vec(result);
	// cout << sol.productExceptSelf(nums);
	cout << "\n";
	return 0;
}