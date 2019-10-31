#include <stdio.h>

long add(long a, long b)
{
        long c = a+b;
        return c;
}

long subtract(long a, long b)
{
        long c = a-b;
        return c;
}

int main()
{
        long operation;
        long a;
        long b;
        long result;

        printf("Select an operation: \n1:add \n2:subtract %s\n", operation);
        printf("Enter your first number: %s\n", a);
        printf("Enter your second number: %s\n", b);

        if(operation == 1)
                result = add(a,b);
        else if(operation == 2)
                result = subtract(a,b);
        else
                printf("\ninvalid operation");

        printf("result: %d", result);

        return 0;
}

