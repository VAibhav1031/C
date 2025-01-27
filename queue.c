/*queue*/
#include <stdio.h>
#include <stdlib.h>

#define size 10


void enqueue(int arr[],int  *rear, int *front, int value){
  if(*rear== size -1){
    printf("   The queue is  full !!! \n");
    return;
  }
  
  if(*front == -1 && *rear == -1){
    *front = *rear = 0; // if  queue is empty and both pointer are at -1 then there should  start with 0  position and then only rear will move  and add element in enqueue operation 

  }
  else{
    (*rear)++;
  } 
  arr[*rear] = value;
  printf("Enqueued the element %d\n",arr[*rear]);

}

void dequeue(int arr[], int *rear, int *front){
  if(*front == -1 || *front > *rear){
    printf("   Queue is  already Empty !!!\n");
    *rear = -1;
    *front = -1;
    return;
  }
  
  printf("Dequeued the Element %d\n",arr[*front]);
  (*front)++;

}

void printQueue(int arr[], int rear ,int front){
  if (front == -1 || front>rear){
    printf("  Queue is already Empty !!!\n");
    return;
  }
  
  printf("\n>>>>> Printing the Queue : \n");
  printf("     [");
  for(int i= front;i<=rear;i++){
    printf("   %d  " ,arr[i]); 
  }
  printf("]");
}
int main(){
  int arr[size];
  int rear ,front ;
  rear = front = -1;
  
  dequeue(arr, &rear, &front);
  enqueue(arr, &rear, &front, 8);
  enqueue(arr, &rear, &front, 10);
  enqueue(arr, &rear, &front, 14);

  dequeue(arr, &rear, &front);
  
  printQueue(arr, rear, front);


  return 0;

}
