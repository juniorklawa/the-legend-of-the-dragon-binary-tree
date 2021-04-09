#include "tree.h"

int buscar (Arvore *a, int v) {
    if (a == NULL) {
        return 0;
    }
    else if (v < a->info) {
        return buscar (a->esq, v);
    }
    else if (v > a->info) {
        return buscar (a->dir, v);
    }
    else {
        return 1;
    }
}

Arvore* inserir (Arvore *a, int v) {
    if (a == NULL) {
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info) {
        a->esq = inserir (a->esq, v);
    }
    else {
        a->dir = inserir (a->dir, v);
    }
    return a;
}

Arvore* remover (Arvore *a, int v) {
    if (a == NULL) { return NULL; }
    else {
        if (a->info > v)
            a->esq = remover (a->esq, v);
        else if (a->info < v)
            a->dir = remover (a->dir, v);
        else {
            if ((a->esq == NULL) && (a->dir == NULL)) {
                free(a);
                a = NULL;
            }
            else if (a->dir == NULL) {
                Arvore *tmp = a;
                a = a->esq;
                free (tmp);
            }
            else if (a->esq == NULL) {
                Arvore *tmp = a;
                a = a->dir;
                free (tmp);
            }
            else {
                Arvore *tmp = a->esq;
                while (tmp->dir != NULL)
                    tmp = tmp->dir;
                a->info = tmp->info;
                tmp->info = v;
                a->esq = remover (a->esq, v);
            }
        }
        return a;
    }
}