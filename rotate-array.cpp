// Problem Link : https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

/*
	Attempt 3 : Using reverse trick
*/

void print_vec(vector<int> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}


void rotate_vec(vector<int> &arr, int start_index, int last_index){
	int temp;
	for(int start = start_index, last = last_index; start <= last; start++, last--){
		temp = arr[start];
		arr[start] = arr[last];
		arr[last] = temp;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Given
	vector<int> nums = {1,2,3,4,5,6,7,8};
	int k = 4;

	// Solution
	k = k % nums.size();
	rotate_vec(nums, 0, nums.size()-1);
	rotate_vec(nums, 0, k-1);
	rotate_vec(nums, k, nums.size()-1);
	print_vec(nums);



	return 0;
}

/*
	Brute Force Solution
*/

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	// Given
// 	vector<int> nums = {1,2,3,4,5,6,7};
// 	int k = 3;

// 	// Solution
// 	int next, next_index, temp;
// 	int len = nums.size();

// 	for(int i = 0; i<k; i++){
// 		next = nums[0];
// 		for(int j = 0; j < len; j++){
// 			next_index = (j+1)%len;
// 			temp = nums[next_index];
// 			nums[next_index] = next;
// 			next = temp;
// 		}
// 	}

// 	for(int i = 0; i<len; i++){
// 		cout << nums[i] << "\t";
// 	}
// 	cout << endl;

// 	return 0;
// }



/*
	Attempt 2 : Optimized solution
	Fails since the array rotates around certain elements only
*/


// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	// Given
// 	vector<int> nums = {1,2,3,4,5,6,7};
// 	int k = 3;

// 	// Solution
// 	int next, next_index, temp;
// 	int len = nums.size();
// 	next_index = (0+k)%len;
// 	next = nums[next_index];

// 	int j;
// 	for(int i = 0; i < len; i++){
// 		j = next_index;
// 		next_index = (j+k)%len;
// 		temp = nums[next_index];
// 		nums[next_index] = next;
// 		next = temp;
// 	}

// 	for(int i = 0; i<len; i++){
// 		cout << nums[i] << "\t";
// 	}
// 	cout << endl;

// 	return 0;
// }