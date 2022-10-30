/*
EMANUEL JESUS SANTOS
TURMA A - MODULO 2;

SISTEMA DE CADASTRO E LISTAGEM v.3;
UTILIZANDO PONTEIROS E LISTA ENCADEADA;

ALGORITMO E ESTRUTURA DE DADOS;
PROFESSOR: MAURICIO BEGNINI;
*/

#include <stdlib.h>
#include <stdio.h>

// STRUCT
typedef struct _no {
    void *element;
    struct _no *prox;
} No;

typedef struct _list {
    No *first;
    No *last;
    int size;
} List;

typedef struct _personagem {
    int ID;
    char nome[20];
    int idade;
} Personagem;

typedef struct _Jogo {
    int ID;
    char titulo[20];
    int anoJogo;

    List *personagens;
} Jogo;

typedef struct _empresa {
    int ID;
    char nome[20];
    char paisFund[20];
    int anoFund;

    List *jogos;
} Empresa;

// DECL FUNCTIONS
void menu();      // OK
void menuOp();    // OK 
List *crtList();  // OK 
void inserir();   // OK 
void *cadEmp();   // OK
void listEmp();   // OK 
void *cadJogo();  // OK 
void listJogo();  // OK
void *cadPerso(); // OK
void listPerso(); // OK
void *buscar();   // OK 
int rmv();        // OK 

// MAIN CODE
void main () {
    List *empresas = crtList();
    List *jogos = crtList();
    List *personagens = crtList();
    Empresa *emp;
    Jogo *game;
    Personagem *perso;
    int op = 1, idEmp = 0, idJogo = 0, idPerso = 0;
    int pos;

    while (op != 0) {
        menu();
        scanf(" %d", &op);

        switch (op) {
        case 1: // CADASTRAR
            system("cls");
            puts("O QUE DESEJA CADASTRAR:\n");
            menuOp();
            scanf(" %d", &op);

            switch (op) {
            case 1: // CAD EMP
                system("cls");
                cadEmp(empresas, idEmp);
                idEmp++;
                puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                system("pause");
                system("cls");
                break;
                
            case 2: //CAD JOGO
                system("cls");
                cadJogo(jogos, idJogo);
                idJogo++;
                puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                system("pause");
                system("cls");
                break;

            case 3: // CAD PERSO
                system("cls");
                cadPerso(personagens, idPerso);
                idPerso++;
                puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                system("pause");
                system("cls");
                break;

            default:
                system("cls");
                puts("\nOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
                break;
            } 
            break; // CADASTRAR
        
        case 2: // LISTAR
            system("cls");
            puts("O QUE DESEJA LISTAR:\n");
            menuOp();
            scanf(" %d", &op);

            switch (op) {
            case 1: // LISTAR EMPRESAS
                if (empresas->size != 0) {
                    system("cls");
                    listEmp(empresas);
                    system("pause");
                    system("cls");
                } else {
                    system("cls");
                    puts("NENHUMA EMPRESA CADASTRADA NO SISTEMA.\n");
                }
                break;
            
            case 2: // LISTAR JOGOS
                if (jogos->size != 0) {
                    system("cls");
                    puts("1 - LISTAR TODOS OS JOGOS");
                    puts("2 - LISTAR JOGOS DE UMA EMPRESA ESPECIFICA");
                    puts("");
                    scanf(" %d", &op);

                    switch (op) {
                    case 1:
                        system("cls");
                        listJogo(jogos);
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        if (empresas->size != 0) {
                            system("cls");
                            listEmp(empresas);
                            puts("DE QUAL EMPRESA DESEJA LISTAR OS JOGOS:\n");
                            scanf(" %d", &pos);

                            emp = buscar(empresas, pos);

                            if (emp != NULL && pos != emp->jogos->size) {
                                puts("");
                                listJogo(emp->jogos);
                                system("pause");
                                system("cls");
                            } else {
                                system("cls");
                                puts("NENHUM JOGO RELACIONADO A ESSA EMPRESA NO SISTEMA.\n");
                            }
                        } else {
                            system("cls");
                            puts("NENHUMA EMPRESA CADASTRADA NO SISTEMA.\n");
                        }
                        break;
                        
                    default:
                        system("cls");
                        puts("\nOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
                        break;
                    }
                } else {
                    system("cls");
                    puts("NENHUM JOGO CADASTRADO NO SISTEMA.\n");
                }
                break; // LISTAR JOGOS

            case 3: // LISTAR PERSONAGENS
                if (personagens->size != 0) {
                    system("cls");
                    puts("1 - LISTAR TODOS OS PERSONAGENS");
                    puts("2 - LISTAR PERSONAGENS DE UM JOGO ESPECIFICO");
                    puts("");
                    scanf(" %d", &op);

                    switch (op) {
                    case 1:
                        system("cls");
                        listPerso(personagens);
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        if (jogos->size != 0) {
                            system("cls");
                            listJogo(jogos);
                            puts("DE QUAL JOGO DESEJA LISTAR OS PERSONAGENS:\n");
                            scanf(" %d", &pos);
                            
                            game = buscar(jogos, pos);
                            
                            if (game != NULL && game->personagens->size != 0) {
                                puts("");            
                                listPerso(game->personagens);
                                system("pause");
                                system("cls");
                            } else {
                                system("cls");
                                puts("NENHUM PERSONAGEM RELACIONADO A ESSE JOGO NO SISTEMA.\n");
                            }
                        } else {
                            system("cls");
                            puts("NENHUM JOGO CADASTRADO NO SISTEMA.\n");
                        }
                        break;

                    default:
                        system("cls");
                        puts("\nOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
                        break;
                    }
                } else {
                    system("cls");
                    puts("NENHUM PERSONAGEM CADASTRADO NO SISTEMA.\n");
                }
                break; // LISTAR PERSONAGENS

                default:
                    system("cls");
                    puts("\nOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
                    break;
            } 
            break; // LISTAR

        case 3: // ASSOCIAR
            if (empresas->size != 0 || jogos->size != 0 || personagens->size != 0) {
                system("cls");
                puts("1 - ASSOCIAR JOGO A EMPRESA");
                puts("2 - ASSOCIAR PERSONAGEM A JOGO");
                puts("");
                scanf(" %d", &op);

                switch (op) {
                case 1: // ASSOCIAR JOGO A EMPRESA
                    if (empresas->size != 0 && jogos->size != 0) {
                        system("cls"); 
                        listJogo(jogos);
                        puts("QUAL JOGO DESEJA ASSOCIAR: ");
                        scanf(" %d", &pos);

                        game = buscar(jogos, pos);
                        puts("");

                        listEmp(empresas);
                        puts("\nEM QUAL EMPRESA O JOGO SERA ASSOCIADO: ");
                        scanf(" %d", &pos);

                        emp = buscar(empresas, pos);

                        if (game != NULL && emp != NULL) {
                            inserir(emp->jogos, game);
                            puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                            system("pause");
                            system("cls");

                        } else {
                            system("cls");
                            puts("\nID DA EMPRESA OU DO JOGO INVALIDO\nTENTE NOVAMENTE.\n");
                            system("pause");
                            system("cls");
                        }
                    } else {
                        system("cls");
                        puts("NENHUMA EMPRESA OU JOGO CADASTRADO NO SISTEMA.\n");
                    } // ASSOCIAR EMPRESA  
                    break;

                case 2: // ASSOCIAR PERSONAGEM A JOGO
                    if (jogos->size != 0 && personagens->size != 0) {
                        system("cls");
                        listPerso(personagens);
                        puts("QUAL PERSONAGEM DESEJA ASSOCIAR: ");
                        scanf(" %d", &pos);

                        perso = buscar(personagens, pos);
                        puts("");

                        listJogo(jogos);
                        puts("\nEM QUAL JOGO O PERSONAGEM SERA ASSOCIADO: ");
                        scanf(" %d", &pos);

                        game = buscar(jogos, pos);

                        if (perso != NULL && emp != NULL) {
                            inserir(game->personagens, perso);
                            puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                            system("pause");
                            system("cls");

                        } else {
                            system("cls");
                            puts("\nID DO JOGO OU DO PERSONAGEM INVALIDO\nTENTE NOVAMENTE.\n");
                            system("pause");
                            system("cls");
                        }

                    } else {
                        system("cls");
                        puts("NENHUM JOGO OU PERSONAGEM CADASTRADO NO SISTEMA\n");
                    }
                        break;

                    default:
                    system("cls");
                    puts("\nOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
                    break;
                } 
            } else {
                system("cls");
                puts("NENHUMA INFORAMCAO CADASTRADA NO SISTEMA.\n");
            }
            break; // ASSOCIAR

        case 4: // DESASSOCIAR
            if (empresas->size != 0 || jogos->size != 0 || personagens->size != 0) {
                system("cls");
                puts("1 - DESASSOCIAR JOGO A EMPRESA");
                puts("2 - DESASSOCIAR PERSONAGEM A JOGO");
                puts("");
                scanf(" %d", &op);

                switch (op) {
                case 1: // DESASSOCIAR JOGO DA EMPRESA
                    if (empresas->size != 0 && jogos->size != 0) {
                        system("cls");
                        listEmp(empresas);
                        puts("DE QUAL EMPRESA O JOGO SERA DESASSOCIADO: ");
                        scanf(" %d", &pos);

                        emp = buscar(empresas, pos);

                        if (emp != NULL && pos != emp->jogos->size) {
                            puts("");
                            listJogo(emp->jogos);
                            puts("QUAL JOGO SERA DESASSOCIADO: ");
                            scanf(" %d", &pos);

                            rmv(emp->jogos, pos);
                            puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                            system("pause");
                            system("cls");
                        } else {
                            system("cls");
                            puts("ID DA EMPRESA INVALIDO\nTENTE NOVAMENTE.\n");
                        }
                    } else {
                        system("cls");
                        puts("NENHUMA EMPRESA OU JOGO CADASTRADO NO SISTEMA.\n");
                    }
                    break;

                case 2: // DESASSOCIAR PERSONAGEM DE JOGO
                    if (jogos->size != 0 && personagens->size != 0) {
                        system("cls");
                        listJogo(jogos);
                        puts("DE QUAL JOGO O PERSONAGEM SERA DESASSOCIADO: ");
                        scanf(" %d", &pos);

                        game = buscar(jogos, pos);

                        if (game != NULL && pos != game->personagens->size) {
                            puts("");
                            listPerso(game->personagens);
                            puts("QUAL PERSONAGEM SERA DESASSOCIADO: ");
                            scanf(" %d", &pos);

                            rmv(game->personagens, pos);
                            puts("\nOPERACAO REALIZADA COM SUCESSO!\n\n\n");
                            system("pause");
                            system("cls");
                        } else {
                            system("cls");
                            puts("ID DA EMPRESA INVALIDO\nTENTE NOVAMENTE.\n");
                        }
                    } else {
                        system("cls");
                        puts("NENHUM JOGO OU PERSONAGEM CADASTRADO NO SISTEMA\n");
                    }
                    break;
                }
            } else {
                system("cls");
                puts("NENHUMA INFORAMCAO CADASTRADA NO SISTEMA.\n");
            }
            break; // DESASSOCIAR
            

        default:
            system("cls");
            puts("\nOPERACAO INVALIDA!\nESCOLHA APENAS UMA DAS OPCOES LISTADA.\n\n");
            break;
        } //SWITCH PRINCIPAL
    } // WHILE
}

// FUNC DEV
void menu() {
    puts("QUAL OPERACAO DESEJA REALIZAR:\n");
    puts("0 - SAIR");
    puts("1 - CADASTRAR");
    puts("2 - LISTAR");
    puts("3 - ASSOCIAR ENTIDADE EXISTENTE");
    puts("4 - DESASSOCIAR ENTIDADE EXISTENTE");
    puts("");
}

void menuOp() {
    puts("1 - EMPRESA");
    puts("2 - JOGO");
    puts("3 - PERSONAGENS");
    puts("");
}

List *crtList() {
    List *newList = (List *)malloc(sizeof(List));

    newList->first = NULL;
    newList->last = NULL;
    newList->size = 0;

    return newList;
}

void inserir(List *list, void *newElement) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->element = newElement;
    novoNo->prox = NULL;

    if(list->size == 0) {
        list->first = novoNo;
        list->last = novoNo;
        list->size++;
    } else {
        list->last->prox = novoNo;
        list->last = novoNo;
        list->size++;
    }
}

void *cadEmp(List *empresas, int idEmp) {
    Empresa *newEmp = (Empresa *)malloc(sizeof(Empresa));
    newEmp->ID = idEmp;

    puts("\nNome da Empresa: ");
    scanf(" %[^\n]s", newEmp->nome);
    puts("\nPais em que a empresa foi fundada: ");
    scanf(" %[^\n]s", newEmp->paisFund);
    puts("\nAno em que a empresa foi fundada: ");
    scanf(" %d", &newEmp->anoFund);

    newEmp->jogos = crtList();

    inserir(empresas, (void *) newEmp);
}

void listEmp (List *empresa) {
    No *aux = empresa->first;
    Empresa *emp;

    while (aux != NULL) {
        emp = (Empresa *) aux->element;
        printf("ID: %d\t|NAME: %s\t|COUNTRY: %s\t|RELEASE YEAR: %d\t|N. GAMES: %d\n", emp->ID, emp->nome, emp->paisFund, emp->anoFund, emp->jogos->size);
        aux = aux->prox;
    }
    puts("\n");
}

void *cadJogo(List *jogos, int idJogo) {
    Jogo *newGame = (Jogo *)malloc(sizeof(Jogo));
    newGame->ID = idJogo;

    puts("\nNome do jogo: ");
    scanf(" %[^\n]s", newGame->titulo);
    puts("\nAno do jogo: ");
    scanf(" %d", &newGame->anoJogo);

    newGame->personagens = crtList();

    inserir(jogos, (void *) newGame);
}

void listJogo(List *jogos) {
    No *aux = jogos->first;
    Jogo *game;

    while (aux != NULL) {
        game = (Jogo *) aux->element;
        printf("ID: %d\t|TITLE: %s\t|RELEASE YEAR: %d\t|N.CHARACTERS: %d\n", game->ID, game->titulo, game->anoJogo, game->personagens->size);
        aux = aux->prox;
    }
    puts("\n");
}

void *cadPerso(List *personagens, int idPerso) {
    Personagem *newPerso = (Personagem *)malloc(sizeof(Personagem));
    newPerso->ID = idPerso;

    puts("\nNome do personagem: ");
    scanf(" %[^\n]s", newPerso->nome);
    puts("\nIdade do Personagem: ");
    scanf(" %d", &newPerso->idade);

    inserir(personagens, (void *) newPerso);
}

void listPerso(List *personagens) {
    No *aux = personagens->first;
    Personagem *perso;

    while (aux != NULL) {
        perso = (Personagem *) aux->element;
        printf("ID: %d\t|NAME: %s\t|AGE: %d\n", perso->ID, perso->nome, perso->idade);
        aux = aux->prox;
    }
    puts("\n");
}

void *buscar(List *lista, int pos) {
    if (pos < 0 || pos >= lista->size) {
        return NULL;
    } else {
        No *aux = lista->first;
        for (int i = 0; i < pos; i++) {
            aux = aux->prox;
        }
        return aux->element;
    }
}

int rmv(List *lista, int pos) {
    if(pos < 0 || pos >= lista->size) {
        return -1;
    } 

    if (lista->size == 1) {
        lista->first = NULL;
        lista->last = NULL;
        lista->size--;
        return 0;
    }

    if (pos == 0) {
        lista->first = lista->first->prox;
        lista->size--;
        return 0;
    }

    No *aux = lista->first;
    for (int i = 0; i < pos-1; i++) {
        aux = aux->prox;       
    }
    aux->prox = aux->prox->prox;

    if (lista->size-1 == pos) {
        lista->last = aux;
    }
    lista->size--;
    return 0;
}