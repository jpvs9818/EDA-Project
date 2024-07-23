#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAM 5
#define yearNum 4

const char* eCivil[] = {"Solteiro(a)", "Casado(a)/Uniao", "Divorciado(a)", "Viuvo(a)"};
const char* eDependente[] = {"conjuge", "filho(a)/enteado(a)", "mae", "pai"};

void criaRegistro(funcionario empresa[]) {
    int i;
    for(i = 0; i < TAM; i++) {
        if(empresa[i].ano_adimissao == 0)
            break;
        }
    if(empresa[i].ano_adimissao == 0) {
        empresa[i] = registraFuncionario();
    }
    else {
        printf("Tamanho max atingido.\n\n");
    }
}

void salvaRegistro(funcionario empresa[TAM]) {
    FILE *ptr_Funcio = fopen("funcionario.txt", "a");
    FILE *ptr_Dependente = fopen("dependente.txt", "a");

    if (ptr_Funcio == NULL || ptr_Dependente == NULL) {
        printf("Erro abrindo arquivo!\n");
        return;
    }

    for (int i = 0; i < TAM; i++) {
        if (empresa[i].ano_adimissao == 0)
            break;

        fprintf(ptr_Funcio, "Nome:             %s\n", empresa[i].cadastro.nome);
        fprintf(ptr_Funcio, "CPF:              %s\n", empresa[i].cadastro.cpf);
        fprintf(ptr_Funcio, "Estado Civil:     %s\n", eCivil[empresa[i].estado_civil]);
        fprintf(ptr_Funcio, "Ano de Adimissao: %d\n\n", empresa[i].ano_adimissao);

        if (empresa[i].dependentes != NULL) {
            for (int j = 0; j < empresa[i].num_dependentes; j++) {
                fprintf(ptr_Dependente, "Dependente do CPF (%s)\n", empresa[i].cadastro.cpf);
                fprintf(ptr_Dependente, "Dependente %d :\n\n", j + 1);
                fprintf(ptr_Dependente, "Nome:      %s\n", empresa[i].dependentes[j].nome);
                fprintf(ptr_Dependente, "CPF:       %s\n", empresa[i].dependentes[j].cpf);
                fprintf(ptr_Dependente, "Relacao:   %s\n\n", eDependente[empresa[i].dependentes[j].relacao]);
            }
        }
    }
    fclose(ptr_Funcio);
    fclose(ptr_Dependente);
}


int menu(){
    int i;
    printf("1.Registrar funcionario\n2.Salvar em arquivo\n3.Limpar arquivo\n4.Sair\n");
    do{
        scanf("%d",&i);
    }while(i < 1 || i > 5);

    return i;
}

void limpaArquivo() {
    FILE *ptr1 = fopen("dependente.txt","w");
    FILE *ptr2 = fopen("funcionario.txt","w");
    fclose(ptr1);
    fclose(ptr2);
}

int main(){
    funcionario empresa[TAM];

    for(int i = 0; i < TAM; i++){
        empresa[i].ano_adimissao = 0;
        empresa[i].dependentes = NULL;
    }
    int x;
    do{
       x = menu();

        switch(x){
            case 1:
                criaRegistro(empresa);
                break;
            case 2:
                salvaRegistro(empresa);
                break;
            case 3:
                limpaArquivo();
                break;
            case 4:
                printf("Finalizando o programa.\n");
                break;
            default:
                printf("Insira um valor valido\n");
                break;
        }
    }while(x != 4);

    for (int i = 0; i < TAM; i++) {
        if (empresa[i].dependentes != NULL) {
            free(empresa[i].dependentes);
        }
    }

    return 0;
}
