// Linear model overview
// Regression
// Cost functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// sizeof(train) = 6 * 2 * 4(bytes) = 48
// sizeof(train[0]) = 2 (number of element) * 4 (byte) = 8
// train_count = 6

#define train_count (sizeof(train) / sizeof(train[0]))

float train[][2] = {
    {1, 5},
    {2, 10},
    {3, 15},
    {4, 20},
    {5, 25},
    {6, 30},
    {7, 35},
    {8, 40},
    {9, 45}
};

float random_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

float cost_function(float weight, float bias)
{
    float result = 0.0f;
    size_t n = train_count;
    for (size_t i = 0; i < n; i++)
    {
        float x = train[i][0];
        float y_actual = train[i][1];
        float y_predicted = x * weight + bias;
        float d = y_predicted - y_actual;
        // square helps to measure error properly
        // it handles the negative distances too
        // it amplifies the smaller distance for getting proper insight

        result += d * d;
    }
    result /= n;
    return result;
}

void approximation_of_the_cost_function(float weight, float bias, float *final_weight, float *final_bias)
{
    float eps = 1e-3;
    float rate = 1e-3;

    float cost = cost_function(weight, bias);
    printf("%f\n", cost_function(weight, bias));

    for (size_t i = 0; i < 10000; i++)
    {

        // https://wikimedia.org/api/rest_v1/media/math/render/svg/aae79a56cdcbc44af1612a50f06169b07f02cbf3
        // approximate the derivative of a function at a specific point.

        float dw = (cost_function(weight + eps, bias) - cost) / eps;
        float db = (cost_function(weight, bias + eps) - cost) / eps;

        weight -= rate * dw;
        bias -= rate * db;

        cost = cost_function(weight, bias);
        // printf("cost = %f, weight = %f, bias = %f\n", cost, weight, bias);
    }
    printf("----------------------\n");

    printf("cost = %f, weight = %f, bias = %f\n", cost_function(weight, bias), weight, bias);
    *final_weight = weight;
    *final_bias = bias;
}
int main()
{
    // every time the number is different
    // srand(time(0));
    srand(12);
    // Weight and Bias
    float weight = random_float() * 10.0f;
    float bias = random_float() * 5.0f;

    float final_weight, final_bias;
    approximation_of_the_cost_function(weight, bias, &final_weight, &final_bias);

    printf("weight: %f, bias: %f\n", final_weight, final_bias);

    // Predict the data 10
    float predict_value = 10;
    float predict = final_weight * predict_value + final_bias;
    // cool :>
    printf(" predicted value = 6 : %f", predict);
    return 0;
}