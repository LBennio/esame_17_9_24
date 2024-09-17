#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dati.h"

/**
 * @brief Mostra il menu principale del programma.
 *
 * Questa funzione gestisce l'interazione con l'utente mostrando un menu di opzioni
 * che permettono di lavorare con la pila (acquisizione, sostituzione, ordinamento, ecc.).
 */
void show_menu(void);

/**
 * @brief Conta i caratteri speciali in una stringa.
 *
 * Questa funzione esamina ogni carattere di una stringa e conta quanti caratteri
 * speciali (non alfanumerici e non spazi) contiene.
 *
 * @param str La stringa in cui contare i caratteri speciali.
 * @return Il numero di caratteri speciali trovati.
 */
int count_special_chars(const char *str);

/**
 * @brief Conta le consonanti in una stringa.
 *
 * Questa funzione esamina ogni carattere di una stringa e conta quante consonanti contiene.
 *
 * @param str La stringa in cui contare le consonanti.
 * @return Il numero di consonanti trovate.
 */
int count_consonants(const char *str);

/**
 * @brief Sostituisce una stringa nella pila.
 *
 * Cerca la prima occorrenza di una stringa all'interno della pila e la sostituisce con una nuova stringa.
 * La sostituzione viene eseguita solo se la nuova stringa non contiene e non è contenuta dalla vecchia stringa.
 *
 * @param stack Puntatore alla pila in cui eseguire la sostituzione.
 * @param old_string La stringa da sostituire.
 * @param new_string La nuova stringa che sostituisce la vecchia.
 */
void substitute_string(Stack *stack, char *old_string, char *new_string);

#endif // FUNCTIONS_H
