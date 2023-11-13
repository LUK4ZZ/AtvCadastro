#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000

struct Usuario {
    int id;
    char nome[100];
    char email[100];
    char sexo[15];
    char endereco[200];
    double altura;
    int vacina;
};

int gerarId() {
    return rand() % 10000 + 1;
}

int validarEmail(const char *email) {
    return strchr(email, '@') != NULL;
}

int validarSexo(const char *sexo) {
    return strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0;
}

int adicionarUsuario(struct Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios < MAX_USERS) {
        struct Usuario novoUsuario;
        novoUsuario.id = gerarId();

        printf("Digite o nome completo: ");
        scanf(" %[^\n]s", novoUsuario.nome);

        printf("Digite o email: ");
        scanf(" %s", novoUsuario.email);

        // Validando o campo de email
        while (!validarEmail(novoUsuario.email)) {
            printf("Email inválido. Certifique-se de incluir '@' no endereço de email.\n");
            printf("Digite o email novamente: ");
            scanf(" %s", novoUsuario.email);
        }

        printf("Digite o sexo (Feminino, Masculino ou Indiferente): ");
        scanf(" %s", novoUsuario.sexo);

        // Validando o campo de sexo
        while (!validarSexo(novoUsuario.sexo)) {
            printf("Sexo inválido. Escolha entre Feminino, Masculino ou Indiferente.\n");
            printf("Digite o sexo novamente: ");
            scanf(" %s", novoUsuario.sexo);
        }

        printf("Digite o endereço: ");
        scanf(" %[^\n]s", novoUsuario.endereco);

        printf("Digite a altura (entre 1 e 2 metros): ");
        scanf("%lf", &novoUsuario.altura);

        // Validando o campo de altura
        while (novoUsuario.altura < 1.0 || novoUsuario.altura > 2.0) {
            printf("Altura inválida. Digite um valor entre 1 e 2 metros.\n");
            printf("Digite a altura novamente: ");
            scanf("%lf", &novoUsuario.altura);
        }

        printf("O usuário foi vacinado? (1 para Sim, 0 para Não): ");
        scanf("%d", &novoUsuario.vacina);

        usuarios[*numUsuarios] = novoUsuario;
        (*numUsuarios)++;

        printf("Usuário adicionado com sucesso!\n");
        return 1; // Indica sucesso na adição
    } else {
        printf("Limite máximo de usuários atingido.\n");
        return 0; // Indica falha na adição
    }
}

void editarUsuario(struct Usuario usuarios[], int numUsuarios) {
    int idEditar;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &idEditar);

    int encontrado = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == idEditar) {
            printf("Digite o novo nome completo: ");
            scanf(" %[^\n]s", usuarios[i].nome);

            printf("Digite o novo email: ");
            scanf(" %s", usuarios[i].email);

            // Validando o campo de email
            while (!validarEmail(usuarios[i].email)) {
                printf("Email inválido. Certifique-se de incluir '@' no endereço de email.\n");
                printf("Digite o email novamente: ");
                scanf(" %s", usuarios[i].email);
            }

            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
            scanf(" %s", usuarios[i].sexo);

            // Validando o campo de sexo
            while (!validarSexo(usuarios[i].sexo)) {
                printf("Sexo inválido. Escolha entre Feminino, Masculino ou Indiferente.\n");
                printf("Digite o sexo novamente: ");
                scanf(" %s", usuarios[i].sexo);
            }

            printf("Digite o novo endereço: ");
            scanf(" %[^\n]s", usuarios[i].endereco);

            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuarios[i].altura);

            // Validando o campo de altura
            while (usuarios[i].altura < 1.0 || usuarios[i].altura > 2.0) {
                printf("Altura inválida. Digite um valor entre 1 e 2 metros.\n");
                printf("Digite a altura novamente: ");
                scanf("%lf", &usuarios[i].altura);
            }

            printf("O usuário foi vacinado? (1 para Sim, 0 para Não): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuário editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}

void excluirUsuario(struct Usuario usuarios[], int *numUsuarios) {
    int idExcluir;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idExcluir);

    int encontrado = 0;
    for (int i = 0; i < *numUsuarios; i++) {
        if (usuarios[i].id == idExcluir) {
            for (int j = i; j < *numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            (*numUsuarios)--;
            printf("Usuário excluído com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}

void buscarUsuarioPorEmail(struct Usuario usuarios[], int numUsuarios) {
    char emailBusca[100];
    printf("Digite o email do usuário que deseja buscar: ");
    scanf(" %s", emailBusca);

    int encontrado = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailBusca) == 0) {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Não");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}

void imprimirUsuarios(struct Usuario usuarios[], int numUsuarios) {
    if (numUsuarios > 0) {
        printf("Lista de Usuários:\n");
        for (int i = 0; i < numUsuarios; i++) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Não");
            printf("--------------\n");
        }
    } else {
        printf("Nenhum usuário cadastrado.\n");
    }
}

int main() {
    struct Usuario usuarios[MAX_USERS];
    int numUsuarios = 0;
    char opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Adicionar Usuário\n");
        printf("2 - Editar Usuário\n");
        printf("3 - Excluir Usuário\n");
        printf("4 - Buscar Usuário por Email\n");
        printf("5 - Imprimir Todos os Usuários\n");
        printf("0 - Sair\n");

        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarUsuario(usuarios, &numUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, numUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &numUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, numUsuarios);
                break;
            case '5':
                imprimirUsuarios(usuarios, numUsuarios);
                break;
            case '0':
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != '0');

    return 0;
}
