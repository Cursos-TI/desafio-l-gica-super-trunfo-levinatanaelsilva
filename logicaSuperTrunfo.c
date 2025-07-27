#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para calcular densidade populacional
float calcularDensidade(Carta c) {
    return c.populacao / c.area;
}

// Função para exibir uma carta
void exibirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nome, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", calcularDensidade(c));
    printf("------------------------------------\n");
}

int main() {
    Carta cidade1, cidade2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1.nome);
    printf("Estado: ");
    scanf(" %[^\n]", cidade1.estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", cidade1.codigo);
    printf("População: ");
    scanf("%d", &cidade1.populacao);
    printf("Área (km²): ");
    scanf("%f", &cidade1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade1.pib);
    printf("Nº de Pontos Turísticos: ");
    scanf("%d", &cidade1.pontosTuristicos);

    printf("\n");

    // Cadastro da segunda carta
    printf("Cadastro da Carta 2:\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2.nome);
    printf("Estado: ");
    scanf(" %[^\n]", cidade2.estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", cidade2.codigo);
    printf("População: ");
    scanf("%d", &cidade2.populacao);
    printf("Área (km²): ");
    scanf("%f", &cidade2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade2.pib);
    printf("Nº de Pontos Turísticos: ");
    scanf("%d", &cidade2.pontosTuristicos);

    printf("\n=== CARTA 1 ===\n");
    exibirCarta(cidade1);
    printf("=== CARTA 2 ===\n");
    exibirCarta(cidade2);

    // Menu de comparação
    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional (menor vence)\n");
    printf("Sua escolha: ");
    scanf("%d", &opcao);

    printf("\n== RESULTADO DA COMPARAÇÃO ==\n");

    if (opcao == 1) {
        if (cidade1.populacao > cidade2.populacao)
            printf("Vencedora: %s (maior população)\n", cidade1.nome);
        else if (cidade2.populacao > cidade1.populacao)
            printf("Vencedora: %s (maior população)\n", cidade2.nome);
        else
            printf("Empate em população!\n");
    } else if (opcao == 2) {
        if (cidade1.area > cidade2.area)
            printf("Vencedora: %s (maior área)\n", cidade1.nome);
        else if (cidade2.area > cidade1.area)
            printf("Vencedora: %s (maior área)\n", cidade2.nome);
        else
            printf("Empate em área!\n");
    } else if (opcao == 3) {
        if (cidade1.pib > cidade2.pib)
            printf("Vencedora: %s (maior PIB)\n", cidade1.nome);
        else if (cidade2.pib > cidade1.pib)
            printf("Vencedora: %s (maior PIB)\n", cidade2.nome);
        else
            printf("Empate em PIB!\n");
    } else if (opcao == 4) {
        float dens1 = calcularDensidade(cidade1);
        float dens2 = calcularDensidade(cidade2);
        if (dens1 < dens2)
            printf("Vencedora: %s (menor densidade populacional)\n", cidade1.nome);
        else if (dens2 < dens1)
            printf("Vencedora: %s (menor densidade populacional)\n", cidade2.nome);
        else
            printf("Empate em densidade populacional!\n");
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
