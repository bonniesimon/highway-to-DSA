#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<long long int> v){
    vector<long long int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it){
        int num = *it;
        cout << num << "  "; 
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// Given
	vector<long long int> nums = {10, 3, 5, 6, 2};
	int n = 5;

	long long int product = 1;
	vector<long long int> P;

	for(int i=0; i<n; i++){
		product = 1;
		// cout << nums[i] << endl;
		for(int j=0; j<n; j++){
			if(i == j) continue;
			product *= nums[j];
		}
		// cout << product<< "\n";
		P.push_back(product);
	}

	print_vec(P);
    return 0;
}