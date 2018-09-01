#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct hash
{
	int size;
    Node **table;
} Hash;

Node* creat_node(int item)
{
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node-> value = item;
	new_node -> next = NULL;
	return new_node;
}

Hash* creat_hash(int size)
{
	int i;
	Hash new_hash = (Hash*) malloc(sizeof(Hash));
	new_hash = size = 0;
	new_hash->table = (Node*)malloc(size * (sizeof(Node)));
	for(i=0;i<size;i++)
	{
		new_hash -> table[i] = NULL;
	}
	return new_hash;
}

Hash* add_hash(Hash *hash, int item)
{
    int key = key % (hash->size);
    hash->table[key] = add_end(hash->table[key],new_data);
    return hash;
}

Node* add_end(Node* head, int item)
{
    int a = 0;
    Node* current = head;
    Node* new_node = create_node(new_data);
    
    if(head == NULL)
    {
        return new_node;
    }
    while(current->next != NULL)
    {
        current = current->next;
    }
    	
    current->next = new_node;
    new_node->prev = current;
    
    return head;
}

Hash *remove_from_hash(Hash* hash, int item)
{
    int key = item % (hash->size);
    
    if(hash->table[key] == NULL)
    {
        printf("No element found\n");
    } 
    else 
    {
        Node* current = hash->table[key];
        
        while(current != NULL && current->data != data)
        {
            current = current->next;
        }
        if(current->next == NULL && current->prev == NULL)
        {
            hash -> table[key] = NULL;
        } 
        else if(current->next == NULL)
        {
            current->prev->next = NULL;
        } 
        else if(current->prev == NULL)
        {
            hash->table[key] = current->next;
        } 
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        free(current);
    }
    return hash;
}

Node* remove_list (Node* head)
{
    Node* current = head;
    while(head != NULL) {
        current = head->next;
        free(head);
        head = current;
    }
}

Hash *free_hash(Hash* hash)
{
    int i;
    for(i=0;i<hash->size;i++){
        if(!is_empty(hash->table[i])){
            remove_list(hash->table[i]);
            hash->table[i] = NULL;
        }
    }
}

int main()
{
    Node* head = NULL;
    Hash *_hash = create_hash(10);

    hash = insert_hash(_hash,1);
    hash = insert_hash(_hash,12);
    delt_hash(_hash);
    printHash(_hash);
	return 0;
}