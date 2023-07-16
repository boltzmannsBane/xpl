#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
  float w1;
  float w2;
  float b;
} Neuron;

typedef struct {
  Neuron neurons[3];
} Xor;

float sigmoidf(float x)
{
    return 1.f / (1.f + expf(-x));
}

float fire(Xor m, float x1, float x2)
{
    float a = sigmoidf(m.neurons[0].w1*x1 + m.neurons[0].w2*x2 + m.neurons[0].b);
    float b = sigmoidf(m.neurons[1].w1*x1 + m.neurons[1].w2*x2 + m.neurons[1].b);
    return sigmoidf(a*m.neurons[2].w1 + b*m.neurons[2].w2 + m.neurons[2].b);
}

typedef float sample[3];
sample xor_train[] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
};

// NAND-gate
sample or_train[] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
};

sample and_train[] = {
    {0, 0, 0},
    {1, 0, 0},
    {0, 1, 0},
    {1, 1, 1},
};

sample nand_train[] = {
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
};

sample nor_train[] = {
    {0, 0, 1},
    {1, 0, 0},
    {0, 1, 0},
    {1, 1, 0},
};

sample *train = xor_train;
size_t train_count = 4;

float cost(Xor m)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = fire(m, x1, x2);
        float d = y - train[i][2];
        result += d*d;
    }
    result /= train_count;
    return result;
}

float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}

Xor rand_xor(void)
{
    Xor m;
    int i;
    for (i = 0; i < 3; i++) {
      m.neurons[i].w1 = rand_float();
      m.neurons[i].w2 = rand_float();
      m.neurons[i].b = rand_float();
  }
    return m;
}

Xor learn(Xor m, Xor g, float rate)
{
    int i;
    for (i = 0; i < 3; i++) {
      m.neurons[i].w1 -= rate*g.neurons[i].w1;
      m.neurons[i].w2 -= rate*g.neurons[i].w2;
      m.neurons[i].b -= rate*g.neurons[i].b;
  }
    return m;
}

Xor finite_diff(Xor m, float eps)
{
    Xor g;
    int i;

    for (i = 0; i < 3; i++) {
      float c = cost(m);
      float saved;

      saved = m.neurons[i].w1;
      m.neurons[i].w1 += eps;
      g.neurons[i].w1 = (cost(m) - c)/eps;
      m.neurons[i].w1 = saved;
      
      saved = m.neurons[i].w2;
      m.neurons[i].w2 += eps;
      g.neurons[i].w2 = (cost(m) - c)/eps;
      m.neurons[i].w2 = saved;

      saved = m.neurons[i].b;
      m.neurons[i].b += eps;
      g.neurons[i].b = (cost(m) - c)/eps;
      m.neurons[i].b = saved;
  }

    return g;
}

int main(void)
{
    srand(time(0));
    Xor m = rand_xor();

    float eps = 1e-1;
    float rate = 1e-1;

    for (size_t i = 0; i < 100*1000; ++i) {
        Xor g = finite_diff(m, eps);
        m = learn(m, g, rate);
        // printf("cost = %f\n", cost(m));
    }
    printf("cost = %f\n", cost(m));
  printf("------------------------------\n");
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            printf("%zu ^ %zu = %f\n", i, j, fire(m, i, j));
        }
    }
    printf("------------------------------\n");
    printf("\"OR\" neuron:\n");
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            printf("%zu | %zu = %f\n", i, j, sigmoidf(m.neurons[0].w1*i + m.neurons[0].w2*j + m.neurons[0].b));
        }
    }
    printf("------------------------------\n");
    printf("\"NAND\" neuron:\n");
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            printf("~(%zu & %zu) = %f\n", i, j, sigmoidf(m.neurons[1].w1*i + m.neurons[1].w2*j + m.neurons[1].b));
        }
    }
    printf("------------------------------\n");
    printf("\"AND\" neuron:\n");
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            printf("%zu & %zu = %f\n", i, j, sigmoidf(m.neurons[2].w1*i + m.neurons[2].w2*j + m.neurons[2].b)); }
    }

    return 0;
}
