#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node* Node;
typedef struct LinkedList* LinkedList;

struct Node
{
    char *data;
    Node next;
    Node prev;
};

struct LinkedList
{
    Node first;
    Node last;
};

void print_List(LinkedList list);
LinkedList new_LinkedList();
static Node new_Node(char *data);
void LinkedList_add_at_front(LinkedList this, char *data);
void* LinkedList_pop(LinkedList this);
void LinkedList_add_at_end(LinkedList this, char *data);
bool LinkedList_contains(const LinkedList this, char *data);
void LinkedList_remove(LinkedList this, char *data);
void* LinkedList_elementAt(LinkedList this, int index);
void print_List(LinkedList this);