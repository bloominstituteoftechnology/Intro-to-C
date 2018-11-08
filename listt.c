//from BEEJ

#include <stdio.h>
#include <stdlib.h>

/**
 * Linked list structure
 */
struct llist {
	int value;
	struct llist *next;
};

/**
 * Free a linked list
 */
void llist_free(struct llist *head)
{
	// Loop through whole list, freeing each element
	while (head != NULL) {

		// We need to save the next pointer, because we're not allowed
		// to use it after the free
		struct llist *next = head->next;

		free(head);

		head = next;
	}
}

/**
 * Insert onto the head of a linked list
 *
 * Question: Why do we have to pass a `struct llist **` for head and not just
 * a `struct llist *`?
 */
void llist_insert(struct llist **head, int value)
{
	// Allocate space for new node
	struct llist *newnode = malloc(sizeof(struct llist));

	// Keep track of the old head, because it's the next pointer for
	// the new one
	struct llist *old_head = *head;

	// Set the head to be at the new node
	*head = newnode;
	(*head)->value = value;
	(*head)->next = old_head;
}

/**
 * For each
 */
void llist_foreach(struct llist *head, void (*f)(int))
{
	// Call function f (passed in as a parameter, above) for every
	// element in the list
	while (head != NULL) {
		f(head->value);
		head = head->next;
	}
}

/**
 * For each test function
 */
void printeach(int value)
{
	printf("This linked list node contains: %d\n", value);
}

/**
 * Main
 */
int main(void)
{
	struct llist *head = NULL;

	llist_insert(&head, 10);
	llist_insert(&head, 20);
	llist_insert(&head, 30);
	llist_insert(&head, 40);

	llist_foreach(head, printeach); // 40 30 20 10

	return 0;
}