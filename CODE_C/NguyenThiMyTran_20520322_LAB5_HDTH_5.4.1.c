#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <semaphore.h>

#include <unistd.h>
sem_t sem;

int sells=0, products=0;

void* PROCESSA()

{

	while(1)

	{

		sem_wait(&sem);	

		sells++;

		printf("sells = %d\n", sells);

		sleep(2);

	}

}

void* PROCESSB()

{

	while(1)

	{

		if (products <= sells + 22 + 10) {

			products++;

			printf("products = %d\n", products);

			sem_post(&sem);

			sleep(1);

		}

		

	}

}

void main()

{

	sem_init(&sem,0,0);

	pthread_t th1, th2;

	pthread_create(&th1, NULL, &PROCESSA, NULL);

	pthread_create(&th2, NULL, &PROCESSB, NULL);

	while(1);

}
