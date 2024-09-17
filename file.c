#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "checks.h"  // Includi il modulo difensivo

// Apertura di un file con controllo difensivo
FILE *open_file(char *name, char *mode) {
    FILE *file = fopen(name, mode);
    assert_file_opened(file, "Impossibile aprire il file.");  // Controllo difensivo
    return file;
}

Stack *read_file(FILE *file) {
    assert_file_opened(file, "File non valido per la lettura.");  // Controllo difensivo

    Stack *stack = create_stack();

    char string_read[MAX_RECORD_SIZE+1] = "\0";
    char string_temp[MAX_RECORD_SIZE+1] = "\0";

    for(int i = 1; !feof(file); i++) {

		fgets(string_read, MAX_STR_LEN, file);
		string_read[strcspn(string_read, "\n")] = '\0';

        strcpy(string_temp, string_read);

        int trattini = count_trattini(string_read);

        if(check_record(stack, string_temp, trattini)) {

            Node *node = create_node();
            node = string_to_data(string_read, trattini);
            set_index(node, i);
            push(stack, node);

        } else {
            printf("Formato record %d non valido\n\n", i);
        }
    }

    if(get_number(node) < MIN_N_RECORDS) {
        printf("Numero di record insufficienti, devono essere almeno %d.\nLa lettura e' stata annullata\n\n", MIN_N_RECORDS);
        destroy_if_defined(&stack);
    }

    return stack;
}

// Chiusura del file con controllo difensivo
void close_file(FILE *file) {
    assert_file_opened(file, "Impossibile chiudere un file non aperto.");  // Controllo difensivo
    fclose(file);
    file = NULL;
}

// Salva la pila su un file binario con controllo difensivo
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
    printf("Salvataggio su file completato.\n");
}

// Legge e stampa la pila dal file con controllo difensivo
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
