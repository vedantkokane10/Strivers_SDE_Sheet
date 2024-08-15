/*
Given the head of a linked list, rotate the list to the right by k places.

Approach - 
First find length of list and tail of the list  then attach tail's next to head
then find kth node set head to kth node's next node and set kth node's next to NULL
return head.
*/

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    
    ListNode* tail = head;
    int size = 1;
    while(tail->next != NULL){
        size++;
        tail = tail->next;
    }
    k = k % size;
    if(k == 0){
        return head;
    }

    tail->next = head;
    ListNode* kthNode = findKthNode(head,size-k);
    ListNode* kthNodeNext = kthNode->next;
    kthNode->next = NULL;

    head = kthNodeNext;


    return head;
}

ListNode* findKthNode(ListNode* head,int k){
    int cnt = 1;
    ListNode* temp = head;
    while(cnt != k){
        temp = temp->next;
        cnt++;
    }
    return temp;
}

/* OR
Use rotate a array approach,
where we first reverse the linked list 
and then find kth node and then reverse from head to kth node and then from kth node to tail
*/


ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    int size = 0;
    ListNode* temp = head;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    k = k % size;

    if( k == 0){
        return head;
    }
    head = reverse(head);
    cout<<k<<" "<<size;
    cout<<" "<<head->val;
    ListNode* kthNode = head;
    int cnt = 1;
    while(cnt < k){
        cnt++;
        kthNode = kthNode->next;
    }

    ListNode* kthNextNode = kthNode->next;
    kthNode->next = NULL;

    kthNextNode = reverse(kthNextNode);
    head = reverse(head);

    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = kthNextNode;
    
    return head;
}


ListNode* reverse(ListNode* head) {
    ListNode* prevNode = NULL;
    ListNode* currentNode = head;
    ListNode* nextNode = NULL;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}
