#include <stdio.h> // input , output işlemleri için
#include <stdlib.h> //malloc , free işlemleri için

// Queue Node 
struct node{
    int data;
    struct node *next;
};

// Front and Rear 
struct node *front=NULL;
struct node *rear=NULL;

// Enqueue
int enqueue(int data){
    // Queue is empty
    if (front==NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        front=new;
        rear=new;    
    }
    // Queue is not empty
    else{
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        rear->next=new; 
        rear=new;
    }
    return 0;
}

// Display Queue
int display(){
    // Queue is empty
    if (front==NULL){
        printf("Queue is empty\n");
        return 0;
    }

    struct node *index=front;

    while (index!=NULL){
        printf("%d - ",index->data);
        index=index->next;
    } 
    return 0;
}

// main func
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    return 0;
}
