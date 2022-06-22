#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <semaphore.h>
#include <unistd.h>

sem_t p1_5, p1_6, p2_3, p2_4, p3_5, p4_6, p5_7, p6_7;

int x1 = 1;

int x2 = 2;

int x3 = 3;

int x4 = 4;

int x5 = 5;

int x6 = 6;

int w, v, z, y, x;

int ans = 0;

void* PROCESS1()

{

	w = x1 * x2;

	printf("w = %d\n", w);

	sem_post(&p1_5);

	sem_post(&p1_6);

	sleep(1);

}

void* PROCESS2()

{

	v = x3 * x4;

	printf("v = %d\n", v);

	sem_post(&p2_3);

	sem_post(&p2_4);

	sleep(1);

}

void* PROCESS3()

{

	sem_wait(&p2_3);

	printf("y = %d\n", y);

	y = v * x5;

	sem_post(&p3_5);

	sleep(1);

}

void *PROCESS4()

{

	sem_wait(&p2_4);

	printf("z = %d\n", z);

	z = v * x6;

	sem_post(&p4_6);

	sleep(1);

}

void *PROCESS5()

{

	sem_wait(&p1_5);

	sem_wait(&p3_5);

	y = w * y;

	printf("y = %d\n", y);

	sem_post(&p5_7);

	sleep(1);

}

void *PROCESS6()

{

	sem_wait(&p1_6);

	sem_wait(&p4_6);

	z = w * z;

	printf("z = %d\n", z);

	sem_post(&p6_7);

	sleep(1);

}

void* PROCESS7()

{

	sem_wait(&p5_7);

	sem_wait(&p6_7);

	ans = y + z;

	printf("ans = %d\n", ans);

	sleep(1);

}

void main()

{

	sem_init(&p1_5, 0, 1);

	sem_init(&p1_6, 0, 0);

	sem_init(&p2_3, 0, 0);

	sem_init(&p2_4, 0, 0);

	sem_init(&p3_5, 0, 0);

	sem_init(&p4_6, 0, 0);

	sem_init(&p5_7, 0, 0);

	sem_init(&p6_7, 0, 0);

	pthread_t th1, th2, th3, th4, th5, th6, th7;

	pthread_create(&th1, NULL, &PROCESS1, NULL);

	pthread_create(&th2, NULL, &PROCESS2, NULL);

	pthread_create(&th3, NULL, &PROCESS3, NULL);

	pthread_create(&th4, NULL, &PROCESS4, NULL);

	pthread_create(&th5, NULL, &PROCESS5, NULL);

	pthread_create(&th6, NULL, &PROCESS6, NULL);

	pthread_create(&th7, NULL, &PROCESS7, NULL);

	while (1);

}
