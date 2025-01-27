#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

int main(){
  srand(time(NULL));
  int guess, i=0;
  int var = 1+rand()%100;
  while(true){
    printf("Welcome to the World Of Guessing Number :");
    scanf("%d",&guess);
  
    if (guess<var){
      printf("Guess a larger number\n\n");
    }

    else if(guess>var){
      printf("Guess a smaller number\n\n");
    }

    else if(guess == var){
      printf("\nCongratulations !!!You have successfully guessed the number in %d guess\n",i);
      printf("Bye Bye, Thanks for playing.\nDeveloped by: $necromancer");
      break;
    }
    i++;
  }


}
