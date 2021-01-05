#ifndef __S_LINKED_LIST_H_
#define __S_LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>

struct SinglyLinkedNode {
    int val;
    struct SinglyLinkedNode *next;
};

void sllappend(struct SinglyLinkedNode* head, int val) {
    struct SinglyLinkedNode *cur;
    cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = calloc(1, sizeof(struct SinglyLinkedNode));
    cur->next->val = val;
}

int sllretrieve(struct SinglyLinkedNode* head, int index) {
    int i = 0;
    struct SinglyLinkedNode *ptr;
    for(; i <= index && ptr != NULL; i++, ptr=ptr->next) {}
}




#endif // __S_LINKED_LIST_H_
