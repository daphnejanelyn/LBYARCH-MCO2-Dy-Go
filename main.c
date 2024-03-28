#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// import C and x86-64 stencil functions
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
        if (array1[i] != array2[i] && fabs(array1[i] - array2[i]) >= 0.01) {
            diff++;
        }
    }
    return diff;
}

void printArray(size_t n, float* Y) {
    for (size_t i = 0; i < n; i++) {
        printf("%.2f", Y[i]);
        if (i < n - 1) {
            printf(",  ");
        }
    }
    printf("\n\n");
}

void initializeArray(size_t n, float* X, char mode) {
    for (size_t i = 0; i < n; i++) {
        switch (mode) {
        case '2':   // fill it from 1 to n
            X[i] = (float)(i % (long long)1e6) + 1.0f;
            break;

        case '3':   // fill the first 10 values with random values
            X[i] = (float)rand() / RAND_MAX * 9 + 1; // Generate random value between 0 and 1
            break;

        default:    // sir's example
            if (i < 8)
                X[i] = (float)i + 1.0f;
            else
                X[i] = 0;
            break;
        }
    }
}

int process() {
    int nResults = 10;

    // input variables
    printf("---- Input ----\n");
    char throwaway;
    printf("Common Array Sizes:\n\t[1] 20\n\t[2] 24\n\t[3] 28\n\t[4] 30\n\nArray Size 2^n (Default: [1] 20): ");
    char power = getchar();
    throwaway = getchar();
    printf("\nFill Array with : \n\t[1] Sir's example\n\t[2] 1 to n MOD 1000000\n\t[3] Random values\n\nFill type (Default: [1] Sir's example): ");
    char arrayFill = getchar();
    throwaway = getchar();

    switch (power) {
    case '2':
        power = 24;
        break;
    case '3':
        power = 28;
        break;
    case '4':
        power = 30;
        break;
    default:
        power = 20;
        break;
    }

    // initialize variables
    const size_t ARRAY_LENGTH = 1ll << power;
    const size_t ARRAY_SIZE = sizeof(float) * ARRAY_LENGTH;

    float* X = (float*)malloc(ARRAY_SIZE);
    float* Y_asm = (float*)malloc(ARRAY_SIZE);
    float* Y_c = (float*)malloc(ARRAY_SIZE);

    int loopCount = 30;

    clock_t begin, end;
    double time_taken = 0;

    // print variables
    printf("\n\n----START----\nArray size: 2^%d or %zu\n", power, ARRAY_LENGTH);
    printf("Fill type: ");
    switch (arrayFill) {
    case '2':
        printf("1 to n MOD 1000000\n");
        break;
    case '3':
        printf("Random values\n");
        break;
    default:
        printf("Sir's example\n");
        break;
    }
    //initialize 
    initializeArray(ARRAY_LENGTH, X, arrayFill);

    // initialize Y
    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        Y_c[i] = 0;
        Y_asm[i] = 0;
    }

    printf("First %d values of X: ", nResults + 6);
    printArray(nResults + 6, X);


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
    printArray(10, Y_c);
    time_taken = 0;

    // 
    // ----------------- x86-64 function -----------------
    // 

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
    printArray(10, Y_asm);

    printf("Errors: %lld\n", compareArray(ARRAY_LENGTH, Y_c, Y_asm));

    free(X);
    free(Y_c);
    free(Y_asm);

    printf("\n\nEnter to continue, N to stop.\n");
    throwaway = getchar();
    return throwaway;
}

int main() {
    int looping = 1;
    while (looping != 'n' && looping != 'N') {
        system("cls");
        looping = process();
    }
    return 0;
}