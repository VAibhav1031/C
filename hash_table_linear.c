#include <stdio.h>
#include <stdlib.h>

#define size 10 

void hash_table(int arr[], int value){
  int index = value % size;
  if (arr[index]!=0){  //0 make thing like  if there is something else 0 means it is occupied by something hence collision
      //linear probing (trying)
    for(int i=0; i <= size ; i++){
      int ind = (index + i) % size;
      if (arr[ind] == 0){
        index =ind; // assigning the new  index where the position is empty   only it is when it is  collided else same (it is only if condition)
        // if there will be true means(collision) then it will go else no.
        break;
      }
    }
  }
  arr[index] = value;

}

int main(){
  int arr[size]= {0};


  hash_table(arr, 5);
  hash_table(arr, 8);
  hash_table(arr, 9);
  hash_table(arr, 19); //collision 9 index already occupied by 9 value
  
  
  for(int i  = 0;i<size;i++){
    printf(" %d ", arr[i]);
  }
  return 0;
  
}
