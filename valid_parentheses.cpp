/*
	problem statement : https://leetcode.com/problems/valid-parentheses/
*/



#include <bits/stdc++.h>
#define SIZE 6000
using namespace std;

class Stack{
private:
	int top = -1;
	char arr[SIZE];
public:
		Stack();
		bool isEmpty();
		bool isFull();
		void push(char);
		char pop();
		char peek();
};

Stack::Stack(){
	top = -1;
}

bool Stack::isFull(){
	if(top == SIZE-1){
		return true;
	}else{
		return false;
	}
}

bool Stack::isEmpty(){
	if(top == -1){
		return true;
	}else{
		return false;
	}
}

void Stack::push(char c){
	if(isFull()){
		return 'c';
	}
	top++;
	arr[top] = c;	
}

char Stack::pop(){
	if(isEmpty()){
		return;
	}
	char to_be_popped_value = arr[top];
	top--;
	return to_be_popped_value;
}

char Stack::peek(){
	char top_value = arr[top];
	return top_value;
}

class Solution {
public:
	char closingBrace(char c){
		switch(c){
			case '(':
				return ')';
			case '[':
				return ']';
			case '{':
				return '}';
		}
		return '(';
	}

	bool isOpeningSymbol(char c){
		if(c=='(' || c=='[' || c=='{'){
			return true;
		}
		return false;
	}

	bool isClosingSymbol(char c){
		if(c==')' || c==']' || c=='}'){
			return true;
		}
		return false;
	}

    bool isValid(string s){
		Stack stack;
		for(int i=0; i<s.length(); i++){
			if(isOpeningSymbol(s[i])){
				stack.push(s[i]);
			}
			else if(isClosingSymbol(s[i]) && stack.isEmpty()){
				return false;
			}
			else{
				if(s[i] == closingBrace(stack.peek())){
					char popped_value = stack.pop();
				}else{
					return false;
				}
			}
		}
		if(stack.isEmpty())
			return true;
		return false;
    }
	
};

int main(){
	string s;
	getline(cin, s);
	Solution sol;
	cout << sol.isValid(s);
	cout << "\n";
	return 0;
}