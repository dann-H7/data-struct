#include <stdbool.h> // bool
#include <stdlib.h>  // calloc
#include <stdio.h>   // printf, putchar

#include "..\\include\\queue.h"

/* define a new contact - n'est pas bien en production */
static Pqueue pfirst = NULL;
static Pqueue plast = NULL;
static size_t length_queue = 0;

struct QUEUE{
    int element;
    struct QUEUE *next;
};

void init_queue(void){
    pfirst = NULL;
    plast  = NULL;
    length_queue = 0;
}


bool is_empty_queue(void){
    return (pfirst == NULL) && (plast == NULL) && (length_queue == 0);
}


size_t queue_length(void){ return length_queue; }


bool enqueue(int new_element){
    Pqueue pfile = calloc(1, sizeof(*pfile));
    if(!pfile)
        return false;

    pfile->element = new_element;
    pfile->next = NULL;

    if(is_empty_queue()){
        pfirst = pfile;
        plast  = pfile;
    } else {
        plast->next = pfile;
        plast = pfile;
    }

    length_queue++;

    return true;
}


bool dequeue(void){
    if(is_empty_queue())
        return false;

    if(length_queue == 1){
        pfirst->element = 0; // juste pour vidage
        free(pfirst);
        pfirst = NULL;
        plast  = NULL;
    } else {
        Pqueue temp = pfirst;
        pfirst = pfirst->next;
        temp->element = 0; // juste pour vidage
        temp->next = NULL; // idem
        free(temp);
    }

    length_queue--;

    return true;
}


bool print_queue(void){
    if(is_empty_queue())
        return false;

    Pqueue temp = pfirst;
    while(temp->next){
        printf("[%d|*]->", temp->element);
        temp = temp->next;
    }
    printf("[%d|NULL]\n", temp->element);
    return true;
}


void empty_queue(void){
    while(!is_empty_queue())
        dequeue();
}
