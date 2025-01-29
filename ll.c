#include "ll.h"
#include <stdio.h>
#include <stdlib.h>


linked_list** lists;
int list_count=0;



linked_list* create_ll(char name){
    linked_list* newlist = (linked_list*) malloc(sizeof(linked_list));
    newlist->head = NULL;
    newlist->name = name;
    if (list_count == 0)
    {
        lists = (linked_list**) malloc(sizeof(linked_list));
    }
    else{
        lists = (linked_list**) realloc(lists,sizeof(linked_list*) * (list_count + 1));
    }
    lists[list_count] = newlist;
    list_count += 1;
    return newlist;
 
}

void print_ll(linked_list* list){
    if (list->head == NULL) {
        printf("The list '%c' is empty.\n", list->name);
        return;
    }
    printf("List '%c': ", list->name);
    nodes* temp = list->head;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("null\n");
}

void free_ll(linked_list* list){

    if(list->head== NULL){
        printf("nothing to remove\n");
        return;
    }
    if(list->head->next== NULL){
        free(list->head);
        list->head= NULL;
        return;
    }
    else{
        nodes* temp1 = list->head;
        nodes* temp2 = list->head->next;
        while(temp2->next != NULL){
            free(temp1);
            temp1 = temp2;
            temp2 = temp2->next;
        }       
        free(temp1);
        free(temp2);
        list->head= NULL;
     }
}

void appendto_ll(linked_list* list, int data){

    nodes* newnode = (nodes*) malloc(sizeof(nodes));
    newnode->data = data;
    newnode->next = NULL;

    if(list->head == NULL){
        list->head = newnode;
        return;
    }
    else{
        nodes* temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;

    }
} 

void removefrom_ll(linked_list* list){
    if(list->head == NULL){
        printf("nothing to remove");
        return;
    }

    if (list->head->next==NULL)
    {
        free(list->head);
        list->head = NULL;
        printf("the list %c is now empty", list->name);
        return;
    }
    
    nodes* temp = list->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
        temp->next= NULL;

}

linked_list* find_list(char list_name){

    for(int i= 0; i < list_count; i++){
        if (lists[i]->name == list_name)
        {
            return lists[i];
        }
    }
    return NULL;
}