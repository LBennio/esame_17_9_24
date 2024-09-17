#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "dati.h"

/**
 * @brief Apre un file con il controllo difensivo.
 *
 * Questa funzione apre un file con il nome e la modalità specificati. Se l'apertura del file fallisce,
 * stampa un messaggio di errore e termina il programma.
 *
 * @param name Nome del file da aprire.
 * @param mode Modalità di apertura del file (es. "r" per lettura, "w" per scrittura).
 * @return FILE* Puntatore al file aperto.
 */
FILE *open_file(char *name, char *mode);

/**
 * @brief Legge la pila da un file.
 *
 * Questa funzione legge i dati di una pila da un file e li restituisce sotto forma di pila.
 * Se la lettura del file fallisce, stampa un messaggio di errore e termina il programma.
 *
 * @param file Puntatore al file da cui leggere la pila.
 * @return Stack* Puntatore alla pila letta dal file.
 */
Stack *read_file(FILE *file);

/**
 * @brief Chiude un file con il controllo difensivo.
 *
 * Questa funzione chiude un file aperto. Se il file non è valido o la chiusura fallisce,
 * stampa un messaggio di errore e termina il programma.
 *
 * @param file Puntatore al file da chiudere.
 */
void close_file(FILE *file);

/**
 * @brief Salva la pila su un file binario.
 *
 * Questa funzione salva tutti gli elementi della pila in un file binario. Se l'apertura
 * o la scrittura nel file falliscono, stampa un messaggio di errore e termina il programma.
 *
 * @param stack Puntatore alla pila da salvare.
 * @param filename Nome del file in cui salvare la pila.
 */
void save_stack_to_file(Stack *stack, const char *filename);

/**
 * @brief Legge e stampa la pila da un file binario.
 *
 * Questa funzione legge gli elementi della pila da un file binario e li stampa sulla console.
 * Se l'apertura o la lettura del file falliscono, stampa un messaggio di errore e termina il programma.
 *
 * @param filename Nome del file da cui leggere la pila.
 */
void read_stack_from_file(const char *filename);

#endif // FILE_H
