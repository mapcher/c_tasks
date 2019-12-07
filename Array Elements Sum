/*
Exercise 2

Develop a program that would read the size of an array,
create the array, request the user for the values of the elements,
and find the sum of all the elements, using RECURSION.

Example:

Enter Array size: 4                                                                                                   
Enter Array elements: 1 2 3 4                                                                                         
>> Array elements sum: 10.
*/

#include <stdio.h>

int sum(int array[], int size){
    if (1==size) return array[0];
    return sum(array, size - 1) + array[size - 1];
}

int main(){
    int size;
    printf("Enter Array size: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter Array elements: ");
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    
    printf(">> Array elements sum: %d.", sum(array, size));
    
    return 0;
}

