#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;

Tree *root_create(int value);
Tree *tree_add_element(Tree *root, int value);
void tree_print(Tree *root, int n);
Tree *search_in_tree(Tree *root, int value);
Tree *minimum(Tree *t);
Tree *maximum(Tree *t);
Tree *delete_element(Tree *root, int value);
int max_way(Tree *t, int len);
int min_way(Tree *t, int len);
int NonTerm(Tree *root);

#endif