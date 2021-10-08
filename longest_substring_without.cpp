/*
	problem statement : https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool contains_duplicate(string s, int head, int tail){
		if(s.length() == 1){
			return false;
		}
		unordered_set<char> char_set;
		for(int i = head; i<tail+1; i++){
			if(char_set.find(s[i]) == char_set.end()){
				char_set.insert(s[i]);
			}
			else{
				return true;
			}
		}
		return false;
	}
    int lengthOfLongestSubstring(string s) {
		int max_long_substring = 0;
		int len = s.length();
		for(int i=0; i<len; i++){
			for(int j=i; j<len; j++){
				if(j-i+1 < max_long_substring){
					continue;
				}
				if(!contains_duplicate(s, i, j)){
					max_long_substring = max(max_long_substring, j-i+1);
				}
				else{
					break;
				}
			}
		}
		return max_long_substring;
    }
	
};

int main(){
	string s;
	getline(cin, s);
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s);
	cout << "\n";
	return 0;
}