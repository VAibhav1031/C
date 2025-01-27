#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
}Node;

Node *front = 0;
Node *rear = 0;

Node *createnode(int value){
  Node *newnode = (Node *)malloc(sizeof(Node *));

  if (!newnode){
    printf("MEmory allocation to the node Failed\n");
  }
  newnode->data = value;
  newnode->next = 0;

  return newnode;
}

void enqueue(int value){
  Node *newnode = createnode(value);
  if(front == 0 && rear ==0){
    rear=front = newnode;
    rear->next = front;
  }

  else{
    rear->next = newnode;
    rear = newnode;  // here we are incrementing the  rear  pointer to the newnode 
    rear->next = front;
  }

  printf("Enqueued element : %d\n", value);
}

void dequeue(){
  if  (rear == 0){
    printf("Circular queue is empty\n");
    return;
  }

  Node *temp = front;
  if (rear == front) {
    rear = front = 0;
  }

  else{
    front = front->next;
    rear->next = front;
  }
  printf("Dqueue element : %d\n",temp->data);
  free(temp);
}

void display(){
  Node *temp = front;
  printf(">>>> PRintintg the Circular Queue: \n"); 
  if (rear == 0){
    printf("Circular  queue is empty: \n");
    return;
  }
    

  do{
    printf("%d ->",temp->data);
    temp =temp->next;
  }while(temp!=rear->next);

  printf("NULL\n");
  
}

int main(){
  enqueue(8);
  enqueue(4);
  enqueue(12);

  display();
  
  dequeue();

  display();
  return 0;
}
