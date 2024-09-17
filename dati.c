#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dati.h"
#include "checks.h"  // Includi il modulo difensivo

// Creazione della pila
Stack* create_stack() {
    Stack stack = (Stack)malloc(sizeof(Stack));
    assert_non_null(stack, "Errore nell'allocazione della pila.");  // Controllo difensivo
    stack->top = NULL;
    return stack;
}

Node *create_node() {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(!newNode) {
        fprintf(stderr, "impossibile allocare memoria al nodo\n");
        exit(EXIT_FAILURE);
    }

    newNode->number = 0;
    strcpy(newNode->string, "");

    newNode->next = NULL;

    return newNode;
}

// Inserisce un elemento nella pila
void push(Stack *stack, Node *node) {

    assert_stack_valid(stack, "Pila non valida per l'inserimento.");

    Node *new_node = create_node();

    assert_non_null(new_node, "Errore nell'allocazione di un nuovo nodo.");  // Controllo difensivo

    set_string(new_node, node->string);
    set_number(new_node, node->number);

    set_next(new_node, stack->top);

    stack->top = new_node;
}





// Rimuove e restituisce un nodo dalla pila, non lo libera
Node* pop(Stack *stack) {
    assert_stack_not_empty(stack);  // Controllo difensivo: verifica che la pila non sia vuota
    Node *removed_node = stack->top;
    stack->top = get_next(stack->top);  // Usa il getter
    return removed_node;
}

// Stampa tutti gli elementi della pila
void print_stack(Stack *stack) {
    assert_stack_not_empty(stack);  // Controllo difensivo: verifica che la pila non sia vuota
    Node *current = stack->top;
    while (current != NULL) {
        printf("%s - %d\n", get_string(current), get_number(current));  // Usa i getter
        current = get_next(current);  // Usa il getter
    }
}




// Libera la memoria associata alla pila
void free_stack(Stack *stack) {
    assert_stack_valid(stack, "Pila non valida per la liberazione.");  // Controllo difensivo
    Node *node;
    while ((node = pop(stack)) != NULL) {
        free(node);
    }
    free(stack);
}

// Getter per la stringa
const char* get_string(Node *node) {
    assert_non_null(node, "Nodo non valido.");  // Controllo difensivo
    return node->string;
}

// Setter per la stringa
void set_string(Node *node, const char *new_string) {
    assert_non_null(node, "Nodo non valido.");  // Controllo difensivo
    assert_non_null(new_string, "Stringa non valida.");  // Controllo difensivo

    strcpy(node->string, new_string);
}

// Getter per il numero
int get_number(Node *node) {
    assert_non_null(node, "Nodo non valido.");  // Controllo difensivo
    return node->number;
}

// Setter per il numero
void set_number(Node *node, int new_number) {
    assert_non_null(node, "Nodo non valido.");  // Controllo difensivo
    node->number = new_number;
}

// Getter per il nodo successivo
Node* get_next(Node *node) {
    assert_non_null(node, "Nodo non valido.");  // Controllo difensivo
    return node->next;
}

// Setter per il nodo successivo
void set_next(Node *node, Node *next_node) {
    assert_non_null(node, "Nodo non valido.");  // Controllo difensivo
    node->next = next_node;
}

void set_index(Node *node, int idx) {
    node->indice = inx;
}

int get_index(Node *node) {
    return node->indice;
}

int count_trattini(char *string) {
    int i = 0;
    for(int i= 1; i <= strlen(string), i++) {
        if(string[i] == '-') {
            i++;
        }
    }

    return i;
}
