#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char item_name[50];
    int quantity;
} Item;

typedef struct DialogueNode {
    char npc_line[200];
    char player_options[MAX_ITEMS][200];
    struct DialogueNode* next_steps[MAX_ITEMS];
    int num_options;
    char requirement[MAX_ITEMS][200];
    struct DialogueNode* parent;
} DialogueNode;

typedef struct {
    Item items[MAX_ITEMS];
    int item_count;
} Inventory;

DialogueNode* init_node(const char* npc_line) {
    DialogueNode* node = (DialogueNode*)malloc(sizeof(DialogueNode));
    if (!node) {
        fprintf(stderr, "Грешка при заделяне на памет за DialogueNode!\n");
        exit(1);
    }

    strcpy(node->npc_line, npc_line);

    node->num_options = 0;
    node->parent = NULL;

    for (int i = 0; i < MAX_ITEMS; i++) {
        node->next_steps[i] = NULL;
        node->player_options[i][0] = '\0';
        node->requirement[i][0] = '\0';
    }

    return node;
}

void add_player_option(DialogueNode* node,
                       const char* option,
                       DialogueNode* next_node,
                       const char* required_item) 
{
    if (node->num_options < MAX_ITEMS) {
        strcpy(node->player_options[node->num_options], option);
        strcpy(node->requirement[node->num_options], required_item);
        node->next_steps[node->num_options] = next_node;
        node->num_options++;
    } else {
        printf("Предупреждение: достигнат е лимитът за опции в този възел!\n");
    }
}

void add_item_to_inventory(Inventory* inv, const char* item_name, int quantity) {
    for (int i = 0; i < inv->item_count; i++) {
        if (strcmp(inv->items[i].item_name, item_name) == 0) {
            inv->items[i].quantity += quantity;
            return;
        }
    }

    if (inv->item_count < MAX_ITEMS) {
        strcpy(inv->items[inv->item_count].item_name, item_name);
        inv->items[inv->item_count].quantity = quantity;
        inv->item_count++;
    } else {
        printf("Предупреждение: Няма място за още предмети в инвентара!\n");
    }
}

int check_inventory(Inventory* inv, const char* item_name, int quantity) {
    for (int i = 0; i < inv->item_count; i++) {
        if (strcmp(inv->items[i].item_name, item_name) == 0 &&
            inv->items[i].quantity >= quantity) 
        {
            return 1;
        }
    }
    return 0;
}

void play_dialogue(DialogueNode* root, Inventory* inv) {
    DialogueNode* current = root;

    while (current != NULL) {
        printf("\nNPC: %s\n", current->npc_line);
        if (current->num_options == 0) {
            if (current->next_steps[0] != NULL) {
                current = current->next_steps[0];
            } else {
                printf("[Разговорът приключи — NPC каза последното слово.]\n");
                return;
            }
            continue;
        }

        for (int i = 0; i < current->num_options; i++) {
            if (strlen(current->requirement[i]) > 0) {
                if (check_inventory(inv, current->requirement[i], 1)) {
                    printf("%d) %s\n", i + 1, current->player_options[i]);
                } else {
                    printf("%d) %s (Нужно: %s)\n",
                           i + 1,
                           current->player_options[i],
                           current->requirement[i]);
                }
            } else {
                printf("%d) %s\n", i + 1, current->player_options[i]);
            }
        }

        printf("Избери опция [1-%d]: ", current->num_options);
        int choice;
        if (scanf("%d", &choice) == 1) {
            if (choice < 1 || choice > current->num_options) {
                printf("Невалиден избор! Опитайте отново.\n");
                while(getchar() != '\n');
                continue;
            }

            int index = choice - 1;
            if (strlen(current->requirement[index]) > 0) {
                if (!check_inventory(inv, current->requirement[index], 1)) {
                    printf("Нямате нужното количество от '%s'!\n",
                           current->requirement[index]);
                    while(getchar() != '\n');
                    continue;
                }
            }

            printf("[Играч]: %s\n", current->player_options[index]);
            current = current->next_steps[index];
        } else {
            printf("Грешен вход! Опитайте отново.\n");
            while(getchar() != '\n');
            continue;
        }
    }

    printf("[Разговорът приключи — последната дума беше на играча.]\n");
}

int main() {
    Inventory inv;
    inv.item_count = 0;

    add_item_to_inventory(&inv, "coins", 10);
    add_item_to_inventory(&inv, "book", 1);

    DialogueNode* node1 = init_node("Welcome to Fantasytown! How can I help you?");
    DialogueNode* node2 = init_node("I have some armors. Which one do you want?");
    DialogueNode* node3 = init_node("Here is your Light armor. Anything else?");
    DialogueNode* node4 = init_node("Here is your Heavy armor. Good luck!");
    DialogueNode* node5 = init_node("You don't have enough coins. Sorry!");
    DialogueNode* node6 = init_node("Thanks for visiting Fantasytown. Have a great day!");
    DialogueNode* node7 = init_node("Oh, you want to leave? Safe travels!");
    
    add_player_option(
        node1,
        "I want to buy armor.",
        node2,
        ""
    );
    add_player_option(
        node1,
        "Actually, I'd like to leave town.",
        node7,
        ""
    );
    add_player_option(
        node1,
        "Nothing, just passing by... (end)",
        node6,
        "" 
    );

    add_player_option(
        node2,
        "I'd like to buy a cheap Light armor.",
        node3,
        "coins"
    );
    add_player_option(
        node2,
        "I'd like to buy an expensive Heavy armor.",
        node4,
        "coins"
    );

    add_player_option(
        node2,
        "On second thought, never mind.",
        node6,
        ""
    );

    add_player_option(
        node3,
        "Can I see other options too?",
        node2,
        ""
    );
    add_player_option(
        node3,
        "Thank you, bye!",
        node6,
        ""
    );

    add_player_option(
        node4,
        "Thanks! I'll be going now.",
        node6,
        ""
    );
    add_player_option(
        node4,
        "Hmm, let me see the other armor again.",
        node2,
        ""
    );

    add_player_option(
        node5,
        "Ok, I'll come back later.",
        node6,
        ""
    );

    add_player_option(
        node7,
        "Yes, farewell!",
        node6,
        ""
    );

    play_dialogue(node1, &inv);

    return 0;
}