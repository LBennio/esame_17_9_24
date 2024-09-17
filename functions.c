#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "checks.h"  // Includi il modulo difensivo

void show_menu() {
    Stack *stack = NULL;
    int choice = 0;

    printf("---- studenti ----\n");

    char *options[] = {"Acquisisci", "Sostituisci", "Ordina", "Esci"};
    int n_opt = sizeof(options)/sizeof(char*);

    do {
        for (int i = 0; i < n_opt; i++) {
            printf("<%d> %s\n", i + 1, options[i]);
        }

        printf("> ");
        choice = get_input_int();

        switch (choice) {
            case 1:
                stack = acquisition();
                assert_non_null(stack, "Errore nella creazione della pila.");  // Controllo difensivo

                print_stack_to_console(stack);
                break;
            case 2:

                break;
            case 3: {
                char old_string[MAX_STR_LEN], new_string[MAX_STR_LEN];
                printf("Inserisci la stringa da sostituire: ");
                scanf("%s", old_string);
                printf("Inserisci la nuova stringa: ");
                scanf("%s", new_string);
                assert_stack_valid(stack, "Pila non valida per la sostituzione.");  // Controllo difensivo
                substitute_string(stack, old_string, new_string);
                break;
            }
            case 5:
                assert_stack_valid(stack, "Pila non valida per il salvataggio.");  // Controllo difensivo
                save_stack_to_file(stack, "Sostituisci.dat");
                break;
            case 6:
                read_stack_from_file("Sostituisci.dat");
                break;
            case 7: {
                int ascending;
                printf("Vuoi ordinare in modo crescente (1) o decrescente (0)? ");
                scanf("%d", &ascending);

                assert_stack_valid(stack, "Pila non valida per l'ordinamento.");  // Controllo difensivo

                if (ascending) {
                    sort_stack(stack, compare_nodes_ascending, 1);
                } else {
                    sort_stack(stack, compare_nodes_descending, 0);
                }
                save_stack_to_file(stack, "Ordina.dat");
                break;
            }
            case 8:
                break;
            default:
                printf("Opzione non valida!\n");
        }
    } while (choice != n_opt);

    free_stack(stack);
}

Stack *acquisition() {
    FILE* file = NULL;
    Stack *stack = NULL;

    char nome[MAX_STR_LEN];
	char format[10];

	sprintf(format, "\%%%ds", MAX_STR_LEN);

	do {
        int c;

        while ((c = getchar()) != '\n' && c != EOF);

        printf("File(.txt): ");
        fscanf(stdin, format, nome);
        nome[strcspn(nome, "\n")] = '\0';

        if(check_txt_extension(nome)) {
            printf("Nome del file non valido\n");
        }
    } while(check_txt_extension(nome));

    if ( ( file = open_file(nome,"r") ) ) {
        stack = read_file(file);
        close_file(file);
    }

    return stack;
}

// Conta i caratteri speciali in una stringa
int count_special_chars(const char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}









// Conta le consonanti in una stringa
int count_consonants(const char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            char lower = tolower(*str);
            if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
                count++;
            }
        }
        str++;
    }
    return count;
}

// Sostituisce una stringa nella pila
void substitute_string(Stack *stack, char *old_string, char *new_string) {
    assert_stack_valid(stack, "Pila non valida per la sostituzione.");  // Controllo difensivo
    Node *current = stack->top;
    while (current != NULL) {
        if (strcmp(get_string(current), old_string) == 0) {
            if (strstr(new_string, old_string) == NULL && strstr(old_string, new_string) == NULL) {
                set_string(current, new_string);
                printf("Sostituzione riuscita!\n");
            } else {
                printf("La nuova stringa è contenuta o contiene la vecchia stringa. Operazione non consentita.\n");
            }
            return;
        }
        current = get_next(current);
    }
    printf("Stringa da sostituire non trovata nella pila.\n");
}
