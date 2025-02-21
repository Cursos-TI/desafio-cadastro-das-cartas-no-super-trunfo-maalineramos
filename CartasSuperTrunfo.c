#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a primeira carta:
struct carta1 {
    // Declarando as variáveis da carta:
    char estado[50], cidade[50];
    int opcao, pontos_turisticos;
    long int populacao;
    float area, pib, densidade, pib_per_capita, superPoder;
};

// Estrutura para a segunda carta:
struct carta2 {
    // Declarando as variáveis da carta:
    char estado[50], cidade[50];
    int opcao, pontos_turisticos;
    long int populacao;
    float area, pib, densidade,  pib_per_capita, superPoder;

};

int main () {

 int option;
 do{   
    int escolha;

    struct carta1 carta1;
    struct carta2 carta2;

    // Iniciando pelo menu
    printf("____JOGO DE CARTAS SUPER TRUNFO____\n\n");
    printf("Escolha uma opção:\n");
    printf("1. Cadastrar cartas \n");
    printf("2. Sair do jogo\n");
    printf("Opção: ");
    scanf("%d", &option);
    getchar();  // Limpa o buffer do scanf

    switch(option){
        case 1:
            
            // Cadastrando os dados da primeira carta
            printf("\n");
            printf("Cadastrando a primeira carta\n Digite o Estado escolhido:\n");
            fgets(carta1.estado, sizeof(carta1.estado), stdin);
            carta1.estado[strcspn(carta1.estado, "\n")] = 0; // Remove o '\n'

            printf("Digite a cidade:\n");
            fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
            carta1.cidade[strcspn(carta1.cidade, "\n")] = 0; // Remove o '\n'

            printf("Digite a quantidade de pontos turísticos:\n");
            scanf("%d", &carta1.pontos_turisticos);
            printf("Digite o número de habitantes:\n");
            scanf("%ld", &carta1.populacao);
            printf("Digite a área em km²:\n");
            scanf("%f", &carta1.area);
            printf("Digite o PIB:\n");
            scanf("%f", &carta1.pib);
            getchar();  // Limpa o buffer do scanf
            printf("\n");

            // Cálculo da densidade populacional 
            if (carta1.area > 0) {
                carta1.densidade = (float)carta1.populacao / carta1.area;
            } else {
                printf("Erro: A área não pode ser zero.\n");
            }
            // Calculo do PIB per capita
            if (carta1.populacao > 0) {
                carta1.pib_per_capita = carta1.pib / (float)carta1.populacao;
            } else {
                printf("Erro: População não pode ser zero.\n");
            }

           
            // Exibição dos dados da primeira carta
            printf("### DADOS DA PRIMEIRA CARTA ###\n");
            printf("ESTADO: %s - CIDADE: %s\n", carta1.estado, carta1.cidade);
            printf("PONTOS TURÍSTICOS: %d\n", carta1.pontos_turisticos);
            printf("POPULAÇÃO: %ld\n", carta1.populacao);
            printf("ÁREA DA CIDADE: %.0f km²\n", carta1.area);
            printf("PIB: R$ %.2f\n", carta1.pib);
            printf("DENSIDADE POPULACIONAL: %.0f hab/km²\n", carta1.densidade);
            printf("PIB PER CAPITA: R$ %.2f\n", carta1.pib_per_capita);
            printf("---------------------------------------------------------\n");
            //getchar();  // Limpa o buffer do scanf


            // Cadastrando os dados da segunda carta
            printf("Cadastrando a segunda carta\n Digite o Estado escolhido:\n");
            fgets(carta2.estado, sizeof(carta2.estado), stdin);
            carta2.estado[strcspn(carta2.estado, "\n")] = 0; // Remove o '\n'

            printf("Digite a cidade:\n");
            fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
            carta2.cidade[strcspn(carta2.cidade, "\n")] = 0; // Remove o '\n'

            printf("Digite a quantidade de pontos turísticos:\n");
            scanf("%d", &carta2.pontos_turisticos);
            printf("Digite o número de habitantes:\n");
            scanf("%ld", &carta2.populacao);
            printf("Digite a área em km²:\n");
            scanf("%f", &carta2.area);
            printf("Digite o PIB:\n");
            scanf("%f", &carta2.pib);
            getchar();  // Limpa o buffer do scanf
            printf("\n");

            // Cálculo da densidade populacional 
            if (carta1.area > 0) {
            carta2.densidade = (float)carta2.populacao / carta2.area;
            } else {
            printf("Erro: A área não pode ser zero.\n");
            }
            // Calculo do PIB per capita 
            if (carta2.populacao > 0) {
            carta2.pib_per_capita = carta2.pib / (float)carta2.populacao;
            } else {
            printf("Erro: População não pode ser zero.\n");
            }

            
            // Exibição dos dados da segunda carta
            printf("### DADOS DA SEGUNDA CARTA ###\n");
            printf("ESTADO: %s - CIDADE: %s\n", carta2.estado, carta2.cidade);
            printf("PONTOS TURÍSTICOS: %d\n", carta2.pontos_turisticos);
            printf("POPULAÇÃO: %ld\n", carta2.populacao);
            printf("ÁREA DA CIDADE: %.0f km²\n", carta2.area);
            printf("PIB: R$ %.2f\n", carta2.pib);
            printf("DENSIDADE POPULACIONAL: %.0f hab/km²\n", carta2.densidade);
            printf("PIB PER CAPITA: R$ %.2f\n", carta2.pib_per_capita);
            printf("-----------------------------------------------------\n");
            
            do{
            //****Dando a opção de  comparação dos atributos
            printf("Escolha o tipo de comparação entre as duas cartas: \n");
            printf("1. Com base no SUPER PODER: calculando somando todos os atributos!  \n");
            printf("2. Com base na Densidade Populacional: Vence a carta com menor valor! \n");
            printf("3. Com base na Quantidade de pontos turísticos: Vence a carta com maior valor! \n");
            printf("4. Com base na Área da cidade: Vence a maior cidade! \n");
            printf("5. Com base no PIB: Vence a carta com maior valor! \n");
            printf("6. Voltar ao Menu \n");
            scanf("%d", &escolha);
            printf("\n");
            

            switch (escolha)
            {
                case 1:
                //Calculo do Super Poder da primeira carta
                carta1.superPoder = carta1.area + carta1.pib + carta1.densidade + carta1.pib_per_capita + (float)carta1.pontos_turisticos + (float)carta1.populacao;
                //printf("**PODER TOTAL carta 1: %.0f \n", carta1.superPoder);
                //Calculo do Super Poder da segunda carta
                carta2.superPoder = carta2.area + carta2.pib + carta2.densidade + carta2.pib_per_capita + (float)carta2.pontos_turisticos + (float)carta2.populacao;
                //printf("**PODER TOTAL carta 2: %.0f \n", carta2.superPoder);

                //Comparação de Super poderes
                    printf("Calculando e comparando os Super Poderes entre as cartas... \n");
                    printf("\n");
                    if (carta1.superPoder > carta2.superPoder) { 
                    printf("CARTA 1 VENCEU!\n");   
                    printf("SUPER PODER da carta 1: %.0f\n SUPER PODER da carta 2: %.0f\n", carta1.superPoder, carta2.superPoder);
                    } else { 
                    printf("CARTA 2 VENCEU!\n"); 
                    printf("SUPER PODER da carta 1: %.0f\n SUPER PODER da carta 2: %.0f\n", carta1.superPoder, carta2.superPoder);
                    }
                    printf("\n");
                break;

                case 2://Comparação de Densidade Populacional
                    printf("Comparando a Densidade Populacional entre as cartas... \n");
                    printf("\n");
                    if (carta1.densidade > carta2.densidade) { 
                    printf("CARTA 1 VENCEU!\n");   
                    printf("DENSIDADE da carta 1: %.0f hab/km²\n DENSIDADE da carta 2: %.0f hab/km²\n", carta1.densidade, carta2.densidade);
                    } else { 
                    printf("CARTA 2 VENCEU!\n");   
                    printf("DENSIDADE da carta 1: %.0f hab/km²\n DENSIDADE da carta 2: %.0f hab/km²\n", carta1.densidade, carta2.densidade);
                    } 
                    printf("\n");
                break; 
                
                case 3:// Comparação de pontos turísticos
                    printf("Comparando os Pontos Turísticos entre as cartas... \n");
                    printf("\n");
                    if (carta1.pontos_turisticos > carta2.pontos_turisticos) { 
                    printf("CARTA 1 VENCEU!\n");   
                    printf("PONTOS TÚRISTICOS da carta 1: %d \n PONTOS TÚRISTICOS da carta 2: %d \n", carta1.pontos_turisticos, carta2.pontos_turisticos);
                    } else { 
                    printf("CARTA 2 VENCEU!\n"); 
                    printf("PONTOS TÚRISTICOS da carta 1: %d \n PONTOS TÚRISTICOS da carta 2: %d \n", carta1.pontos_turisticos, carta2.pontos_turisticos);
                    }
                    printf("\n");
                break; 

                case 4://Comparação da Área da cidade
                    printf("Comparando a Área da cidade entre as cartas... \n");
                    printf("\n");
                    if (carta1.area > carta2.area) { 
                    printf("CARTA 1 VENCEU!\n");   
                    printf("ÁREA da carta 1: %.0f \n ÁREA da carta 2: %.0f \n", carta1.area, carta2.area);
                    } else { 
                    printf("CARTA 2 VENCEU!\n");  
                    printf("ÁREA da carta 1: %.0f \n ÁREA da carta 2: %.0f \n", carta1.area, carta2.area);
                    } 
                    printf("\n");
                break; 

                case 5://Comparação do PIB
                   printf("Comparando o PIB da cidade entre as cartas... \n");
                    printf("\n");
                    if (carta1.pib > carta2.pib) { 
                    printf("CARTA 1 VENCEU!\n");    
                    printf("PIB da carta 1: %.2f \n PIB da carta 2: %.2f \n", carta1.pib, carta2.pib);
                    } else { 
                    printf("CARTA 2 VENCEU!\n");    
                    printf("PIB da carta 1: %.2f \n PIB da carta 2: %.2f \n", carta1.pib, carta2.pib);
                    } 
                    printf("\n");
                break; 
            
                case 6: printf(" Saindo... \n");
                    printf("\n");
                break;            

            default: printf("Opção invalida! \n");
                    printf("\n");
                break;
            }
            } while (escolha != 6);
         

        case 2:
            printf("Saindo do jogo...\n");
            printf("\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }       printf("\n");
} while (option != 2); 


    return 0;
}
