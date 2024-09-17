#ifndef checks.h
#define checks.h

#include <stdio.h>
#include "dati.h"  // Include la definizione di Stack

#define RECORD_SEPARATOR "-"

/**
 * @brief Verifica che un puntatore non sia NULL.
 *
 * Questa funzione controlla che il puntatore passato non sia NULL.
 * Se il puntatore è NULL, viene stampato un messaggio di errore e il programma termina.
 *
 * @param ptr Il puntatore da verificare.
 * @param message Messaggio di errore da stampare se il puntatore è NULL.
 */
void assert_non_null(void *ptr, const char *message);

/**
 * @brief Verifica che la pila non sia vuota.
 *
 * Controlla che la pila esista e che non sia vuota.
 * Se la pila è vuota, il programma stampa un messaggio di errore e termina.
 *
 * @param stack La pila da verificare.
 */
void assert_stack_not_empty(Stack *stack);

/**
 * @brief Verifica che il file sia stato aperto correttamente.
 *
 * Controlla che il file passato sia stato aperto correttamente.
 * Se il file non è stato aperto, viene stampato un messaggio di errore e il programma termina.
 *
 * @param file Puntatore al file da verificare.
 * @param message Messaggio di errore in caso di file non valido.
 */
void assert_file_opened(FILE *file, const char *message);

/**
 * @brief Verifica che la pila non sia NULL.
 *
 * Controlla che la pila esista (non NULL).
 * Se la pila non esiste, il programma stampa un messaggio di errore e termina.
 *
 * @param stack Puntatore alla pila da verificare.
 * @param message Messaggio di errore in caso di pila non valida.
 */
void assert_stack_valid(Stack *stack, const char *message);

#endif // checks.h
