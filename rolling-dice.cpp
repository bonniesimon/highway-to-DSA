//
// Problem : https://atcoder.jp/contests/abc208/tasks/abc208_a
//
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	if(a*6 < b || a > b) cout << "NO";
	else cout << "YES";

	cout << '\n';
	return 0;
}