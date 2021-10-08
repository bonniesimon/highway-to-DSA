/*
	Problem statement : https://leetcode.com/problems/3sum/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void print_vector(vector<int> v){
		for(int i=0; i<v.size(); i++){
			cout << v[i] << " ";
		}
		cout << "\n";
	}
    vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		unordered_multiset<int> hash;
		set<vector<int>> set_of_vectors;
		vector<vector<int>> solution;

		for(auto i: nums){
			hash.insert(i);
		}	

		int target, desired_value, second_value;
		vector<int> each_sol_item;
		for(int i=0; i<len-2; i++){
			target = nums[i];
			for(int j=i+1; j<len-1; j++){
				second_value = nums[j];
				desired_value = -(target+second_value);
				if(hash.count(desired_value) > 0 ){
					/*
					* Pusing the three numbers whose sum is 0 to each_sol_item
					*/
					each_sol_item.push_back(target);
					each_sol_item.push_back(second_value);
					each_sol_item.push_back(desired_value);

					/*
					* Sorting the vector so that it's easier to distuinguish them
					*/
					sort(each_sol_item.begin(), each_sol_item.end());

					/*
					* Pusing the each_sol_item to a set data structure to 
					* avoid insertion of duplicates 
					*/
					set_of_vectors.insert(each_sol_item);
					// print_vector(each_sol_item);

					/* 
					* Clearing the each_sol_item to remove the previously pushed 
					* data 
					*/
					each_sol_item.clear();
				}
			}
		}
		for(auto it=set_of_vectors.begin(); it != set_of_vectors.end(); it++){
			// print_vector(*it);
			solution.push_back(*it);
		}
		return solution;
    }
};

int main(){
	// vector<int> nums = {-1,0,1,2,-1,-4};
	vector<int> nums = {0,0,0};
	vector<vector<int>> solution;

	Solution sol;
	solution = sol.threeSum(nums);
	for(auto it = solution.begin(); it != solution.end(); it++){
		sol.print_vector(*it);
	}
	cout << "\n";
	return 0;
}