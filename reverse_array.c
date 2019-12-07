/*
Exercise 1
Develop a program that would read the size of an array,
create the array, request the user for the values of the elements,
and reverse the array.

Example:
Enter Array size: 4                                                                                                   
Enter Array elements: 1 2 3 4                                                                                         
>> 4 3 2 1
*/

#include <stdio.h>

int main(){
    int size;
    printf("Enter Array size: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter Array elements: ");
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    
    int last_index = size - 1;
    for (int i = 0; i < size / 2; i++){
        int temp = array[i];
        array[i] = array[last_index - i];
        array[last_index - i] = temp;
    }
    
    printf(">> ");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}
