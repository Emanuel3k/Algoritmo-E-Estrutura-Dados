#include <stdio.h>
#include <stdlib.h>

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

    Personagem pesonagens[5];
    int numPerso;

} Jogo;

typedef struct _empresa
{
    int ID;
    char nome[20];
    char pais[20];
    int anoFund;

    Jogo jogos[5];
    int numJogo;

} Empresa;

// FUNCTIONS DECL
void menu();
Empresa CadEmp();
void ListEmo();
Jogo CadJogo();
void ListJogo();
Personagem CadPerso();
void ListPerso();

// FUNC MAIN
void main()
{
    // VARIAVEIS
    Empresa empresas[5];
    Jogo jogos[5];
    Personagem personagens[5];
    int idEmp = 0, idJogo = 0, idPerso = 0;
    int emp, jogo;
    int op;

    while (op != 7)
    {
        menu();
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
                puts("Nenhuma empresa cadastrada!");
            }
            else
            {
                system("cls");
                ListEmo(empresas, idEmp);
                system("pause");
                system("cls");
            }
            break;

        case 3: // CADASTRAR JOGOS

            if (idEmp == 0)
            {
                system("cls");
                puts("Nenhuma empresa cadastrada!");
            }
            else
            {
                system("cls");
                ListEmo(empresas, idEmp);
                puts("Digite o ID da empresa que vai cadastrar o jogo: ");
                scanf("%d", &emp);

                idJogo = empresas[emp].numJogo;
                empresas[emp].jogos[idJogo] = CadJogo(idJogo);
                empresas[emp].numJogo++;
                idJogo++;

                puts("\nOperacao concluida com sucesso!\n\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 4: // LISTAR JOGOS

            if (idEmp == 0)
            {
                system("cls");
                puts("Nenhuma empresa cadastrada!");
            }
            else
            {
                system("cls");
                ListEmo(empresas, idEmp);
                puts("De qual empresa deseja listar os jogos: ");
                scanf("%d", &emp);

                if (empresas[emp].numJogo == 0)
                {
                    system("cls");
                    puts("Esta empresa nao tem nenhum jogo cadastrado");
                }
                else
                {
                    system("cls");
                    ListJogo(empresas[emp].jogos, idJogo);
                    system("pause");
                    system("cls");
                }
            }
            break;

        case 5: // CADASTRAR PERSONAGEM
            if (idEmp == 0)
            {
                system("cls");
                puts("Nenhuma empresa cadastrada!");
            }
            else
            {
                system("cls");
                ListEmo(empresas, idEmp);
                puts("Digite o ID da empresa: ");
                scanf("%d", &emp);

                if (empresas[emp].numJogo == 0)
                {
                    system("cls");
                    puts("Esta empresa nao tem nenhum jogo cadastrado");
                }
                else
                {
                    ListJogo(empresas[emp].jogos, idJogo);
                    puts("Digite o ID do jogo em que o personagem sera adicionado: ");
                    scanf("%d", &jogo);

                    idPerso = empresas[emp].jogos[jogo].numPerso;
                    empresas[emp].jogos[jogo].pesonagens[idPerso] = CadPerso(idPerso);
                    empresas[emp].jogos[jogo].numPerso++;
                    idPerso++;

                    puts("\nOperacao concluida com sucesso!\n\n\n");
                    system("pause");
                    system("cls");
                }
            }
            break;

        case 6:

            if (idEmp == 0)
            {
                system("cls");
                puts("Nenhuma empresa cadastrada!");
            }
            else
            {
                system("cls");
                ListEmo(empresas, idEmp);
                puts("De qual empresa deseja listar os jogos: ");
                scanf("%d", &emp);

                if (empresas[emp].numJogo == 0)
                {
                    system("cls");
                    puts("Esta empresa nao tem nenhum jogo cadastrado");
                }
                else
                {
                    ListJogo(empresas[emp].jogos, idJogo);
                    puts("De qual jogo deseja listar os personagens: ");
                    scanf("%d", &jogo);

                    if (empresas[emp].jogos[jogo].numPerso == 0)
                    {
                        puts("Nenhum personagem cadastrado nesse jogo");
                    }
                    else
                    {
                        ListPerso(empresas[emp].jogos[jogo].pesonagens, idPerso);
                        system("pause");
                        system("cls");
                    }
                }
            }

            break;

        default:

            system("cls");
            puts("Operacao Invalida!\nEscolhas Apenas uma das opcoes listadas.\n");
            break;
        }
    }
}

// DEV FUNC
void menu()
{
    puts("1 - Inserir nova empresa");
    puts("2 - Listar empresas");
    puts("3 - Inserir novo jogo");
    puts("4 - Listar jogos");
    puts("5 - Inserir novo personagem");
    puts("6 - Listar personagens");
    puts("7 - Sair");
}

Empresa CadEmp(int idEmp)
{
    Empresa newEmp;
    newEmp.ID = idEmp;

    puts("\nNome do Empresa: ");
    scanf(" %[^\n]s", newEmp.nome);
    puts("\nPais em que a empresa foi fundada: ");
    scanf(" %[^\n]s", newEmp.pais);
    puts("\nAno em que a empresa foi fundada: ");
    scanf(" %d", &newEmp.anoFund);

    newEmp.numJogo = 0;

    return newEmp;
}

void ListEmo(Empresa empresas[], int idEmp)
{

    for (int i = 0; i < idEmp; i++)
    {
        printf("%d\t| %s\t| %s\t| %d\n", empresas[i].ID, empresas[i].nome, empresas[i].pais, empresas[i].anoFund);
    }
    puts("\n");
}

Jogo CadJogo(int idliv)
{
    Jogo newGame;
    newGame.ID = idliv;

    puts("\nNome do jogo: ");
    scanf(" %[^\n]s", newGame.titulo);
    puts("\nAno do jogo: ");
    scanf(" %d", &newGame.anoJogo);

    newGame.numPerso = 0;

    return newGame;
}

void ListJogo(Jogo jogos[], int idJogo)
{

    for (int i = 0; i < idJogo; i++)
    {
        printf("%d\t| %s\t| %d\n", jogos[i].ID, jogos[i].titulo, jogos[i].anoJogo);
    }
    puts("\n");
}

Personagem CadPerso(int idPerso)
{
    Personagem newPerso;
    newPerso.ID = idPerso;

    puts("\nNome do personagem: ");
    scanf(" %[^\n]s", newPerso.nome);
    puts("\nIdade do Personagem: ");
    scanf(" %d", &newPerso.idade);

    return newPerso;
}

void ListPerso(Personagem Personagens[], int idPerso)
{

    for (int i = 0; i < idPerso; i++)
    {
        printf("%d\t| %s\t| %d", Personagens[i].ID, Personagens[i].nome, Personagens[i].idade);
    }
    puts("\n");
}