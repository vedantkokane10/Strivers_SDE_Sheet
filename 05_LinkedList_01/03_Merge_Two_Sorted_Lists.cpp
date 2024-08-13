/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/

void addNode(ListNode* &start,ListNode* &last , int data){
    ListNode* temp = new ListNode(data);
    if(start == NULL){
        start = temp;
        last = start;
    }
    else{
        last->next = temp;
        last = last->next;
    }
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* start = NULL;
    ListNode* last = NULL;
    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            addNode(start,last,list1->val);
            list1 = list1->next;
        }
        else{
            addNode(start,last,list2->val);
            list2 = list2->next;
        }
    }
    while(list1 != NULL){
        addNode(start,last,list1->val);
        list1 = list1->next;
    }
    while(list2 != NULL){
        addNode(start,last,list2->val);
        list2 = list2->next;
    }
    return start;
}
