// Linked Listlerde kontrol ifadeleri, başa ve sona eleman ekleme , sondan eleman silme işlemleri 
#include <stdio.h>
#include <stdlib.h>

// Node Structı
struct node{
    int data;
    struct node *next;
};

// Linked Listin başındaki ve sonundaki eleman değerlerine NULL atıyoruz
struct node *head=NULL;
struct node *tail=NULL;

// Liste boş mu dolumu kontrol edilip sonrasında ona göre eleman ekleme işlemini gerçekleştiren fonksiyon
int addnode(int data){
    if (head==NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        head=tail=new;
    }
    else if(head!=NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        tail->next=new;
        tail=new;
    }
    return 0;
}

// Listenin başına eleman ekleme işlemini gerçekleştiren fonksiyon
int addnodehead(int data){ 
    if (head==NULL){
        struct node *new =(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        head=tail=new;
    }
    else if(head!=NULL){
        struct node *new=(struct node * )malloc(sizeof(struct node));
        new->data=data;
        new->next=head;
        head=new;
    }
    return 0;

}

// Listenin son elemanını silip silinen elemanın hafızadaki adresini serbest bırakan fonksiyon
int delete(int data ){
    struct node *prev;
    struct node *index=head
    if (head==NULL){
        printf("empty");
        return 0;
    }
    else if (head->data==data){
        struct node *start=head;
        head=head->next;
        free(start);
        }
    while (index!=NULL &&index->data!=data){
        prev=index;
        index=index->next;
        return 0;
    }
    if (index==NULL){
        printf("data not found");
        return 0;
    }
    prev->next=index->next;
    if(tail->data==data){
        tail=prev;
    }
    free(index);
    return 0;
}

// Liste elemanlarını yan yana yazdıran fonksiyon
int printlist(){
    struct node *start=head;
    while (start!=NULL){
        if (start->next!=NULL){
        printf("%3d - ",start->data);
        start=start->next;
        }
        else if (start->next==NULL){
        printf("%3d",start->data);
        start=start->next;
        }
    }
    printf("\n");
    return 0;
}
int main(){
    addnode(89);
    printlist();
    addnodehead(99);
    printlist();
    addnode(89);
    printlist();
    delete(99);
    printlist();
    addnodehead(100);
    printlist();
    addnode(0);
    printlist();
    return 0;
}
