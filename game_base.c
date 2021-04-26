#include "game_classes.h"
#include "game_base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chapterWithChallengeManager(struct Node *n, struct Player *player) {
    puts("D E S A F I O");
    printf("%s\n", n->challenge->description);
    int choice = 0;
    printf("Digite sua resposta: ");
    scanf("%d", &choice);
    printf("\n");


    if (choice == n->challenge->rightAnswer) {

        player->score += 25;
        puts("Você passou pelo desafio! \n");
        return;
    } else {
        puts("Você falhou no desafio.");
        puts("\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀\n"
             "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼\n"
             "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀\n"
             "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼\n"
             "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼\n"
             "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼\n"
             "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼\n"
             "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼\n"
             "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼████▄┼┼┼▄▄▄▄▄▄▄┼┼┼▄████┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼▀▀█▄█████████▄█▀▀┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼█████████████┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼██▀▀▀███▀▀▀██┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼██┼┼┼███┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼█████▀▄▀█████┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼███████████┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼▄▄▄██┼┼█▀█▀█┼┼██▄▄▄┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼▀▀██┼┼┼┼┼┼┼┼┼┼┼██▀▀┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼");
        printf("\nSeu score final foi: %d.", player->score);
        exit(0);
    }
}

void endOfGameManager(struct Player *player){
    puts("Obrigado por jogar!\n");
    puts("Desenvolvido e roteirizado por:\n");
    puts("Caio Henrique Marques Meira");
    puts("Everaldo Rosa de Souza Junior");
    puts("Heitor Derber Trevisol");
    printf("\nSeu score final foi: %d.", player->score);
    exit(0);
}


void endOfChapterManager(struct Node *n, struct RPGGame *game, struct Player *player) {

    if(n->key == 41 || n->key == 42) {
        printf("%s\n", n->description);
        puts(n->nextNodeAsciiArt);
        endOfGameManager(player);
    }

    if (n->key == 4 || n->key == 5) {
        printf("%s\n", n->description);
        n->left = game->chapter2;
		game->currentTree = game->chapter2;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 9 || n->key == 10) {
        printf("%s\n", n->description);
        n->left = game->chapter3;
		game->currentTree = game->chapter3;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 12 || n->key == 15 || n->key == 16) {
        printf("%s\n", n->description);

        if (n->challenge != NULL) {
            chapterWithChallengeManager(n, player);
            puts("Após isso vocẽ rastreia o ninho e vai em busca de informações");
        }
        n->left = game->chapter4;
		game->currentTree = game->chapter4;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 18 || n->key == 19) {
        printf("%s\n", n->description);

        if (n->challenge != NULL) {
            chapterWithChallengeManager(n, player);
        }

        n->left = game->chapter5;
		game->currentTree = game->chapter5;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 25 || n->key == 26 || n->key == 27 || n->key == 28) {
        printf("%s\n", n->description);

        if (n->challenge != NULL) {
            chapterWithChallengeManager(n, game);
        }

        n->left = game->chapter6;
		game->currentTree = game->chapter6;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 30 || n->key == 31) {
        printf("%s\n", n->description);

        if (n->challenge != NULL) {
            chapterWithChallengeManager(n, game);
            puts("Após derrotar o mimico, você utiliza uma de suas poções e segue seu trajeto em direção rio acima até achar a cachoeira que habita \"A Grande Chama\"");
        }

        n->left = game->chapter7;
		game->currentTree = game->chapter7;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 36 || n->key == 37 || n->key == 38 || n->key == 39) {
        printf("%s\n", n->description);

        if (n->challenge != NULL) {
            chapterWithChallengeManager(n, game);
        }

        n->left = game->chapter8;
		game->currentTree = game->chapter8;
        puts(n->nextNodeAsciiArt);
        game_manager(n->left, game, player);
    }

    if (n->key == 41 || n->key == 42) {
        printf("%s\n", n->description);
        n->left = game->chapter8;
        puts(n->nextNodeAsciiArt);
        exit(0);
    }
}


void deathManager(struct Node *n, struct Player *player) {

    if (n->key == 3 || n->key == 8 || n->key == 36 || n->key == 38) {
        printf("%s\n", n->description);
        puts("\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀\n"
             "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼\n"
             "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀\n"
             "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼\n"
             "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼\n"
             "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼\n"
             "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼\n"
             "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼\n"
             "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼████▄┼┼┼▄▄▄▄▄▄▄┼┼┼▄████┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼▀▀█▄█████████▄█▀▀┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼█████████████┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼██▀▀▀███▀▀▀██┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼██┼┼┼███┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼█████▀▄▀█████┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼███████████┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼▄▄▄██┼┼█▀█▀█┼┼██▄▄▄┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼▀▀██┼┼┼┼┼┼┼┼┼┼┼██▀▀┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼\n"
             "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼"
        );

        printf("\nSeu score final foi: %d.", player->score);
        exit(0);
    }
}

void game_manager(struct Node *n, struct RPGGame *game, struct Player *player) {

	autoSave(n, game, player);
    int choice;
    if (n != NULL) {
        if (n->left == NULL && n->right==NULL) {
            endOfChapterManager(n, game, player);
        }

        deathManager(n, player);

        printf("%s\n", n->description);

        printf("Digite sua escolha: ");
        scanf("%d", &choice);
        printf("\n");
        player->score += 5;
        if (choice == 1) {
            game_manager(n->left, game, player);
        } else {
            game_manager(n->right, game, player);
        }

    }

}

int save(struct Node *n, struct RPGGame *game, Player *p, int l) {
    int save_n;
    char file_name[50];
    if (l != 0) {
        printf("Selecione o slot do save (1-6)\n\n");
        scanf("%d", &save_n);
        switch (save_n) {
            case 1:
                strcpy(file_name, "save1.txt");
                break;
            case 2:
                strcpy(file_name, "save2.txt");
                break;
            case 3:
                strcpy(file_name, "save3.txt");
                break;
            case 4:
                strcpy(file_name, "save4.txt");
                break;
            case 5:
                strcpy(file_name, "save5.txt");
                break;
            case 6:
                strcpy(file_name, "save6.txt");
                break;
            default:
                printf("Save slot inválido");
                break;
        }
    } else {
        strcpy(file_name, "autosave.txt");
    }

    FILE *arquivo = fopen(file_name, "w");
    if (arquivo == NULL) {
        printf("Arquivo não enontrado\n\n");
        return 0;
    }

    fprintf(arquivo, "%s\n", p->name);
    fprintf(arquivo, "%d\n", p->score);
	fprintf(arquivo, "%d\n", game->currentTree->key);
    fprintf(arquivo, "%d\n", n->key);

    //printf("\nJOGO SALVO!!!\n");
    fclose(arquivo);

    return 0;

}



FILE *load(struct Node *n, struct RPGGame *game, Player *p, int l) {
    int load_n;
    char file_name[50];
    if (l != 0) {
        printf("Selecione o slot do save (0-6) 0 é o autosave\n\n");
        scanf("%d", &load_n);
        switch (load_n) {
            case 0:
                strcpy(file_name, "autosave.txt");
                break;
            case 1:
                strcpy(file_name, "save1.txt");
                break;
            case 2:
                strcpy(file_name, "save2.txt");
                break;
            case 3:
                strcpy(file_name, "save3.txt");
                break;
            case 4:
                strcpy(file_name, "save4.txt");
                break;
            case 5:
                strcpy(file_name, "save5.txt");
                break;
            case 6:
                strcpy(file_name, "save6.txt");
                break;
            default:
                printf("Save slot inválido");
                break;
        }
    } else
        strcpy(file_name, "autosave.txt");


    FILE *arquivo = fopen(file_name, "r");

    int aux, key;
    char line[256], name[50];

    if (arquivo == NULL) {
        printf("Arquivo não encontrado \n\n");
        return NULL;
    } else {
        fgets(line, 256, arquivo);
        sscanf(line, "%s ", name);
        p->name = name;
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &aux);
        p->score = aux;
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &key);
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &aux);
        printf("SAVE CARREGADO!!\n\n\n");
        fclose(arquivo);
		switch(key){
			case 1:
				game->currentTree = game->chapter1;
				break;				
			case 6:
				game->currentTree = game->chapter2;
				break;				
			case 11:
				game->currentTree = game->chapter3;
				break;			
			case 17:
				game->currentTree = game->chapter4;
				break;				
			case 22:
				game->currentTree = game->chapter5;
				break;				
			case 29:
				game->currentTree = game->chapter6;
				break;				
			case 33:
				game->currentTree = game->chapter7;
				break;				
			case 40:
				game->currentTree = game->chapter8;
				break;
			default:
				exit(1);
		}
		n = searchNode(game->currentTree, aux);
		game_manager(n, game, p);
        return arquivo;
    }

}

void autoSave(struct Node *n, struct RPGGame *game, Player *p) {
    save(n, game, p, 0);
}

void loadautoSave(struct Node *n, struct RPGGame *game, Player *p) {
    load(n, game, p, 0);
}

void newName(Player *p) {
    char temp[50];
    scanf("\n\n%s", temp);
    p->name = temp;
}
