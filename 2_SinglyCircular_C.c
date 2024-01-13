// Singly Circular liked list

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(int));
    newn->data = No;
    newn->next = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}
void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(int));
    newn->data = No;
    newn->next = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}
void DeleteFirst(PPNODE First, PPNODE Last)
{

    if ((*First == NULL) && (*Last == NULL)) // empty
    {
        return;
    }
    else if (*First == *Last) // single node
    {
        free(*First);
        *First = *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*Last)->next);
        (*Last)->next = *First;
    }
}
void DeleteLast(PPNODE First, PPNODE Last)
{
    PNODE temp = *First;

    if ((*First == NULL) && (*Last == NULL)) // empty
    {
        return;
    }
    else if ((*First) == (*Last)) // single node
    {
        free(*First);
        *First = (*Last) = NULL;
    }
    else
    {
        while (temp->next != *Last)
        {
            temp = temp->next;
        }
        free(temp->next); // FRee(*Last);
        *Last = temp;
        (*Last)->next = *First;
    }
}

void Display(PNODE First, PNODE Last)
{
    printf("elements of LInked list are:\n");

    do
    {
        printf("| %d |->", First->data);
        First = First->next;
    } while (First != Last->next);
    {
        printf("\n");
    }
}
int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    printf("elements of LInked list are:\n");

    do
    {
        iCnt++;
        First = First->next;
    } while (First != Last->next);
    {
        printf("\n\n\n");
    }

    return iCnt;
}
void InsertAtPos(PPNODE First, PPNODE Last, int no, int ipos)
{
    int iNodeCnt = 0;
    int iCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE newn = NULL;
    PNODE temp = *First;

    if ((ipos < 0) || (ipos > iNodeCnt + 1))
    {
        printf("invalid case ");
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
        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}
void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int iNodeCnt = 0;
    int iCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    if ((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        printf("invalid case \n");
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if (ipos == iNodeCnt)
    {
        DeleteLast(First, Last);
    }
    else
    {
        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1 = temp2->next;
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
            InsertFirst(&Head,&Tail,iNo);
            break;
        case 2:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            InsertLast(&Head,&Tail, iNo);
            break;
        case 3:
            printf("Enter the data to insert :\n");
            scanf("%d", &iNo);
            printf("Enter the position :\n");
            scanf("%d", &iPos);
            InsertAtPos(&Head,&Tail, iNo, iPos);
            break;
        case 4:
            DeleteFirst(&Head,&Tail);
            break;
        case 5:
            DeleteLast(&Head,&Tail);
            break;
        case 6:
            printf("Enter the position :\n");
            scanf("%d", &iPos);
            DeleteAtPos(&Head,&Tail, iPos);
            break;
        case 7:
            Display(Head,Tail);
            break;
        case 8:
            iRet = Count(Head,Tail);
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