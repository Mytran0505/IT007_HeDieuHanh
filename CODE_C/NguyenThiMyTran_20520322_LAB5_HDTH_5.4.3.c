#include <stdio.h>

#include <semaphore.h>

#include <pthread.h>

 

pthread_t tid[2];

 

sem_t sem;

int x = 0;

 

void* f1()

{

     while (1) {

          x = x + 1;

          if (x == 20)

               x = 0;

          printf("Thread 1 = %d\n", x);

     }

}

void* f2()

{

     while (1) {

          x = x + 1;

          if (x == 20)

               x = 0;

          printf("Thread 2= %d\n", x);

     }

}

 

int main(int argc, char* argv[])

{

     int i;

     sem_init(&sem, 0, 0);

      

     pthread_create(&tid[0], NULL, f1, NULL);

     pthread_create(&tid[1], NULL, f2, NULL);

     for (i = 0; i < 2; i++)

          pthread_join(tid[i], NULL);

}

	

