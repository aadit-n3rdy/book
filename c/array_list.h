#ifndef __ARRAY_LIST_H_
#define __ARRAY_LIST_H_

#include <stdlib.h>
#include <stdio.h>

#ifndef AL_MAX_SIZE
#define AL_MAX_SIZE 30
#endif // AL_MAX_SIZE


struct ArrayList {
    int* raw;
    int size;
};

void alinit(struct ArrayList *al) {
    al->raw = malloc(sizeof(int) * AL_MAX_SIZE);
    al->size = 0;
}

int alretrieve(struct ArrayList* al, int index) {
    if(index >= 0 && index < al->size) {
        return al->raw[index];
    }
    else {
        fprintf(stderr, "ERROR: Invalid index");
        exit(-1);
    }
}

void alset(struct ArrayList* al, int index, int value) {
    if(index >= 0 && index < al->size) {
        al->raw[index] = value;
    }
    else {
        fprintf(stderr, "ERROR: Invalid index");
        exit(-1);
    }
}

int alnext(struct ArrayList* al, int index) {
    return alretrieve(index+1);
}

int alprev(struct ArrayList* al, int index) {
    return alretrieve(index-1);
}

int alfirst(struct ArrayList* al) {
    return alretrieve(0);
}

int al_locate(struct ArrayList* al, int element) {
    int size = al->size;
    int ret = -1;
    for(int i = 0; i < size && ret==-1; i++) {
        if(alretrieve(al, i) == element) {
            ret = i;
        }
    }
    return ret;
}

void aldelete(struct ArrayList* al, int index) {
    int size = al->size;
    for(int i = index; i < size-1; i++) {
        alset(al, i, alretrieve(al, i+1));
    }
    al->size--;
}

void alinsert(struct ArrayList* al, int index, int value) {
    int size = al->size;
    if(size == AL_MAX_SIZE - 1) {
        fprintf("WARNING: Element not inserted, no space");
    }
    else {
        for(int i = index+1; i <= size; i++) {
            alset(al, i, alretrieve(al, i-1));
        }
        alset(al, index, value);
        al->size++;
    }
}

void alprint(struct ArrayList* al, FILE* stream) {
    int size = al->size;
    for(int i = 0; i < size; i++) {
        fprintf(stream, "%d\n", alretrieve(al, i));
    }
}

#endif // __ARRAY_LIST_H_
