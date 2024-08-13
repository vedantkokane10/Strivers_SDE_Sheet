/*
Just Right shift each node for last node do it after the while loop.
Because We have condition node->next->next so last node would not considered inside the while loop
*/

void deleteNode(ListNode* node) {
    ListNode* temp = node;
    while(temp->next->next != NULL){
        temp->val = temp->next->val;
        temp = temp->next;
    }
    temp->val = temp->next->val;
    temp->next = NULL;
}
