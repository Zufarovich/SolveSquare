#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "funcSS.h"
#include "testSolveSquare.h"

const double around0 = 1e-5;
const int _INF_ROOTS = -1;

struct testData{
    int amount;
    double a;
    double b;
    double c;
};

void UnitTest(void)
{
    struct testData pack1[] = {
     {.amount = 2, .a = 1, .b = 0, .c = -1},
     {.amount = 0, .a = 1, .b = 0, .c = 1},
     {.amount = _INF_ROOTS, .a = 0, .b = 0, .c = 0},
     {.amount = 1, .a = 1, .b = 2, .c = 1},
     {.amount = 2, .a = 5, .b = 6, .c = -6},
     {.amount = 1, .a = 0, .b = 1, .c = -9}
    };

    printf("Test 1\n");

    int numOfTests = sizeof(pack1) / sizeof(pack1[0]);

    for (int i = 0; i < numOfTests; i++)
        testSolveSquare(pack1[i].amount, pack1[i].a, pack1[i].b, pack1[i].c);

    printf("Test 2\n");

    FILE* file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("File doesn't opened");
        abort();
    }

    double data[4];

    int ret = 4;

    while (true)
    {
        ret = fscanf(file, "%lf %lf %lf %lf", &data[0], &data[1], &data[2], &data[3]);

        if (ret != EOF && ret == 4)
            testSolveSquare(data[0], data[1], data[2], data[3]);
        else
            break;
    }

    fclose(file);
}
void testSolveSquare(int amount, double a, double b, double c)
{
    double r1 = NAN,
           r2 = NAN;

    bool success = false;

    int val = SolveSquare(a, b, c, &r1, &r2);

    if (val == amount)
    {
        double solCheck1 = a*r1*r1 + b*r1 + c;
        double solCheck2 = a*r2*r2 + b*r2 + c;

        switch (amount)
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
        printf("Coeficients a = %.2lf, b = %.2lf, c  = %.2lf\n", a, b, c);
        printf("Actual amount of roots %d\n", amount);
        printf("Amount of roots that returned function %d\n", val);
        printf("This roots x1 = %.4lf     x2 = %.4lf\n", r1, r2);
    }
}
