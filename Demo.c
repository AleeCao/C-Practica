#include <stdbool.h>
#include <stdio.h>

int solution(int A[], int N);

int main() {
    int A[] = {1, 3, 6, 4, 1, 2};
    int N = sizeof(A) / sizeof(A[0]);
    printf("Expected 5, got %d\n", solution(A, N));

    int B[] = {1, 2, 3};
    N = sizeof(B) / sizeof(B[0]);
    printf("Expected 4, got %d\n", solution(B, N));

    int C[] = {-1, -3};
    N = sizeof(C) / sizeof(C[0]);
    printf("Expected 1, got %d\n", solution(C, N));

    return 0;
}

int solution(int A[], int N) {
    bool check[N+2];
    for(int i=0; i<N+2; i++) {
        check[i] = false;
    }
    for(int i=0; i<N; i++) {
        if(A[i] > 0 && A[i] <= N) {
            check[A[i]] = true;
        }
    }
    for(int i=1; i<N+2; i++) {
        if(check[i] == false) {
            return i;
        }
    }
    return N+1;
}