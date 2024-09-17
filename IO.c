#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"
#include "checks.h"  // Includi il modulo difensivo

/**
 * @brief Legge i dati da un file e li inserisce nella pila.
 *
 * Questa funzione apre un file di testo, legge ogni riga, estrae una stringa
 * e un numero separati da un carattere #, e li inserisce nella pila.
 *
 * @param stack Puntatore alla pila in cui inserire i dati.
 * @param filename Nome del file da cui leggere i dati.
 */
Node *read_file_to_stack(Stack *stack, const char *filename) {
    assert_stack_valid(stack, "Pila non valida per la lettura dal file.");  // Controllo difensivo

    FILE *file = fopen(filename, "r");
    assert_file_opened(file, "Errore nell'aprire il file per la lettura.");  // Controllo difensivo

    char line[256];
    while (fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = '\0';  // Rimuove il newline

        char *token = strtok(line, "#");

        if (token != NULL) {
            char string[MAX_STR_LEN];
            strcpy(string, token);
            token = strtok(NULL, "#");
            if (token != NULL) {
                int number = atoi(token);
                push(stack, string, number);
            }
        }
    }
    fclose(file);
}

/**
 * @brief Stampa il contenuto della pila sulla console.
 *
 * Questa funzione stampa tutti gli elementi della pila sulla console.
 *
 * @param stack Puntatore alla pila da stampare.
 */
void print_stack_to_console(Stack *stack) {
    assert_stack_valid(stack, "Pila non valida per la stampa.");  // Controllo difensivo
    print_stack(stack);
}

/**
 * @brief Salva il contenuto della pila in un file.
 *
 * La funzione scrive il contenuto della pila su un file binario.
 *
 * @param stack Puntatore alla pila da salvare.
 * @param filename Nome del file in cui salvare i dati.
 */
void save_stack_to_file(Stack *stack, const char *filename) {
    assert_stack_valid(stack, "Pila non valida per il salvataggio.");  // Controllo difensivo

    FILE *file = fopen(filename, "wb");
    assert_file_opened(file, "Errore nell'aprire il file per la scrittura.");  // Controllo difensivo

    Node *current = stack->top;
    while (current != NULL) {
        fwrite(current, sizeof(Node), 1, file);
        current = current->next;
    }

    fclose(file);
}

/**
 * @brief Legge una pila da un file binario e ne stampa il contenuto.
 *
 * La funzione legge i dati di una pila salvata in un file binario
 * e ne stampa gli elementi (stringa e numero) sulla console.
 *
 * @param filename Nome del file da cui leggere i dati della pila.
 */
void read_stack_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    assert_file_opened(file, "Errore nell'aprire il file per la lettura.");  // Controllo difensivo

    Node temp;
    printf("\n--- Contenuto del file %s ---\n", filename);
    while (fread(&temp, sizeof(Node), 1, file) == 1) {
        printf("%s - %d\n", temp.string, temp.number);
    }

    fclose(file);
}
