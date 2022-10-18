#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

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

bool inserir_produto() {

}

void listar_catalogo(produtos *catalogo) {
    for (int i = 0; i < MAXIMO_PRODUTOS; i++)
    {   
        printf("\nNome: %s\nDescricao: %s\nEstoque: %d\nCódigo do Produto: %d\n", catalogo[i].nome, catalogo[i].descricao, catalogo[i].estoque,catalogo[i].codigo);
        puts("---------------------------------"); 
        Sleep(450); 
    }  
}

int main() {

    int a;

    setlocale(LC_ALL,"Portuguese");
    produtos catalogo[MAXIMO_PRODUTOS];

        // Implementacao Manual da Lista Inicial
    catalogo[0].categoria=Eletrodomestico; strcpy(catalogo[0].nome,"Geladeira"); catalogo[0].estoque=10;
    strcpy(catalogo[0].descricao,"Geladeira Eletrolux 120L");
    catalogo[1].categoria=Eletrodomestico; strcpy(catalogo[1].nome,"Forno elétrico"); catalogo[1].estoque=25;
    strcpy(catalogo[1].descricao,"Forno Eletrico Britania");
    catalogo[2].categoria=Vestuario; strcpy(catalogo[2].nome,"Capuz Preto"); catalogo[2].estoque=120;
    strcpy(catalogo[2].descricao,"Capuz Preto Nike lã preta");
    catalogo[3].categoria=Vestuario; strcpy(catalogo[3].nome,"Jaqueta Couro"); catalogo[3].estoque=22;
    strcpy(catalogo[3].descricao,"Jaqueta de couro de Onça");
    catalogo[4].categoria=Ferramenta; strcpy(catalogo[4].nome,"Martelo"); catalogo[4].estoque=61;
    strcpy(catalogo[4].descricao,"Martelo Tramontina");
    catalogo[5].categoria=Ferramenta; strcpy(catalogo[5].nome,"Furadeira"); catalogo[5].estoque=26;
    strcpy(catalogo[5].descricao,"Furadeira Bosch 450W");

        // Loop para codigo de auto-incremento Inicial
    for (int i = 0; i <= MAXIMO_PRODUTOS; i++){
        catalogo[i].codigo = (i+1);}
    
    while (1)
    {
        puts("Escolha uma Ação: ");
        puts("(1) Listar todos os produtos\n(2) Insirir um novo produto\n(3) Remover um Produto existente\n(4) Atualizar o estoque\n(5) Aumentar o estoque de algum produto\n(6) Diminuir o estoque de algum produto");
        scanf("%d", &a);

        switch (a){

        case 1:
            listar_catalogo(catalogo);
            break;
        
        case 2:
            //inserir_produto();
            break;
        case 3:
            //remover_produto();
            break;
        case 4:
            //atualizar_produto():
            break;
        case 5:
            //aumentar_produto();
            break;
        case 6:
            //diminuir_estoque();
            break;
        default:
            puts("Erro na Escolha das ações, digite um numero valido");
            break;
            
        }
    }
}