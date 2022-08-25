#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cassert>
#include "funcSolveSquare.h"
#include "testSolveSquare.h"

const double around0 = 1e-5;
const int _INF_ROOTS = -1;

void printRoots(int amount, double root1, double root2)
{
    switch (amount)
    {
        case _INF_ROOTS:
            printf("a = 0, b = 0 and c = 0 there's infinity ammount of roots\n");
            break;

        case 0:
            printf("This equation has no roots\n");
            break;

        case 1:
            printf("This equation has 1 root:x = %.2lf\n", root1);
            break;

        case 2:
            printf("This equation has 2 roots:x1 = %.2lf x2 = %.2lf\n", root1, root2);
            break;

        default:
            printf("Incorrect valid roots\n");
            break;
    }
}



int SolveSquare(double a, double b, double c, double *r1, double *r2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(r1 != NULL);
    assert(r2 != NULL);
    assert(r1 != r2);

    if (isZero(a))
        return SolveLinear(b, c, r1);

    double discr = b*b - 4*a*c;
    double a2 = 2*a;

    if (isZero(discr))
    {
        *r1 = -b / a2;
        return 1;
    }
    else if (discr > 0)
    {
        double sqrt_discr = sqrt(discr);
        *r1 = (-b - sqrt_discr) / a2;
        *r2 = (-b + sqrt_discr) / a2;
        return 2;
    }
    else
        return 0;
}

int SolveLinear(double b, double c, double *r1)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(r1 != NULL);

    if (isZero(b))
    {
        if (isZero(c))
            return _INF_ROOTS;
        else
            return 0;
    }
    else
    {
        *r1 = -c / b;
        return 1;
    }
}

bool isZero(double rate)
{
    return fabs(rate) < around0;
}
