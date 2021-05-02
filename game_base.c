#include "game_classes.h"
#include "game_base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Essa função é resposável por cuidar de um nó quando ele tem um desafio
void chapterWithChallengeManager(struct Node *n, struct Player *player) {
    puts("D E S A F I O");
    // Exibe a pergunta no terminal
    printf("%s\n", n->challenge->description);
    int choice = 0;
    printf("Digite sua resposta: ");
    scanf("%d", &choice);
    printf("\n");


    if (choice == 1 || choice == 2) {
        // Verifica se a resposta do usuario é igual a resposta do desafio
        if (choice == n->challenge->rightAnswer) {

            player->score += 25;
            puts("Você passou pelo desafio! \n");
            // Se sim aumenta o score do player e retorna.
            return;
        } else {
            // Se não o jogo acaba
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
            printf("\nSeu score final foi: %d", player->score);
            exit(0);
        }
    } else {
        puts("ATENÇÃO, AS UNICAS ENTRADAS POSSIVEIS SÃO 1 E 2");
        chapterWithChallengeManager(n, player);
    }


}

// Função responsável por exibir os créditos e o score caso o usuário chegue ao final do jogo
void endOfGameManager(struct Player *player) {
    puts("Obrigado por jogar!\n");
    puts("Desenvolvido e roteirizado por:\n");
    puts("Caio Henrique Marques Meira");
    puts("Everaldo Rosa de Souza Junior");
    puts("Heitor Derber Trevisol");
    printf("\nSeu score final foi: %d", player->score);
    exit(0);
}

// Função responsavel por lidar com nós que são folha de uma árvore e por "enxertar" uma árvore na outra"
void endOfChapterManager(struct Node *n, struct RPGGame *game, struct Player *player) {

    // 41 e 42 são chaves dos últimos nós do último capítulo, por isso são tratados de forma diferente
    if (n->key == 41 || n->key == 42) {
        printf("%s\n", n->description);
        puts(n->nextNodeAsciiArt);
        endOfGameManager(player);
    }
    // Aqui verificamos as chaves do nó
    if (n->key == 4 || n->key == 5) {
        // Aqui printamos o conteúdo do nó
        printf("%s\n", n->description);
        // Aqui acontece o "enxerto" de uma árvore na outra, como conveção, todo "enxerto" é feito do lado esquerdo
        n->left = game->chapter2;
        game->currentTree = game->chapter2;
        // Aqui mostramos uma ascii art que tem relação com o capitulo posterior
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

    // Esse é um caso de um nó que tem desafio
    if (n->key == 12 || n->key == 15 || n->key == 16) {
        printf("%s\n", n->description);

        // Se o nó tiver desafio então chamaos a função de desafio e se for necessário printamos a história de "sucesso" do jogador
        if (n->challenge != NULL) {
            chapterWithChallengeManager(n, player);
            puts("Após isso vocẽ rastreia o ninho e vai em busca de informações");
        }
        n->left = game->chapter4;
        // Após o desafio o enxerto ocorre normalmente
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

// Essa é a função que cuida do Game Over
void deathManager(struct Node *n, struct Player *player) {

    // Alguns nós não tem desafio, e são considerados "falhas críticas" que fazem o jogador perder na hora
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

        printf("\nSeu score final foi: %d", player->score);
        exit(0);
    }
}

// Essa é a função que toma conta do jogo todo, checa se é fim de capítulo, faz a recursão e etc.
void game_manager(struct Node *n, struct RPGGame *game, struct Player *player) {

    save(n, game, player);
    int choice;
    if (n != NULL) {
        // Aqui vemos se o nó atual é folha, se sim, chamamos a função que cuida de nós que são folha (fim de capítulo)
        if (n->left == NULL && n->right == NULL) {
            endOfChapterManager(n, game, player);
        }

        // Função responsável por saber se o nó atual é um nó de "falha crítica"
        deathManager(n, player);


        printf("%s\n", n->description);

        printf("Digite sua escolha: ");
        scanf("%d", &choice);
        printf("\n");
        // Cada nó passado recebe +5 no score
        player->score += 5;
        if (choice == 1) {
            game_manager(n->left, game, player);
        } else if (choice == 2) {
            game_manager(n->right, game, player);
        } else {
            puts("ATENÇÃO, AS UNICAS ENTRADAS POSSIVEIS SÃO 1 E 2");
            game_manager(n, game, player);
        }

    }

}

// Função encarregada de salvar o jogo automaticamente a cada nó passado no jogo
int save(struct Node *n, struct RPGGame *game, Player *p) {
    char file_name[50];
    strcpy(file_name, "autosave.txt");

    // Abre o arquivo ou cria um novo para escrever os atributos a serem salvados
    FILE *arquivo = fopen(file_name, "w");

    // Teste de segurança caso ocorra um erro na abertura do arquivo
    if (arquivo == NULL) {
        printf("Arquivo não enontrado\n\n");
        return 0;
    }

    fprintf(arquivo, "%s\n", p->name);
    fprintf(arquivo, "%d\n", p->score);
    fprintf(arquivo, "%d\n", game->currentTree->key);
    fprintf(arquivo, "%d\n", n->key);

    fclose(arquivo);

    return 0;

}

// Função encarregada de carregar o jogo caso o usuário deseje no menu inicial do jogo
FILE *load(struct Node *n, struct RPGGame *game, Player *p) {
    char file_name[50];
    strcpy(file_name, "autosave.txt");

    FILE *arquivo = fopen(file_name, "r");

    int aux, key;
    char line[256], name[50];
    // Teste de segurança caso o arquivo não seja encontrado
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

        // Switch utilizado para definir o capítulo em que o jogo foi salvado

        switch (key) {
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

// Função que percorre a árvore do cápitulo e procura o nó desejado
struct Node *searchNode(struct Node *n, int key) {
    if (n == NULL)
        return NULL;
    else if (n->key == key)
        return n;

    else {
        Node *a = searchNode(n->left, key);
        if (a == NULL)
            a = searchNode(n->right, key);
        return a;
    }
}

// Função responsável por atribuir o nome do jogador a Struct do Player
void newName(Player *p) {
    char temp[50];
    printf("Digite seu nome: ");
    scanf("\n\n%s", temp);
    p->name = temp;
}
