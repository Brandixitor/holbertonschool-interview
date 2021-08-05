#include "binary_trees.h"

/**
 * heap_heapify - heapify the tree until the node proper max heap
 * @current: Last node found with the binary algorithm
 * Returns: A pointer to the new current node 
**/
heap_t *heap_heapify(heap_t *current)
{
    heap_t *swap, *swapl, *swapr;
    while (current->parent)
    {
        if (current->parent)
        {
            if (current->n > current->parent->n)
            {
                swap = current->parent;
                swapl = current->parent->left;
                swapr = current->parent->right;
                current->parent->left = current->left;
                current->parent->right = current->right;
                if (swapl == current)
                    current->left = current->parent;
                else
                    current->left = swapl;
                if (swapr == current)
                    current->right = current->parent;
                else
                    current->right = swapr;
                if (current->parent->parent)
                {
                    if (current->parent->parent->left == current->parent)
                        current->parent->parent->left = current;
                    if (current->parent->parent->right == current->parent)
                        current->parent->parent->right = current;
                    current->parent = current->parent->parent;
                }
                swap->parent = current;
                if (current->right && current->right->parent == swap)
                    current->right->parent = current;
                if (current->left && current->left->parent == swap)
                    current->left->parent = current;
            }
        }
        current = current->parent;
    }
    return current;
}
/**
 * heap_heapify2 - Heapify child of root if value is greater
 * @root: Head of the binary tree
 * @current: Last node found with the binary algorithm
 * Return: Pointer to the root node
**/
heap_t **heap_heapify2(heap_t **root, heap_t *current)
{
    heap_t *swap, *swapl, *swapr;
    if (current && current->right)
    {
        if (current->right->n > current->n)
        {
            swapl = current->right->left;
            swapr = current->right->right;

            current->right->right = current;
            current->left->parent = current->right;
            current->right->left = current->left;
            current->right->parent = current->parent;

            current->parent = current->right;
            current->left = swapl;
            current->right = swapr;
            (*root) = current->parent;
        }
    }
    if (current && current->left)
    {
        if (current->left->n > current->n)
        {
            swapl = current->left->left;
            swapr = current->left->right;

            current->left->right = current;
            current->left->left = current->left;
            current->left->parent = current->parent;

            current->parent = current->left;
            current->left = swapl;
            current->right = swapr;
            (*root) = current->parent;
        }
    }
    return (root);
}
/**
 * heap_swap - swaps if the new child is lower than its parent 
 * @root: Head of the binary tree
 * @new: new node to be swapped with the root
 * @tmp: last node returned by the binary algorithm
 * Return: returns 1 if insertion otherwise 0
**/
bool heap_swap(heap_t **root, heap_t *new, heap_t *tmp)
{
    if ((*root) == tmp && new->n > tmp->n)
    {
        new->parent = NULL;
        if (tmp->left == new)
            new->left = tmp;
        else
            new->left = tmp->left;

        if (tmp->right == new)
            new->right = tmp;
        else
            new->right = tmp->right;
        tmp->parent = new;
        tmp->left = NULL;
        tmp->right = NULL;
        (*root) = new;
        return true;
    }
    return false;
}
/**
 * convert_to_binary - Converts integer to a binary
 * @num: Integer value
 * Return: Binary values into array of integer
**/
int *convert_to_binary(int num){
    static int bin[10], i;

    for (i = 1; num > 0; i++){
        bin[i] = num % 2;
        num /= 2;
    }
    bin[0] = i - 2;
    bin[i - 1] = -1;

    return bin;
}

/**
* heap_size - Get numbers of element in a binary tree
* @head: Head of the binary tree
* @size: Current size of the binary tree
* Return: Size of the binary tree
**/
int heap_size(heap_t *head, int size)
{   
    if (head->left)
        size = heap_size(head->left, size + 1);

    if (head->right)
        size = heap_size(head->right, size + 1);
    return size;
}
/**
 * heap_insert - function that inserts a value into a Max Binary Heap.
 * @root: is a double pointer to the root node of the Heap.
 * @value: is the value store in the node to be inserted.
 * Return: returns a pointer to the inserted node, or NULL on failure.
**/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new, *tmp = *root, *current;
    int *binary, size = 1, i = 0, parent_pos = 0;
    new = malloc(sizeof(heap_t));
    if (new == NULL)
        return NULL;
    new->parent = NULL;
    new->n = value;
    new->left = NULL;
    new->right = NULL;
    if (!(*root)){
        (*root) = new;
        return new;
    }
    size = heap_size(*root, size);
    binary = convert_to_binary(size + 1);
    for (i = binary[0]; i > 0; i--)
    {
        if (binary[i] == 0)
        {
            if (tmp->left)
                tmp = tmp->left;
        }
        else
        {
            if (tmp->right)
                tmp = tmp->right;
        }
    }
    parent_pos = binary[i + 1];
    new->parent = tmp;
    if (!tmp->left)
        tmp->left = new;
    else
        tmp->right = new;
    if (heap_swap(root, new, tmp))
        return new;
    current = heap_heapify(new);
    root = heap_heapify2(root, current);
    return new;
}