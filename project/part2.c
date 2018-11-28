#define size 10

#include <stdio.h>

void runFilter(float alpha, float beta)
{
    float x[size] = {[0 ...(size - 1)] = 1}; // = {1};
    float y[size] = {0};
    float w[size] = {0};

    for (int i = 2; i < size; i++)
    {
        // w[i] = (i-2) + alpha * w[i - 1] + beta * w[i - 2];
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

void main()
{

    printf("Hd1 orignal values: 1.981, 0.98155\n");
    // Hd1 orignal values
    runFilter(1.981, 0.98155);

    printf("Hd1 approximated values: 1.9844, 0.98438\n");
    // Hd1 approximated values
    runFilter(1.9844, 0.98438);

    printf("Hd2 orignal values: 1.9554, 0.95603\n");
    // Hd2 orignal values
    runFilter(1.9554, 0.95603);

    printf("Hd2 approximated values: 1.9531, 0.95312\n");
    // Hd2 approximated values
    runFilter(1.9531, 0.95312);
}
