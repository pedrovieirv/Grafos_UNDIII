#include <stdio.h>
#include <stdbool.h>

#define MAX_USUARIOS 20

// Estrutura para representar a rede social
typedef struct {
    int matrizAdjacencia[MAX_USUARIOS][MAX_USUARIOS];
    int numUsuarios;
} RedeSocial;

// Fun��o para inicializar a rede social
void inicializarRedeSocial(RedeSocial* rede) {
    int i, j;
    rede->numUsuarios = 0;
    for (i = 0; i < MAX_USUARIOS; i++) {
        for (j = 0; j < MAX_USUARIOS; j++) {
            rede->matrizAdjacencia[i][j] = 0;
        }
    }
}

// Fun��o para adicionar um usu�rio � rede social
void adicionarUsuario(RedeSocial* rede) {
    if (rede->numUsuarios < MAX_USUARIOS) {
        rede->numUsuarios++;
    }
}

// Fun��o para adicionar uma conexao entre dois usuarios
void adicionarConexao(RedeSocial* rede, int usuario1, int usuario2) {
    if (usuario1 >= 0 && usuario1 < rede->numUsuarios &&
        usuario2 >= 0 && usuario2 < rede->numUsuarios) {
        rede->matrizAdjacencia[usuario1][usuario2] = 1;
        rede->matrizAdjacencia[usuario2][usuario1] = 1;
    }
}

// Fun��o para remover uma conexao entre dois usuarios
void removerConexao(RedeSocial* rede, int usuario1, int usuario2) {
    if (usuario1 >= 0 && usuario1 < rede->numUsuarios &&
        usuario2 >= 0 && usuario2 < rede->numUsuarios) {
        rede->matrizAdjacencia[usuario1][usuario2] = 0;
        rede->matrizAdjacencia[usuario2][usuario1] = 0;
    }
}

// Fun��o para mostrar a matriz de adjac�ncia
void mostrarMatrizAdjacencia(RedeSocial* rede) {
    int i, j;
    for (i = 0; i < rede->numUsuarios; i++) {
        for (j = 0; j < rede->numUsuarios; j++) {
            printf("%d ", rede->matrizAdjacencia[i][j]);
        }
        printf("\n");
    }
}