#include <cs50.h>
#include <stdio.h>
#include <helpers.h>

bool search(int value, int values[], int n)
{
 int low = 0;
 int high = n - 1;
 while(low <= high)
  {
    int mid = low + ((high-low)/2);
    if (value == values[mid])
        return true;
    else if (value < values[mid])
        high = mid -1;
    else if (value > values[mid]) 
        low = mid + 1; 
  }
 return false; 
}
	
void sort(int values[], int n)
{
 for(int i = 1; i < n; i++)
 {
    int valueToIn = values[i];
    int j = i-1;
    while((j >= 0) && (valueToIn < values[j]))
    {
        values[j+1] = values[j];
        j --;
    }
 values[j+1] = valueToIn; 
 }
 return; 
}
