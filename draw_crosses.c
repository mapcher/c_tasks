/*
Exercise 1
Develop a program that would draw the shown figures,
using WHILE loop.

    *                                                                                                                   
    *                                                                                                                   
    *                                                                                                                   
    *                                                                                                                   
*********                                                                                                               
    *                                                                                                                   
    *                                                                                                                   
    *                                                                                                                   
    *                                                                                                                   
*       *                                                                                                               
 *     *                                                                                                                
  *   *                                                                                                                 
   * *                                                                                                                  
    *                                                                                                                   
   * *                                                                                                                  
  *   *                                                                                                                 
 *     *                                                                                                                
*       *

The size of the figures should be variable.
*/

#include <stdio.h>

int draw_cross(int size) {
    int row = 0; 
    while (row < size) {
        printf("\n");
        int col = 0;
        while (col < size) {
            if (row == size / 2 || col == size / 2) {
                printf("*");
            } else {
                printf(" ");
            }
            col++;
        }
        row++;
    }
}

int draw_x(int size) {
    int row = 0; 
    while (row < size) {
        printf("\n");
        int col = 0;
        while (col < size) {
            if (row == col || row + col == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
            col++;
        }
        row++;
    }
}

int main() {
    int size;
    printf("Size: ");
    scanf("%d", &size);
    
    draw_cross(size);
    printf("\n");
    draw_x(size);
    
    return 0;
}

