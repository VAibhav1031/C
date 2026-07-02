#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void catch_int(int sig_num){
    
    // signal(SIGINT, catch_int);
    char *write_thing = "Dont Do that\n";
    write(1,write_thing,strlen(write_thing));

    fflush(stdout);

}

int main(int argc, char* argv[]){

    signal(SIGINT,catch_int);

    for (;;){
        pause();
    }

    return 0; 
}
