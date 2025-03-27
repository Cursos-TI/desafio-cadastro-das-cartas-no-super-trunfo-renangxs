#include <stdio.h>
#include <string.h>

struct CartaSuperTrunfo {
    char estado;
    char codigo[5];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

void calcularAtributos(struct CartaSuperTrunfo *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
    else
        carta->pibPerCapita = 0;
    
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita + (carta->densidadePopulacional > 0 ? 1.0 / carta->densidadePopulacional : 0);
}

struct CartaSuperTrunfo lerCarta() {
    struct CartaSuperTrunfo carta;
    printf("Digite o estado (A a H): ");
    scanf(" %c", &carta.estado);
    printf("Digite o código da carta (ex: A01, B03): ");
    scanf("%4s", carta.codigo);
    printf("Digite o nome da cidade: ");
    getchar();
    fgets(carta.nomeCidade, sizeof(carta.nomeCidade), stdin);
    carta.nomeCidade[strcspn(carta.nomeCidade, "\n")] = '\0';
    printf("Digite a população da cidade: ");
    scanf("%lu", &carta.populacao);
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &carta.area);
    printf("Digite o PIB da cidade (bilhões de reais): ");
    scanf("%f", &carta.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontosTuristicos);
    calcularAtributos(&carta);
    return carta;
}

void compararCartas(struct CartaSuperTrunfo c1, struct CartaSuperTrunfo c2) {
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    printf("Área: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 2, c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional ? 1 : 2, c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita ? 1 : 2, c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", c1.superPoder > c2.superPoder ? 1 : 2, c1.superPoder > c2.superPoder);
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    printf("Insira os dados da primeira carta:\n");
    carta1 = lerCarta();
    printf("\nInsira os dados da segunda carta:\n");
    carta2 = lerCarta();
    compararCartas(carta1, carta2);
    return 0;
}
