#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
}node;

typedef struct queue {
  int size;
  node *head;
}Queue;

Queue* creat_q()
{
  Queue* new_queue = (Queue*) malloc (sizeof (Queue));

  new_queue-> head = NULL;
  new_queue -> size = 0;
  return new_queue;
}
node* creat_node(int item)
{
  node* new_node = (node*) malloc ( sizeof (node));
  new_node -> value = item;
  new_node -> next = NULL ;
  return new_node;
}

void enqueue(Queue *q,int item)
{
  node* new_node = creat_node(item);
  
  if (q -> head == NULL)
  {
    q->head = new_node;
  } 
  else 
  {
  node* current = q->head;
  while (current->next != NULL) 
  {
    current = current->next;
  }
    new_node->next = current->next;
    current->next = new_node;

  }
}

node* dequeue(Queue *q)
{
  if (q->head == NULL) 
  {
    return ;
  } 
  else 
  {
    node* new_node = q->head;

    q->head = new_node->next;
    new_node->next = NULL;
    free(new_node);
  }
}

void print(Queue* q)
{
  node* _node = q->head;
  
  while(_node!=NULL)
  {
    printf("%d ",_node->value);
    _node = _node -> next;
  }
}

int main()
{ 
  Queue* q = creat_q(); 

  enqueue(q,5000);
  enqueue(q,23);
  enqueue(q,24);

  dequeue(q);
  print(q);
  printf("\n");
  return 0;
}