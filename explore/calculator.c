#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void printMenu();
double division(double, double);
double modulus(int, int);

int main(){
  int choice;
  double result,first, second;
  while (1) {
    printMenu();
    printf("Enter the choice: ");
    scanf("%d",&choice);
    if (choice == 7){
      break;
    }

    else if(choice <1 ||  choice>7){
      printf("Choose between 1-7\n");
      continue;
    }

    
    printf("Enter the First Element: ");
    scanf("%lf",&first);
    printf("Enter the Second Element: ");
    scanf("%lf",&second);
    switch (choice) {
      case 1:
        result = first+second;
        break;
      case 2:
        result = first-second;
        break;
      case 3:
        result = first*second;
        break;

      case 4:
        result = division(first,second);
        break;

      case 5:
        result = modulus((int)first, (int)second);
        break;

      case 6:
        result = pow(first,second);
        break;
      default:
        break;
      }

    printf("Result of The operation %.2f \n\n",result);
  };
  return 0;
}

double division(double f,double s){
  if (s == 0){
    fprintf(stderr, "You cannot divide by the 0\n");
    return NAN;
  }
  else{
    return f/s;
  }
}

double modulus(int f, int s){
  if(s==0){
    fprintf(stderr, "You cannot modulus with 0\n");
    return NAN;
  }

  else{
    return f%s;
  }
}

void printMenu(){
  printf("Welcome to Simple Calculator: \n\n");
  printf("Choose one of the following : \n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("5. Modulus\n");
  printf("6. Power\n");
  printf("7. Exit\n");
}
