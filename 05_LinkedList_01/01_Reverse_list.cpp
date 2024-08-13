ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = NULL;
    ListNode* currentNode = head;
    ListNode* nextNode = NULL;
    while(curr != NULL){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}
