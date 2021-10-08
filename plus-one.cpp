/*
	Problem Statement : https://leetcode.com/problems/plus-one/
*/

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int lsb, msb;
		int len;

		len = digits.size();
		lsb = len - 1;
		msb = 0;

		int current_digit;
		bool is_msb_adjust_needed = true;

		current_digit = lsb;

		while(current_digit > msb){
			// cout << "Current digit : " << current_digit << endl;
			if(digits[current_digit]+1 > 9){
				digits[current_digit] = 0;
				current_digit--;
			}else{
				digits[current_digit]++;
				is_msb_adjust_needed = false;
				break;
			}
		}

		// cout << "is_msb_adjust_needed : " << is_msb_adjust_needed << endl;
		if(is_msb_adjust_needed && digits[msb]+1 > 9){
			digits[msb] = 0;
			digits.insert(digits.begin(), 1);
		}else if(is_msb_adjust_needed){
			digits[msb]++;
		}else{
			// pass
		}
		return digits;	
    }
};

int main(){
	vector<int> digits = {1,2,4};
	vector<int> result;

	Solution sol;

	result = sol.plusOne(digits);
	print_vector(result);
	return 0;
}