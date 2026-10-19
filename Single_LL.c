#include <stdio.h>
#include <stdlib.h>
struct node
{
    int prn;
    char name[20];
    struct node *next;
};
void create_SLL(struct node *head);
void display_SLL(struct node *head);
void insert_SLL(struct node *head);
void delete_SLL(struct node *head);
int count_nodes(struct node *head);
void reverse_SLL(struct node *head);
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    create_SLL(head);
    printf("\nAfter creation:");
    display_SLL(head);
    printf("Total nodes = %d\n", count_nodes(head));
    insert_SLL(head);
    printf("\nAfter insertion:");
    display_SLL(head);
    printf("Total nodes = %d\n", count_nodes(head));
    delete_SLL(head);
    printf("\nAfter deletion:");
    display_SLL(head);
    printf("Total nodes = %d\n", count_nodes(head));
    reverse_SLL(head);
    printf("\nAfter Reversing:");
    display_SLL(head);
    printf("Total nodes = %d\n", count_nodes(head));
    
    
    

    return 0;
}
void create_SLL(struct node *head)
{
    char ch;
    struct node *ptr, *last;
    last = head;
    do
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter PRN: ");
        scanf("%d", &ptr->prn);
        printf("Enter name: ");
        scanf("%19s", ptr->name);
        ptr->next = NULL;
        last->next = ptr;
        last = ptr;
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

void display_SLL(struct node *head)
{
    struct node *temp;
    temp = head->next;
    if (temp == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d | %s", temp->prn, temp->name);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}
int count_nodes(struct node *head)
{
    int count = 0;
    struct node *temp;
     temp = head->next;
     while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
void insert_SLL(struct node *head)
{
    int pos, i;
    struct node *ptr, *temp;
    printf("\nEnter position to insert: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
     ptr = (struct node *)malloc(sizeof(struct node));
     printf("Enter PRN: ");
    scanf("%d", &ptr->prn);
    printf("Enter name: ");
    scanf("%19s", ptr->name);
    temp = head;
    for (i = 1; i < pos; i++)
    {
        if (temp->next == NULL)
        {
            printf("Invalid position.\n");
            free(ptr);
            return;
        }

        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    printf("Node inserted successfully.\n");
}

void delete_SLL(struct node *head)
{
    int prn;
    struct node *temp, *prev;

    printf("\nEnter PRN to delete: ");
    scanf("%d", &prn);

    prev = head;
    temp = head->next;

    while (temp != NULL)
    {
        if (temp->prn == prn)
        {
            prev->next = temp->next;
            free(temp);

            printf("Node deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("PRN not found.\n");
}
void reverse_SLL(struct node *head)
{
    struct node *prev, *current, *next;

    prev = NULL;
    current = head->next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head->next = prev;

    printf("List reversed successfully.\n");
}
