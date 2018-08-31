#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* next;
	struct node* previus;
}Node;

typedef struct list
{
	Node* front;
	Node* back;
	int size;
}List;

List* start_list()
{
	List* new_list = (List*) malloc(sizeof (List));
	new_list -> front = NULL;
	new_list -> back = NULL;
	new_list -> size = 0;
}

Node* create_node(int item)
{
	Node* new_node = (Node*) malloc (sizeof(Node));
	new_node -> value = item;
	new_node -> next = NULL;
	new_node -> previus = NULL;
	return new_node; 
}

void add_end(List* lista,int item)
{
	Node* new_node =create_node(item);
	
	if(lista ->size == 0)
	{
		lista->front = lista->back = new_node;
	}
	else
	{	
		lista->back->next = new_node;
		new_node -> previus = lista->back;
		lista->back = new_node;
	}
	lista->size ++;
}

void add_front(List* lista,int item)
{	
	Node* new_node = create_node(item);
	
	if(lista->size ==0)
	{
		lista->front = lista->back = new_node;
	}
	else
	{
		new_node -> next = lista->front;
		lista-> front -> previus = new_node;
		lista->front = new_node;
	}

	lista->size ++;
}

void delet (List* lista,int item)
{
	if(lista->size == 1)
	{
		free(lista->front);
		lista-> front = lista->back = NULL;
		lista-> size = 0;
	}
	else if(lista->front -> value == item)
	{
	  	Node* temp = lista->front;
        lista->front = lista->front->next;
        lista->front->previus = NULL;
        free(temp);
        lista->size--;
    }
    else if(lista->back->value == item)
    {
        Node* temp = lista->back;
        lista->back = lista->back->previus;
        lista->back->next = NULL;
        free(temp);
        lista->size --;
    }
    else 
    {
        Node* iterator = lista->front;
        Node* prev;
        Node* next;
        while(iterator!= NULL)
        {
            if(iterator -> value == item)
            {
                prev = iterator->previus;
                prev-> next = iterator->next;
                next = iterator->next;
                next-> previus = iterator->previus;
                free(iterator);
                lista->size--;
                return;
            }
            iterator = iterator->next;
        }
    }

}

int searsh (List* lista,int item)
{
	int cont = -1;
	Node* aux = lista->front;

	while(aux != NULL && aux-> value == item)
	{
		aux = aux -> next;
		cont ++;
	}
	return cont;
}

void print_front(List* lista)
{
	Node* head = lista->front;
	
	while(head != NULL)
	{
		printf("%d ",head->value);
		head = head->next;

	}
}

void print_end(List* lista)
{
	Node* head = lista->back;

	while(head!= NULL)
	{
		printf("%d ",head->value);
		head = head -> previus;
	}
}

int main()
{
	List* lista = start_list();
	
	add_end(lista,1);
	add_end(lista,2);
	add_front(lista,3);
	add_front(lista,4);
	add_end(lista,5);
	add_front(lista,6);
	
	print_front(lista);
	printf ("\n");
	print_end(lista);
	printf ("\n");
	
	delet(lista,6);
	delet(lista,3);
	delet(lista,5);

	print_front(lista);
	printf ("\n");
	print_end(lista);
	printf ("\n");
	
	printf("\n%d\n",searsh(lista,4));
	
	return 0;
}