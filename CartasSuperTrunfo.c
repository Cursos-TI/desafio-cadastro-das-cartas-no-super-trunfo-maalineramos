#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    char codigo_cidade[4];
    char estado[50], cidade[50];
    int pontos_turisticos;
    long int populacao;
    float  area, pib, densidade, pib_per_capita;
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    /*printf("Digite o Estado escolhido:\n");
    scanf(" %s", &estado);
    printf("Digite a cidade:\n");
    scanf(" %s", &cidade);*/
    printf("Digite o Estado escolhido:\n");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = 0;
    printf("Digite a cidade:\n");
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strcspn(cidade, "\n")] = 0;
    printf("Digite a quantidade de pontos turísticos:\n");
    scanf("%d", &pontos_turisticos);
    printf("Digite o número de habitantes:\n");
    scanf("%ld", &populacao);
    printf("Digite a área em km:\n");
    scanf("%f", &area);
    printf("Digite o PIB:\n");
    scanf("%f", &pib);
    printf("\n");

    // Calculo da densidade:
    densidade = (float)populacao / area;

    // Calculo do PIB per capita:
    pib_per_capita = pib / (float)populacao;

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.*/
    printf("### DADOS DA CARTA ###\n");
    printf("ESTADO: %s - CIDADE: %s \n", estado, cidade);
    printf("PONTOS TURÍSTICOS: %d \n", pontos_turisticos);
    printf("POPULAÇÃO: %ld \n", populacao);
    printf("ÁREA DA CIDADE: %f \n", area);
    printf("PIB: %.2f \n", pib);
    printf("DENSIDADE POPULACIONAL: %f \n", densidade);
    printf("PIB per capita: %.2f \n", pib_per_capita);
    printf("\n");

    return 0;
}
