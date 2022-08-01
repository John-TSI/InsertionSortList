// https://leetcode.com/problems/insertion-sort-list/

#include<iostream>
#include"../inc/solution.hpp"


// prints data of all nodes linked to the passed head
void PrintData(ListNode* head)
{
	ListNode* p{head};
	if(p == nullptr){ std::cout << "No nodes are linked.\n"; }
	while(p != nullptr)
	{
		std::cout << p->val;
		p = p->next;
	}
}

int main()
{
	ListNode n5(2);
	ListNode n4(4, &n5);
	ListNode n3(5, &n4);
	ListNode n2(1, &n3);
	ListNode n1(3, &n2); // head node of linked list

	Solution sol{};
	PrintData( sol.insertionSortList(&n1) );
	
	return 0;
}