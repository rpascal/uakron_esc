#define size 10

#include <stdio.h>


/*
    Generate an array of values for y based on inputs
*/
void runFilter(float alpha, float beta)
{
    float x[size] = {[0 ...(size - 1)] = 1}; // = {1};
    float y[size] = {0};
    float w[size] = {0};

    for (int i = 2; i < size; i++)
    {
        w[i] = x[i] + alpha * w[i - 1] + beta * w[i - 2];
        y[i] = w[i] + 2 * w[i - 2] + w[i - 2];
    }

    for (int i = 0; i < size; i++)
    {
        printf("y[%d] = %f ", i, y[i]);
        if ((i + 1) % 5 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");
}

void option2()
{
    // Hd1 orignal values
    printf("Hd1 orignal values: 1.981, 0.98155\n");
    runFilter(1.981, 0.98155);

    // Hd1 approximated values
    printf("Hd1 approximated values: 1.9844, 0.98438\n");
    runFilter(1.9844, 0.98438);

    // Hd2 orignal values
    printf("Hd2 orignal values: 1.9554, 0.95603\n");
    runFilter(1.9554, 0.95603);

    // Hd2 approximated values
    printf("Hd2 approximated values: 1.9531, 0.95312\n");
    runFilter(1.9531, 0.95312);
}

/*
    Both equations for Hd1 and Hd2 are the same
    except for the coeffients.
*/
float calcY(float x,
            float wk,
            float wk1,
            float wk2,
            float alpha,
            float beta)
{
    float w = x + alpha * wk1 + beta * wk2;
    return w + 2 * wk1 + wk2;
}

void option1()
{
    float x = 0;
    float wk = 0;
    float wk1 = 0;
    float wk2 = 0;

    // Y calculated from Hd1 with actual values
    float yHd1Actual = calcY(x, wk, wk1, wk2, 1.981, 0.98155);
    printf("yHd1Actual = %f ", yHd1Actual);

    // Y calculated from Hd1 with approximated values
    float yHd1Approximated = calcY(x, wk, wk1, wk2, 1.9844, 0.98438);
    printf("yHd1Approximated = %f ", yHd1Approximated);

    // Y calculated from Hd1 with actual values
    float yHd2Actual = calcY(x, wk, wk1, wk2, 1.9554, 0.95603);
    printf("yHd2Actual = %f ", yHd2Actual);

    // Y calculated from Hd1 with approximated values
    float yHd2Approximated = calcY(x, wk, wk1, wk2, 1.9531, 0.95312);
    printf("yHd2Approximated = %f ", yHd2Approximated);
}

void main()
{
    // Option 1
    option1();

    // Option 2
    option2();
}
