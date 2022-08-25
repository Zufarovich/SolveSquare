#include <stdio.h>
#include <math.h>
#include "funcSS.h"
#include "testSolveSquare.h"


int main(void)
{
    double a = NAN,
           b = NAN,
           c = NAN,
           x1 = NAN,
           x2 = NAN;

    char ch = '\0';

    printf("Enter 1 to start unit test, 2 to enter your own square equation, or q to quit:\n");
    while ((ch = getchar()) != 'q')
    {
        rewind(stdin);
        if (ch == '\n')
            continue;
        if (ch == '1')
        {
            UnitTest();
        }
        else if (ch == '2')
        {
            printf("Enter rates a, b and c:\n");
            while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
            {
                printf("You entered incorrect values!\n");
                printf("Enter 3 real numbers:\n");
                rewind(stdin);
            }
            int roots = SolveSquare( a, b, c, &x1, &x2);
            printRoots(roots, x1, x2);
        }
        else
        {
            printf("You entered incorrect value\n");
            printf("Try again\n");
        }
        printf("Enter 1 to start unit test, 2 to enter your own square equation, or q to quit:\n");
    }
    return 0;
}

