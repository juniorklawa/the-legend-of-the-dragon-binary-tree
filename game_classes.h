//
// Created by everaldo on 17/04/2021.
//

#ifndef BINARY_TREE_RPG_GAME_CLASSES_H
#define BINARY_TREE_RPG_GAME_CLASSES_H


typedef struct Node {
    int key;
    char *description;
    struct Node *left, *right;
    int isEndOfChapter;
    struct Challenge *challenge;
    char *nextNodeAsciiArt;
} Node;

typedef struct Challenge {
    char *description;
    int rightAnswer;
} Challenge;


typedef struct Player {
    int score;
    char *name;
} Player;

typedef struct RPGGame {
    struct Node *currentTree;
    struct Node *chapter1;
    struct Node *chapter2;
    struct Node *chapter3;
    struct Node *chapter4;
    struct Node *chapter5;
    struct Node *chapter6;
    struct Node *chapter7;
    struct Node *chapter8;
};


struct RPGGame *newRPGGame(struct Node *chapter1, struct Node *chapter2, struct Node *chapter3, struct Node *chapter4,
                           struct Node *chapter5, struct Node *chapter6, struct Node *chapter7, struct Node *chapter8);

struct Node *newNode(int k, char *description);

struct Node *newNodeEndOfChapter(int k, char *description, char *nextAsciiCode, struct Challenge *challenge);

struct Node *newChallenge(char *description, int rightAnswer);

struct Player *newPlayer(int score, char *name);


#endif //BINARY_TREE_RPG_GAME_CLASSES_H
