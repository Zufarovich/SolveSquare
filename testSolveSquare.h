struct testData
{
    int amount;
    double a;
    double b;
    double c;
};

/**
* UnitTest
* This function uses test data to test function SolveSquare.
*/

int UnitTest(void);

/**
* testSolveSquare1
* This function accepts pointer to struct testData to check function SolveSquare
* Then it checks whether function SolveSquare returns correct number of roots and their value.
* @param const struct testData *test - pointer to struct testData
* @return ERROR_OPEN_FILE if file with data didn't opened or 0 if test completed successfully
*/

void testSolveSquare1(const struct testData *test);
