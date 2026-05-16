

#include <stdio.h>
#include <stddef.h>

#include "../include/queue.h"

int main(void){
    putchar('\n');
    if(is_empty_queue())
        puts("Empty queue. \n");
    else 
        puts("queue is not empty. \n");

    if(!print_queue())
        puts("Empty queue - Nothing to display !");
    printf("Queue length: %zu\n\n", queue_length());

    enqueue(14);
    enqueue(-34);
    if(!print_queue())
        puts("Empty queue - Nothing to display !");
    printf("Queue length: %zu\n\n", queue_length());

    dequeue();
    dequeue();
    if(!print_queue())
        puts("Empty queue - Nothing to display !");
    printf("Queue length: %zu\n\n", queue_length());

    enqueue(26);
    enqueue(0);
    enqueue(-100);
    if(!print_queue())
        puts("Empty queue - Nothing to display !");
    printf("Queue length: %zu\n\n", queue_length());

    empty_queue();
    printf("Queue length: %zu\n", queue_length());
    if(is_empty_queue())
        puts("Empty queue. \n");
    else 
        puts("queue is not empty. \n");

    return 0;
}
