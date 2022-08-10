#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 32; i < 127; i++)
    {
        printf("%c = %d \n", i, i);
    }

    return 0;
}
