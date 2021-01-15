#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <string.h>

// Aimer 19 50
// Neige 19 61

struct node
{
    char name;
    int age;
    // double grade;
    int grade;
    LIST_ENTRY(node)
    nodes; // you can change this to pointers it will be entries usually
} * n1, *n2, *np;

LIST_HEAD(listhead, node)
head;

int main(int argc, char const *argv[])
{
    LIST_INIT(&head);
    n1 = malloc(sizeof(struct node));
    n1->name = 'A';
    n1->age = 19;
    n1->grade = 50;
    n1->nodes.le_next = NULL;
    n1->nodes.le_prev = NULL;
    LIST_INSERT_HEAD(&head, n1, nodes);
    n2 = malloc(sizeof(struct node));
    n2->name = 'N';
    n2->age = 19;
    n2->grade = 61;
    n2->nodes.le_next = NULL;
    n2->nodes.le_prev = NULL;
    LIST_INSERT_AFTER(n1, n2, nodes);
    for (np = head.lh_first; np != NULL; np = np->nodes.le_next) {
        printf("Name:  %c\n", np->name);
        printf("Age:   %d\n", np->age);
        printf("Grade: %d\n", np->grade);
    }

    return 0;
}
