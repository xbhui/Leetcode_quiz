#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *detectCycle(ListNode *head){

		ListNode *slow = head;
		ListNode *fast = head;

		if(slow == NULL || slow->next == NULL){
			return NULL;
		}

		while(fast != NULL && fast->next != NULL){
			if(slow == fast){
				return head;
			}

			slow = slow->next;
			fast = fast->next->next;
		}
		return NULL;
	}
};
