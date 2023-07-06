#include <stdio.h>
#include <stdlib.h>

typdef struct root
{
    struct root right;
    struct root left;
    int number;
}
root;

root *make_tree(int layers);

int main(void)
{
    root *r = make_tree(3);
    print_tree(r);
    // free_tree(r);
}

root *make_tree(int layers)
{
    root *r = malloc(sizeof(root));

    if (layers > 1)
    {
        root *root_left = make_tree(layers - 1);
        root *root_right = make_tree(layers - 1);

        r -> left = root_left;
        r -> right = root_right;
        r -> number = 
    }
}