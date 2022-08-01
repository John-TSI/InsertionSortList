#include"../inc/solution.hpp"


ListNode* Solution::insertionSortList(ListNode* head)
{
    if(!head || !head->next){ return head; }  // handle zero/one node cases
    ListNode dummy{}; dummy.next = head;
    ListNode* sorted{head}, * prev{head}, * curr{head->next};  // 'sorted' will act as iterator over the sorted nodes

    while(curr)
    {
        if(curr->val < prev->val)  // misplaced node found
        {
            sorted = &dummy;  // reset the 'iterator' pointer
            while(sorted->next->val < curr->val){ sorted = sorted->next; }  // traverse sorted list until reaching node with val >= current
            prev->next = curr->next;  // prev stores address of the next node to be sorted
            curr->next = sorted->next;  // curr is inserted into the sorted list, between sorted and sorted->next
            sorted->next = curr;
            curr = prev->next;  // curr points to the next node to be sorted
        }
        else  // current node is already sorted, continue traversing list
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;  // dummy node points to actual head of linked list
}