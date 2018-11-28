#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, string argv[])
 {
 if (argc != 2)
  {
    printf("Nope\n");
    return 1;
  }
 

 int k = atoi(argv[1]);


 if (k < 0)
  {
    printf("Nope\n");
    return 1;
  }
 else
 {
    printf("plaintext:");
    string cipher = GetString();
 
    printf("ciphertext:");
    for (int i = 0, n = strlen(cipher); i < n; i++)
        {

        if islower(cipher[i])
            printf("%c", (((cipher[i] + k) - 97) % 26) + 97);
        else if isupper(cipher[i])
            printf("%c", (((cipher[i] + k) - 65) % 26) + 65);
        else
            printf("%c", cipher[i]);
        }
 printf("\n");
 return 0;
  }
 }
