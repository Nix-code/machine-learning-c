// Linear model overview
// Regression
// Cost functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// sizeof(train) = 6 * 2 * 4(bytes) = 48
// sizeof(train[0]) = 2 (number of element) * 4 (byte) = 8
// train_count = 6

#define train_count (sizeof(train) / sizeof(train[0]));
float train[][2] = {
    {0, 1},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    {5, 10}

};

float random_float (void) {
    return (float)rand() / (float) RAND_MAX;
}

int main()
{
    // every time the number is different
    //srand(time(0));
    srand(12);
    // Weight and Bias
    float W = random_float()*10.0f;
    size_t n = train_count;
    for(size_t i = 0; i < n; i++){
        float x = train[i][0];
        float y = x * W; // y = mx+c i.e linear equation
        printf("actual: %f, expected: %f \n", y, train[i][1]);
    }
    return 0;
}