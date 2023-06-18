#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - represents the kinds of cards
 * @SPADE: spade kind
 * @HEART: heart kind
 * @CLUB: club kind
 * @DIAMOND: diamond kind
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - represents a playing card
 * @value: a pointer to a character that holds the value of the card
 *          (e.g., "Ace", "2", "3", ..., "10", "Jack", "Queen", "King")
 * @kind: the kind of the card (e.g., SPADE, HEART, CLUB, DIAMOND)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - represents a node of a doubly-linked list of cards
 * @card: a pointer to a card_t struct that contains the data of the node
 * @prev: a pointer to the previous node of the list
 * @next: a pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* function prototypes */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
