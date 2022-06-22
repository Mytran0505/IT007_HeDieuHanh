#include <stdio.h>

#include <semaphore.h>

#include <pthread.h>

#include <time.h>

#include <stdlib.h>

 

pthread_t tid[2];

 

int a[100000];

int size_a = 0;

 

void* f1()

{

     while (1) {

          if (size_a > 0) {

               size_a--;

               printf("Lay b ra Size of array_A: %d\n", size_a);

          }

          else

               printf("Nothing in array_A\n");

     }

}

void* f2()

{

     while (1) {

          a[size_a] = rand() % 100000;

          size_a++;

          printf("Size of array_A: %d\n", size_a);

     }

}

 

int main(int argc, char* argv[])

{

     srand(time(NULL));

     int i;

     for (i = 0; i < 100000; i++) {

          a[i] = 0;

     }

 

     pthread_create(&tid[0], NULL, f1, NULL);

     pthread_create(&tid[1], NULL, f2, NULL);

 

     for (i = 0; i < 2; i++)

          pthread_join(tid[i], NULL);

}
