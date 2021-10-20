/*
	problem statement : https://leetcode.com/problems/linked-list-cycle/
*/



#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
		bool isLoop = false;
		ListNode* slow = head;
		ListNode* fast = head;
		if(head == NULL || head->next == NULL){
			return false;
		}

		if(head->next == head){
			return true;
		}

		if(head->next->next == NULL){
			return false;
		}

		slow = head->next;
		fast = head->next->next;


		while((slow != fast)){
			slow = slow->next;

			if(slow == NULL){
				break;
			}

			fast = fast->next->next;
			if(fast == NULL){
				break;
			}
			// cout << "Slow value = " << slow->val << endl;
			// cout << "Fast value = " << fast->val << endl;
		}
		if(slow == NULL || fast == NULL){
			return false;
		}
		return true;
    }
	
};

int main(){
	ListNode* head = new ListNode();
	ListNode* second = new ListNode();
	ListNode* third = new ListNode();
	ListNode* forth = new ListNode();

	head->val = 3;
	head->next = second;

	second->val = 2;
	second->next = third;

	third->val = 0;
	third->next = forth;

	forth->val = -4;
	forth->next = second;

	Solution sol;
	cout <<  sol.hasCycle(head);
	cout << "\n";
	return 0;
}