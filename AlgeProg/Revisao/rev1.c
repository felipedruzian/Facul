/* Crie um programa que receba os dados referentes a compra de 10 produtos. 
O sistema deve receber código compra, descrição, quantidade e valor unitário (calcular valor total) 
- os valores deverão ser informados de forma aleatória (automático). 
Com os valores armazenados disponibilizar o seguinte menu na tela:
//// MENU ////
1. Listas todas as compras
2. Consulta por código
3. Consulta por descrição
4. Valor médio das compras por item
5. Listar valores totais em ordem crescente
6. Sair
P.S. Enquanto o usuário não digitar Sair, o sistema deverá permanecer no Menu.
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{

    //variaveis
    char descricao[10][16];
    int codigo[10];
    int quantidade[10];
    float valorunitario[10];
    float valortotal[10];
 



    system("pause");
    return 0;
}
