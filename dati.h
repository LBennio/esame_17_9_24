#ifndef DATI_H
#define DATI_H

#define MAX_STR_LEN 100  // Definisce la lunghezza massima della stringa

/**
 * @brief Struttura che rappresenta un nodo della pila.
 *
 * Ogni nodo contiene una stringa, un numero intero e un puntatore al nodo successivo nella pila.
 */
typedef struct Node {
    char string[MAX_STR_LEN]; /**< Stringa memorizzata nel nodo */
    int number;               /**< Numero associato al nodo */
    int indice;
    struct Node *next;        /*< Puntatore al nodo successivo */
} Node;

/**
 * @brief Struttura che rappresenta la pila.
 *
 * La pila contiene un puntatore al nodo in cima (top).
 */
typedef struct Stack {
    Node top; /*< Puntatore al nodo in cima alla pila */
} Stack;

/**
 * @brief Crea una nuova pila.
 *
 * Questa funzione alloca memoria per una pila e inizializza la cima della pila a NULL.
 *
 * @return Stack* Puntatore alla pila appena creata.
 */
Stack* create_stack(void);

/**
 * @brief Inserisce un elemento nella pila.
 *
 * Questa funzione crea un nuovo nodo con i valori specificati e lo inserisce in cima alla pila.
 *
 * @param stack Puntatore alla pila in cui inserire l'elemento.
 * @param string Stringa da associare al nodo.
 * @param number Numero da associare al nodo.
 */
void push(Stack *stack, char *string, int number);

/**
 * @brief Rimuove un elemento dalla pila.
 *
 * Questa funzione rimuove il nodo in cima alla pila e lo restituisce senza liberarne la memoria.
 *
 * @param stack Puntatore alla pila da cui rimuovere l'elemento.
 * @return Node* Puntatore al nodo rimosso.
 */
Node* pop(Stack *stack);

/**
 * @brief Stampa il contenuto della pila.
 *
 * Questa funzione stampa ogni nodo della pila, visualizzando la stringa e il numero associati.
 *
 * @param stack Puntatore alla pila da stampare.
 */
void print_stack(Stack *stack);

/**
 * @brief Libera la memoria della pila.
 *
 * Questa funzione rimuove tutti i nodi dalla pila e libera la memoria associata a ciascuno di essi.
 *
 * @param stack Puntatore alla pila da liberare.
 */
void free_stack(Stack *stack);

/**
 * @brief Restituisce la stringa associata a un nodo.
 *
 * Questa funzione restituisce la stringa memorizzata nel nodo specificato.
 *
 * @param node Puntatore al nodo da cui ottenere la stringa.
 * @return const char* La stringa associata al nodo.
 */
const char* get_string(Node *node);

/**
 * @brief Imposta la stringa di un nodo.
 *
 * Questa funzione imposta la stringa memorizzata nel nodo specificato.
 *
 * @param node Puntatore al nodo di cui modificare la stringa.
 * @param new_string La nuova stringa da associare al nodo.
 */
void set_string(Node *node, const char *new_string);

/**
 * @brief Restituisce il numero associato a un nodo.
 *
 * Questa funzione restituisce il numero memorizzato nel nodo specificato.
 *
 * @param node Puntatore al nodo da cui ottenere il numero.
 * @return int Il numero associato al nodo.
 */
int get_number(Node *node);

/**
 * @brief Imposta il numero di un nodo.
 *
 * Questa funzione imposta il numero memorizzato nel nodo specificato.
 *
 * @param node Puntatore al nodo di cui modificare il numero.
 * @param new_number Il nuovo numero da associare al nodo.
 */
void set_number(Node *node, int new_number);

/**
 * @brief Restituisce il nodo successivo nella pila.
 *
 * Questa funzione restituisce il puntatore al nodo successivo nella pila.
 *
 * @param node Puntatore al nodo di cui ottenere il nodo successivo.
 * @return Node* Puntatore al nodo successivo nella pila.
 */
Node* get_next(Node *node);

/**
 * @brief Imposta il nodo successivo di un nodo.
 *
 * Questa funzione imposta il puntatore al nodo successivo nella pila.
 *
 * @param node Puntatore al nodo di cui modificare il successivo.
 * @param next_node Puntatore al nuovo nodo successivo.
 */
void set_next(Node *node, Node *next_node);

#endif // DATI_H
