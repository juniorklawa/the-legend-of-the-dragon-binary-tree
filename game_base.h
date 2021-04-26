#include "game_classes.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef BINARY_TREE_RPG_GAME_BASE_H
#define BINARY_TREE_RPG_GAME_BASE_H

void game_manager (struct  Node *n, struct RPGGame *game, struct Player *player);
void chapterWithChallengeManager(struct Node *n, struct Player *player);
void endOfChapterManager(struct Node *n, struct RPGGame *game, struct Player *player);
void deathManager(struct Node *n, struct Player *player);
void endOfGameManager(struct Player *player);
int save(Player *p, int key, int l);
FILE *load(Player *p, int *key, int l);
void autoSave(Player *p, int key);
void loadautoSave(Player *p, int *key);
void newName(Player *p);
#endif //BINARY_TREE_RPG_GAME_BASE_H
