#include <stdio.h>
#include <pthread.h>

int beers = 2000000;
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

void* drink_lots(void* a)
{
	int i;
	pthread_mutex_lock(&beers_lock);
	for (i = 0; i < 100000; i++) {
		beers = beers - 1;
	}
	pthread_mutex_unlock(&beers_lock);
	printf("맥주 = %i\n", beers);
	return NULL;
}

int main()
{
	pthread_t threads[20];
	int t;
	printf("벽에 있는 맥주병 개수: %i\n맥주병 개수: %i\n", beers, beers);
	for (t = 0; t < 20; t++) {
		pthread_create(&threads[t], NULL, drink_lots, NULL);
	}

	void* result;
	for (t = 0; t < 20; t ++) {
		pthread_join(threads[t], &result);
	}

	printf("벽에 %i 병의 맥주가 남아있습니다.\n", beers);
	return 0;
}

