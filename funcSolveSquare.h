/**
* SolveSquare
* This function returns ammount of roots and changes values of 2 variables (roots)
* It accepts 3 rates in equation (a, b, c) and 2 pointers to roots
* @param double a - first rate in square equation
* @param double b - second rate in squre equation
* @param double c - third rate  in squre equation
* @param *r1 - adress of first root
* @param *r2 - adress of second root
* @return ammount of roots
*/

int SolveSquare(double a, double b, double c, double *r1, double *r2);

/**
* SolveLinear
* This function returns ammount of roots and changes value of variable (root)
* It accepts 2 rates in equation (b, c) and pointer to root
* @param double b - first rate in square equation
* @param double c - second rate in equation
* @param*r1 - adress of root
* @return ammount of roots
*/

int SolveLinear(double b, double c, double *r1);



/**
* printRoots
* This function accepts amount of roots and their values.
* Then it prints it.
* @param int amount - amount of roots
* @param double root1 - value of first root
* @param double root2 - value of second root
*/

void printRoots(int amount, double root1, double root2);



/**
* isZero
* This function checks is your number differ from 0 less than 1e-5 or not.
* @param double rate - number that you want to check
* @return true if your number differ from 0 less than 1e-5, else false
*/

bool isZero(double rate);
