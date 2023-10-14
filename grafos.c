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

// Fun��o para mostrar a lista de seguidores
void mostrarListaSeguidores(RedeSocial* rede) {
    int i, j;
    for (i = 0; i < rede->numUsuarios; i++) {
        printf("%d -> ", i);
        bool seguidorEncontrado = false;
        for (j = 0; j < rede->numUsuarios; j++) {
            if (rede->matrizAdjacencia[i][j] == 1) {
                if (seguidorEncontrado) {
                    printf(" -> ");
                }
                printf("%d", j);
                seguidorEncontrado = true;
            }
        }
        printf("\n");
    }
}

// Fun��o para listar as conexoes de um usu�rio espec�fico no formato desejado
void listarConexoesUsuario(RedeSocial* rede, int usuario) {
    if (usuario >= 0 && usuario < rede->numUsuarios) {
        printf("%d -> ", usuario);
        bool conexaoEncontrada = false;
        for (int i = 0; i < rede->numUsuarios; i++) {
            if (rede->matrizAdjacencia[usuario][i] == 1) {
                if (conexaoEncontrada) {
                    printf(" -> ");
                }
                printf("%d", i);
                conexaoEncontrada = true;
            }
        }
        if (!conexaoEncontrada) {
            printf("Nenhuma conexao.");
        }
        printf("\n");
    } else {
        printf("Usuario invalido.\n");
    }
}

int main() {
    RedeSocial rede;
    inicializarRedeSocial(&rede);

    int opcao;
    int usuario1, usuario2;

    do {
    	printf("----------------------------------------\n");
        printf("\n\t ESCOLHA UMA OPCAO:\n\n");
        printf("----------------------------------------\n");
        printf("|1| Adicionar usuario\n");
        printf("----------------------------------------\n");
        printf("|2| Adicionar conexao entre usuarios\n");
        printf("----------------------------------------\n");
        printf("|3| Remover conexao entre usuarios\n");
        printf("----------------------------------------\n");
        printf("|4| Mostrar matriz de adjacencia\n");
        printf("----------------------------------------\n");
        printf("|5| Mostrar lista de seguidores\n");
        printf("----------------------------------------\n");
        printf("|6| Listar conexoes de um usuario\n");
        printf("----------------------------------------\n");
        printf("|7| Sair\n");
		printf("----------------------------------------\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarUsuario(&rede);
                printf("usuario adicionado.\n");
                break;
            case 2:
                printf("Digite o numero do primeiro usuario: ");
                scanf("%d", &usuario1);
                printf("Digite o numero do segundo usuario: ");
                scanf("%d", &usuario2);
                adicionarConexao(&rede, usuario1, usuario2);
                break;
            case 3:
                printf("Digite o numero do primeiro usuario: ");
                scanf("%d", &usuario1);
                printf("Digite o numero do segundo usuario: ");
                scanf("%d", &usuario2);
                removerConexao(&rede, usuario1, usuario2);
                break;
            case 4:
                mostrarMatrizAdjacencia(&rede);
                break;
            case 5:
                mostrarListaSeguidores(&rede);
                break;
            case 6:
                printf("Digite o numero do usuario para listar conexoes: ");
                scanf("%d", &usuario1);
                listarConexoesUsuario(&rede, usuario1);
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

