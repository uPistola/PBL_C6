#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_PRODUTOS 12
#define MAXIMO_DESCRICAO 30

enum categorias{Eletrodomestico, Ferramenta, Vestuario};

typedef struct 
{
    int codigo;
    char descricao[MAXIMO_DESCRICAO];
    char nome[15];
    int estoque;
    enum categorias categoria;
}produtos;

void listar_catalogo() {
    produtos catalogo[MAXIMO_PRODUTOS];
    for (int i = 0; i < MAXIMO_PRODUTOS; i++)
    {
        printf("Nome: %s\nDescricao: %s\nEstoque: %d\n", catalogo[i].nome, catalogo[i].descricao, catalogo[i].estoque);
        puts("---------------------------------");
    }
    
}

int main() {

    produtos catalogo[MAXIMO_PRODUTOS];
    catalogo[0].categoria=Eletrodomestico; strcpy(catalogo[0].nome,"Geladeira"); catalogo[0].estoque=10;
    strcpy(catalogo[0].descricao,"Geladeira Eletrolux 120L Branca");
    catalogo[1].categoria=Eletrodomestico; strcpy(catalogo[1].nome,"Forno elétrico"); catalogo[1].estoque=25;
    strcpy(catalogo[1].descricao,"Forno Eletrico Britania 50L 110v Aço Escovado");
    catalogo[2].categoria=Vestuario; strcpy(catalogo[2].nome,"Capuz Preto"); catalogo[2].estoque=120;
    strcpy(catalogo[2].descricao,"Capuz Preto Nike lã preta");
    catalogo[3].categoria=Vestuario; strcpy(catalogo[3].nome,"Jaqueta Couro"); catalogo[3].estoque=22;
    strcpy(catalogo[3].descricao,"Jaqueta de couro de Onça GG");
    catalogo[4].categoria=Ferramenta; strcpy(catalogo[4].nome,"Martelo"); catalogo[4].estoque=61;
    strcpy(catalogo[4].descricao,"Martelo Tramontina Cabo de Fibra de Vidro");
    catalogo[5].categoria=Ferramenta; strcpy(catalogo[5].nome,"Furadeira"); catalogo[5].estoque=26;
    strcpy(catalogo[5].descricao,"Furadeira Bosch 450W 220V");

    for (int i = 0; i <= MAXIMO_PRODUTOS; i++){

        catalogo[i].codigo = (i+1);
    }
    
    listar_catalogo();

}