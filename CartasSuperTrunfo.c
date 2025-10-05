#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a primeira carta:
struct Carta {
    // Declarando as variáveis da carta:
    char estado[50], cidade[50];
    int opcao, pontos_turisticos;
    long int populacao;
    double superPoder, densidade, pib, area, pib_per_capita;
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarCarta(struct Carta *carta) {
    printf("Digite o Estado:\n");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0; // Remove '\n'

    printf("Digite a Cidade:\n");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0; // Remove '\n'

    printf("Digite a quantidade de pontos turísticos:\n");
    scanf("%d", &carta->pontos_turisticos);

    printf("Digite o número de habitantes:\n");
    scanf("%ld", &carta->populacao);

    printf("Digite a área em km²:\n");
    scanf("%lf", &carta->area); // Use %lf para double

    printf("Digite o PIB:\n");
    scanf("%lf", &carta->pib);

    // Limpa o buffer do teclado
    limparBuffer();

    // Cálculos
    if(carta->area > 0) carta->densidade = carta->populacao / carta->area;
    else carta->densidade = 0;

    if(carta->populacao > 0) carta->pib_per_capita = carta->pib / carta->populacao;
    else carta->pib_per_capita = 0;
}

void mostrarCarta(struct Carta carta, int num) {
    printf("\n### DADOS DA %s CARTA ###\n", (num == 1) ? "PRIMEIRA" : "SEGUNDA");
    printf("ESTADO: %s - CIDADE: %s\n", carta.estado, carta.cidade);
    printf("PONTOS TURÍSTICOS: %d\n", carta.pontos_turisticos);
    printf("POPULAÇÃO: %ld\n", carta.populacao);
    printf("ÁREA DA CIDADE: %.0f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("DENSIDADE POPULACIONAL: %.0f hab/km²\n", carta.densidade);
    printf("PIB PER CAPITA: R$ %.2f\n", carta.pib_per_capita);
    printf("-----------------------------------------------------\n");
}

double calcularSuperPoder(struct Carta carta) {
    return carta.area + carta.pib + carta.densidade + carta.pib_per_capita + 
           (double)carta.pontos_turisticos + (double)carta.populacao;
}

void compararCartas(struct Carta c1, struct Carta c2, int tipo) {
    int vencedor = 0;

    switch(tipo) {
        case 1: // Super Poder
            c1.superPoder = calcularSuperPoder(c1);
            c2.superPoder = calcularSuperPoder(c2);
            vencedor = (c1.superPoder > c2.superPoder) ? 1 : 2;
            printf("Comparando SUPER PODER: %.0f x %.0f\n", c1.superPoder, c2.superPoder);
            break;
        case 2: // Densidade
            vencedor = (c1.densidade < c2.densidade) ? 1 : 2;
            printf("Comparando DENSIDADE: %.0f x %.0f\n", c1.densidade, c2.densidade);
            break;
        case 3: // Pontos turísticos
            vencedor = (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 2;
            printf("Comparando PONTOS TURÍSTICOS: %d x %d\n", c1.pontos_turisticos, c2.pontos_turisticos);
            break;
        case 4: // Área
            vencedor = (c1.area > c2.area) ? 1 : 2;
            printf("Comparando ÁREA: %.0f x %.0f\n", c1.area, c2.area);
            break;
        case 5: // PIB
            vencedor = (c1.pib > c2.pib) ? 1 : 2;
            printf("Comparando PIB: %.2f x %.2f\n", c1.pib, c2.pib);
            break;
    }

    printf("CARTA %d VENCEU!\n\n", vencedor);
}


int main () {
    struct Carta carta1, carta2;

 int option;//Para a funçao do-while usada no menu
 do{   
    int escolha;//Para a segunda funçao de escolha das comparações

    // Iniciando pelo menu
    printf("____JOGO DE CARTAS SUPER TRUNFO____\n\n");
    printf("Escolha uma opção:\n");
    printf("1. Cadastrar cartas \n");
    printf("2. Sair do jogo\n");
    printf("Opção: ");
    scanf("%d", &option);
    limparBuffer();

    switch(option){
        case 1:
            
            // Cadastrando os dados da primeira carta
            printf("\nCadastrando a primeira carta:\n");
            cadastrarCarta(&carta1);

           
            // Exibição dos dados da primeira carta
            mostrarCarta(carta1, 1);    


            printf("\nCadastrando a segunda carta:\n");
            cadastrarCarta(&carta2);

            
            // Exibição dos dados da segunda carta
            mostrarCarta(carta2, 2);
            
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
            limparBuffer();
            printf("\n");
                
            switch (escolha)
            {
                case 1:
                compararCartas(carta1, carta2, escolha);
                break;

                case 2://Comparação de Densidade Populacional
                    printf("Comparando a Densidade Populacional entre as cartas... \n");
                    printf("\n");
                    if (carta1.densidade < carta2.densidade) { 
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
         
        break;
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
