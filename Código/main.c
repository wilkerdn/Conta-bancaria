#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ficha{
    char nome[50];
    char cpf[11];
    double saldo;
}ficha_cad;

int menu(ficha_cad *cliente){
    double vlr_deposito=0;
    double vlr_saque=0;
    int operacao=0;
    printf("Para consultar saldo digite: 1\nPara realizar saque digite: 2\nPara realizar um deposito digite: 3\nPara encerrar digite: 4\n");
    scanf("%d",&operacao);
    switch(operacao){
    case 1:
        printf("Nome do titular: %s",cliente->nome);
        printf("Saldo: R$%.2lf\n",cliente->saldo);
        menu(&*cliente);
        break;
    case 2:
        printf("Digite o valor para saque:\nR$");
        scanf("%lf",&vlr_saque);
        cliente->saldo = cliente->saldo - vlr_saque;
        printf("Nome do titular: %s",cliente->nome);
        printf("Saldo: R$%.2lf\n",cliente->saldo);
        menu(&*cliente);
        break;
    case 3:
        printf("Digite o valor para deposito:\nR$");
        scanf("%lf",&vlr_deposito);
        cliente->saldo = cliente->saldo + vlr_deposito;
        printf("Nome do titular: %s",cliente->nome);
        printf("Saldo: R$%.2lf\n",cliente->saldo);
        menu(&*cliente);
        break;
    case 4:
        free (cliente);
        return 0;
        break;
    }
}

int main(){
    ficha_cad *cliente;
    cliente = malloc(sizeof(ficha_cad));
    printf("Digite o nome:\n");
    fgets(cliente->nome,50,stdin);
    printf("Digite o CPF (apenas numeros):\n");
    scanf("%s",cliente->cpf);
    printf("Digite o valor para deposito inicial:\nR$");
    scanf("%lf",&cliente->saldo);
    menu(&*cliente);
    free (cliente);
    return 0;
}
