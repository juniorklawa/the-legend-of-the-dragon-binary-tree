#ifndef BINARY_TREE_RPG_TREE_H
#define BINARY_TREE_RPG_TREE_H


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

int buscar (Arvore *a, int v);

Arvore* inserir (Arvore *a, int v);

Arvore* remover (Arvore *a, int v);

#endif //BINARY_TREE_RPG_TREE_H
