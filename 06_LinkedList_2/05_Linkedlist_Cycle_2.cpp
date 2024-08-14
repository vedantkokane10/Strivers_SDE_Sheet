/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

Approach - first find if there is cycle or not if there is cycle then keep fast as it it and set slow to head
and iterate and if slow == fast then return that node as it will be the starting node.

Dry Run!!!
*/

ListNode *detectCycle(ListNode *head) {

    if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(fast == NULL || fast->next == NULL || fast->next->next == NULL){
        return NULL;
    }
    slow = head;
    while(slow != NULL){
        if(slow == fast){
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
