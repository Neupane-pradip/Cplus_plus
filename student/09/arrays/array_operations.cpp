#include "array_operations.hh"


int greatest_v1(int *itemptr, int size)
{
    int greatest = *itemptr;

       for (int i = 0; i < size; i++)
       {
           int current = *(itemptr + i);
           if (current > greatest)
           {
               greatest = current;
           }

       }
       return greatest;
}

int greatest_v2(int *itemptr, int *endptr)
{

}

void copy(int *itemptr, int *endptr, int *targetptr)
{

}

void reverse(int *leftptr, int *rightptr)
{

}
