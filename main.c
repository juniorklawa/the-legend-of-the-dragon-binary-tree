#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    char* description;
    struct Node *left, *right;
    int isEndOfChapter;
    char* nextNodeAsciiArt;
};

typedef struct Player {
    int health;
    int score;
    char* name;
    int class;
};

typedef struct RPGGame {
    struct Node *introduction;
    struct Node *firstChapter;
    struct Node *secondChapter;
    struct Node *currentTree;
    int gameStatus;
};

struct RPGGame *newRPGGame(struct Node *introduction, struct Node *firstChapter, struct Node *secondChapter) {
    struct RPGGame *RPGGame = (struct RPGGame *)malloc(sizeof(struct RPGGame));
    RPGGame->introduction = introduction;
    RPGGame->firstChapter = firstChapter;
    RPGGame->secondChapter = secondChapter;
    RPGGame->currentTree = introduction;
    RPGGame->gameStatus = 0;
    return RPGGame;
}




struct Node *newNode(int k, char* description) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->description = description;
    node->right = node->left = NULL;
    return node;
}

struct Node *newNodeEndOfChapter(int k, char* description, char* nextAsciiCode) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->description = description;
    node->isEndOfChapter = 1;
    node->nextNodeAsciiArt = nextAsciiCode;
    node->right = node->left = NULL;
    return node;
}

struct Player *newPlayer(int health, int score, char* name, int class){
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));
    player->name = name;
    player->class = 0;
    player->health = 100;
    player->score = 0;
}


void print_story (struct  Node *n, struct RPGGame *game){

    int choice = 0;
    if (n != NULL) {
        if(n->isEndOfChapter == 1){
            if(n->key == 4 || n->key == 5){
                printf ("%s\n", n->description);
                n->left = game->firstChapter;
                puts(n->nextNodeAsciiArt);
                print_story(n->left,game);
            }

            if(n->key == 9 || n->key == 10){
                printf ("%s\n", n->description);
                n->left = game->secondChapter;
                puts(n->nextNodeAsciiArt);
                print_story(n->left,game);
            }

        }

        if(n->key == 8 || n->key == 12) {
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

        printf ("%s\n", n->description);
        scanf("%d", &choice);
        if(choice == 1){
            print_story(n->left, game);
        } else {
            print_story(n->right, game);
        }
    }

}


void game_controller (struct RPGGame *game) {
    print_story(game->currentTree, game);
}

int main() {




    char *firstChapterAscii =  "                .-~~~~~~~~~-._       _.-~~~~~~~~~-.\n"
                               "            __.'              ~.   .~              `.__\n"
                               "          .'//                  \\./                  \\\\`.\n"
                               "        .'//                     |                     \\\\`.\n"
                               "      .'// .-~\"\"\"\"\"\"\"~~~~-._     |     _,-~~~~\"\"\"\"\"\"\"~-. \\\\`."
                               "    .'//.-\"                 `-.  |  .-'                 \"-.\\\\`.\n"
                               "  .'//______.============-..   \\ | /   ..-============.______\\\\`.\n"
                               ".'______________________________\\|/______________________________`.\n"
                               "\n"
                             ;



    char *mageAscii =  "       ___\n"
                       "       )_(                                            _\n"
                       "       | |                                           [_ ]\n"
                       "     .-'-'-.       _                               .-'. '-.\n"
                       "    /-::_..-\\    _[_]_                            /:;/ _.-'\\\n"
                       "    )_     _(   /_   _\\      [-]                  |:._   .-|\n"
                       "    |;::    |   )_``'_(    .-'-'-.       (-)      |:._     |\n"
                       "    |;::    |   |;:   |    :-...-:     .-'-'-.    |:._     |\n"
                       "    |;::    |   |;:   |    |;:   |     |-...-|    |:._     |\n"
                       "    |;::-.._|   |;:.._|    |;:.._|     |;:.._|    |:._     |\n"
                       "    `-.._..-'   `-...-'    `-...-'     `-...-'    `-.____.-'\n"
    ;


    char *warriorAscii =  "                           .-.\n"
                          "                          {{@}}\n"
                          "          <>               8@8\n"
                          "        .::::.             888\n"
                          "    @\\\\/W\\/\\/W\\//@         8@8\n"
                          "     \\\\/^\\/\\/^\\//     _    )8(    _\n"
                          "      \\_O_<>_O_/     (@)__/8@8\\__(@)\n"
                          " ____________________ `~\"-=):(=-\"~`\n"
                          "|<><><>  |  |  <><><>|     |.|\n"
                          "|<>      |  |      <>|     |S|\n"
                          "|<>      |  |      <>|     |'|\n"
                          "|<>   .--------.   <>|     |.|\n"
                          "|     |   ()   |     |     |P|\n"
                          "|_____| (O\\/O) |_____|     |'|\n"
                          "|     \\   /\\   /     |     |.|\n"
                          "|------\\  \\/  /------|     |U|\n"
                          "|       '.__.'       |     |'|\n"
                          "|        |  |        |     |.|\n"
                          ":        |  |        :     |N|\n"
                          " \\<>     |  |     <>/      |'|\n"
                          "  \\<>    |  |    <>/       |.|\n"
                          "   \\<>   |  |   <>/        |K|\n"
                          "    `\\<> |  | <>/'         |'|\n"
                          "       `-.|  |.-`           \\ /\n"
                          "          '--'               ^\n"
    ;





    struct Node *introductionTree = newNode(1,
                                              "\n"
                                              "Você acorda dentro de uma prisão, sem se lembrar muito como foi parar lá, enquanto você tenta se lembrar como foi parar preso um guarda aparece na porta e diz:\n"
                                              "\n"
                                              "- De pé, prisioneiro. Preciso que você confirme algumas informações para mim.\n"
                                              "\n"
                                              "Prisioneiro, alguem la fora gosta muito de você e pagou sua fiança, pegue suas coisas e se retire da prisão.\n"
                                              "\n"
                                              "1. Pegar suas coisas e sair\n"
                                              "2. Atacar o guarda");



    introductionTree->left = newNode(2,"Ao sair da prisão você vai para a Taverna pedir uma bebida, quando um homem estranho aparece na sua frente.\n"
                                                   "\n"
                                                   "1. Perguntar ao Homem o que ele quer.\n"
                                                   "2. Ignorar o homem.");

    introductionTree->right = newNode(3,"Por algum motivo (que nem você entende direito) você ataca o guarda o derruba no chão. Os outros soldados logo percebem o ataque e partem pra cima de você, eles te imobilizam e dias depois você é condenado a forca.,");

    introductionTree->left->left = newNodeEndOfChapter(4,"Você olha para o homem e pergunta o que ele quer",firstChapterAscii);

    introductionTree->left->right = newNodeEndOfChapter(5,"Você ignora o homem e continua bebendo.\n"
                                              "\n"
                                              "- ",firstChapterAscii);




    struct Node *firstChapter = newNode(6,"O homem se aproxima da mesa, sem falar nada e deixa uma carta e sai.\n"
                                          "\n"
                                          "Após achar tudo isso muito estranho, você espera o homem sair do local e abre a carta:\n"
                                          "\n"
                                          "A carta diz:\n"
                                          "\n"
                                          "\n"
                                          "Siga para o Sul, encontra a caverna secreta, mate o Dragão e recupere meu tesouro, você é o unico capaz de fazer isso!\n"
                                          "\n"
                                          "Você fecha a carta e:\n"
                                          "\n"
                                          "\n"
                                          "1. Vai até o dono da Taverna perguntar se ele sabem quem era o homem misterioso.\n"
                                          "\n"
                                          "2. Sai com pressa ta taberna para chegar o mais rapido possivel no lugar que o mapa indica");


    firstChapter->left = newNode(7,"Você pergunta para o dono da Taverna quem era aquele homem e ele te responde:\n"
                                   "\n"
                                   "- Ele me pediu para não revelar sua identidade, mas me disse que você deveria escolher um desses dois equipamentos.\n"
                                   "\n"
                                   "O Taberneiro te leva para a parte de trás do local e te mostra equipamentos de um guerreiro e equipamentos de um mago e um cavalo, o que você escolhe?\n"
                                   "\n"
                                   "\n"
                                   "1. Guerreiro\n"
                                   "2. Mago");
    firstChapter->right = newNode(8, "Você sai com pressa da taberna em direção ao sul, mas vocẽ não tem equipamento, nem comida, nem cavalo. Após 4h de viagem, um grupo de Goblins te ataca e você morre.");
    firstChapter->left->left = newNodeEndOfChapter(9,"Você se lembra que antes da prisão era um guerreiro muito famoso e escolhe o equipamento do guerreiro",warriorAscii);
    firstChapter->right->left = newNodeEndOfChapter(10, "Você se lembra que antes da prisão era um mago muito famoso e escolhe o equipamento de mago.",mageAscii);



    struct Node *secondChapter = newNode(11,"Após vários dias de viagem, você encontra a caverna com ajuda da carta que o homem misterioso deixou para você.\n"
                                           "\n"
                                           "\n"
                                           "Ao entrar na caverna você começar a ver manchas negras nas parades, como se tivessem sido queimadas pelo fogo.\n"
                                           "\n"
                                           "Ao adentrar ainda mais na caverna, você vê o dragão estirado no chão, e logo abaixo dele um bau com o mesmo selo que está na carta que você recebeu.\n"
                                           "\n"
                                           "\n"
                                           "1. Você acha que o dragão está morto e vai diretamente para o bau\n"
                                           "2. Você se aproxima lentamente e ataca o dragão no coração");


    secondChapter->left = newNode(12,"Vocẽ sai correndo em diração ao bau, tropeça em uma pedra e cai no chão.\n"
                                     "\n"
                                     "O Dragão acorda com o barulho e te dá um ataque mortal, você morre.");
    secondChapter->right = newNode(13, "Você se aproxima lentamente do dragão e (ataque mortal dependendo da classe)\n"
                                       "\n"
                                       "O Dragão morre e você fica rico.");
























    struct RPGGame *rpgGame = newRPGGame(introductionTree,firstChapter, secondChapter);


    puts("   ▄████████       ▄█          ▄████████ ███▄▄▄▄   ████████▄     ▄████████      ████████▄   ▄██████▄       ████████▄     ▄████████    ▄████████    ▄██████▄     ▄████████  ▄██████▄  \n"
         "  ███    ███      ███         ███    ███ ███▀▀▀██▄ ███   ▀███   ███    ███      ███   ▀███ ███    ███      ███   ▀███   ███    ███   ███    ███   ███    ███   ███    ███ ███    ███ \n"
         "  ███    ███      ███         ███    █▀  ███   ███ ███    ███   ███    ███      ███    ███ ███    ███      ███    ███   ███    ███   ███    ███   ███    █▀    ███    ███ ███    ███ \n"
         "  ███    ███      ███        ▄███▄▄▄     ███   ███ ███    ███   ███    ███      ███    ███ ███    ███      ███    ███  ▄███▄▄▄▄██▀   ███    ███  ▄███          ███    ███ ███    ███ \n"
         "▀███████████      ███       ▀▀███▀▀▀     ███   ███ ███    ███ ▀███████████      ███    ███ ███    ███      ███    ███ ▀▀███▀▀▀▀▀   ▀███████████ ▀▀███ ████▄  ▀███████████ ███    ███ \n"
         "  ███    ███      ███         ███    █▄  ███   ███ ███    ███   ███    ███      ███    ███ ███    ███      ███    ███ ▀███████████   ███    ███   ███    ███   ███    ███ ███    ███ \n"
         "  ███    ███      ███▌    ▄   ███    ███ ███   ███ ███   ▄███   ███    ███      ███   ▄███ ███    ███      ███   ▄███   ███    ███   ███    ███   ███    ███   ███    ███ ███    ███ \n"
         "  ███    █▀       █████▄▄██   ██████████  ▀█   █▀  ████████▀    ███    █▀       ████████▀   ▀██████▀       ████████▀    ███    ███   ███    █▀    ████████▀    ███    █▀   ▀██████▀  \n"
         "                  ▀                                                                                                     ███    ███                                                   ");




    game_controller(rpgGame);

}




