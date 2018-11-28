#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
 int returned = 0;
 int kst = round(change * 100);
 
 printf("kiko vidati? \n");
 float change = GetFloat();

 while (change < 0) {
 printf("kiko vidati? \n");
 change = GetFloat();
 }
 
 while (kst > 0) {
 if ((kst - 25) >= 0) { kst = kst - 25; returned++; }
 else if ((kst - 10) >= 0){ kst = kst - 10; returned++;}
 else if ((kst - 5) >= 0) { kst = kst - 5; returned++; }
 else if ((kst - 1) >= 0) { kst = kst - 1; returned++; }
 }
 
 printf("%d\n", returned);
}
