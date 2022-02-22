#include<cstddef>
#include <stdlib.h>
#include<stdio.h>

// struct is logical group/structure data with a single memory address
typedef struct Node{
    // data and next or struct fields
    int data;
    struct Node * next;
} NodeT;

NodeT *init(const int val){
    NodeT *newNode = (NodeT *)mallac(sizeof(NodeT));
    newNode->data = val;
    newNOde->next = NULL;
    return newNode;
}

NodeT *destroy(NodeT * node){
    NodeT *next = node->next;
    free(node);
    return next;
}

void append(NodeT **head, const int val){
    NodeT *nedNode = init(val);

    NodeT *last = *head;

    if(*head == NULL)
    {
        *head = newNode;
        return; 
    }

    while(last_>next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void print(NodeT**head){
    NodeT* last = *head;

    while(last_>next != NULL)
    {
        printf("%d\n", last->data);
        last = last->next;
    }
    printf("%d\n", last->data)''
}

int getnth(NodeT** head, const int idx){
    NodeT*last = *head;

    int count = 0;
    while(last->next != NULL){
        if(count == idx){
            return last->data;
        }
        last = last->next;
        count++;
    }
    return -1;
}
int main()
{
    //Constant Time O(1)
    //Linear Time O(N)
    //Exponential Time O(N^X)

    // A -> B -> C -> D -> C, will keep going from C to D

    NodeT * head = init(1);

    // memory head double pointer
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    // pointer of type int 
    // mallac a size of memory size int x the array length
    // mallac gives a void pointer, that gets cast to int type
    //int * arr = (int*)mallac(sizeof(int)*10);

    //free(arr);
}

void foo(){
    char *s = "hello world";
    char **s2;

    // double pointer char is a array or arrays, first is a array of char, second is strings
    s2[0] = "Hello World";
    s2[1] = "Goodbye";
}