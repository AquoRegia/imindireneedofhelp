#ifndef LL_H
#define LL_H
extern int list_count;


typedef struct node{
    int data;
    struct node* next;
}nodes;

typedef struct linkedlist{
    char name;
    nodes* head;
}linked_list;


linked_list* create_ll(char name);
    
void print_ll(linked_list* list);

void free_ll(linked_list* list);

void appendto_ll(linked_list* list, int data);

void removefrom_ll(linked_list* list);

linked_list* find_list(char list_name);

extern linked_list** lists;
#endif