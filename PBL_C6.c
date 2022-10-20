#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAXIMO_PRODUTOS 12
#define MAXIMO_DESCRICAO 30
#define MAXIMO_NOME 15

enum categorias{ELETRODOMESTICO, FERRAMENTA, VESTUARIO};

char* categor[] = {"Eletrodomesticos","Ferramentas","Vestuario"};

typedef struct 
{
    int codigo;
    char descricao[MAXIMO_DESCRICAO];
    char nome[MAXIMO_NOME];
    int estoque;
    char cat[20];
    enum categorias categoria;
}produtos;

int listar_catalogo(produtos *catalogo, int total) {
    for (int i = 0; i < total; i++)
    {
            printf("\nNome: %s\nDescricao: %s\nEstoque: %d\nCodigo do Produto: %d\nCategoria: %s\n", catalogo[i].nome, catalogo[i].descricao, catalogo[i].estoque,catalogo[i].codigo, catalogo[i].cat);
            puts("---------------------------------");
            Sleep(450); 
    }  
    return 0;
}

bool IHC_inserir_produto(produtos *catalogo, int ultimo_produto){

    char desc[MAXIMO_DESCRICAO];
    char nome[MAXIMO_NOME];
    int cat;
    if (ultimo_produto > 12)
    {
        puts("Limite maximo da Lista atingido...\nRetornando para a pagina Inicial");
        return false;
    }else{
        puts("Insira o Nome do seu Produto, maximo de 15 caracteres: ");
        scanf("%s", &nome);
        fflush(stdin);
        puts("Insira a Descricao do seu Produto, maximo de 30 caracteres: ");
        fgets(desc, MAXIMO_DESCRICAO, stdin);
        fflush(stdin);
        puts("Qual Categoria seu Produto sera?\n(0) Eletrodomesticos\n(1) Ferramentas\n(2) Vestuario"); 
        scanf("%d", &cat);
        fflush(stdin);
        puts("Realizando Pedido ...");
        Sleep(1000);
        strcpy(catalogo[ultimo_produto].nome, nome); strcpy(catalogo[ultimo_produto].descricao, desc);catalogo[ultimo_produto].estoque = 0;   
        strcpy(catalogo[ultimo_produto].cat, categor[cat]);
        
    }
    return true;
}

bool IHC_remover_produto (produtos *catalogo, int total){
    int cod;
    puts("Insira o Codigo do Produto para ser removido: ");
    scanf("%d", &cod);
    if((cod > total) || (cod < 1)){
        return false;
    }
    for (int i = cod - 1; i < MAXIMO_PRODUTOS - 1; i++)
    {
        strcpy(catalogo[i].nome, catalogo[i+1].nome); strcpy(catalogo[i].descricao, catalogo[i+1].descricao);
        catalogo[i].categoria = catalogo[i+1].categoria; catalogo[i].estoque = catalogo[i+1].estoque;     
    }  
    return true;  
}

bool IHC_atualizar_estoque(produtos *catalogo, int total){
    int cod, qtd;
    puts("Insira o Codigo do Produto que ira atualizar: "); scanf("%d",&cod);
    puts("Digite a quantidade: "); scanf("%d", &qtd);
    if((cod > total) || (cod < 1)|| (qtd < 0)){
        return false;
    }else{
        catalogo[cod-1].estoque = qtd;
    }
    return true;
}


bool IHC_atualizar_produto(produtos *catalogo, int total){
    int cod, qtd;
    puts("Insira o Codigo do Produto que ira atualizar: "); scanf("%d",&cod);
    puts("Insira a Quantia que ira aumentar: "); scanf("%d",&qtd);

    if ((cod > total) || (cod < 1) || (qtd < 0))
    {
        return false;
    }else{
        catalogo[cod - 1].estoque += qtd;
    } 
    return true;
   
}

bool IHC_aumentar_produto(produtos *catalogo, int total){
    int cod, qtd;
    puts("Insira o Codigo do Produto que ira aumentar: "); scanf("%d",&cod);
    puts("Insira a Quantia que ira Diminuir: "); scanf("%d",&qtd);

    if ((cod > total) || (cod < 1) || (catalogo[cod - 1].estoque - qtd < 0))
    {
        return false;
    }else{
        catalogo[cod - 1].estoque -= qtd;
    } 
    return true;
   
}


int main() {

    int a;
    int num = 6;
    bool resultado = false;

    produtos catalogo[MAXIMO_PRODUTOS];

        // Implementacao Manual da Lista Inicial
    catalogo[0].categoria=ELETRODOMESTICO; strcpy(catalogo[0].nome,"Geladeira"); catalogo[0].estoque=10;
    strcpy(catalogo[0].descricao,"Geladeira Eletrolux 120L"); strcpy(catalogo[0].cat, categor[ELETRODOMESTICO]);
    catalogo[1].categoria=ELETRODOMESTICO; strcpy(catalogo[1].nome,"Forno eletrico"); catalogo[1].estoque=25;
    strcpy(catalogo[1].descricao,"Forno Eletrico Britania"); strcpy(catalogo[1].cat, categor[ELETRODOMESTICO]);
    catalogo[2].categoria=VESTUARIO; strcpy(catalogo[2].nome,"Capuz Preto"); catalogo[2].estoque=120;
    strcpy(catalogo[2].descricao,"Capuz Preto Nike la preta"); strcpy(catalogo[2].cat, categor[VESTUARIO]);
    catalogo[3].categoria=VESTUARIO; strcpy(catalogo[3].nome,"Jaqueta Couro"); catalogo[3].estoque=22;
    strcpy(catalogo[3].descricao,"Jaqueta de couro de Onca"); strcpy(catalogo[3].cat, categor[VESTUARIO]);
    catalogo[4].categoria=FERRAMENTA; strcpy(catalogo[4].nome,"Martelo"); catalogo[4].estoque=61;
    strcpy(catalogo[4].descricao,"Martelo Tramontina"); strcpy(catalogo[4].cat, categor[FERRAMENTA]);
    catalogo[5].categoria=FERRAMENTA; strcpy(catalogo[5].nome,"Furadeira"); catalogo[5].estoque=26;
    strcpy(catalogo[5].descricao,"Furadeira Bosch 450W"); strcpy(catalogo[5].cat, categor[FERRAMENTA]);
  
    while (1)
    {   

        // Loop para codigo de auto-incremento
        for (int i = 0; i <= num; i++){
        catalogo[i].codigo = i+1;
        }

        puts("Escolha uma Ação: ");
        puts("(1) Listar todos os produtos\n(2) Insirir um novo produto\n(3) Remover um Produto existente\n(4) Atualizar o estoque\n(5) Aumentar o estoque de algum produto\n(6) Diminuir o estoque de algum produto");
        scanf("%d", &a);


        switch (a){

        case 1:
            listar_catalogo(catalogo, num);
            break;
        
        case 2:
            resultado = IHC_inserir_produto(catalogo, num);
            if(resultado == true){
                num++;
                printf("Inserido com Sucesso!\n");
            } else if(resultado == false){
                printf("Erro na Operacao!\n");
            }
            break;
        case 3:
            resultado = IHC_remover_produto(catalogo, num);
             if(resultado == true){
                num--;
                printf("Removido com Sucesso!\n");
            } else if(resultado == false){
                printf("Erro na Operacao!\n");
            }
            break;
        case 4:
            resultado = IHC_atualizar_estoque(catalogo, num);
            if(resultado == true){
                printf("Atualizado com Sucesso!\n");
            } else if(resultado == false){
                printf("Erro na Operacao!\n");
            }
            break;
        case 5:
            resultado = IHC_atualizar_produto(catalogo, num);
            if(resultado == true){
                printf("Aumentado com Sucesso!\n");
            } else if(resultado == false){
                printf("Erro na Operacao!\n");
            }
            break;
        case 6:
            resultado = IHC_aumentar_produto(catalogo, num);
            if(resultado == true){
                printf("Diminuido com Sucesso!\n");
            } else if(resultado == false){
                printf("Erro na Operacao!\n");
            }
            break;
        default:
            puts("Erro na Escolha das ações, digite um numero valido");
            break;
            
        }
    }
}