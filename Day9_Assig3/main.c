#include<stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main()
{
   float area_circle = Calculate_areaofCircle(6);
   printf("Area of Circle: %.2f\n", area_circle);

   float area_square = Calculate_areaofSquare(5);
   printf("Arera of Square: %.2f\n", area_square);

   float area_rectangle = Calculate_areaofRectangle(2,4);
   printf("Area of Rectangle: %.2\n", area_rectangle);

 return 0;
}
