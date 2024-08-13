/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Ex- 
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int nodesCnt = 1;
    ListNode* temp = head;
    while(temp != NULL){
        nodesCnt++;
        temp = temp->next;
    }
    int position = nodesCnt - n;
    if(position == 1){
        return head->next;
    }
    int it = 1;
    temp = head;
    while(temp != NULL){
        if(it + 1 == position){
            if(temp->next->next != NULL){
                temp->next = temp->next->next;
            }
            else{
                temp->next = NULL;
            }
            break;
        }
        it++;
        temp = temp->next;
    }
    return head;
}
