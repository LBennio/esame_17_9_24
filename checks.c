#include <stdio.h>
#include <stdlib.h>
#include "checks.h"

/**
 * @brief Verifica che un puntatore non sia NULL.
 *
 * Questa funzione controlla che il puntatore passato non sia NULL.
 * Se il puntatore è NULL, viene stampato un messaggio di errore e il programma termina.
 *
 * @param ptr Il puntatore da verificare.
 * @param message Messaggio di errore da stampare se il puntatore è NULL.
 */
void assert_non_null(void *ptr, const char *message) {
    if (ptr == NULL) {
        fprintf(stderr, "Errore: %s\n", message);
        exit(EXIT_FAILURE);  // Termina il programma se il puntatore è NULL
    }
}

/**
 * @brief Verifica che la pila non sia vuota.
 *
 * Controlla che la pila esista e che non sia vuota.
 * Se la pila è vuota, il programma stampa un messaggio di errore e termina.
 *
 * @param stack La pila da verificare.
 */
void assert_stack_not_empty(Stack *stack) {
    if (stack == NULL || stack->top == NULL) {
        fprintf(stderr, "Errore: La pila è vuota!\n");
        exit(EXIT_FAILURE);  // Termina il programma se la pila è vuota
    }
}

/**
 * @brief Verifica che il file sia stato aperto correttamente.
 *
 * Controlla che il file passato sia stato aperto correttamente.
 * Se il file non è stato aperto, viene stampato un messaggio di errore e il programma termina.
 *
 * @param file Puntatore al file da verificare.
 * @param message Messaggio di errore in caso di file non valido.
 */
void assert_file_opened(FILE *file, const char *message) {
    if (file == NULL) {
        fprintf(stderr, "Errore: %s\n", message);
        exit(EXIT_FAILURE);  // Termina il programma se il file non è stato aperto correttamente
    }
}

bool check_record(char *string, int i) {
    int n = strstr(string, "#");

    if(!n) {
        return false;
    }

    isNum(string[n+1]);
    return true;
}

/**
 * @brief Verifica che la pila non sia NULL.
 *
 * Controlla che la pila esista (non NULL).
 * Se la pila non esiste, il programma stampa un messaggio di errore e termina.
 *
 * @param stack Puntatore alla pila da verificare.
 * @param message Messaggio di errore in caso di pila non valida.
 */
void assert_stack_valid(Stack *stack, const char *message) {
    if (stack == NULL) {
        fprintf(stderr, "Errore: %s\n", message);
        exit(EXIT_FAILURE);  // Termina il programma se la pila non è valida
    }
}
