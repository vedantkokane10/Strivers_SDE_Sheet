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
