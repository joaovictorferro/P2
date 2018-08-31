#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int priority;
  struct node *next;
}node;

typedef struct priority_queue {
  int size;
  node *head;
}priority_queue;

priority_queue* creat_pq()
{
  priority_queue* new_queue = (priority_queue*) malloc (sizeof (priority_queue));

  new_queue-> head = NULL;
  new_queue -> size = 0;
  return new_queue;
}
node* creat_node(int p)
{
  node* new_node = (node*) malloc ( sizeof (node));
  new_node -> priority = p;
  new_node -> next = NULL ;
  return new_node;
}

void enqueue(priority_queue *pq,int p)
{
  node* new_node = creat_node(p);
  if (pq -> head == NULL)
  {
    new_node -> next = pq->head;
    pq->head = new_node;
  }
  else if (p > pq->head->priority) 
  {
    new_node -> next = pq->head;
    pq->head = new_node;
  } 
  else 
  {
  node* current = pq->head;
  while ((current->next != NULL) &&(current->next->priority > p)) 
  {
    current = current->next;
  }
    new_node->next = current->next;
    current->next = new_node;

  }
}

node* dequeue(priority_queue *pq)
{
  if (pq->head == NULL) 
  {
    return NULL;
  } 
  else 
  {
    node* new_node = pq->head;

    pq->head = new_node->next;
    new_node->next = NULL;
    free(new_node);
  }
}

void print(priority_queue* pq)
{
  node* _node = pq->head;
  
  while(_node!=NULL)
  {
    printf("%d ",_node->priority);
    _node = _node -> next;
  }
}
int main()
{ 
  priority_queue* pq = creat_pq(); 

  enqueue(pq,5000);
  enqueue(pq,23);
  enqueue(pq,24);

  dequeue(pq);
  print(pq);
  printf("\n");
  return 0;
}