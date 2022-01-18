#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Banda {
    char nome[16][32];
    char genero[16][32];
    int nintegrantes, ranking;
} banda[5];

void topx () {
    int fav;
    printf("\nDigite um numero de 1 a 5: ");
    scanf("%i", &fav);
    for (int i = 0; i < 5; i++) {
        if (fav == banda[i].ranking) {
            printf("\nInformacoes da Banda: \n");
            printf("Nome da Banda: %s\n", banda[i].nome);
            printf("Genero: %s\n", banda[i].genero);
            printf("Numero de integrante: %i\n", banda[i].nintegrantes);
        }
    }
}
void generomus () {
    char gen[16][32];
    printf("\nDigite um genero musical: ");
    scanf("%s", &gen);
    for (int i = 0; i < 5; i++) {
        if (strcmp(gen, banda[i].genero) == 0) {
            printf("\nInformacoes da Banda: \n");
            printf("Nome da Banda: %s\n", banda[i].nome);
            printf("Genero: %s\n", banda[i].genero);
            printf("Numero de integrante: %i\n", banda[i].nintegrantes);
        }
    }
}
void bandamus () {
    char nomebanda[16][32];
    int x = 0;
    printf("\nDigite o nome de uma banda: ");
    scanf("%s", &nomebanda);
    for (int i = 0; i < 5; i++) {
        if (strcmp(nomebanda, banda[i].nome) == 0) {
            x=1;
        }
    }
    if (x == 1) {printf("A banda esta na sua lista de favoritas\n");
    }else{printf("A banda nao esta nas suas favoritas!\n"); }
}


int main() {
    int opc, tecla=0;
    while (opc != 0) {
        system("cls");
        printf("/// Programa de Bandas Favoritas ///\n");
        printf("1. Cadastrar 5 Bandas Favoritas\n");
        printf("2. Informacoes das Bandas\n");
        printf("3. Procurar pelo ranking de favoritas\n");
        printf("4. Procurar pelo genero de musica\n");
        printf("5. Conferir se a banda esta nas favoritas\n");
        printf("0. Sair do Programa\n");
        printf("-----------------///-----------------\n");
        printf("Digite uma opcao: ");
        scanf("%i", &opc);
        fflush(stdin);
        switch (opc) {
        case 1:
            for (int i = 0; i < 2; i++) {
                system("cls");
                printf("Infos da Banda %i:\n", i+1);
                printf("Digite o nome da banda: ");
                gets(banda[i].nome);
                printf("Digite o tipo de musica desta banda: ");
                gets(banda[i].genero);
                printf("Quanto integrantes essa banda tem? ");
                scanf("%i", &banda[i].nintegrantes);
                printf("De 1 a 5, em que posicao do seu ranking de favorito ela esta? ");
                scanf("%i", &banda[i].ranking);
                fflush(stdin); 
                system("cls");
            }
            break;
        case 2:
            while (tecla != 10) {
                system("cls");

                printf("\nInformacoes de todas as Bandas: \n");
                for (int i = 0; i < 2; i++) {
                    printf("Nome da Banda %i: %s\n", i+1, banda[i].nome);
                    printf("Genero: %s\n", banda[i].genero);
                    printf("Numero de integrante: %i\n", banda[i].nintegrantes);
                    printf("Posicao no TOP 5 Favoritas: %i\n\n", banda[i].ranking);
                }

                printf("\nPressione Enter para voltar. . . ");
                //scanf("%c", &tecla);
                tecla = getchar();
                //printf("%i", tecla);
            }
            tecla = 0;
            break;
        case 3:
            while (tecla != 10) {
                system("cls");

                topx();
                
                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 4:
            while (tecla != 10) {
                system("cls");

                generomus();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 5:
            while (tecla != 10) {
                system("cls");
            
                bandamus();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 0:
            printf("\nFinalizando o programa...\n");
            break;
        default:
            printf("\nSelecione um opcao valida!\n");
            break;
        }
    }

    system("pause");
    return 0;
}