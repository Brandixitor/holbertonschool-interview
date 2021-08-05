#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;
void binary_tree_print(const binary_tree_t *tree);


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

heap_t *heap_heapify(heap_t *current);
heap_t **heap_heapify2(heap_t **root, heap_t *current);
bool heap_swap(heap_t **root, heap_t *new, heap_t *tmp);
int *convert_to_binary(int num);
int heap_size(heap_t *head, int size);

heap_t *heap_insert(heap_t **root, int value);

#endif /* _BINARY_TREES_H_ */