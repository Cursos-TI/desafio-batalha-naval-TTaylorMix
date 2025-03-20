#include <stdio.h>

#define TAM_TABULEIRO 10  // Tam. tabuleiro
#define TAM_NAVIO 3       // Tam. navios

// exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Iniciar do tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = { 0 };

    // Coordenadas e posicao do navio horizontal
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 1;

    // Coordenadas e posicao do navio vertical
    int linhaNavioVertical = 4;
    int colunaNavioVertical = 5;

    // Posicao do navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (colunaNavioHorizontal + i < TAM_TABULEIRO) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        }
    }

    // Posicionando o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaNavioVertical + i < TAM_TABULEIRO) {
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        }
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
