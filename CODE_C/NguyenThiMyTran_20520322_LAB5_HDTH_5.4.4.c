

#include <stdio.h>

#include <semaphore.h>

#include <pthread.h>

 

pthread_t tid[2];

pthread_mutex_t mutex;

sem_t sem;

int x = 0;

 

void* f1()

{

     while (1) {

          pthread_mutex_lock(&mutex);

          x = x + 1;

          if (x == 20)

               x = 0;

          printf("Thread 1: x = %d\n", x);

          pthread_mutex_unlock(&mutex);

     }

}

void* f2()

{

     while (1) {

          pthread_mutex_lock(&mutex);

          x = x + 1;

          if (x == 20)

               x = 0;

          printf("Thread 2: x = %d\n", x);

          pthread_mutex_unlock(&mutex);

     }

}

 

int main(int argc, char* argv[])

{

     int i;

     sem_init(&sem, 0, 0);

     pthread_mutex_init(&mutex, NULL);

     pthread_create(&tid[0], NULL, f1, NULL);

     pthread_create(&tid[1], NULL, f2, NULL);

     for (i = 0; i < 2; i++)

          pthread_join(tid[i], NULL);

 

     pthread_mutex_destroy(&mutex);

     return 1;

}
