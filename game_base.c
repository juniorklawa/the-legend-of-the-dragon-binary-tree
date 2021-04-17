#include "game_classes.h"
#include "game_base.h"
#include <stdio.h>
#include <stdlib.h>

void endOfChapterManager(struct  Node *n, struct RPGGame *game) {
    if(n->key == 4 || n->key == 5){
        printf ("%s\n", n->description);
        n->left = game->firstChapter;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game);
    }

    if(n->key == 9 || n->key == 10){
        printf ("%s\n", n->description);
        n->left = game->secondChapter;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game);
    }
}

void deathManager(struct  Node *n) {
    if(n->key == 8 || n->key == 3 || n->key == 12) {

        printf ("%s\n", n->description);

        puts("Você morreu.");
        puts("  .---.\n"
             " /     \\\n"
             "( () () )\n"
             " \\  M  / VK\n"
             "  |HHH|\n"
             "  `---'\n"
             "\n"
        );

        exit(0);
    }
}

void game_manager (struct  Node *n, struct RPGGame *game){

    int choice = 0;
    if (n != NULL) {

        if(n->isEndOfChapter == 1){
            endOfChapterManager(n, game);
        }

        deathManager(n);

        printf ("%s\n", n->description);
        scanf("%d", &choice);


        if(choice == 1){
            game_manager(n->left, game);
        } else {
            game_manager(n->right, game);
        }
    }

}