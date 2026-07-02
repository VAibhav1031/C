#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]){

    // basic parsing it is working here 
   if(argc!=3){
        fprintf(stderr,"Usage: %s <signal number> <pid>\n",argv[0]);
        return 1;
   } 

   int signal_number = atoi(argv[1]);
   pid_t pid = atoi(argv[2]);


   if (signal_number <= 0){
        fprintf(stderr,"Invalid signal number: %d\n",signal_number);
        return 1;
   }

   if (kill(pid, signal_number) == -1 )
    {
        perror("Error Sending signal");
        return 1;
    }
   return 0;
}
