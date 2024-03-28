#include <stdio.h>

void stencilC(size_t n, float* X, float* Y) {
    for (size_t i = 3; i < n - 3; i++) {
        Y[i - 3] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}