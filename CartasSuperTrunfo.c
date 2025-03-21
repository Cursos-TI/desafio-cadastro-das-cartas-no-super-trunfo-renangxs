#include <stdio.h>

struct CartaSuperTrunfo {
    char estado;              // Letra do estado (A a H)
    char codigo[5];           // Código da carta (ex: A01, B03)
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área da cidade em km²
    float pib;                // PIB da cidade (em bilhões de reais)
    int pontosTuristicos;     // Número de pontos turísticos
};

struct CartaSuperTrunfo lerCarta() {
    struct CartaSuperTrunfo carta;
    
    printf("Digite o estado (A a H): ");
    scanf(" %c", &carta.estado); // O espaço antes de %c é para consumir qualquer caractere residual no buffer

    printf("Digite o código da carta (ex: A01, B03): ");
    scanf("%s", carta.codigo); // Lê o código da carta

    printf("Digite o nome da cidade: ");
    scanf(" %s", carta.nomeCidade); // Lê o nome da cidade até o enter

    printf("Digite a população da cidade: ");
    scanf("%d", &carta.populacao); // Lê a população

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta.area); // Lê a área

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta.pib); // Lê o PIB

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta.pontosTuristicos); // Lê o número de pontos turísticos

    return carta;
}

struct CartaSuperTrunfo exibirCarta(struct CartaSuperTrunfo carta, int numCarta) {
    printf("\nCarta %d:\n", numCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %f km²\n", carta.area);
    printf("PIB: %f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);

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
