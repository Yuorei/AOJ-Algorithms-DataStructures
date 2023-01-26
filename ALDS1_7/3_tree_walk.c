#include <stdio.h>
#define NIL -1
#define MAX 100000

typedef struct
{
    int pearent;
    int left;
    int right;
} NODE;

NODE T[MAX];
int n;

int main()
{
    int root, id, left, right;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        T[i].pearent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &id, &left, &right);
        T[id].left = left;
        T[id].right = right;
        if (left != NIL)
        {
            T[left].pearent = id;
        }
        if (right != NIL)
        {
            T[right].pearent = id;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (T[i].pearent == NIL)
        {
            root = i;
        }
    }
    printf("Preorder\n");
    preParse(root);
    printf("\n");
    printf("Inorder\n");
    inParse(root);
    printf("\n");
    printf("Postorder\n");
    postParse(root);
    printf("\n");

    return 0;
}

void preParse(int u)
{
    if (u == NIL)
    {
        return;
    }
    printf(" %d", u);
    preParse(T[u].left);
    preParse(T[u].right);
}

void inParse(int u)
{
    if (u == NIL)
    {
        return;
    }
    inParse(T[u].left);
    printf(" %d", u);
    inParse(T[u].right);
}

void postParse(int u)
{
    if (u == NIL)
    {
        return;
    }
    postParse(T[u].left);
    postParse(T[u].right);
    printf(" %d", u);
}