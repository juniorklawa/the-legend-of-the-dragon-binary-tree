#include "game_classes.h"
#include <stdio.h>
#include <stdlib.h>

struct RPGGame *newRPGGame(struct Node *introduction, struct Node *firstChapter, struct Node *secondChapter) {
    struct RPGGame *RPGGame = (struct RPGGame *)malloc(sizeof(struct RPGGame));
    RPGGame->firstChapter = firstChapter;
    RPGGame->secondChapter = secondChapter;
    RPGGame->currentTree = introduction;
    return RPGGame;
}

struct Node *newNode(int k, char* description) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->description = description;
    node->right = node->left = NULL;
    return node;
}

struct Node *newNodeEndOfChapter(int k, char* description, char* nextAsciiCode) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->description = description;
    node->isEndOfChapter = 1;
    node->nextNodeAsciiArt = nextAsciiCode;
    node->right = node->left = NULL;
    return node;
}

struct Player *newPlayer(int health, int score, char* name, int class){
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));
    player->name = name;
    player->class = 0;
    player->health = 100;
    player->score = 0;
}