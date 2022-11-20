// TODO Operating Systems
// TODO Marian B
// TODO Task 1

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t Semaphore_A; // semaphore A
sem_t Semaphore_B; // semaphore B
sem_t Semaphore_C; // semaphore C

_Noreturn void *print_A(); // noreturn pointer function
_Noreturn void *print_B(); // noreturn pointer function
_Noreturn void *print_C(); // noreturn pointer function

int main(){
    sem_init(&Semaphore_A,0,1); // init semaphore A, not shared, start first
    sem_init(&Semaphore_B,0,0); // init semaphore B, not shared
    sem_init(&Semaphore_C,0,0); // init semaphore C, not shared

    pthread_t threadA; // thread A
    pthread_t threadB; // thread B
    pthread_t threadC; // thread C

    pthread_create(&threadA,NULL, print_A, NULL); // create thread A
    pthread_create(&threadB,NULL, print_B, NULL); // create thread B
    pthread_create(&threadC,NULL, print_C, NULL); // create thread C

    pthread_join(threadA,NULL); // join thread A
    pthread_join(threadB,NULL); // join thread B
    pthread_join(threadC,NULL); // join thread C
}

_Noreturn void *print_A(){
    while(1){
        sem_wait(&Semaphore_A);
        printf("Synchro A\n");
        sleep(1);
        sem_post(&Semaphore_B);
//        printf("Non synchro A\n");
//        sleep(1);
    }
}

_Noreturn void *print_B(){
    while(1){
        sem_wait(&Semaphore_B);
        printf("Synchro B\n");
        sleep(1);
        sem_post(&Semaphore_C);
//        printf("Non synchro B\n");
//        sleep(1);
    }
}

_Noreturn void *print_C(){
    while(1){
        sem_wait(&Semaphore_C);
        printf("Synchro C\n");
        sleep(1);
        sem_post(&Semaphore_A);
//        printf("Non synchro C\n");
//        sleep(1);
    }
}