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
int save(struct Node *n, struct RPGGame *game, Player *p, int l);
FILE *load(struct Node *n, struct RPGGame *game, Player *p, int l);
void autoSave(struct Node *n, struct RPGGame *game, Player *p);
void loadautoSave(struct Node *n, struct RPGGame *game, Player *p);
void newName(Player *p);
#endif //BINARY_TREE_RPG_GAME_BASE_H
