#include <iostream>
#include "stdio.h"


using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
		
		if (l1==NULL || l2==NULL) return NULL;	
 
		ListNode* res = new ListNode(0);
	    ListNode* p = l1, *q = l2, *cur = res;

		int carry = 0;		
		while(p != NULL || q != NULL) {
			
			cout << "p:" << p->val << "q:" << q->val << endl;
			int x = (p != NULL) ? p->val : 0;
			int y = (q != NULL) ? q->val : 0;
			int sum = carry + x + y;
			
      		cur->next = new ListNode(sum%10);
			cur = cur->next;	
			if (p != NULL) p = p->next;
			if (q != NULL) q = q->next;

			carry = sum/10;
		}
	
		if (carry > 0) {
			cur->next = new ListNode(carry);
		}

		return res->next;
	}
};


int main()
{
	ListNode* l1 = new ListNode(2);
	ListNode *pl1 = l1;
	l1->next = new ListNode(4);
	l1=l1->next;
	l1->next = new ListNode(7);

	ListNode *l2 = new ListNode(5);
	ListNode *pl2 = l2;
	l2->next = new ListNode(6);
    l2=l2->next;
	l2->next = new ListNode(7);

	Solution so;
	ListNode *l = so.addTwoNumbers(pl1,pl2);

	while(l->next != NULL)
	{
		cout << "->" << l->val << endl;;	
		l=l->next;
	}

	cout << l->val<< endl;

	return 0;
}
