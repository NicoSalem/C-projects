#include "LinkedList.h"

LinkedList new_LinkedList()
{
    LinkedList this = (LinkedList)malloc(sizeof(struct LinkedList));
    this->first = this->last = NULL;
    return this;
}

static Node new_Node(void *data) {
    Node this = (Node)malloc(sizeof(struct Node));
    this->data = data;
    this->next = this->prev = NULL;
    return this;
}

void LinkedList_add_at_front(LinkedList this, void *data) {
    Node node = new_Node(data);
    node->next = this->first;
    if (this->first != NULL) {
        this->first->prev = node;
    }
    this->first = node;
    if (this->last == NULL) {
        this->last = node;
    }
}

void LinkedList_remove(LinkedList this, void *data) {
    for (Node node=this->first; node != NULL; node=node->next) {
        if (node->data == data) {
            if (node == this->first) {
                this->first = node->next;
            }
            if (node == this->last) {
                this->last = node->prev;
            }
            if (node->prev != NULL) {
                node->prev->next = node->next;
            }
            if (node->next != NULL) {
                node->next->prev = node->prev;
            }
            free(node);
            return;
        }
    }
}

void* LinkedList_elementAt(LinkedList this, int index) {
    int i = 0;
    for (Node node=this->first; node != NULL; node=node->next) {
        if (i == index) {
            return node->data;
        }
        i += 1;
    }
    return NULL;
}

void* LinkedList_pop(LinkedList this) {
    void *data = LinkedList_elementAt(this, 0);
    if (data != NULL) {
        LinkedList_remove(this, data); // Removes first occurrence
    }
    return data;
}

void LinkedList_add_at_end(LinkedList this, void *data) {
    Node node = new_Node(data);
    node->prev = this->last;
    if (this->last != NULL) {
        this->last->next = node;
    }
    this->last = node;
    if (this->first == NULL) {
        this->first = node;
    }
}

bool LinkedList_contains(const LinkedList this, void *data) {
    for (Node node=this->first; node != NULL; node=node->next) {
        if (node->data == data) {
            return true;
        }
    }
    return false;
}

void print_List(LinkedList this)
{
    Node current;
    current = this->first;
    do
    {
        printf("%s\n",current->data);
        current = current->next;
    }
    while(current!=NULL);
}


