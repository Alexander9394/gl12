#include <stdio.h>
#include <pthread.h>

int count = 100000;
pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
void* change()
{
        pthread_mutex_lock(&count_lock);
        for(int i =0; i < 10000; i++) {
                count = count - 1;
        }
        pthread_mutex_unlock(&count_lock);
        printf("count = %i\n", count);
        return NULL;

}

int main()
{
        pthread_t threads[10];

        printf("Счётчик равен %i\n", count);

        pthread_create(&threads[0], NULL, change, NULL);
        pthread_create(&threads[1], NULL, change, NULL);
        pthread_create(&threads[2], NULL, change, NULL);
        pthread_create(&threads[3], NULL, change, NULL);
        pthread_create(&threads[4], NULL, change, NULL);
        pthread_create(&threads[5], NULL, change, NULL);
        pthread_create(&threads[6], NULL, change, NULL);
        pthread_create(&threads[7], NULL, change, NULL);
        pthread_create(&threads[8], NULL, change, NULL);
        pthread_create(&threads[9], NULL, change, NULL);

        void* result;

        pthread_join(threads[0], &result);
        pthread_join(threads[1], &result);
        pthread_join(threads[2], &result);
        pthread_join(threads[3], &result);
        pthread_join(threads[4], &result);
        pthread_join(threads[5], &result);
        pthread_join(threads[6], &result);
        pthread_join(threads[7], &result);
        pthread_join(threads[8], &result);
        pthread_join(threads[9], &result);

        printf("Счетчик равен %i\n", count);
        return 0;
}
