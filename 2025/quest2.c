// Wayne Mack
// Everybody Codes
// Quest2
// Written in: C

#include <stdio.h>

struct Tuple {
    long long x;
    long long y;
    long long satisfiesBounds;                  
};
void add(long long* x1, long long* y1, long long *x2, long long *y2) {
    //printf("Adding %d , %d to %d , %d\n", *x1, *y1, *x2, *y2);
    *x1 = *x1 + *x2;
    *y1 = *y1 + *y2;
    return;
}

void multiply(long long* x1, long long* y1, long long* x2, long long* y2) {
    //printf("Multiplying %d , %d by %d , %d\n", *x1, *y1, *x2, *y2);
    long long tempX1 = *x1;
    long long tempY1 = *y1;
    long long tempX2 = *x2;
    long long tempY2 = *y2;   
    *x1 = (tempX1 * tempX2) - (tempY1 * tempY2);
    *y1 = (tempX1 * tempY2) + (tempY1 * tempX2);
    return;
}

void divide(long long* x1, long long* y1, long long x2, long long y2) {
    //printf("Dividing %d , %d by %d , %d\n", *x1, *y1, x2, y2);
    if (x2 == 0 || y2 == 0) {
        printf("Error: Division by zero\n");
        return;
    }
    *x1 = (*x1 / x2);
    *y1 = (*y1 / y2);
    return;
}

void computeCycle(long long* p1AnswerX, long long* p1AnswerY, long long *multX, long long *multY, long long divideX, long long divideY, long long addX, long long addY) {
    multiply(p1AnswerX,p1AnswerY , p1AnswerX, p1AnswerY);
    divide  (p1AnswerX, p1AnswerY, divideX, divideY);
    add     (p1AnswerX, p1AnswerY, &addX, &addY);
    return;
}

struct Tuple PartOne (long long p1AnswerX, long long p1AnswerY, long long addNumberx, long long addNumbery, long long divideNumber, long long numberOfCycles, long long bound) {
    long long withinBounds = 1;
    for (long long j = 0; j < numberOfCycles; j++) {
        computeCycle(&p1AnswerX, &p1AnswerY, &p1AnswerX, &p1AnswerY, divideNumber, divideNumber, addNumberx, addNumbery); 
        if ((p1AnswerX > bound || p1AnswerX < -bound  || p1AnswerY > bound || p1AnswerY < -bound)) {
            //printf(" - Out of bounds! %d %d ",p1AnswerX, p1AnswerY);
            withinBounds = 0;
            //printf("%d \n",withinBounds);
        }
    }
    struct Tuple T = {p1AnswerX, p1AnswerY,withinBounds};
    T.satisfiesBounds = withinBounds;
    return T;
}

long long partTwo(long long firstCornerX , long long firstCornerY, long long distanceX, long long distanceY,long long divideNumber,  long long numberOfCycles, long long bound, int steps) {
    long long count = 0;  
    long long lastCornerX = firstCornerX + distanceX;
    long long lastCornerY = firstCornerY + distanceY;
    for (long long x = firstCornerX; x <= lastCornerX; x+=steps) {
        for (long long y = firstCornerY; y <= lastCornerY; y+=steps) {
            struct Tuple P1 = PartOne(0, 0, x, y, divideNumber, numberOfCycles, bound);
            if (P1.satisfiesBounds == 1) {
                count++;
            }
        }
    }
    return count;
}

int main () {

    struct Tuple P1X = PartOne(0, 0, 25,9,10,3, 0);
    struct Tuple P1 = PartOne(0, 0, 141, 53, 10, 3, 0);
    printf("[%d,%d] - Example\n", P1X.x, P1X.y);
    printf("[%d,%d] - Part One\n", P1.x, P1.y);

    printf("%d - Part Two Sample\n", partTwo(35300, -64910, 1000, 1000, 100000, 100, 1000000 , 10 ));
    printf("%d - Part Two Puzzle\n", partTwo(-3354, -69783, 1000, 1000, 100000, 100, 1000000 , 10));
  
    printf("%d - Part Three Sample\n", partTwo(35300, -64910, 1000, 1000, 100000, 100, 1000000 , 1));
    printf("%d - Part Two Puzzle\n", partTwo(-3354, -69783, 1000, 1000, 100000, 100, 1000000 , 1));
    return 0;
}
