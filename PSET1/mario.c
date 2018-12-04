#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int h;

   
    do
    {
        printf("height ");
        h = GetInt();
    }
    while (h < 0 || h > 23);


    for (int l = 0; l < h; l++)
    {
        for (int s = h - l; s > 1; s--)
        {
            printf(" ");
        }
        for (int hash = 0; hash < l + 2; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
