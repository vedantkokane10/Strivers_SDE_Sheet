/*
Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.


Approach - Bottom part of each node is sorted.
So if we iterate using recursion go the  last node and then merge the last and second last lists
and keep repeating this we will get a single linked list which has only bottom nodes in sorted order.

Only merging of lists logic is needed.

Dry Run!!
*/


Node *flatten(Node *root) {
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    Node* newMergedList = flatten(root->next);
    return mergeLists(root,newMergedList);
}

Node* mergeLists(Node *list1, Node *list2){
    Node* newHead = new Node(-1);
    Node* temp = newHead;
    while(list1 != NULL && list2 != NULL){
        if(list1->data <= list2->data){
            Node* newNode = new Node(list1->data);
            temp->bottom = newNode;
            list1 = list1->bottom;
        }
        else{
            Node* newNode = new Node(list2->data);
            temp->bottom = newNode;
            list2 = list2->bottom;
        }
        temp = temp->bottom;
    }
    
    if(list1 != NULL){
        temp->bottom = list1;
    }
    
    if(list2 != NULL){
        temp->bottom = list2;
    }
    return newHead->bottom;
}
