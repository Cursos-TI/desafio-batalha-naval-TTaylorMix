#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TAM 10

// Exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]); // Imprime cada celula do tabuleiro
        }
        printf("\n");
    }
}

// Posiciona o navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + 2 >= TAM) return 0; // Verifica se o navio cabe horizontalmente
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; // Verifica se há sobreposição
        }
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3; // Posiciona o navio
    }
    return 1;
}

// Posiciona o navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + 2 >= TAM) return 0; // Verifica se o navio cabe verticalmente
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0; // Verifica se há sobreposição
        }
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 3; // Posiciona o navio
    }
    return 1;
}

// Posiciona o navio na diagonal principal
int posicionarNavioDiagonal1(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + 2 >= TAM || coluna + 2 >= TAM) return 0; // Verifica se o navio cabe na diagonal
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) {
            return 0; // Verifica se há sobreposição
        }
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // Posiciona o navio
    }
    return 1;
}

// Posiciona o navio na diagonal inversa
int posicionarNavioDiagonal2(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha - 2 < 0 || coluna + 2 >= TAM) return 0; // Verifica se o navio cabe na diagonal inversa
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha - i][coluna + i] != 0) {
            return 0; // Verifica sobreposição
        }
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha - i][coluna + i] = 3; // Posiciona o navio
    }
    return 1;
}

int main() {
    int tabuleiro[TAM][TAM] = { 0 }; // Inicia o tabuleiro com 0

    // Posiciona navios
    posicionarNavioHorizontal(tabuleiro, 2, 1);
    posicionarNavioVertical(tabuleiro, 4, 5);
    posicionarNavioDiagonal1(tabuleiro, 7, 7);
    posicionarNavioDiagonal2(tabuleiro, 6, 2);

    // Tabuleiro após posicionar os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
