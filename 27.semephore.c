#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define NUM_INSTANCES 4

sem_t sem;
int i;
void *process(void *arg) {
    int id = *(int *)arg;
    printf("Process P%d is waiting on semaphore\n", id);
    sem_wait(&sem);
    printf("Process P%d acquired semaphore\n", id);
    sleep(2);
    sem_post(&sem);
    printf("Process P%d released semaphore\n", id);
    return NULL;
}

int main() {
    sem_init(&sem, 0, NUM_INSTANCES);
    pthread_t threads[4];
    int ids[4] = {1, 2, 3, 4};
    for (i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, process, &ids[i]);
    }
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&sem);
    return 0;
}

