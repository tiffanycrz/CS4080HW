#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

/* insert at front */
void insert(const char *s) {
    Node *n = malloc(sizeof(Node));
    n->data = strdup(s);
    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

/* find a node */
Node *find(const char *s) {
    for (Node *p = head; p != NULL; p = p->next)
        if (strcmp(p->data, s) == 0)
            return p;
    return NULL;
}

/* delete a node */
void delete(const char *s) {
    Node *p = find(s);
    if (p == NULL) return;

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    free(p->data);
    free(p);
}

int main(void) {
    printf("Hello, world!\n");

    insert("three");
    insert("two");
    insert("one");

    delete("two");

    for (Node *p = head; p != NULL; p = p->next)
        printf("%s ", p->data);

    printf("\n");
    return 0;
}
