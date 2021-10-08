//
// Problem : https://mega.nz/folder/4W4ClA6Q#Zzljx0B9877OlEP6wGVQEw/folder/sDY1zIrC
//

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int min_count = floor(n/3);
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	unordered_multiset<int> itemset;
	unordered_set<int> result;
	for(int i=0; i<n; i++){
		itemset.insert(arr[i]);
	}

	for(int i=0; i<n; i++){
		if(itemset.count(arr[i]) > min_count){
			result.insert(arr[i]);
		}
	}

	unordered_set<int>::iterator it;
	for(it = result.begin(); it!=result.end(); it++){
		cout << *it << "  ";
	}

	cout << '\n';
	return 0;
}