#include "game_classes.h"
#include "game_base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void chapterWithChallengeManager(struct  Node *n, struct RPGGame *game) {
    if(n->key == 3){
        puts("D E S A F I O");
        printf ("%s\n", n->challenge->description);
        int choice = 0;
        scanf("%d", &choice);

        if(choice == n->challenge->rightAnswer){
            puts("Você passou pelo desafio! \n\n");
            n->left = game->firstChapter->left;
            game_manager(n->left, game);
        } else {
            //diminuir vida do player
            puts("Você morreu.");
            puts("  .---.\n"
                 " /     \\\n"
                 "( () () )\n"
                 " \\  M  / \n"
                 "  |HHH|\n"
                 "  `---'\n"
                 "\n"
            );
        }
    }
}

void deathManager(struct  Node *n) {
//    if(n->key == 8 || n->key == 12) {
//
//        printf ("%s\n", n->description);
//
//        puts("Você morreu.");
//        puts("  .---.\n"
//             " /     \\\n"
//             "( () () )\n"
//             " \\  M  / \n"
//             "  |HHH|\n"
//             "  `---'\n"
//             "\n"
//        );
//
//        exit(0);
//    }
}

void game_manager (struct  Node *n, struct RPGGame *game){

    int choice = 0;
    if (n != NULL) {

        if(n->challenge != NULL){
            chapterWithChallengeManager(n,game);
        }

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

int save(Player *p, int key, int l){
    int save_n;
    char file_name[50];
        if (l != 0) {
                printf ("Selecione o slot do save (1-6)\n\n");
                scanf ("%d", &save_n);
                switch (save_n){
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
        }
        else {
                strcpy(file_name, "autosave.txt");
        }

    FILE *arquivo = fopen(file_name, "w");
    if(arquivo==NULL) {
        printf("Arquivo não enontrado\n\n");
        return 0;
    }

    fprintf(arquivo, "%s\n", p->name);
    fprintf(arquivo, "%d\n", p->health);
    fprintf(arquivo, "%d\n", p->score);
    fprintf(arquivo, "%d\n", p->class);
    fprintf(arquivo, "%d\n", key);

    printf("\nJOGO SALVO!!!\n");
    fclose(arquivo);

    return 0;

}

FILE * load(Player *p, int *key, int l){
    int load_n;
    char file_name[50];
        if (l != 0){
                printf ("Selecione o slot do save (0-6) 0 é o autosave\n\n");
                scanf ("%d", &load_n);
                switch (load_n){
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
        }
        else
                strcpy(file_name, "autosave.txt");
			
			
    FILE *arquivo = fopen(file_name, "r");

    int aux;
    char line[256], name[50];

    if(arquivo == NULL){
        printf("Arquivo não encontrado \n\n");
        return NULL;
    }
    else{
        fgets(line, 256, arquivo);
        sscanf(line, "%s ", name);
        p->name = name;
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &aux);
        p->health = aux;
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &aux);
        p->score = aux;
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &aux);
        p->class = aux;
        fgets(line, 256, arquivo);
        sscanf(line, "%d ", &aux);
        *key = aux;
        printf("SAVE CARREGADO!!\n\n\n");
        fclose(arquivo);
        return arquivo;
    }

}

void autoSave (Player *p, int key){
    save(p, key, 0);
}

void loadautoSave(Player *p, int *key){
    int aux;
    load(p, &aux, 0);
    *key = aux;
}

void newName(Player *p){
	char temp[50];	
	scanf("\n\n%s", temp);
	p->name = temp;
}
