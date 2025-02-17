#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declarando as variáveis do jogo:
    char estado[50], cidade[50];
    int opcao, pontos_turisticos;
    long int populacao;
    float area, pib, densidade = 0, pib_per_capita = 0;

    // Iniciando pelo menu
    printf("____JOGO DE CARTAS SUPER TRUNFO____\n\n");
    printf("Escolha uma opção:\n");
    printf("1. Iniciar o jogo\n");
    printf("2. Sair do jogo\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    getchar();  // Limpa o buffer do scanf

    switch (opcao) {
        case 1:
            // Cadastrando os dados da carta
            printf("\nDigite o Estado escolhido:\n");
            fgets(estado, sizeof(estado), stdin);
            estado[strcspn(estado, "\n")] = 0; // Remove o '\n'

            printf("Digite a cidade:\n");
            fgets(cidade, sizeof(cidade), stdin);
            cidade[strcspn(cidade, "\n")] = 0; // Remove o '\n'

            printf("Digite a quantidade de pontos turísticos:\n");
            scanf("%d", &pontos_turisticos);
            printf("Digite o número de habitantes:\n");
            scanf("%ld", &populacao);
            printf("Digite a área em km²:\n");
            scanf("%f", &area);
            printf("Digite o PIB:\n");
            scanf("%f", &pib);
            printf("\n");

            // Cálculo da densidade populacional e PIB per capita 
            if (area > 0) {
                densidade = (float)populacao / area;
            } else {
                printf("Erro: A área não pode ser zero.\n");
            }

            if (populacao > 0) {
                pib_per_capita = pib / (float)populacao;
            } else {
                printf("Erro: População não pode ser zero.\n");
            }

            // Exibição dos dados da carta
            printf("### DADOS DA CARTA ###\n");
            printf("ESTADO: %s - CIDADE: %s\n", estado, cidade);
            printf("PONTOS TURÍSTICOS: %d\n", pontos_turisticos);
            printf("POPULAÇÃO: %ld\n", populacao);
            printf("ÁREA DA CIDADE: %.2f km²\n", area);
            printf("PIB: R$ %.2f\n", pib);
            printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", densidade);
            printf("PIB PER CAPITA: R$ %.2f\n", pib_per_capita);
            printf("\n");

            break;

        case 2:
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
