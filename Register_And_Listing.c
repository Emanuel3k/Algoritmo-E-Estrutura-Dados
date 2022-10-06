/*
EMANUEL JESUS SANTOS
TURMA A - MODULO 2;

SISTEMA DE CADASTRO E LISTAGEM v.2;
UTILIZANDO PONTEIROS;

ALGORITMO E ESTRUTURA DE DADOS;
PROFESSOR: MAURICIO BEGNINI;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCT
typedef struct _personagem
{
    int ID;
    char nome[20];
    int idade;

} Personagem;

typedef struct _jogo
{
    int ID;
    char titulo[20];
    int anoJogo;

    Personagem *personagens[10];
    int numPerso;

} Jogo;

typedef struct _empresa
{
    int ID;
    char nome[20];
    char pais[20];
    int anoFund;

    Jogo *jogos[10];
    int numJogo;

} Empresa;

// DECL FUNCTIONS
void Menu();            // OK
void MenuListJogo();    // OK
void MenuListPerso();   // OK
Empresa *CadEmp();      // OK
void ListEmp();         // OK
Jogo *CadJogo();        // OK
void ListJogo();        // OK
Personagem *CadPerso(); // OK
void ListPerso();       // OK
void *CadJogoEmp();     // OK
void *CadPersoJogo();   // OK

// MAIN CODE
void main()
{
    // VARIAVEIS
    Empresa *empresas[10];
    Jogo *jogos[10];
    Personagem *personagens[10];
    int idEmp = 0, idJogo = 0, idPerso = 0;
    int posEmp, posJogo, posPerso;
    int op;

    while (op != 0)
    {
        Menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1: // CADASTRAR EMPRESA
            system("cls");
            empresas[idEmp] = CadEmp(idEmp);
            idEmp++;
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        case 2: // LISTAR EMPRESAS
            if (idEmp == 0)
            {
                system("cls");
                puts("\nNenhuma empresa cadastrada no sistema.\n\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                ListEmp(empresas, idEmp);
                system("pause");
                system("cls");
            }
            break;

        case 3: // CADASTRAR JOGO
            system("cls");
            jogos[idJogo] = CadJogo(idJogo);
            idJogo++;
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        case 4: // LISTAR JOGOS
            if (idJogo == 0)
            {
                system("cls");
                puts("\nNenhum jogo cadastrado no sistema.\n\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                MenuListJogo();
                scanf("%d", &op);

                switch (op)
                {
                case 1: // LISTAR TODOS OS JOGOS
                    system("cls");
                    ListJogo(jogos, idJogo);
                    system("pause");
                    system("cls");
                    break;

                case 2: // LISTAR JOGO ESPECIFICO
                    if (idEmp == 0)
                    {
                        system("cls");
                        puts("\nNenhuma empresa cadastrada no sistema.\n\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        ListEmp(empresas, idEmp);
                        puts("De qual empresa deseja visualizar os jogos ?");
                        scanf("%d", &posEmp);
                        if (empresas[posEmp]->numJogo == 0)
                        {
                            system("cls");
                            puts("\nEssa empresa nao cadastrou nenhum jogo no sistema\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            system("cls");
                            ListJogo(empresas[posEmp]->jogos, idJogo);
                            system("pause");
                            system("cls");
                        }
                    }
                    break;

                default:
                    system("cls");
                    puts("\nOperacao Invalida!\n");
                    break;
                }
            }
            break;

        case 5: // CADASTRAR PERSONAGEM
            system("cls");
            personagens[idPerso] = CadPerso(idPerso);
            idPerso++;
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        case 6: // LISTAR PERSONAGENS
            if (idPerso == 0)
            {
                system("cls");
                puts("\nNenhum personagem cadastrado no sistema.\n\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                MenuListPerso();
                scanf("%d", &op);

                switch (op)
                {
                case 1: // LISTAR TODOS OS PERSONAGENS
                    system("cls");
                    ListPerso(personagens, idPerso);
                    system("pause");
                    system("cls");
                    break;

                case 2: // LISTAR PERSONAGEM ESPECIFICO
                    if (idPerso == 0)
                    {
                        system("cls");
                        puts("\nNenhum personagem cadastrado no sistema.\n\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        ListJogo(jogos, idJogo);
                        puts("De qual jogo deseja visualizar os personagens ?");
                        scanf("%d", &posJogo);
                        if (jogos[posJogo]->numPerso == 0)
                        {
                            system("cls");
                            puts("\nEsse jogo nao contem personagens cadastrado no sistema\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            system("cls");
                            ListPerso(jogos[posJogo]->personagens, idPerso);
                            system("pause");
                            system("cls");
                        }
                    }
                    break;

                default:
                    system("cls");
                    puts("\nOperacao Invalida!\n");
                    break;
                }
            }
            break;

        case 7: // CONECTAR JOGO A EMPRESA
            system("cls");
            ListEmp(empresas, idEmp);
            puts("Digite o ID da empresa que o jogo sera relacionado");
            scanf("%d", &posEmp);

            ListJogo(jogos, idJogo);
            puts("\nDigite o ID do jogo");
            scanf("%d", &posJogo);

            CadJogoEmp(empresas[posEmp], jogos[posJogo]);
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        case 8: // CONECTAR PERSONAGEM A JOGO
            system("cls");
            ListJogo(jogos, idJogo);
            puts("Digite o ID do jogo que o personagem sera relacionado");
            scanf("%d", &posJogo);

            ListPerso(personagens, idPerso);
            puts("Digite o ID do personagem");
            scanf("%d", &posPerso);

            CadPersoJogo(jogos[posJogo], personagens[posPerso]);
            puts("\nOperacao concluida com sucesso!\n\n\n");
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            puts("\nOperacao Invalida!\nEscolhas Apenas uma das opcoes listadas.\n\n");
            break;
        }
    }
}

void Menu()
{
    puts("0 - Sair");
    puts("1 - Inserir nova empresa");
    puts("2 - Listar empresas");
    puts("3 - Inserir novo jogo");
    puts("4 - Listar jogos");
    puts("5 - Inserir novo personagem");
    puts("6 - Listar personagens");
    puts("7 - Linkar jogo a empresa");
    puts("8 - Linkar personagem a jogo");
    puts("");
}

void MenuListJogo()
{
    puts("");
    puts("1 - Listar todos os jogos");
    puts("2 - Listar jogos de uma empresa especifica");
}

void MenuListPerso()
{
    puts("");
    puts("1 - Listar todos os personagens");
    puts("2 - Listar personagens de um jogo especifico");
}

Empresa *CadEmp(int idEmp)
{
    Empresa *NewEmp = (Empresa *)malloc(sizeof(Empresa));
    NewEmp->ID = idEmp;

    puts("\nNome do Empresa: ");
    scanf(" %[^\n]s", NewEmp->nome);
    puts("\nPais em que a empresa foi fundada: ");
    scanf(" %[^\n]s", NewEmp->pais);
    puts("\nAno em que a empresa foi fundada: ");
    scanf(" %d", &NewEmp->anoFund);

    NewEmp->numJogo = 0;

    return NewEmp;
}

void ListEmp(Empresa *empresas[], int idEmp)
{
    for (int i = 0; i < idEmp; i++)
    {
        printf("ID: %d\t|NOME:%s\t|PAIS: %s\t|A.FUND: %d\t|N.JOGOS: %d\n", empresas[i]->ID, empresas[i]->nome, empresas[i]->pais, empresas[i]->anoFund, empresas[i]->numJogo);
    }
    puts("\n");
}

Jogo *CadJogo(int idJogo)
{
    Jogo *NewGame = (Jogo *)malloc(sizeof(Jogo));
    NewGame->ID = idJogo;

    puts("\nNome do jogo: ");
    scanf(" %[^\n]s", NewGame->titulo);
    puts("\nAno do jogo: ");
    scanf(" %d", &NewGame->anoJogo);

    NewGame->numPerso = 0;

    return NewGame;
}

void ListJogo(Jogo *jogos[], int idJogo)
{
    for (int i = 0; i < idJogo; i++)
    {
        printf("ID: %d\t|TITULO: %s\t|LANCAMENTO: %d\t|N.PERSONAGEM: %d\n", jogos[i]->ID, jogos[i]->titulo, jogos[i]->anoJogo, jogos[i]->numPerso);
    }
    puts("\n");
}

Personagem *CadPerso(int idPerso)
{
    Personagem *NewPerso = (Personagem *)malloc(sizeof(Personagem));
    NewPerso->ID = idPerso;

    puts("\nNome do personagem: ");
    scanf(" %[^\n]s", NewPerso->nome);
    puts("\nIdade do Personagem: ");
    scanf(" %d", &NewPerso->idade);

    return NewPerso;
}

void ListPerso(Personagem *Personagens[], int idPerso)
{

    for (int i = 0; i < idPerso; i++)
    {
        printf("ID: %d\t|NOME: %s\t|IDADE: %d\n", Personagens[i]->ID, Personagens[i]->nome, Personagens[i]->idade);
    }
    puts("\n");
}

void *CadJogoEmp(Empresa *empresa, Jogo *jogo)
{
    empresa->jogos[empresa->numJogo] = jogo;
    empresa->numJogo++;
}

void *CadPersoJogo(Jogo *jogo, Personagem *personagem)
{
    jogo->personagens[jogo->numPerso] = personagem;
    jogo->numPerso++;
}
