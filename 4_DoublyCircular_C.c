#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*First == NULL) && (*Last == NULL)) // only one item
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
    (*First)->prev = *Last;
    (*Last)->next = *First;
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*First == NULL) && (*Last == NULL)) // only one item
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
    }
    (*First)->prev = *Last;
    (*Last)->next = *First;
}
void Display(PNODE First, PNODE Last)
{
    if (First == NULL && Last == NULL)
    {
        printf("linked list is empty");
        return;
    }
    printf("elements of linked lists are :\n");

    do
    {
        printf("| %d |<=>", First->data);
        First = First->next;

    } while (First != Last->next);

    printf("\n\n");
}
int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    if (First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        First = First->next;

    } while (First != Last->next);
    return iCnt;
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if (*First == NULL && *Last == NULL)
    {
        return; // empty LL
    }
    else if (*First == *Last) // only one node
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev); // or free(*Last->next);

        (*First)->prev = *Last; // or return from line 108
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if (*First == NULL && *Last == NULL)
    {
        return; // empty LL
    }
    else if (*First == *Last) // only one node
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *Last = (*Last)->prev;
        free((*First)->prev); // free(*Last->next)

        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void InsertAtPos(PPNODE First, PPNODE Last, int no, int ipos)
{
    int iNodeCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if ((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        printf("Invalid position ");
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(First, Last, no);
    }
    else if (ipos == iNodeCnt + 1)
    {
        InsertLast(First, Last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        temp = *First;

        for (iCnt = 1; iCnt = ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}
void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int iNodeCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE temp = NULL;
    int iCnt = 0;

    if ((ipos < 1) || (ipos > iNodeCnt))
    {
        printf("Invalid position ");
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if (ipos == iNodeCnt + 1)
    {
        DeleteLast(First, Last);
    }
    else
    {

        temp = *First;

        for (iCnt = 1; iCnt = ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
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
            InsertFirst(&Head, &Tail, iNo);
            break;
        case 2:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            InsertLast(&Head, &Tail, iNo);
            break;
        case 3:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            printf("Enter the position :\n");
            scanf("%d", &iPos);
            InsertAtPos(&Head, &Tail, iNo, iPos);
            break;
        case 4:
            DeleteFirst(&Head, &Tail);
            break;
        case 5:
            DeleteLast(&Head, &Tail);
            break;
        case 6:
            printf("Enter the position :\n");
            scanf("%d", &iPos);
            DeleteAtPos(&Head, &Tail, iPos);
            break;
        case 7:
            Display(Head, Tail);
            break;
        case 8:
            iRet = Count(Head, Tail);
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