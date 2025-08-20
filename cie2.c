#include <stdio.h>
#include <time.h>
#include <omp.h>  

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    clock_t start = clock();

    long long sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sum = %lld\n", sum);
    printf("Execution time: %f seconds\n", time_spent);

    return 0;
}
