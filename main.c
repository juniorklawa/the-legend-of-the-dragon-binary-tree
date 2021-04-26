#include <stdio.h>
#include "game_base.h"
#include "game_classes.h"
#include "game_story.c"
#include "game_challenges.c"
#include "game_ascii_arts.c"


int main() {

    struct Challenge *challenge1 = newChallenge(challengeDescription1, 2);

    struct Challenge *challenge2 = newChallenge(challengeDescription2, 2);

    struct Challenge *challenge3 = newChallenge(challengeDescription3, 1);

    struct Challenge *challenge4 = newChallenge(challengeDescription4, 2);

    struct Challenge *challenge5 = newChallenge(challengeDescription5, 2);

    struct Challenge *challenge6 = newChallenge(challengeDescription6, 1);

    struct Challenge *challenge7 = newChallenge(challengeDescription7, 1);

    //CHAPTER 1
    struct Node *chapter1 = newNode(1, key1Description);
    chapter1->left = newNode(2, key2Description);
    chapter1->right = newNode(3, key3Description);
    chapter1->left->left = newNodeEndOfChapter(4, key4Description, firstChapterAscii, NULL);
    chapter1->left->right = newNodeEndOfChapter(5, key5Description, firstChapterAscii, NULL);

    //CHAPTER 2
    struct Node *chapter2 = newNode(6, key6Description);
    chapter2->left = newNode(7, key7Description);
    chapter2->right = newNode(8, key8Description);
    chapter2->left->left = newNodeEndOfChapter(9, key9Description, warriorAscii, NULL);
    chapter2->left->right = newNodeEndOfChapter(10, key10Description, mageAscii, NULL);

    //CHAPTER 3
    struct Node *chapter3 = newNode(11, key11Description);
    chapter3->left = newNodeEndOfChapter(12, key12Description, goblinAscii, NULL);
    chapter3->right = newNode(13, key13Description);
    chapter3->right->left = newNodeEndOfChapter(15, key15Description, goblinAscii, NULL);
    chapter3->right->right = newNodeEndOfChapter(16, key16Description, goblinAscii, challenge1);


    //CHAPTER 4
    struct Node *chapter4 = newNode(17, key17Description);
    chapter4->left = newNodeEndOfChapter(18, key18Description, kingGoblinAscii, challenge2);
    chapter4->right = newNodeEndOfChapter(19, key19Description, kingGoblinAscii, challenge3);

    //CHAPTER 5
    struct Node *chapter5 = newNode(22, key22Description);
    chapter5->left = newNode(23, key23Description);
    chapter5->right = newNode(24, key24Description);
    chapter5->left->left = newNodeEndOfChapter(25, key25Description, hutAscii, NULL);
    chapter5->left->right = newNodeEndOfChapter(26, key26Description, goblinAscii, challenge4);
    chapter5->right->left = newNodeEndOfChapter(27, key27Description, goblinAscii, challenge5);
    chapter5->right->right = newNodeEndOfChapter(28, key28Description, forestAscii, NULL);

    //CHAPTER 6
    struct Node *chapter6 = newNode(29, key29Description);
    chapter6->left = newNodeEndOfChapter(30, key30Description, waterfallAscii, challenge6);
    chapter6->right = newNodeEndOfChapter(31, key31Description, waterfallAscii, NULL);

    //CHAPTER 7
    struct Node *chapter7 = newNode(33, key33Description);
    chapter7->left = newNode(34, key34Description);
    chapter7->right = newNode(35, key35Description);
    chapter7->left->left = newNode(36, key36Description);
    chapter7->left->right = newNodeEndOfChapter(37, key37Description, dragonAscii, NULL);
    chapter7->right->left = newNode(38, key38Description);
    chapter7->right->right = newNodeEndOfChapter(39, key39Description, dragonAscii, challenge7);

    //CHAPTER 8
    struct Node *chapter8 = newNode(40, key40Description);
    chapter8->left = newNodeEndOfChapter(41, key41Description, bagOfMoney, NULL);
    chapter8->right = newNodeEndOfChapter(42, key42Description, handShakingAscii, NULL);


    struct Player *player = newPlayer(0, "temp");


    struct RPGGame *rpgGame = newRPGGame(chapter1, chapter2, chapter3, chapter4, chapter5, chapter6, chapter7,
                                         chapter8);


    puts("   ▄████████       ▄█          ▄████████ ███▄▄▄▄   ████████▄     ▄████████      ████████▄   ▄██████▄       ████████▄     ▄████████    ▄████████    ▄██████▄     ▄████████  ▄██████▄  \n"
         "  ███    ███      ███         ███    ███ ███▀▀▀██▄ ███   ▀███   ███    ███      ███   ▀███ ███    ███      ███   ▀███   ███    ███   ███    ███   ███    ███   ███    ███ ███    ███ \n"
         "  ███    ███      ███         ███    █▀  ███   ███ ███    ███   ███    ███      ███    ███ ███    ███      ███    ███   ███    ███   ███    ███   ███    █▀    ███    ███ ███    ███ \n"
         "  ███    ███      ███        ▄███▄▄▄     ███   ███ ███    ███   ███    ███      ███    ███ ███    ███      ███    ███  ▄███▄▄▄▄██▀   ███    ███  ▄███          ███    ███ ███    ███ \n"
         "▀███████████      ███       ▀▀███▀▀▀     ███   ███ ███    ███ ▀███████████      ███    ███ ███    ███      ███    ███ ▀▀███▀▀▀▀▀   ▀███████████ ▀▀███ ████▄  ▀███████████ ███    ███ \n"
         "  ███    ███      ███         ███    █▄  ███   ███ ███    ███   ███    ███      ███    ███ ███    ███      ███    ███ ▀███████████   ███    ███   ███    ███   ███    ███ ███    ███ \n"
         "  ███    ███      ███▌    ▄   ███    ███ ███   ███ ███   ▄███   ███    ███      ███   ▄███ ███    ███      ███   ▄███   ███    ███   ███    ███   ███    ███   ███    ███ ███    ███ \n"
         "  ███    █▀       █████▄▄██   ██████████  ▀█   █▀  ████████▀    ███    █▀       ████████▀   ▀██████▀       ████████▀    ███    ███   ███    █▀    ████████▀    ███    █▀   ▀██████▀  \n"
         "                  ▀                                                                                                     ███    ███                                                   ");


    int menuChoice = 0;
    printf("Você deseja, começar um novo jogo ou carregar um save? \n\n 1. Novo jogo \n 2. Carregar \n");

    scanf("\n\n%d", &menuChoice);


    if (menuChoice == 1) {
//		newName(player);
        rpgGame->currentTree = rpgGame->chapter1;
        game_manager(rpgGame->currentTree, rpgGame, player);
    } else if (menuChoice == 2) {
        load(rpgGame->currentTree, rpgGame, player);
    }


}




