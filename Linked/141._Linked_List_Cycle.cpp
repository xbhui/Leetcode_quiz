#include <iostream>
#include <stdlib.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


int main()
{
	int b;
	int a = (b = 5);
	printf("a=%d",a);
    return 0;
}

class Solution {
public:
    bool hasCycle(ListNode *head){
		ListNode *slow = head;	
		if(slow == NULL || slow->next == NULL){
			return false;
		}

		ListNode *fast = slow->next->next;
		
		while(fast != NULL && fast->next != NULL){
			if (slow == fast){
				return true;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		
		return false;		
    } 
};
