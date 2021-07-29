#include "lists.h"
listint_t *insert_node(listint_t **head, int number){
    listint_t *new;
    listint_t *tmp;
    
    if (!head)
        return NULL;

    tmp = *head;
    new = malloc(sizeof(listint_t));

    if (new == NULL)
        return NULL;
    new->n = number;
    
    if ((*head) == NULL || (*head)->n >= number){
        new->next = (*head);
        (*head) = new;
        return new;
    }

    while ((*head)){
        if (!(*head)->next || (*head)->next->n >= number){
            new->next = (*head)->next;
            (*head)->next = new;
            (*head) = tmp;
            return new;
        }
        (*head) = (*head)->next;
    }

    return NULL;
}