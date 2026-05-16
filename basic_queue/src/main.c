#include <stdio.h>
#include <stddef.h>

#include "..\include\queue.h"

int main(void){
    putchar('\n');
    if(is_empty_queue())
        puts("file vide ! \n");
    else 
        puts("file non vide! \n");

    if(!print_queue())
        puts("file vide - rien a afficher !");
    printf("Taille de file: %zu\n\n", queue_length());

    enqueue(14);
    enqueue(-34);
    if(!print_queue())
        puts("file vide - rien a afficher !");
    printf("Taille de file: %zu\n\n", queue_length());

    dequeue();
    dequeue();
    if(!print_queue())
        puts("file vide - rien a afficher !");
    printf("Taille de file: %zu\n\n", queue_length());

    enqueue(26);
    enqueue(0);
    enqueue(-100);
    if(!print_queue())
        puts("file vide - rien a afficher !");
    printf("Taille de file: %zu\n\n", queue_length());

    empty_queue();
    printf("Taille de file: %zu\n", queue_length());
    if(is_empty_queue())
        puts("file vide ! \n");
    else 
        puts("file non vide! \n");

    return 0;
}
