#pragma once
#define nome_size 250
#define cpf_size 12
#define empresa_size 10

typedef struct Pessoa{
    char nome[nome_size];
    char cpf[cpf_size];
    int relacao;     
}pessoa;

typedef struct funcio{
    struct Pessoa cadastro;
    int estado_civil;
    int ano_adimissao;
    struct Pessoa *dependentes;
    int num_dependentes;
}funcionario;

pessoa registraDependente(int i);
funcionario registraFuncionario();

