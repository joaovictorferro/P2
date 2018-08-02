#include <stdio.h>
#include <stdlib.h>

// definir um node
typedef struct node
{
	int value;
	struct node* next;
} node;

// cria lista através de nós, ou seja, fazer com que crie uma lista, com a cabeça apontando para nulo
node *linked_list_node () 
{
	return  NULL;
} 

// criando um no
node* create_node (int item)
{
	node *new_node = (node*) malloc ( sizeof (node));
	new_node -> value = item;
	new_node -> next = NULL ;
	return new_node;
}

// inserir no cmç da lista
node *insert_begin(node *head, int item)
{
	node *new_node = create_node(item); 
	new_node -> value = item;
	new_node -> next = head; 
	return new_node;
}
//inserir no final da lista
node *insert_end(node *head, int item)
{
	node *new_node = create_node(item);
	node *aux = head; // para nao perder a referencia do ponteiro

	if (head != NULL)
    {
        while (head -> next != NULL)
        {
            head = head -> next;
        }

        head -> next = new_node;

        return aux;
    }
    else
    {
        return new_node;
    }

}

// funcao que insere ordenadamente
node *insert_order(node *head, int item)
{
	node *previous = NULL;
	node *current = head;
	node *new_node = create_node(item);

	// verifica se a lista esta vazia, caso esteja ela add ele na cabeca
    if (head == NULL)
    {
    	return new_node;
    }

	// verifica se tem so um unico node na lista
    if (head -> value >= item) 
    {
    	new_node -> next = head;

    	return new_node;
    }

    while (current != NULL && current -> value <= item)  
    {
    	previous = current;
    	current = current -> next;
    }
    
     // verifica ate o ultimo item
    if (previous -> next == NULL)
    {
    	previous -> next = new_node;
    	new_node -> next = NULL;
    }
    else 
    {
    	// os ponteiros apontarem ate o new_node
        previous -> next = new_node; 
        new_node -> next = current;
    }

    return head;
}

// funcao que remove um elemento, seja ele em qualquer posicao
node *delt (node *head, int item)
{
    node *previous = NULL;      // previous = anterior
    node *current = head;       // corrent = atual

    while (current != NULL && current -> value != item)
    {
    	previous = current;
    	current = current -> next;
    }

    if (current == NULL)
    {
    	return head;
    }

    if (previous == NULL)
    {
    	head = current -> next;
    }
    else
    {
    	previous -> next = current -> next;
    }

    free(current);
    return head;
}

// funçao que verificar se a lista é nula
int is_empty(node *head)
{
	return (head == NULL);
}

// função que printa a lista
void print(node *head)
{
	if (head != NULL)
	{
		printf("%d ", head -> value);
		print(head -> next);
	}   
}

int main()
{
	node* head = linked_list_node();

	//head = insert_begin(head, 8);
	head = insert_begin(head, 26);
	head = insert_end(head, 55);
	head = delt(head,55);
	head = insert_end(head, 55);
	head = insert_order(head,56);

	print (head);
	printf ("\n");
	
	return 0;	
}