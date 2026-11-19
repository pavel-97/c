#include "stdio.h"
#include <stdlib.h>

typedef struct Node
{
  int id;
  struct Node *next;
} Node;

Node *create_node(int node_id)
{
  Node *ptr = malloc(sizeof(Node));

  if (ptr == NULL)
  {
    return NULL;
  }

  (*ptr).id = node_id;
  (*ptr).next = NULL;

  return ptr;
}

void free_nodes(Node *head)
{
  Node *curr = head;

  while (curr != NULL)
  {
    Node *next = (*curr).next;
    free(curr);
    curr = next;
  }
}

int push(Node **ptr, Node *ptr_next)
{
  (*(*ptr)).next = ptr_next;

  return 0;
}

int main(void)
{
  Node *node = create_node(0);
  Node *node_next;
  Node *head = node;

  for (int i = 1; i < 5; i++)
  {
    node_next = create_node(i);
    push(&node, node_next);
    node = node_next;
  }

  for (Node *tmp = head; tmp != NULL; tmp = (*tmp).next)
  {
    printf("node id = %d\n", (*tmp).id);
  }

  free_nodes(head);

  return 0;
}
