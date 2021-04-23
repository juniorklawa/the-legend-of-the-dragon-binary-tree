//
// Created by everaldo on 17/04/2021.
//

#ifndef BINARY_TREE_RPG_GAME_CLASSES_H
#define BINARY_TREE_RPG_GAME_CLASSES_H


typedef struct Node {
    int key;
    char* description;
    struct Node *left, *right;
    int isEndOfChapter;
    struct  Challenge *challenge;
    char* nextNodeAsciiArt;
};

typedef struct Challenge {
    char* description;
    int rightAnswer;
} Challenge;


typedef struct Player {
    int health;
    int score;
    char* name;
    int class;
} Player;

typedef struct RPGGame {
    struct Node *firstChapter;
    struct Node *secondChapter;
    struct Node *currentTree;
};


struct RPGGame *newRPGGame(struct Node *introduction, struct Node *firstChapter, struct Node *secondChapter);

struct Node *newNode(int k, char* description);

struct Node *newNodeEndOfChapter(int k, char* description, char* nextAsciiCode);

struct Node *newNodeChallenge(int k, char* description, struct Challenge *challenge);
struct Node *newChallenge(char* description, int rightAnswer);
struct Player *newPlayer(int health, int score, char* name, int class);

#endif //BINARY_TREE_RPG_GAME_CLASSES_H
