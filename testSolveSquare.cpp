#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "funcSolveSquare.h"
#include "testSolveSquare.h"

int UnitTest(void)
{
    struct testData pack1[] = {
     {.amount = 2,          .a = 1, .b = 0, .c = -1},
     {.amount = 0,          .a = 1, .b = 0, .c =  1},
     {.amount = _INF_ROOTS, .a = 0, .b = 0, .c =  0},
     {.amount = 1,          .a = 1, .b = 2, .c =  1},
     {.amount = 2,          .a = 5, .b = 6, .c = -6},
     {.amount = 1,          .a = 0, .b = 1, .c = -9}
    };

    printf("Test 1\n");

    int numOfTests = sizeof(pack1) / sizeof(pack1[0]);

    for (int i = 0; i < numOfTests; i++)
        testSolveSquare1(&pack1[i]);

    FILE* file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("File doesn't opened");
        return ERROR_OPEN_FILE;
    }

    struct testData pack2 = {};

    printf("Test 2\n"); 

    while (true)
    {
        int ret = fscanf(file, "%d %lf %lf %lf", &pack2.amount, &pack2.a, &pack2.b, &pack2.c);

        if (ret != 4)
            break;

        testSolveSquare1(&pack2);
    }

    fclose(file);

    return 0;
}

void testSolveSquare1(const struct testData *test)
{
    double root1 = NAN,
           root2 = NAN;

    bool success = false;

    int val = SolveSquare(test->a, test->b, test->c, &root1, &root2);

    if (val == test->amount)
    {
        double solCheck1 = test->a*root1*root1 + test->b*root1 + test->c;
        double solCheck2 = test->a*root2*root2 + test->b*root2 + test->c;

        switch (test->amount)
        {
            case 0:
                success = true;
                break;

            case 1:
                success = (isZero(solCheck1));
                break;

            case 2:
                success = (isZero(solCheck1) && isZero(solCheck2));
                break;

            case _INF_ROOTS:
                success = true;
                break;

            default:
                success = false;
                break;
        }
    }
    else
    {
        success = false;
    }
    if (success)
    {
        printf("Unit Test       Success\n");
    }
    else
    {
        printf("Unit Test       Failed\n");
        printf("Coeficients a = %.2lf, b = %.2lf, c  = %.2lf\n", test->a, test->b, test->c);
        printf("Actual amount of roots %d\n", test->amount);
        printf("Amount of roots that returned function %d\n", val);
        printf("This roots x1 = %.4lf     x2 = %.4lf\n", root1, root2);
    }
}

