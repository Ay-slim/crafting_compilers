#include "test.h"

/**
 * initialize: Initializes a doubly linkedlist
 * @val: String to initialize with
 * Returns: Pointer to doubly linkedlist head
*/
doub_list_t* initialize(char *val) {
  doub_list_t *new = malloc(sizeof(doub_list_t));
  if (!new) {
    return NULL;
  }
  new->prev = NULL;
  new->next = NULL;
  new->val = val;
  return new;
}

/**
 * insert: Inserts a value in a doubly linked list
 * @head: Pointer to list head
 * @val: String to insert at the end of doubly_linked list
 * Return: Nothing
*/
void insert(doub_list_t *head, char *val) {
  doub_list_t *new = malloc(sizeof(doub_list_t));
  if (!new) {
    return;
  }
  new->val = val;
  new->next = NULL;
  doub_list_t *tmp = head;
  while (tmp->next) {
    tmp = tmp->next;
  }
  new->prev = tmp;
  tmp->next = new;
}

/**
 * find: Searches for a value in a doubly linkedlist
 * @head: Pointer to list head
 * @val: String to find in doubly_linked list
 * Return: Integer (1 if found 0 otherwise)
*/
int find(doub_list_t *head, char *val) {
  doub_list_t *tmp = head;
  while (tmp) {
    if (strcmp(val, tmp->val) == 0) {
      return 1;
    }
    tmp = tmp->next;
  }
  return 0;
}

/**
 * delete: Removes the node containing a string from a doubly linked list
 * @head: Pointer to list head
 * @val: String to find in doubly_linked list and delete
 * Return: 1 if found and deleted, return 0 otherwise
*/
int delete(doub_list_t **head, char *val) {
  doub_list_t *tmp = *head;
  doub_list_t *nxt;
  doub_list_t *prv;

  while (tmp) {
    if (strcmp(val, tmp->val) == 0) {
      if (!tmp->prev) {
        if (!tmp->next) {
          free(tmp);
          return 1;
        }
        nxt = tmp->next;
        nxt->prev = NULL;
        *head = nxt;
        free(tmp);
        return 1;
      }
      prv = tmp->prev;
      if (!tmp->next) {
        prv->next = NULL;
        free(tmp);
        return 1;
      }
      nxt = tmp->next;
      prv->next = nxt;
      nxt->prev = prv;
      free(tmp);
      return 1;
    }
    tmp = tmp->next;
  }
  return 0;
}

void print(doub_list_t *head) {
  doub_list_t *tmp = head;

  while (tmp) {
    printf("%s\n", tmp->val);
    tmp = tmp->next;
  }
}

/**
 * main: Test them functions and struct
 * Return: Exit success
*/
int main() {
  doub_list_t *doub_linked = initialize("one");
  insert(doub_linked, "two");
  insert(doub_linked, "three");
  insert(doub_linked, "four");
  insert(doub_linked, "five");
  print(doub_linked);
  delete(&doub_linked, "one");
  delete(&doub_linked, "two");
  print(doub_linked);
  return EXIT_SUCCESS;
}