#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Caminhos completos das pastas de entrada e saída
const char INPUT_DIR[] = "C:/Users/enzol/CLionProjects/root/warmup/04-digitos-diferentes/input/";
const char OUTPUT_DIR[] = "C:/Users/enzol/CLionProjects/root/warmup/04-digitos-diferentes/output/";

// Função para verificar se um número tem dígitos repetidos
int has_repeated_digits(int number) {
    int digits[10] = {0}; // Array para contar a ocorrência de cada dígito (0-9)
    while (number > 0) {
        int digit = number % 10;
        if (digits[digit] == 1) {
            return 1; // Dígito repetido encontrado
        }
        digits[digit] = 1;
        number /= 10;
    }
    return 0; // Nenhum dígito repetido
}

void process_file(const char* input_file) {
    FILE *fin, *fout;
    char output_file[256];
    int N, M;

    // Abrindo o arquivo de entrada
    fin = fopen(input_file, "r");
    if (fin == NULL) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", input_file);
        return;
    }

    // Lendo os valores de N e M do arquivo de entrada
    fscanf(fin, "%d %d", &N, &M);
    fclose(fin);

    // Construindo o caminho do arquivo de saída correspondente
    snprintf(output_file, sizeof(output_file), "%s%s", OUTPUT_DIR, strrchr(input_file, '/') + 1);

    // Abrindo o arquivo de saída para comparar o resultado
    fout = fopen(output_file, "r");
    if (fout == NULL) {
        printf("Erro ao abrir o arquivo de saída: %s\n", output_file);
        return;
    }

    // Contando os números sem dígitos repetidos
    int count = 0;
    for (int i = N; i <= M; i++) {
        if (!has_repeated_digits(i)) {
            count++;
        }
    }

    // Lendo o resultado esperado do arquivo de saída
    int expected_count;
    fscanf(fout, "%d", &expected_count);
    fclose(fout);

    // Comparando o resultado obtido com o esperado
    if (count == expected_count) {
        printf("Teste %s: OK\n", input_file);
    } else {
        printf("Teste %s: Falhou (Esperado: %d, Obtido: %d)\n", input_file, expected_count, count);
    }
}

int main() {
    DIR *dir;
    struct dirent *entry;

    // Abrindo a pasta de entrada
    dir = opendir(INPUT_DIR);
    if (dir == NULL) {
        printf("Erro ao abrir a pasta de entrada: %s\n", INPUT_DIR);
        return 1;
    }

    // Processando cada arquivo na pasta de entrada
    while ((entry = readdir(dir)) != NULL) {
        // Ignorando diretórios "." e ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construindo o caminho completo do arquivo de entrada
        char input_file[256];
        snprintf(input_file, sizeof(input_file), "%s%s", INPUT_DIR, entry->d_name);

        // Processando o arquivo
        process_file(input_file);
    }

    closedir(dir);
    return 0;
}