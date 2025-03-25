#include <stdio.h>
#include <string.h> // Para usar strcspn

struct CartaSuperTrunfo {
    char estado;               // Letra do estado (A a H)
    char codigo[5];            // Código da carta (ex: A01, B03)
    char nomeCidade[50];       // Nome da cidade
    int populacao;             // População da cidade
    float area;                // Área da cidade em km²
    float pib;                 // PIB da cidade (em bilhões de reais)
    int pontosTuristicos;      // Número de pontos turísticos
    float densidadePopulacional; // Densidade populacional
    float pibPerCapita;        // PIB per capita
};

// Função para calcular a densidade populacional e o PIB per capita
void calcularDensidadeEPIB(struct CartaSuperTrunfo *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;  // PIB per capita em reais
}

struct CartaSuperTrunfo lerCarta() {
    struct CartaSuperTrunfo carta;
    
    // Entrada de dados
    printf("Digite o estado (A a H): ");
    scanf(" %c", &carta.estado);

    printf("Digite o código da carta (ex: A01, B03): ");
    scanf("%s", carta.codigo);

    printf("Digite o nome da cidade: ");
    getchar();  // Consome o caractere de nova linha residual
    fgets(carta.nomeCidade, sizeof(carta.nomeCidade), stdin);
    carta.nomeCidade[strcspn(carta.nomeCidade, "\n")] = '\0'; // Remove o '\n' no final

    printf("Digite a população da cidade: ");
    scanf("%d", &carta.populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta.area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta.pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta.pontosTuristicos);

    // Calculando a densidade e PIB per capita
    calcularDensidadeEPIB(&carta);

    return carta;
}

struct CartaSuperTrunfo exibirCarta(struct CartaSuperTrunfo carta, int numCarta) {
    printf("\nCarta %d:\n", numCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);

    // Exibindo a densidade populacional e o PIB per capita
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);

    return carta;
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;

    printf("Insira os dados da primeira carta:\n");
    carta1 = lerCarta();

    printf("\nInsira os dados da segunda carta:\n");
    carta2 = lerCarta();

    printf("\nInformações Cadastradas:\n");
    carta1 = exibirCarta(carta1, 1);
    carta2 = exibirCarta(carta2, 2);

    return 0;
}
