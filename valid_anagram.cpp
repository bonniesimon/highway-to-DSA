/*
	problem statement : 
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t){
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if(s == t) return true;
		return false;
    }
	
};

int main(){
	string s, t;
	getline(cin, s);
	getline(cin, t);
	Solution sol;
	cout << sol.isAnagram(s, t);
	cout << "\n";
	return 0;
}