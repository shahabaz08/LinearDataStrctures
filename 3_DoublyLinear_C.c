// Doubly linear linked list//

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
struct node
{

    int data;
    struct node *next;
    struct node *prev; // X
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}
void InsertLast(PPNODE First, int No)
{
    PNODE temp = *First;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}
void DeleteFirst(PPNODE First)
{
    PNODE temp = NULL;
    if (*First == NULL)
    {
        return;
    }
    else if ((*First)->next == NULL)
    {
        free(*First);
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev);
        (*First)->prev = NULL;
    }
}
void DeleteLast(PPNODE First)
{
    PNODE temp = *First;
    if (*First == NULL)
    {
        return;
    }
    else if ((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void Display(PNODE First)
{
    while (First != NULL)
    {
        printf("| %d |<=>", First->data);
        First = First->next;
    }
    printf("NULL\n");
}
int Count(PNODE First)
{
    int iCnt = 0;
    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}
void InsertAtPosition(PPNODE First, int no, int iPos)
{
    int NodeCnt = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    NodeCnt = Count(*First);
    if ((iPos < 1) || (iPos > (NodeCnt + 1)))
    {
        printf("Invalid position:\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(First, no);
    }
    else if (iPos == NodeCnt + 1)
    {
        InsertLast(First, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *First;
        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}
void DeleteAtPosition(PPNODE First, int iPos)
{
    int NodeCnt = 1, iCnt = 0;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    NodeCnt = Count(*First);

    if ((iPos < 1) || (iPos > NodeCnt))
    {
        printf("Invalid Position:\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(First);
    }
    else if (iPos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        free(temp2);
    }
}
int main()
{
    PNODE Head = NULL;
   PNODE Tail=NULL;
    int iChoice = 0, iPos = 0, iRet = 0, iNo = 0;
    printf("Welcome to data structure application written by Shahabaz Sayyad\n");

    while (1) // loop without conditon
    {
        printf("_____________________________________\n");
        printf("Please select the desired option \n");
        printf("1:Insert new node at First position\n");
        printf("2:Insert new node at Last position\n");
        printf("3:Insert new node at given position\n");
        printf("4:Delete node from First position\n");
        printf("5:Delete node from Last position\n");
        printf("6:Delete node from First position\n");
        printf("7:Display the contents of linked list\n");
        printf("8:Count number of nodes from liked list\n");
        printf("_____________________________________\n");
        scanf("%d", &iChoice);
        switch (iChoice)
        {
        case 1:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            InsertFirst(&Head,iNo);
            break;
        case 2:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            InsertLast(&Head,iNo);
            break;
        case 3:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            printf("Enter the position :\n");
            scanf("%d", &iPos);
            InsertAtPosition(&Head, iNo, iPos);
            break;
        case 4:
            DeleteFirst(&Head);
            break;
        case 5:
            DeleteLast(&Head);
            break;
        case 6:
            printf("Enter the position :\n");
            scanf("%d", &iPos);
            DeleteAtPosition(&Head,iPos);
            break;
        case 7:
            Display(Head);
            break;
        case 8:
            iRet = Count(Head);
            printf("Number of elements are: %d", iRet);
            break;
        case 9:
            printf("Thank you for using application \n\n");
            return 0;
        default:
            printf("Invalid option\n\n");
        }
    }

    return 0;
    
    
}