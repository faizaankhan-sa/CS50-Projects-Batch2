#include <stdio.h>
#include <cs50.h>

void bobthebuilder(int h)
{
    for (int x = 0; x < h; x++)
    {
        for (int y = h - x; y > 1; y--)
        {
            printf(" ");
        }
        for (int z = 0; z <= x; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    int h;
    do
    {
        h = get_int("How tall would you like the pyramid to be: ");
    }
    while (h < 1 || h > 8);
    bobthebuilder(h);
}
