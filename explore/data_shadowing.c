#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
 size_t count;
 size_t capacity;
}Header;


int *arr_init(int init_capacity){
    
    // [header][numbers]
    //         ^
    //         data
    Header  *header = malloc(sizeof(int)*init_capacity + sizeof(Header)); // we need to havce the one memory block foir the header which has the all the metadata related to the things  
    header->count = 0;
    header->capacity = init_capacity;
    return (int *)(header +  1); 

}


void arr_push(int *arr, int x){
   // to push we need to update the metadata thing also 
    // [header][numbers]
    // ^
    // data
   
    // why casting here , i would tell you brtother , reason is very simple you have alrady allocated that memory block anbd that is being interpreted using Header type , and then  we are accessing it again we have to type cast it again so that we can  easily interpret  that memory block without any problem  i would say 
    Header *header = ((Header *)arr)-1; // it is not giving me to the right memory address pointer , i am unable to ge tthe thing ansd assert get failed 
    assert(header->count < header->capacity);
    arr[header->count++] = x;
}

int arr_len(int *arr){

    return ((Header*)arr-1)->count;
}
int main(){
        

    int *numbers  = arr_init(256);
    arr_push(numbers, 33);
    arr_push(numbers, 123);
    arr_push(numbers, 563);
    arr_push(numbers, 873);


    for(size_t i =0; i< arr_len(numbers) ; ++i){

        printf("%d\n",numbers[i]);
    }
}
