#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
 size_t count;
 size_t capacity;
}Header;

// int *arr_init(int init_capacity){
//
//     // [header][numbers]
//     //         ^
//     //         data
//     Header  *header = malloc(sizeof(int)*init_capacity + sizeof(Header)); // we need to havce the one memory block foir the header which has the all the metadata related to the things  
//     header->count = 0;
//     header->capacity = init_capacity;
//     return (int *)(header +  1); 
//
// }


// void arr_push(int *arr, int x){
//    // to push we need to update the metadata thing also 
//     // [header][numbers]
//     // ^
//     // data
//
//     // why casting here , i would tell you brtother , reason is very simple you have alrady allocated that memory block anbd that is being interpreted using Header type , and then  we are accessing it again we have to type cast it again so that we can  easily interpret  that memory block without any problem  i would say 
//     Header *header = ((Header *)arr)-1; // it is not giving me to the right memory address pointer , i am unable to ge tthe thing ansd assert get failed 
//     assert(header->count < header->capacity);
//     arr[header->count++] = x;
// }


//--------------------------------------------------------------------------------------------------------------------------------------
// above was  a initial  approach of data shadowing i would say so , which we can do a little better in the macros , and even we can shadow the arr_init thing , which is included in the arr_push , to make it more shadowed approach and you just go with the initialized the arra with NULL and use the arr_push to do a thing , else things is just packed there 
// ------------------------------------------------------------------------------------------------------------------------------------


#define ARR_INIT_CAPACITY 4

// currently we are using is the  curly braces for the creation of the scope , whichis good for defining the htings and  working way better than we thought as other way if we say so ,  but the thing is that it is being the pre
// processor which replace tghat  arr_push thing usage with this curly base scope , if we uyse the thing whiuchis not a problem but if we use that thing normally like programming other way , if  else block ,  we would use the ; semi-colon but since it is being the curly braces  which is the syntatic error , most of the time we rarely know about thathting 
//
// we can make thing out of this by using the  do and while  in the  macros of these type where curly braces are used 
#define arr_push(arr, x)\
    do {\
     Header *header;\
     if((arr) ==NULL){\   
                header = malloc(sizeof(*(arr))*ARR_INIT_CAPACITY + sizeof(Header));\
                if(!header) break;\
                header->count = 0;                                                          \
                header->capacity = ARR_INIT_CAPACITY;                                        \
                arr = (void *)(header +  1);                                                  \
        }\
     else{\
        header = ((Header *)(arr))-1;\ 
    }\
    if (header->count >= header->capacity){\
        size_t new_cap = header->capacity *2;\
        Header *new_header = realloc(header, sizeof(*(arr))*header->capacity + sizeof(Header));\
        if (!new_header) break;\
        header = new_header;\
        header->capacity = new_cap;\
        arr = (void *)(header + 1);\
    }\
    else{\
        header = ((Header *)(arr)) - 1;\
    }\
    (arr)[header->count++] = (x);            \
    } while(0) \
    // it will go only one go with false 0\

// there is a thing in the macros while defining the thing like function the parameter mostly  used in the parens () inside the functiohn 

// upper in the arr_push macro you have seen  void pointer casting while assigning things to the variable 'arr' which is kind of making it to work witrh any other  tye then particular int type , must to understand 
#define arr_len(arr) (((Header*)(arr))-1)->count

#define arr_free(arr) free(((Header*)(arr) -1))


int main(){

    // int *numbers  = arr_init(256);
    int *numbers = NULL;
    arr_push(numbers, 33);
    arr_push(numbers, 123);
    arr_push(numbers, 563);
    arr_push(numbers, 873);
    arr_push(numbers, 9873);

    for(size_t i =0; i< arr_len(numbers); ++i){

        printf("%d\n",numbers[i]);
    }


    // we cant make the free statement directly onthe *numbers array we have to know the headers which was allocated toegther, since these things are already  shadowed from using here if you see soo 
    
    arr_free(numbers);
}
