/*
	problem statement : https://leetcode.com/problems/longest-palindromic-substring/
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		string res = "";
		int res_len = 0;
		int len = s.length();

		int head, tail, i;

		for(i=0; i<len; i++){
			/*
			* Finding odd length palindromes
			*/
			head = i; tail = i;
			while(head>=0 && tail<len && s[head]==s[tail]){
				// cout << "head = " << s[head]<< " tail = " << s[tail] << endl;
				// cout << "head = " << head << " tail = " << tail << endl;
				if(tail - head + 1 > res_len){
					res = s.substr(head, tail-head+1);
					res_len = tail-head+1;
				}
				head--;
				tail++;
			}

			// cout << " --------------------------------- \n";

			/*
			* Finding even length palindromes
			*/
			head = i; tail = i+1;
			while(head>=0 && tail<len && s[head]==s[tail]){
				// cout << "head = " << s[head] << " tail = " << s[tail] << endl;
				// cout << "head = " << head << " tail = " << tail << endl;
				if(tail - head + 1 > res_len){
					res = s.substr(head, tail-head+1);
					// cout << "res = " << res << endl;
					res_len = tail-head+1;
				}
				head--;
				tail++;
			}
		}
		return res;
    }
	
};

int main(){
	string s;
	getline(cin, s);
	Solution sol;
	cout << sol.longestPalindrome(s);
	cout << "\n";
	return 0;
}