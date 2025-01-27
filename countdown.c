/* countdown.c */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){

  int number, i;
  printf("Enter the number: ");
  fflush(stdout);
  scanf("%d", &number);

  i=number;
  while (i>=0){
    printf("The value is the %d\n",i);
    sleep(1);
  
    i=i-1;
  }


  int n =  10;
  /* this  is    differernt  way cuz  i am loving this  moment  its  not  focused one */
  while(n){
    printf("*");
    fflush(stdout); 

    sleep(1);

    n--;
       
  }
  printf("\n");
  number = 8;
  while(1){
    number--;
    if (number ==3){
      continue;
    }
    printf("%d\n",number);
    sleep(1) ;
    if (number <=0){
      break;
    }
    

  }

  return 0;
}

