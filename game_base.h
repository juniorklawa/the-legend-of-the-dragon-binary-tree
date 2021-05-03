#include "game_classes.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef BINARY_TREE_RPG_GAME_BASE_H
#define BINARY_TREE_RPG_GAME_BASE_H

void free_tree (struct Node *n);
void exitGameManager (struct RPGGame *game);
void game_manager (struct  Node *n, struct RPGGame *game, struct Player *player);
void chapterWithChallengeManager(struct Node *n, struct Player *player, struct RPGGame *game);
void endOfChapterManager(struct Node *n, struct RPGGame *game, struct Player *player);
void deathManager(struct Node *n, struct Player *player, struct RPGGame *game);
void endOfGameManager(struct RPGGame *game, struct Player *player);
int save(struct Node *n, struct RPGGame *game, Player *p);
FILE *load(struct Node *n, struct RPGGame *game, Player *p);
struct Node *searchNode(struct Node *n, int key);
void newName(Player *p);
#endif //BINARY_TREE_RPG_GAME_BASE_H
