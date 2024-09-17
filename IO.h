#ifndef IO_H
#define IO_H

#include "dati.h"

/**
 * @brief Legge i dati da un file e li inserisce nella pila.
 *
 * La funzione apre un file di testo, legge ogni riga, estrae una stringa
 * e un numero separati da un carattere #, e li inserisce nella pila.
 *
 * @param stack Puntatore alla pila in cui inserire i dati.
 * @param filename Nome del file da cui leggere i dati.
 */
void read_file_to_stack(Stack *stack, const char *filename);

/**
 * @brief Stampa il contenuto della pila sulla console.
 *
 * Questa funzione stampa tutti gli elementi della pila sulla console.
 *
 * @param stack Puntatore alla pila da stampare.
 */
void print_stack_to_console(Stack *stack);

/**
 * @brief Salva il contenuto della pila in un file.
 *
 * La funzione scrive il contenuto della pila su un file binario.
 *
 * @param stack Puntatore alla pila da salvare.
 * @param filename Nome del file in cui salvare i dati.
 */
void save_stack_to_file(Stack *stack, const char *filename);

/**
 * @brief Legge una pila da un file binario e ne stampa il contenuto.
 *
 * La funzione legge i dati di una pila salvata in un file binario
 * e ne stampa gli elementi (stringa e numero) sulla console.
 *
 * @param filename Nome del file da cui leggere i dati della pila.
 */
void read_stack_from_file(const char *filename);

#endif // IO_H
