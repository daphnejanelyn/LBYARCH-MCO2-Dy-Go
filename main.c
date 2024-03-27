#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "c_stencil.h"

extern float asm_stencil(float* X);

void stencilAsm(size_t n, float* X, float* Y) {
    for (size_t i = 3; i < n - 3; i++) {
        Y[i - 3] = asm_stencil(&X[i]);
    }
}

long long compareArray(size_t n, float* array1, float* array2) {
    long long diff = 0;
    for (size_t i = 0; i < n; i++) {
        if (array1[i] != array2[i]) {
            diff++;
        }
    }
    return diff;

}

int main() {

    int power = 20;
    const size_t ARRAY_LENGTH = 1 << power;
    const size_t ARRAY_SIZE = sizeof(float) * ARRAY_LENGTH;

    float* X = (float*)malloc(ARRAY_SIZE);
    float* Y_asm = (float*)malloc(ARRAY_SIZE);
    float* Y_c = (float*)malloc(ARRAY_SIZE);

    int loopCount = 30;

    clock_t begin, end;
    double time_taken = 0;

    printf("Array size: 2^%d or %zu\n\n", power, ARRAY_LENGTH);
    //initialize X
    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        if (i < 8) {
            X[i] = i + 1.0;
        }
        else {
            X[i] = 0;
        }
    }
    // initialize Y
    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        Y_c[i] = 0;
        Y_asm[i] = 0;
    }


    // 
    // ----------------- C function -----------------
    // 

    // prefill cache
    stencilC(ARRAY_LENGTH, X, Y_c);



    for (int i = 0; i < loopCount; i++) {
        begin = clock();
        stencilC(ARRAY_LENGTH, X, Y_c);
        end = clock();
        time_taken += ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
    }
    printf("[C function]\nTakes %lf milliseconds\nFirst 10 results: ", time_taken / loopCount);
    printStencil(10, Y_c);


    // reset variables
    time_taken = 0;

    // prefill cache
    stencilAsm(ARRAY_LENGTH, X, Y_asm);

    // start assembly
    for (int i = 0; i < loopCount; i++) {
        begin = clock();
        stencilAsm(ARRAY_LENGTH, X, Y_asm);
        end = clock();
        time_taken += ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
    }

    printf("\n[x86-64 function]\nTakes %lf milliseconds\nFirst 10 results: ", time_taken / loopCount);
    printStencil(10, Y_asm);

    printf("Errors: %lld\n", compareArray(ARRAY_LENGTH, Y_c, Y_asm));

    free(X);
    free(Y_c);
    free(Y_asm);

    return 0;
}