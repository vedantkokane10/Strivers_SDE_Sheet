/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Ex -
[1,2,3,4,5]

fs
[1,2,3,4,5]

   s f
[1,2,3,4,5]

     s   f
[1,2,3,4,5]


When f (fast pointer) points to last node, slow points the middle node.

*/

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
