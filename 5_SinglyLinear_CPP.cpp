// Singly Linear Linked list

#include <iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
class SinglyLL
{
public:
    PNODE First;
    PNODE Last; 
    int iCount;

    // Behavoiurs
    SinglyLL();

    void InsertFirst(int no);
    void InsertLast(int);
    void InsertAtPosition(int, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);

    void Display();
};
// Return_Value Class_Name::Function_Name(Parameters)
//{
// Logic
//}

SinglyLL ::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL ::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else
    {

        newn->next = First;
        First = newn;
        (Last)->next = First;
    }

    iCount++;
}

void SinglyLL ::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    PNODE temp = First;
    if (First == NULL) // or if(iCount==0)
    {
        First = newn;

        iCount++;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        Last->next = First;

        iCount++;
    }
}

void SinglyLL ::InsertAtPosition(int no, int iPos)
{
    if ((iPos < 0) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
        iCount++;
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
        iCount++;
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        PNODE temp1 = First;

        for (int iCnt = 0; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        newn->next = temp1->next;
        temp1->next = newn;
        iCount++;
    }
}

void SinglyLL ::DeleteFirst()
{
    if (First == NULL) // iCount==0
    {
        return;
    }
    else if (First->next == NULL) // iCount==1
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
        iCount--;
    }
}

void SinglyLL ::DeleteLast()
{
    if (First == NULL) // iCount==0
    {
        return;
    }
    else if (First->next == NULL) // iCount==1
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

void SinglyLL ::DeleteAtPosition(int iPos)
{
    if ((iPos < 0) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = First;
        PNODE temp2 = NULL;

        for (int iCnt = 0; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;

        delete temp2;
        iCount--;
    }
}

void SinglyLL::Display()
{
    cout << "elements of linked list are :"
         << "\n";
    PNODE temp = First;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "| NULL |"
         << "\n";
}

int main()
{
    SinglyLL obj1;
    cout << sizeof(obj1) << "\n";

    cout << "first pointer contains :" << obj1.First << "\n";
    cout << "Number of nodes are :" << obj1.iCount << "\n";

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    cout << "Number of nodes are :" << obj1.iCount << "\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);

    obj1.Display();
    cout << "Number of nodes are :" << obj1.iCount << "\n";

    obj1.InsertAtPosition(105, 5);
    obj1.Display();
    cout << "Number of nodes are :" << obj1.iCount << "\n";

    obj1.DeleteAtPosition(5);
    obj1.Display();
    cout << "Number of nodes are :" << obj1.iCount << "\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.Display();
    cout << "Number of nodes are :" << obj1.iCount << "\n";

    return 0;
}