#include<iostream>
using namespace std;

template<class T>
struct node3
{
    T data;
    struct node3 *next;
};

template<class T>
class SinglyCLL
{
    public:

        struct node3<T> *Head;
        struct node3<T> *Tail;
        int Count;

        SinglyCLL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        void Display();
        int CountNode();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head=NULL;
    Tail=NULL;
    Count=0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T iNo)
{
    struct node3<T> *newn=NULL;
    newn=new node3<T>;
    newn->data=iNo;
    newn->next=NULL;
    if(Head==NULL && Tail==NULL)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Tail->next=Head;
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T iNo)
{
    struct node3<T> *newn=NULL;
    newn=new node3<T>;
    newn->data=iNo;
    newn->next=NULL;
    if(Head==NULL && Tail==NULL)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        Tail->next=newn;
        Tail=newn;
    }
    Tail->next=Head;
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T iNo,int iPos)
{
    if((iPos<1) || (iPos>Count+1))
    {
        cout<<"Invalid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==Count+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node3<T> *newn=NULL;
        newn=new node3<T>;
        newn->data=iNo;
        newn->next=NULL;

        struct node3<T> *temp=Head;
        
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        Count++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(Head==NULL && Tail==NULL)
        {
            return;
        }
        else if(Head==Tail)
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
        }
        else
        {
            Head=Head->next;
            delete Tail->next;
            Tail->next=Head;
        }
        Count--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if(Head==NULL && Tail==NULL)
        {
            return;
        }
        else if(Head==Tail)
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
        }
        else
        {
            struct node3<T> *temp=Head;
            for(int i=1;i<Count-1;i++)
            {
                temp=temp->next;
            }
            delete Tail;
            Tail=temp;
            Tail->next=Head;
        }
        Count--;
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
    if(iPos<1 || iPos>Count)
        {
            return;
        }
        if(iPos==1)
        {
            DeleteFirst();
        }
        else if(iPos==Count)
        {
            DeleteLast();
        }
        else
        {
            struct node3<T> *temp1=Head;
            int iCnt=0;

            for(iCnt=1;iCnt<iPos-1;iCnt++)
            {
                temp1=temp1->next;
            }
            struct node3<T> *temp2=temp1->next;
            temp1->next=temp2->next;
            delete temp2;
            Count--;
        }
}

template<class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct node3<T> *temp=Head;
    for(int i=1;i<=Count;i++)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}