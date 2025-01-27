/* circular Queue*/ 

#include <stdio.h>
#include <stdlib.h>


#define size  5

void enqueue(int cqueue[], int *rear, int *front, int value){
  if ((*rear+1)%size == *front ){
    printf("Queue is full !! \n");
    return;
  }

  else if(*rear == -1 && *front == -1){
    *rear = *front =0;
    cqueue[*rear]=value;
    printf("Enqueued the element : %d \n", cqueue[*rear]);
  }

  else{
    *rear = (*rear + 1)% size;

     cqueue[*rear] = value;
    printf("Enqueued the element : %d\n",cqueue[*rear]);
  }
}

void dequeue(int cqueue[], int *rear, int *front){
  if(*rear == -1 && *front == -1){
    printf("Queue is Already empty !!\n");
    return;
  }

  else if(*rear == *front){
    printf("The dequeued element* : %d\n", cqueue[*front]);
    *front = *rear = -1;
  }

  else{
    printf("The dequeued element : %d \n", cqueue[*front]);
    *front =(*front +1) %size;
  }
}


void printQueue(int cqueue[], int rear, int front){
  int i = front;
  printf("\n>>>>Printing the Circular Queue : \n");
  if (rear == -1 && front == -1){
    printf("Queue is already empty : \n");
    return;
  }

  else{
    do {
      printf("   %d  ",cqueue[i]);
      i = (i+1) % size;
    }while(i!= (rear +1 ) %size);
    
    printf("\n");
  }
}

int main (){
  int cqueue[size];
  int rear, front;
  rear = front = -1;


  
  enqueue(cqueue, &rear, &front, 8);
  enqueue(cqueue, &rear, &front, 12);

  enqueue(cqueue, &rear, &front, 21);
  enqueue(cqueue, &rear, &front, 4);
  enqueue(cqueue, &rear, &front, 15);


  printQueue(cqueue, rear, front);


  dequeue(cqueue, &rear, &front);
  dequeue(cqueue, &rear, &front);
  
  printQueue(cqueue, rear, front);

  enqueue(cqueue, &rear, &front, 32);
  enqueue(cqueue, &rear, &front, 42);

  printQueue(cqueue, rear, front);

  return 0;
}
