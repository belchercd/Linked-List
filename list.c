// list/list.c
// 
// Implementation for linked list.
//
// Camryn Belcher

#include <stdio.h>
#include <stdlib.h> 
#include "list.h"

list_t *list_alloc() {
  //allocating memory for the list
  list_t *new_list = (list_t *)malloc(sizeof(list_t));
  //allocating memory for the node
  node_t *new_node = (node_t *)malloc(sizeof(list_t));
  new_list ->head = NULL;
  
  return new_list;  
}

void list_free(list_t *l) {
  node_t *current = l ->head;
  node_t *temp;
 
  while(current != NULL){
    temp = current ->next;
    free(current);
    current = temp;
  }
  
  //clearing up any remnants 
  free(temp);
  free(current);
  free(l); 
}

void list_print(list_t *l) {
  node_t *current = l ->head;
  
  while(current != NULL){
    printf("%d\n", current ->value);
    printf("\n");
    current = current ->next;
  }  
}

int list_length(list_t *l) { 
  int i = 0;
  node_t *current = l ->head;
  
  while(current != NULL){
    i++;
    current = current ->next;
  }
  return i; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node ->value = value;
  new_node ->next = NULL;

  //check if the list is already empty 
  if(l ->head == NULL){
    l ->head = new_node;
    //return;
  }
  else{
    node_t* current = l ->head;
    while(current ->next != NULL){
      current = current ->next;
    }
    current ->next = new_node;
  } 
}
void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node ->value = value;
  new_node ->next = NULL;
  
  //check if the list is already empty
  if (l ->head == NULL){
    l ->head = new_node;
    //return;
  }
  else{
    node_t *current = l ->head;
    l ->head = new_node;
    new_node ->next = current;
  }
}
void list_add_at_index(list_t *l, elem value, int index) { 
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node ->value = value;
  new_node ->next = NULL;
  
  int length = list_length(l);
  
  //check if the list is already empty
  if(l ->head == NULL){
    l ->head = new_node;
    //return;
  }
  else{
    node_t *current = l ->head;
    node_t *prev;
    int i = 0;
    while(i != index){
    prev = current;
    current = current ->next;
    i++;
    }
    prev ->next = new_node;
    new_node ->next = current;
  }
}
 
elem list_remove_from_back(list_t *l) {
  elem val;
  
  //check if the list is empty 
  if(l ->head == NULL){
    printf("The list is already empty.\n");
  }
  else if(l ->head ->next == NULL){
    val = l ->head ->value;
    free(l ->head);
    return val;
  }
  else{
    node_t *current = l ->head;
    while(current -> next ->next !=NULL){//get to the second to last node in the list
      current = current->next;
    }
    //now remove last item
    val = current ->next ->value;
    free(current ->next);
    current ->next = NULL;
    return val; 
  } 
}
elem list_remove_from_front(list_t *l) {
  //check if the list is empty
  if (l ->head == NULL){
    printf("The list is already empty.\n");
  }
  else{
    node_t *current = l ->head;
    elem val = current ->value;
    l ->head = current ->next;
    free(current);
    return val;
  }
}
elem list_remove_at_index(list_t *l, int index) {  
  //check if the list is already empty
  if(l ->head == NULL){
    printf("List is already empty.\n");
    //return;
  }
  node_t *current = l ->head;
  node_t *prev;
  elem val;
  int i = 0;
  int length = list_length(l);
  while(i < length){
    if (i == index){
      //delete it
      val = current ->value;
      prev ->next = current ->next;
      free(current);
      return val;
    }
    prev = current;
    current = current ->next;
    i++;
  }
  
  //if it makes it out the loop then it did not find index
  printf("Index not found.\n");
  return;
}

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l ->head;
  
  while(current != NULL){
    if(current ->value == value){
      printf("Found.\n");
      return true;
    }
    else{
      current = current ->next;
    }
  }
  
  printf("Not found.\n");
  return false; 
}

elem list_get_elem_at(list_t *l, int index) {
  node_t *current = l ->head;
  
  int length = list_length(l);
  int i = 0; //counter
  while(i < length){
    if (i == index){
      return current ->value;
    }
    else{
      current = current ->next;
      i++;
    }
  }
  printf("Index not found.\n");
  return;
}

int list_get_index_of(list_t *l, elem value) { 
  node_t *current = l ->head;
  int i = 0;
  while(current != NULL){
    if (current ->value == value){
      return i;
    }
    else{
      current = current ->next;
      i++;
    }
  }

  printf("Value not found.\n");
  return;
}