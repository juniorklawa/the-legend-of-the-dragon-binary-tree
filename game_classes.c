#include "game_classes.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Aqui isolamos todas as criações de structs
 *
 * */


struct RPGGame *newRPGGame(struct Node *chapter1, struct Node *chapter2, struct Node *chapter3, struct Node *chapter4,
                           struct Node *chapter5, struct Node *chapter6, struct Node *chapter7, struct Node *chapter8) {
    struct RPGGame *RPGGame = (struct RPGGame *) malloc(sizeof(struct RPGGame));
    RPGGame->chapter1 = chapter1;
    RPGGame->chapter2 = chapter2;
    RPGGame->chapter3 = chapter3;
    RPGGame->chapter4 = chapter4;
    RPGGame->chapter5 = chapter5;
    RPGGame->chapter6 = chapter6;
    RPGGame->chapter7 = chapter7;
    RPGGame->chapter8 = chapter8;
    return RPGGame;
}

struct Node *newNode(int k, char *description) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key = k;
    node->description = description;
    node->right = node->left = NULL;
	node->isEndOfChapter = 0;
    return node;
}


struct Node *newChallenge(char *description, int rightAnswer) {
    struct Challenge *challenge = (struct Challenge *) malloc(sizeof(struct Challenge));
    challenge->description = description;
    challenge->rightAnswer = rightAnswer;

    return challenge;
}

struct Node *newNodeEndOfChapter(int k, char *description, char *nextAsciiCode, struct Challenge *challenge) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key = k;
    node->description = description;
    node->nextNodeAsciiArt = nextAsciiCode;
    node->right = node->left = NULL;
	node->isEndOfChapter = 1;
    node->challenge = challenge;
    return node;
}

struct Player *newPlayer(int score, char *name) {
    struct Player *player = (struct Player *) malloc(sizeof(struct Player));
    player->name = name;
    player->score = score;
}
