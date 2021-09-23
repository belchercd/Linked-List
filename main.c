#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  printf("\n");
  
  printf("Allocating new list...\n");
  list_t * test_list = list_alloc();
  printf("\n");
  
  printf("Adding to the front of the list\n");
  list_add_to_front(test_list, 2);
  list_add_to_front(test_list, 1);
  list_print(test_list);
  printf("\n");
  
  printf("Adding to the back of the list\n");
  list_add_to_back(test_list, 3);
  list_add_to_back(test_list, 6);
  list_print(test_list);
  printf("\n");
  
  printf("Inserting at index\n");
  list_add_at_index(test_list, 4, 3);
  list_add_at_index(test_list, 5, 4);
  list_print(test_list);
  printf("\n");
  
  printf("The list length is %d\n",list_length(test_list));
  printf("\n");
  
  printf("Removing from index 4: %d\n", list_remove_at_index(test_list, 4));
  printf("\n");
  
  printf("Removing from the front of the list: %d\n", list_remove_from_front(test_list));
  printf("\n");
  
  printf("Removing from the back of the list: %d\n", list_remove_from_back(test_list));
  printf("\n");
  
  printf("Checking to see if 5 is in the list: %d\n", list_is_in(test_list, 5));
  printf("\n");
  
  printf("Returning the value at index 1: %d\n", list_get_elem_at(test_list,1));
  printf("\n");
  
  printf("Searching for the index of element 4: %d\n", list_get_index_of(test_list,4));
  printf("\n");
  
  list_free(test_list);
  
  return 0;
}