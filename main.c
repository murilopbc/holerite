#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para obter os dados do funcionário


void obterDadosFuncionario(char* nome, float* salario_bruto, float* inss, float* ir, float* outros_descontos) {
    printf("Digite o nome do funcionário: ");
    scanf(" %49[^\n]", nome);

    printf("Digite o salário bruto: R$ ");
    while (scanf("%f", salario_bruto) != 1 || *salario_bruto <= 0) {
        printf("Erro: Salário bruto inválido. Tente novamente.\n");
        fflush(stdin); 
        printf("Digite o salário bruto: R$ ");
    }

    printf("Digite o valor do INSS: R$ ");
    while (scanf("%f", inss) != 1 || *inss < 0) {
        printf("Erro: Valor do INSS inválido. Tente novamente.\n");
        fflush(stdin);
        printf("Digite o valor do INSS: R$ ");
    }

    printf("Digite o valor do IR (Imposto de Renda): R$ ");
    while (scanf("%f", ir) != 1 || *ir < 0) {
        printf("Erro: Valor do IR inválido. Tente novamente.\n");
        fflush(stdin);
        printf("Digite o valor do IR (Imposto de Renda): R$ ");
    }

    printf("Digite outros descontos: R$ ");
    while (scanf("%f", outros_descontos) != 1 || *outros_descontos < 0) {
        printf("Erro: Valor de outros descontos inválido. Tente novamente.\n");
        fflush(stdin);
        printf("Digite outros descontos: R$ ");
    }
}

// Função para calcular o salário líquido


float calcularSalarioLiquido(float salario_bruto, float inss, float ir, float outros_descontos) {
    return salario_bruto - (inss + ir + outros_descontos);
}

// Função para exibir o holerite


void exibirHolerite(char* nome, float salario_bruto, float inss, float ir, float outros_descontos, float salario_liquido) {
    printf("\n---- Holerite ----\n");
    printf("Funcionário: %s\n", nome);
    printf("Salário Bruto: R$ %.2f\n", salario_bruto);
    printf("INSS: R$ %.2f\n", inss);
    printf("Imposto de Renda: R$ %.2f\n", ir);
    printf("Outros Descontos: R$ %.2f\n", outros_descontos);
    printf("Salário Líquido: R$ %.2f\n", salario_liquido);
}

// Função para perguntar ao usuário se deseja cadastrar outro funcionário


bool desejaCadastrarOutro() {
    char opcao;
    printf("\nDeseja adicionar outro funcionário? (s/n): ");
    scanf(" %c", &opcao);

    switch (opcao) {
        case 's':
        case 'S':
            return true;
        case 'n':
        case 'N':
            return false;
        default:
            printf("Opção inválida. Encerrando...\n");
            return false;
    }
}

int main() {
    bool continuar = true; // Variável de controle do loop principal
    int num_funcionarios = 0;

    while (continuar) {
        char nome[50];
        float salario_bruto = 0.0f, inss = 0.0f, ir = 0.0f, outros_descontos = 0.0f, salario_liquido = 0.0f;

        // Obtém os dados do funcionário

        obterDadosFuncionario(nome, &salario_bruto, &inss, &ir, &outros_descontos);

        // Calcula o salário líquido

        salario_liquido = calcularSalarioLiquido(salario_bruto, inss, ir, outros_descontos);

        // Exibe o holerite

        exibirHolerite(nome, salario_bruto, inss, ir, outros_descontos, salario_liquido);

        // Contador de funcionários

        num_funcionarios++;

        // Pergunta se o usuário deseja adicionar outro funcionário

        continuar = desejaCadastrarOutro();
    }

    printf("\nTotal de funcionários cadastrados: %d\n", num_funcionarios);
    printf("Encerrando o programa...\n");
    return 0;
}
