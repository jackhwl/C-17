/*You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output : 7 -> 0 -> 8
	Explanation : 342 + 465 = 807.
	*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

	/**
	* Definition for singly-linked list.
	* struct ListNode {
	*     int val;
	*     ListNode *next;
	*     ListNode(int x) : val(x), next(NULL) {}
	* };
	*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	//77.05%
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		int mod = (l1->val + l2->val) % 10;
		int extra = (l1->val + l2->val) > 9 ? 1 : 0;
		if (l1->next == NULL) {
			ListNode * lsum = new ListNode(mod);
			lsum->next = extra > 0 ? addTwoNumbers(new ListNode(extra), l2->next) : l2->next;
			return lsum;
		}
		if (l2->next == NULL) {
			ListNode * lsum = new ListNode(mod);
			lsum->next = extra > 0 ? addTwoNumbers(new ListNode(extra), l1->next) : l1->next;
			return lsum;
		}
		ListNode * lsum = new ListNode(mod);
		lsum->val = mod;
		auto l2withextra = extra > 0 ? addTwoNumbers(new ListNode(extra), l2->next) : l2->next;
		lsum->next = addTwoNumbers(l1->next, l2withextra);
		return lsum;
	}

	ListNode* generateListNode(vector<int> v1) {
		
		if (v1.size() <= 0) return NULL;
		if (v1.size() == 1) { 
			return new ListNode(*begin(v1)); 
		}
		else {
			ListNode* l1 = new ListNode(*begin(v1));
			vector<int> v2(v1.size()-1);
			copy(begin(v1)+1, end(v1), begin(v2));
			l1->next = generateListNode(v2);
			return l1;
		}
	}
};



int main2() {
	vector<int> v1{ 3,4,2 };
	vector<int> v2{ 4,6,5 };
	Solution myso;
	ListNode* l1 = myso.generateListNode(v1);
	ListNode* l2 = myso.generateListNode(v2);

	auto lsum = myso.addTwoNumbers(l1, l2);

	return 0;
}