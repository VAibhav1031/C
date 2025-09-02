/* Stack.c */ 
#include <stdio.h>
#include <stdlib.h>

/*  we  have  to  make  the  stack full working where we have  to  push function, pop function , condition of  overflow and underflow also rectify */

#define  size 13

void push(int arr[],int *top, int value){
  if (*top == size - 1){
      printf("   Overeflow !!! \n\n");
      printf(" --Can't push element %d\n\n",value);
      return;
  }

  (*top)++;
  arr[*top] = value;
  printf(" Pushed element %d\n",value);
}

void pop(int arr[],int *top){
  if (*top == - 1){
      printf("Underflow !!!\n");
      return;
  }

  printf("Popping the element: %d\n",arr[*top]);
  (*top)--;
}


void printStack(int arr[], int *top){
  if (*top == -1){
    printf("Stack is empty");
    return;
  }
  printf("\nPrinting The Elements : \n");
  for(int i = *top;i>=0;i--){
    printf(" |   %d   |\n",arr[i]);
      
  } 
  printf("\n");
}

int main(){
  int arr[size];
  int top = -1;

  push(arr,&top,8);
  push(arr,&top,18);
  push(arr,&top,11);
  push(arr,&top,3);
  push(arr,&top,4);
  push(arr,&top,1);
  push(arr,&top,5);
  push(arr,&top,9);
  push(arr,&top,42);
  push(arr,&top,32);
  push(arr,&top,12);
  push(arr,&top,13);
  push(arr,&top,15);
  push(arr,&top,88);
  


  pop(arr,&top);

  push(arr, &top, 24);


  printStack(arr,&top);

  
   
  return 0;

}
