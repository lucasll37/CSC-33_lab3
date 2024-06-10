#include <stdio.h>
#include <pthread.h>

typedef struct {
    int width;
    int height;
} rectangle;

void* calculate_area(void* arg) {
    rectangle* rect = (rectangle*)arg;
    int area = rect->width * rect->height;
    printf("Area of rectangle with width %d and height %d is: %d\n", rect->width, rect->height, area);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;

    rectangle rect1 = {
        .width = 5,
        .height = 10
    }; 

    rectangle rect2 = {
        .width = 8,
        .height = 15
    }; 

    pthread_create(&tid1, NULL, calculate_area, (void*)&rect1);
    pthread_create(&tid2, NULL, calculate_area, (void*)&rect2);


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
