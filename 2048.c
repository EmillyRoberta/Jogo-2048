#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

//Protótipos das Funções
void ganhador ();
void inicializa_matriz(char casa[3][3]);
void tab(char casa[3][3]);
void menu();
void jogvsjog();
void jogvspc();
void torneio();

int coisa=0;
int gar=0;
///////MAIN
int main()
{
    system("mode con:cols=60 lines=20"); //Define o tamanho da tela
    system("title Jogo da Velha");
    system("color f");
    system("color B");

    FILE* f;

	f = fopen("winner.txt", "w");


    setlocale(LC_ALL, "Portuguese");
    menu();
}


void menu()
{
    int opcao, vez=0, cont=1;
    char mat[3][3];
    do
    {
        printf("                                                 \n");
        printf("\t********Escolha o Modo de Jogo Desejado*********\n");
        printf("\t|                                              |\n");
        printf("\t|           1. Jogador1 vs Jogador2            |\n");
        printf("\t|           2. Jogador vs Maquina              |\n");
        printf("\t|           3. Torneio                         |\n");
        printf("\t|           4. Sair                            |\n");
        printf("\t|______________________________________________|\n\n");


        printf("\tDigite a opcao: ");
        scanf("%d", &opcao);


        if (opcao>4 || opcao<1)
        {
            printf("Digite uma opção válida!!");
        }
        system("cls");

        switch(opcao)
        {
        case 1:
            inicializa_matriz(mat);
            tab(mat);
            jogvsjog(mat);
            menu();
            break;

        case 2:
            inicializa_matriz(mat);
            tab(mat);
            jogvspc(mat);
            vez++;
            menu();
            break;

        case 3:
            torneio();
            break;

        case 4:
            printf("Voce escolheu sair..TCHAU...\n");
            exit(1);
            break;
        default:
            printf("Digite uma opcao valida\n");
            system("cls");
            menu();
            break;
        }
    }
    while(opcao<=0 || opcao>4);
}

void inicializa_matriz(char casa[3][3])
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            casa[i][j] =' ';
        }
    }
}

void tab(char casa[3][3])
{
    system("cls");
    printf("\n       0  1  2\n");
    printf("\n    0  %c| %c |%c ", casa[0][0], casa[0][1],casa[0][2]);
    printf("\n      --|---|--");
    printf("\n    1  %c| %c |%c ", casa[1][0], casa[1][1], casa[1][2]);
    printf("\n      --|---|--");
    printf("\n    2  %c| %c |%c\n\n\n", casa[2][0], casa[2][1], casa[2][2]);

}

void jogvsjog(char mat[3][3], FILE *f)
{
    int l=0, c=0, conta=0, vez=0, i, cont=1;
    int jogadas=0;
    int opcao;
    inicializa_matriz(mat);

    //do
    //     {
    //       inicializa_matriz(mat);
    do
    {

        tab(mat);//Chama a matriz
        if(jogadas==((9+conta)))
        {
            printf("FIM DE JOGO \n");
            break;
        }

        //Mostra a vez de qual jogador





        else //Caso contrário
        {
            if (vez%2==0) //É para definir o que marcar, se é X ou O
            {
            printf("Jogador: X \n");
        printf("Insira a linha: ");
        scanf("%d", &l);
        printf("insira a coluna: ");
        scanf("%d",&c);
          if((l<=-1) || (l>=3) || (c<=-1) || (c>=3)) //Para validar as posições, que variam de 0 incluindo o mesmo até 2.
        {
            printf("invalido\n");
            system("pause");
            //continue; //Caso digite abaixo de 0 ou maior = a 3, retorna inválido e para a execução
        }

                if(mat[l][c]=='X' || mat[l][c]=='O')
                {
                    //NÃO FAZ NADA ( É SÓ PRA CASO O JOGADOR REPETIR A POSIÇÃO QUE JÁ FOI DIGITADA ANTES, NÃO SOBREESCREVER NO LOCAL )
                    conta ++;//Conta quantas vezes passou aqui, pra agregar na contagem das jogadas.
                }
                else
                {
                    mat[l][c]='X';
                }
            }
            else if(vez%2==1)
            {
             printf("Jogador: O \n");
        printf("Insira a linha: ");
        scanf("%d", &l);
        printf("insira a coluna: ");
        scanf("%d",&c);
          if((l<=-1) || (l>=3) || (c<=-1) || (c>=3)) //Para validar as posições, que variam de 0 incluindo o mesmo até 2.
        {
            printf("invalido\n");
            system("pause");
            //continue; //Caso digite abaixo de 0 ou maior = a 3, retorna inválido e para a execução
        }

                if(mat[l][c]=='X' || mat[l][c]=='O')
                {
                    //NÃO FAZ NADA ( É SÓ PRA CASO O JOGADOR REPETIR A POSIÇÃO QUE JÁ FOI DIGITADA ANTES, NÃO SOBREESCREVER NO LOCAL )
                    conta ++; //Conta quantas vezes passou aqui, pra agregar na contagem das jogadas.
                }
                else
                {
                    mat[l][c]='O';
                }
            }

        }
        vez++; //Incrementa para poder passar para o próximo jogador
        jogadas++; //Permite que se repita quantas vezes necessário, até preencher a matriz, sem deixar que sobreescreva a posição
        cont++; //Para falar a vez de qual jogador.
        if(cont>=3)//Fica oscilando entre 0 e 1, que seriam jogador 0 e jogador 1
        {
            cont=1;

        }

        //GANHA NA HORIZONTAL
        if(mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[1][0] == 'X' && mat[1][1] =='X' && mat[1][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[2][0] == 'X' && mat[2][1] == 'X' && mat[2][2] == 'X')
        {
            jogadas=11;
        }
        //GANHA NA VERTTICAL
        if(mat[0][0] == 'X' && mat[1][0] == 'X' && mat[2][0] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][1] == 'X' && mat[1][1] == 'X' && mat[2][1] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][2] == 'X' && mat[1][2] =='X' && mat[2][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[1][0] == 'X' && mat[1][1] == 'X' && mat[1][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[1][0] == 'X' && mat[1][1] == 'X' && mat[1][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][2] == 'X' && mat[1][1] == 'X' && mat[2][0] == 'X')
        {
            jogadas=11;
        }

        // O NA HORIZONTAL
        if(mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[2][0] == 'O' && mat[2][1] == 'O' && mat[2][2] == 'O')
        {
            jogadas=12;
        }
        //GANHA NA VERTTICAL
        if(mat[0][0] == 'O' && mat[1][0] == 'O' && mat[2][0] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][1] == 'O' && mat[1][1] == 'O' && mat[2][1] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][2] == 'O' && mat[1][2] =='O' && mat[2][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][2] == 'O' && mat[1][1] == 'O' && mat[2][0] == 'O')
        {
            jogadas=12;
        }

    }
    while(jogadas<(10+conta));
    tab(mat);
    if (jogadas == 9)
    {
        printf("Deu Velha :( \n");
    }
    else if (jogadas == 11)
    {
        printf("Jogador X ganhou!!\n");
        fprintf(f,"%c\n", 'X');
    }
    else if (jogadas == 12)
    {
        printf("Jogador O ganhou!!\n");
        fprintf(f,"%c\n", 'O');
    }

    fclose(f);
}
void jogvspc(char mat[3][3])
{
    int l=0, c=0, conta=0, vez=0,cont=1, i, j;
    int jogadas=0;
    inicializa_matriz(mat);


    do
    {
        tab(mat); //Chama a matriz
        if(jogadas==((9+conta)))
        {
            printf("\tFIM DE JOGO \n");
            break;
        }
        printf("Jogador: X \n"); //Mostra a vez de qual jogador
        printf("Insira a linha: ");
        scanf("%d", &l);
        printf("insira a coluna: ");
        scanf("%d",&c);
        if((l<=-1) || (l>=3) || (c<=-1) || (c>=3)) //Para validar as posições, que variam de 0 incluindo o mesmo até 2.
        {
            printf("invalido\n");
            system("pause");
            //continue; //Caso digite abaixo de 0 ou maior = a 3, retorna inválido e para a execução
        }
        else //Caso contrário
        {
            if (vez%2==0) //É para definir o que marcar, se é X ou O
            {
                if(mat[l][c]=='X' || mat[l][c]=='O')
                {
                    //NÃO FAZ NADA ( É SÓ PRA CASO O JOGADOR REPETIR A POSIÇÃO QUE JÁ FOI DIGITADA ANTES, NÃO SOBREESCREVER NO LOCAL )
                    conta ++;//Conta quantas vezes passou aqui, pra agregar na contagem das jogadas.
                }
                else
                {
                    mat[l][c]='X';
                }
            }
            else if(vez%2==1)
            {
                if(mat[l][c]=='X' || mat[l][c]=='O')
                {
                    //NÃO FAZ NADA ( É SÓ PRA CASO O JOGADOR REPETIR A POSIÇÃO QUE JÁ FOI DIGITADA ANTES, NÃO SOBREESCREVER NO LOCAL )
                    conta ++; //Conta quantas vezes passou aqui, pra agregar na contagem das jogadas.
                }
                else
                {
                    mat[l][c]='O';
                }
            }

        }
        //vez++; //Incrementa para poder passar para o próximo jogador
        jogadas++; //Permite que se repita quantas vezes necessário, até preencher a matriz, sem deixar que sobreescreva a posição
        cont++; //Para falar a vez de qual jogador.
        if(cont>=3) //Fica oscilando entre 0 e 1, que seriam jogador 0 e jogador 1
        {
            cont=1;
        }
//Estratégias de ATAQUE

        //Se o jogador iniciar pelo meio
        if(mat[1][1]=='X' && mat[0][0]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][0]== ' ' && mat[1][2]==' '
                && mat[2][0]==' ' && mat[2][1]==' '&& mat[2][2]==' ')
        {
            mat[0][0]='O';
        }

        //Se o jogador iniciar por um dos cantos centrais
        if(mat[1][2]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][0]== ' ' && mat[2][0]==' ' && mat[2][1]==' '&& mat[2][2]==' ')
        {
            mat[1][1]='O';
        }
        if(mat[1][0]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][2]==' '
                && mat[2][0]==' ' && mat[2][1]==' '&& mat[2][2]==' ')
        {
            mat[1][1]='O';
        }
        if(mat[0][1]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][2]==' '
                && mat[1][0]== ' ' && mat[1][2]==' '
                && mat[2][0]==' ' && mat[2][1]==' '&& mat[2][2]==' ')
        {
            mat[1][1]='O';
        }
        if(mat[2][1]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][0]==' ' && mat[1][2]==' '
                && mat[2][0]==' ' && mat[2][2]==' ')
        {
            mat[0][0]='O';
        }

        //Se o jogador iniciar jogando pelas esquinas
        if(mat[0][0]=='X' && mat[1][1]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][0]==' ' && mat[1][2]==' '
                && mat[2][0]==' ' && mat[2][2]==' ')
        {
            mat[1][1]='O';
        }
        if(mat[0][2]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][1]==' '
                && mat[1][0]==' ' && mat[1][2]==' '
                && mat[2][0]==' ' && mat[2][2]==' ')
        {
            mat[1][1]='O';
        }
        if(mat[2][2]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][0]==' ' && mat[1][2]==' '
                && mat[2][0]==' ')
        {
            mat[1][1]='O';
        }
        if(mat[2][0]=='X' && mat[1][1]==' ' && mat[0][0]==' ' && mat[0][1]==' ' && mat[0][2]==' '
                && mat[1][0]==' ' && mat[1][2]==' '
                && mat[2][2]==' ')
        {
            mat[1][1]='O';
        }

        //ESTRATÉGIAS DE DEFESA

        //Estratégia 02: Bloquear o jogador de ganhar
        else if(mat[1][2]=='X' && mat[0][0]=='X' && mat[2][0]=='X')
        {
            mat[2][2]='O';
        }

        //Começando verificando  as extremidades das  horizontais
        else if(mat[0][0]=='X' && mat[0][2]=='X' && mat[0][1]==' ')
        {

            mat[0][1]='O';
        }
        else if(mat[1][0]=='X' && mat[1][2]=='X' && mat[1][1]==' ')
        {

            mat[1][1]='O';
        }
        else if(mat[2][0]=='X' && mat[2][2]=='X' && mat[2][1]==' ')
        {

            mat[2][1]='O';
        }

        //Verificando os seguimentos de horizontais da esquerda para direita
        else if(mat[0][0]=='X' && mat[0][1]=='X' && mat[0][2]==' ' )
        {

            mat[0][2]='O';
        }
        else if(mat[1][0]=='X' && mat[1][1]=='X' && mat[1][2]==' ' )
        {

            mat[1][2]='O';
        }
        else if(mat[2][0]=='X' && mat[2][1]=='X' && mat[2][2]==' ' )
        {

            mat[2][2]='O';
        }
        //Verificando os seguimentos de horizontais da direita para esquerda
        else if(mat[0][1]=='X' && mat[0][2]=='X' && mat[0][0]==' ' )
        {

            mat[0][0]='O';
        }
        else if(mat[1][1]=='X' && mat[1][2]=='X' && mat[1][0]==' ' )
        {

            mat[1][0]='O';
        }
        else if(mat[2][1]=='X' && mat[2][2]=='X' && mat[2][0]==' ' )
        {

            mat[2][0]='O';
        }


        //Estratégia 02: Bloquear pelas verticais marcando o meio

        else if(mat[0][0]=='X' && mat[2][0]=='X' && mat[1][0]==' ')
        {

            mat[1][0]='O';
        }
        else if(mat[0][1]=='X' && mat[2][1]=='X' && mat[1][1]==' ')
        {

            mat[1][1]='O';
        }
        else if(mat[0][2]=='X' && mat[2][2]=='X' && mat[1][2])
        {

            mat[1][2]='O';
        }

        //Estratégia 03: Bloquear pelas verticais marcando a extremidade inferior

        else if(mat[0][0]=='X' && mat[1][0]=='X' && mat[2][0]==' ')
        {

            mat[2][0]='O';
        }
        else if(mat[0][1]=='X' && mat[1][1]=='X' && mat[2][1]==' ')
        {

            mat[2][1]='O';
        }
        else if(mat[0][2]=='X' && mat[1][2]=='X' && mat[2][2]==' ')
        {

            mat[2][2]='O';
        }

        //Estratégia 04: Bloquear pelas verticais marcando a extremidade superior

        else if(mat[1][0]=='X' && mat[2][0]=='X' && mat[0][0]==' ')
        {

            mat[0][0]='O';
        }
        else if(mat[1][1]=='X' && mat[2][1]=='X' && mat[0][1]==' ')
        {

            mat[0][1]='O';
        }
        else if(mat[1][2]=='X' && mat[2][2]=='X' && mat[0][2]==' ')
        {

            mat[0][2]='O';
        }

        //Estratégia 05: Bloquear pelas diagonais

        // Da direita pra esquerda, superior para inferior
        else if(mat[1][1]=='X' && mat[0][2]=='X' && mat[2][0]==' ')
        {

            mat[2][0]='O';
        }
        //Da esquerda pra direita, superior para inferior
        else if(mat[1][1]=='X' && mat[0][0]=='X' && mat[2][2]==' ')
        {

            mat[2][2]='O';
        }
        //Da direita para esquerda, inferior para superior
        else if(mat[1][1]=='X' && mat[2][2]=='X' && mat[0][0]==' ')
        {

            mat[0][0]='O';
        }
        //Da esquerda para direita, inferior para superior
        else if(mat[1][1]=='X' && mat[2][0]=='X' && mat[0][2]==' ')
        {

            mat[0][2]='O';
        }
        else if(mat[2][1]=='X' && mat[2][2]=='X' && mat[1][0]=='X')
        {

            mat[1][1]='O';
        }
        else if(mat[2][1]=='X' && mat[2][2]=='O' && mat[1][0]=='X')
        {

            mat[0][1]='O';
        }
        //________________________________________________________________________________________

        //CASA [0][0]
        else if(mat[0][0]=='X' && mat[1][1]=='O' && mat[2][1]=='X' && mat[2][0]==' ')
        {
            mat[2][0] = 'O';
        }
        else if(mat[0][0]=='X' && mat[1][1]=='O' && mat[1][2]=='X' && mat[2][0]==' ')
        {
            mat[2][0] = 'O';
        }
        else if(mat[0][0]=='X' && mat[1][1]=='O' && mat[2][2]=='X' && mat[2][0]==' ')
        {
            mat[2][0] = 'O';
        }
        //CASA[0][1]
        else if(mat[0][1]=='X' && mat[1][1]=='O' && mat[1][0]=='X' && mat[0][0]==' ')
        {
            mat[0][0] = 'O';
        }
        else if(mat[0][1]=='X' && mat[1][1]=='O' && mat[2][0]=='X' && mat[0][0]==' ')
        {
            mat[0][0] = 'O';
        }
        else if(mat[0][1]=='X' && mat[1][1]=='O' && mat[2][1]=='X' && mat[0][0]==' ')
        {
            mat[0][0] = 'O';
        }
        else if(mat[0][1]=='X' && mat[1][1]=='O' && mat[2][2]=='X' && mat[0][0]==' ')
        {
            mat[0][0] = 'O';
        }
        else if(mat[0][1]=='X' && mat[1][1]=='O' && mat[1][2]=='X' && mat[0][0]==' ')
        {
            mat[0][0] = 'O';
        }
        //CASA[0][2]
        else if(mat[0][2]=='X' && mat[1][1]=='O' && mat[2][0]=='X' && mat[2][2]==' ')
        {
            mat[2][2] = 'O';
        }
        else if(mat[0][2]=='X' && mat[1][1]=='O' && mat[2][1]=='X' && mat[2][2]==' ')
        {
            mat[2][2] = 'O';
        }
        else if(mat[0][2]=='X' && mat[1][1]=='O' && mat[1][0]=='X' && mat[2][2]==' ')
        {
            mat[2][2] = 'O';
        }
        //CASA[1][0]
        else if (mat[1][0]=='X' && mat[1][1]=='O' && mat[2][1]=='X' && mat[0][2]==' ')
        {
            mat[0][2] = 'O';
        }
        else if (mat[1][0]=='X' && mat[1][1]=='O' && mat[2][2]=='X' && mat[0][2]==' ')
        {
            mat[0][2] = 'O';
        }
        else if (mat[1][0]=='X' && mat[1][1]=='O' && mat[1][2]=='X' && mat[0][2]==' ')
        {
            mat[0][2] = 'O';
        }

        //CASA [1][2]
        else if (mat[1][2]=='X' && mat[1][1]=='O' && mat[2][0]=='X' && mat[0][1]==' ')
        {
            mat[0][1] = 'O';
        }
        else if (mat[1][2]=='X' && mat[1][1]=='O' && mat[2][1]=='X' && mat[2][2]==' ')
        {
            mat[2][2] = 'O';
        }


        //ATAQUE ATRAVESSADO
        else if(mat[2][0]=='O' && mat[1][1]=='O' && mat[0][2]==' ')
        {
            mat[0][2] = 'O';
        }
        else if (mat[0][2]=='O' && mat[1][1]=='O' && mat[2][0]==' ')
        {
            mat[2][0] = 'O';
        }
        else if (mat[0][0]=='O' && mat[1][1]=='O' && mat[2][2]==' ')
        {
            mat[2][2] = 'O';
        }
        else if (mat[2][2]=='O' && mat[1][1]=='O' && mat[0][0]==' ')
        {
            mat[0][0] = 'O';
        }

        //GANHA
        if(mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[1][0] == 'X' && mat[1][1] =='X' && mat[1][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[2][0] == 'X' && mat[2][1] == 'X' && mat[2][2] == 'X')
        {
            jogadas=11;
        }

        //GANHA NA VERTTICAL
        if(mat[0][0] == 'X' && mat[1][0] == 'X' && mat[2][0] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][1] == 'X' && mat[1][1] == 'X' && mat[2][1] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][2] == 'X' && mat[1][2] =='X' && mat[2][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[1][0] == 'X' && mat[1][1] == 'X' && mat[1][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[1][0] == 'X' && mat[1][1] == 'X' && mat[1][2] == 'X')
        {
            jogadas=11;
        }
        if(mat[0][2] == 'X' && mat[1][1] == 'X' && mat[2][0] == 'X')
        {
            jogadas=11;
        }

        // O NA HORIZONTAL
        if(mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[2][0] == 'O' && mat[2][1] == 'O' && mat[2][2] == 'O')
        {
            jogadas=12;
        }
        //GANHA NA VERTTICAL
        if(mat[0][0] == 'O' && mat[1][0] == 'O' && mat[2][0] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][1] == 'O' && mat[1][1] == 'O' && mat[2][1] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][2] == 'O' && mat[1][2] =='O' && mat[2][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')
        {
            jogadas=12;
        }
        if(mat[0][2] == 'O' && mat[1][1] == 'O' && mat[2][0] == 'O')
        {
            jogadas=12;
        }
        else if(jogadas==5)
        {
            jogadas=9;
        }

    }


    while(jogadas<(10+conta));
    tab(mat);
    if (jogadas == 9)
    {
        printf("Deu Velha :( \n");
    }
    if (jogadas == 11)
    {
        printf("Jogador X ganhou!!\n");
    }
    if (jogadas == 12)
    {
        printf("Jogador O ganhou!!\n");
    }
}

void torneio()
{
    int jogadores, i, j, num;
    int *vet;
    char *teste;
    char mat[3][3], ch, chae;

	FILE* f;

	f = fopen("winner.txt", "w");

    printf("Insira quantos jogadores irão jogar: ");
    scanf("%d", &jogadores);
    if(jogadores%2==0)
    {
        jogadores = jogadores/2;
    }
    else {
        if (jogadores == 3)
        jogadores = jogadores-1;

        else if(jogadores >= 3){
            jogadores = jogadores - 2;
        }
    }

    vet = (int *) malloc(jogadores * sizeof (int));
    teste = (char*)malloc(jogadores *sizeof(char));

    for(i=1; i<=jogadores; i++)
    {
        //printf("Partida: %d\n",i+1);
        printf(" Jogador %d - X (xis)\n",++coisa);
        printf(" Jogador %d - O (bolinha)\n\n",++coisa);

        jogvsjog(mat, f);
    }
    fclose(f);
	f = fopen("winner.txt", "r");
    while( (ch=fgetc(f))!= EOF )
    {
        teste[j] = ch;
        putchar(ch);
        j++;
    }
    int y;
    for(y=0; y<jogadores; y++)
    {
        printf("%c\n",teste[y]);
    }
    fclose(f);
    f = fopen("winner.txt", "r");

    while( (chae=fgetc(f))!= EOF )
    {
			if(chae == '\n')
			  num++;
    }
}
