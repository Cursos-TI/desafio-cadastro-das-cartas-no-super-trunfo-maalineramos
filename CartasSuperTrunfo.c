#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int pturisticos;
    char estado [20];
    unsigned int populacao, pib, area;
    // Cadastro das Cartas:
      /*1.São Paulo
        2.Rio de Janeiro
        3.Minas Gerais
        4.Bahia
        5.Santa Catarina
        6.Goiás
        7.Amazonas
        8.Rio Grande do Sul*/
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf("Primeiro escolha com qual estado irá jogar:\n");
    printf("Digite o nome entre as opções:\n");
    printf("São Paulo - Rio de Janeiro - Minas Gerais - Bahia - Santa Catarina - Goiás - Amazonas - Rio Grande do Sul \n");
    scanf("%s", &estado);
    printf("\n");
    printf("##Parabens! Você escolheu: %s\n", estado);
    printf("\n");
    printf("Agora digite o número de pontos turístico que seu estado terá: \n");
    scanf("%d", &pturisticos);
    printf("Uau! Há %d pontos turisticos na sua carta do estado: %s!!!\n", pturisticos, estado);
    printf("\n");
    printf("Digite o número aproximado de habitantes da cidade escolhida\n");
    scanf("%u", &populacao);
    printf("##Registrado! Há %u habitantes no estado %s!!!\n", populacao, estado);
    printf("\n");
    printf("DADOS DA SUA CARTA:\n ESTADO: %s\n PONTOS TURÍSTICOS: %d\n HABITANTES: %u \n", estado, pturisticos, populacao);
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
