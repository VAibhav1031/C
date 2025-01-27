/* Dice game */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
  /* you play a dice roll game where you place a bet this number will come on the dice
   dice has 1-6 number on it .  if you win  the bet . You  triple your bet else you loose
   what you bet*/
  
  int tot_money,dice_b;
  int bet;
  //srand(getpid());
  srand(time(NULL));
  printf("Enter the purse amount:");
  scanf("%d",&tot_money);

  while(1){
    
    if (tot_money <=0) {
      printf("You have no money Left !!!\n\n Leave!!!!");
      printf("\n ---------GAME OVER-------");
      break;

    }

    printf("Your Total money : %d \n\n", tot_money);

    printf("Your Bet on Dice(1-6) number : ");
    scanf("%d",&dice_b);

    if (dice_b<1 || dice_b>6 ){
      printf("Invalid Dice number !! Please bet on a number between 1 and 6. \n\n");
      continue;
    }
    
    printf("Money to bet on {%d} ", dice_b);
    scanf("%d",&bet);


    if (bet > tot_money || bet<=0){
      printf("Invalid bet amount !! You have : %d. \n\n",tot_money);
      continue;
    }
    
    int dice = rand() % 6 + 1;

    if (dice == dice_b){
      printf("You won !!, The bet \n\n");
      tot_money+=3*bet;
    }

    else {
      printf("You loose!! :( \n Dice  is : %d\n", dice);
      printf("You lost this round, but don't give up! Keep trying!\n");
      tot_money -= bet;
    }

  }

  return 0;
}
