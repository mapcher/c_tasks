/*
Program draws a cartesian plane and put points on it.
Also it is possible to draw function graphs.
*/

#include <stdio.h>
#include <math.h>

int width = 110;        // width of the plane in pixels
int height = 30;        // height of the plane in pixels
float Xleft = -2;       // left limit of X
float Xright = 5;       // right limit of X
float Ytop = 2;         // top limit of Y
float Ybottom = -2;     // bottom limit of Y
char *arrayPointer;

int indexFromXY(int x, int y) {
    return width * y + x;
}

char *cellPointer(int x, int y) {
    return (arrayPointer + indexFromXY(x, y));
}

int printPlane() {
    for (int row = height - 1; row >= 0; row--) {// draw upside down because the screen's Y-axis goes down
        for (int column = 0; column < width; column++) {
            printf ("%C", *cellPointer(column, row));
        }
        printf ("\n");
    }
    return 0;
}

int initializePlane (){
    for (int row = 0; row < height; row++)
        for (int column = 0; column < width; column++)
            *cellPointer(column, row) = ' ';
    return 0;
}

int pixFromReal(float coord, float smallestCoord, float biggestCoord, int biggestPix) {
    return biggestPix * (coord - smallestCoord) / (biggestCoord - smallestCoord);
}

int XpixFromReal(float x) {
    return pixFromReal(x, Xleft, Xright, width);
}

int YpixFromReal(float y) {
    return pixFromReal(y, Ybottom, Ytop, height);
}

int drawPoint (float x, float y, char penType) {
    int column = XpixFromReal(x);
    int row = YpixFromReal(y);
    if (row < 0 || row >= height) return 1;			// out of screen
    if (column < 0 || column >= width)  return 1;			// out of screen
    
    *cellPointer(column, row) = penType;
    return 0;
}

int drawAxes () {
    int X = XpixFromReal(0);
    int Y = YpixFromReal(0);
    if (X >= 0 && X < width){
        for (int row = 0; row < height; row++)
            *cellPointer(X, row) = '|';
    }
    if (Y >= 0 && Y < height){
        for (int column = 0; column < width; column++)
            *cellPointer(column, Y) = '-';
    }
    if (Y >= 0 && Y < height && X >= 0 && X < width){
        *cellPointer(X, Y) = '+';
    }
    return 0;
}

int drawSin (float A,float B,float C,float D){
    float pixel=(Xright-Xleft)/width;
    for (float x = Xleft; x < Xright; x += pixel){
        float y =A * sin(B * x + C) +D;
        drawPoint (x, y, '>');
    }
    return 0;   
}

int main (){
    char plane[width * height];
    arrayPointer = plane;
    initializePlane ();
    drawAxes ();
    
    drawPoint (0, 0, '0');
    drawPoint (0, 1, 'A');
    drawPoint (0, -1, 'V');
    drawPoint (1, 0, '>');
    drawPoint (-1, 0, '<');
    drawPoint (1, 1, 'q');
    drawPoint (-1, -1, 'b');
    drawPoint (1, -1, 'd');
    drawPoint (-1, 1, 'p');
    drawSin (1, 3, 1, 1);
    drawSin (1.5, 0.7, 0, 0);

    printPlane ();
    return 0;
}





