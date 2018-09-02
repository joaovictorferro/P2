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
} ht;

ht *create_hash(int size)
{
    int i;
    ht* new_hash = (ht*)malloc(sizeof(ht));
    new_hash->table = (Node**)malloc(size * (sizeof(Node)));
    new_hash->size = size;
    
    for(i=0;i<size;i++) 
    {
        new_hash->table[i] = NULL;
    }
    return new_hash;
}

Node* create_node(int item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node-> value = item;
    return new_node;
}

ht* remove_from_hash(ht *hash, int item)
{
    int key = item % (hash->size);
    if(hash->table[key] == NULL)
    {
        return hash;
    } 
    else 
    {
        Node* current = hash->table[key];
        Node* prev = NULL;
        while(current != NULL && current->value != item)
        {
            prev = current;
            current = current->next;
        }
        
        if(current->next == NULL && prev == NULL)
        {
            hash->table[key] = NULL;
        }
        else
        {
            current = current->next;
        }
        free(current);
    }
    return hash;
}

int is_empty(Node* head)
{
    return head == NULL;
}

void print_list(Node* head)
{
    Node *current = head;
    while(current != NULL)
    {
        printf("%d ->", current->value);
        current = current->next;
    }
    printf(" -> \\n");
    return;
}

void printHash(ht* hash)
{
    int i
    ;
    for(i=0;i<hash->size;i++)
    {
        if(!is_empty(hash->table[i]))
        {
            printf(" %d",hash->table[i]);
            print_list(hash->table[i]);
        }
    }
    return;
}

Node *remove_list (Node *head)
{
    Node *current = head;
    while(head != NULL) 
    {
        current = head->next;
        free(head);
        head = current;
    }
}

ht* free_hash(ht* hash)
{
    int i;
    for(i=0;i<hash->size;i++)
    {
        if(!is_empty(hash->table[i]))
        {
            remove_list(hash->table[i]);
            hash->table[i] = NULL;
        }
    }
}

Node* insert_end(Node *head, int new_data)
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
    return head;
}

int key_res(int key, int size)
{
    return key % size;
}

ht *insert_hash(ht *hash, int item)
{
    int i;
    int key = key_res(item, hash->size);
    hash->table[key] = insert_end(hash->table[key],item);
    return hash;
}

int main()
{
    int a,n,i,j,k,n1;
    Node* head = NULL;

    scanf("%d",&a);

    for(i=0;i<a;i++)
    {
        scanf("%d %d",&n,&j);
        ht *hash = create_hash(n);
        for(k=0;k<j;k++)
        {
            scanf("%d",&n1);
            hash = insert_hash(hash,n1);
        }
        printHash(hash);
        //free_hash(hash);
    }
    return 0;
}