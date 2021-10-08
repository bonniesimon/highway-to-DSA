#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
	bool is_contains_duplicate = false;
	sort(nums.begin(), nums.end());

	for(int i=1; i < nums.size(); i++){
		if(nums[i] == nums[i-1]){
			cout << "true\n";
			is_contains_duplicate = true;
			break;
		}
	}	
	if(!is_contains_duplicate) cout << "false\n";

	return 0;
}