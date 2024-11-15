#include <stdio.h>
#include <stdlib.h>


struct bintree {
    int info;
    struct bintree *left, *right;
};
typedef struct bintree node;

node *insert(node *, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);


node *insert(node *s, int n) {
    node *nn;
    nn = (node *)malloc(sizeof(node));
    nn->info = n;
    nn->left = NULL;
    nn->right = NULL;
    if (s == NULL) {
        return nn;
    } else {
        node *S = s;
        while (1) {
            if (n < S->info) {
                if (S->left == NULL) {
                    S->left = nn;
                    break;
                } else {
                    S = S->left;
                }
            }
             else {
                if (S->right == NULL) {
                    S->right = nn;
                    break;
                } else {
                    S = S->right;
                }
            }
        }
    }
    return s;
}

void inorder(node *s) {
    if (s != NULL) {
        inorder(s->left);
        printf("%d ", s->info);
        inorder(s->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(node *s) {
    if (s != NULL) {
        printf("%d ", s->info);
        preorder(s->left);
        preorder(s->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(node *s) {
    if (s != NULL) {
        postorder(s->left);
        postorder(s->right);
        printf("%d ", s->info);
    }
}

main() {
    node *s = NULL;
    int n, i, val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        s = insert(s, val);
    }
    printf("Inorder Traversal: ");
    inorder(s);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(s);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(s);
    printf("\n");


}
