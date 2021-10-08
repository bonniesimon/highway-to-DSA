/*
	problem statement : https://leetcode.com/problems/container-with-most-water/
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxAreaBetween(int first_value, int last_value, int leap){
		return min(first_value, last_value) * leap;
	}
    int maxArea(vector<int>& height) {
		int len = height.size();
		int first = 0, last = len-1;
		int max_capacity = INT_MIN;
		int capacity;

		while(first < last){
			// cout << first << " " << last << '\n';
			capacity = maxAreaBetween(height[first], height[last], last-first);	
			max_capacity = max(capacity, max_capacity);	
			// Update pointer
			if(height[first] < height[last]){
				first++;
			}else{
				last--;
			}
		}

		return max_capacity;
    }
	
};

int main(){
	// vector<int> height= {1,8,6,2,5,4,8,3,7};
	vector<int> height= {1,1};
	Solution sol;
	cout << sol.maxArea(height);
	cout << "\n";
	return 0;
}