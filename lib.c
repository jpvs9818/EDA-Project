#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define nome_size 250
#define cpf_size 12

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void tratamentoString(char s[]) {
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        i++;
    }
}

pessoa registraDependente(int i);

funcionario registraFuncionario() {
    funcionario n_func;
    n_func.dependentes = NULL;  // Inicializando n_func
    n_func.num_dependentes = 0;
    n_func.cadastro.relacao = 0;

    printf("Nome:\n");
    fgets(n_func.cadastro.nome, nome_size, stdin);
    tratamentoString(n_func.cadastro.nome);

    printf("CPF:\n");
    fgets(n_func.cadastro.cpf, cpf_size, stdin);
    tratamentoString(n_func.cadastro.cpf);

    printf("Ano de adimissao:\n");
    scanf("%d", &n_func.ano_adimissao);
    clearBuffer();

    printf("Estado civil: (0.Solteiro, 1.Casado/Uniao, 2.Divorciado, 3.Viuvo)\n");
    do {
        scanf("%d", &n_func.estado_civil);
        clearBuffer();
    } while (n_func.estado_civil < 0 || n_func.estado_civil > 3);

    printf("Quantidade de dependentes:\n");
    do {
        scanf("%d", &n_func.num_dependentes);
        clearBuffer();  // limpando input
    } while (n_func.num_dependentes < 0);

    if (n_func.num_dependentes > 0) {
        n_func.dependentes = (pessoa*) malloc(n_func.num_dependentes * sizeof(pessoa)); // alocando memoria para vetor dependente
        if (n_func.dependentes == NULL) {
            perror("Failed to allocate memory for dependentes");
            exit(1);
        }
        for (int k = 0; k < n_func.num_dependentes; k++) {
            n_func.dependentes[k] = registraDependente(k + 1);
        }
    }

    return n_func;
}

pessoa registraDependente(int i) {
    pessoa dependente;
    int j;
    printf("Nome do dependente %d:\n", i);
    fgets(dependente.nome, nome_size, stdin);
    tratamentoString(dependente.nome);
    printf("CPF do dependente %d:\n", i);
    fgets(dependente.cpf, cpf_size, stdin);
    tratamentoString(dependente.cpf);
    printf("Relacao com dependente %d (1.cônjuge, 2.filho(a)/enteado(a), 3.mãe, 4.pai):\n", i);
    do {
        scanf("%d", &j);
        clearBuffer();  // Limpando o \n ao apertar enter
    } while (j < 1 || j > 4);
    dependente.relacao = j - 1;  // correção ao indexar o valor na matriz dependente
    return dependente;
}
