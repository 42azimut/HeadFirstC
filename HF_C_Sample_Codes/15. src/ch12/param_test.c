#include <stdio.h>
#include <pthread.h>

void* do_stuff(void* param)
{
	long thread_no = (long)param;
	printf("스레드 번호: %ld\n", thread_no);
	return (void*)(thread_no + 1);
}

int main()
{
	pthread_t threads[3];
	long t;
	for (t=0; t<3; t++) {
		pthread_create(&threads[t], NULL, do_stuff, (void*)t);
	}

	void* result;
	for (t=0; t<3; t++) {
		pthread_join(threads[t], &result);
		printf("스레드 %ld가 %ld를 반환했습니다.\n", t, (long)result);
	}

	return 0;
}
