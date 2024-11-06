#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int getRandomInteger(int rmin, int rmax)
{
    return rmin + rand() % (rmax - rmin);
}

int listLength(Node* head)    
{
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int main()
{
srand(time(NULL));

Node *head = NULL;
head = malloc(sizeof(Node));
head->data = getRandomInteger(10,20) ;
head->next = NULL;

Node *first = NULL;
first = malloc(sizeof(Node));
first->data = getRandomInteger(10,20);
head->next = first;
first->next = NULL;

Node *second = NULL;
second = malloc(sizeof(Node));
second->data = head->data + first->data; // Calcul de la somme des deux premiers nœuds
first->next = second; // Lien entre le deuxième et le troisième nœud
second->next = NULL;
printf("%p head    : (%d, %p)\n", head, head->data, head->next);
printf("%p first   : (%d, %p)\n", first, first->data, first->next);
printf("%p second   : (%d, %p)\n", second, second->data, second->next);
printf("Longueur de la liste : %d\n", listLength(head));
    return 0;
}