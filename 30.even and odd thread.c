#include <stdio.h>
#include <pthread.h>
int i;
void *printEvenNumbers(void *arg) {
    int n = *((int *) arg);
    for (i = 2; i <= n; i += 2) {
        printf("Even Thread: %d\n", i);
    }
    pthread_exit(NULL);
}

void *printOddNumbers(void *arg) {
    int n = *((int *) arg);
    for (i = 1; i <= n; i += 2) {
        printf("Odd Thread: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;
    int n = 10; // Number limit for even and odd numbers

    // Create thread for even numbers
    pthread_create(&tid1, NULL, printEvenNumbers, (void *) &n);

    // Create thread for odd numbers
    pthread_create(&tid2, NULL, printOddNumbers, (void *) &n);

    // Wait for both threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

