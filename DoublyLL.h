using namespace std;
template<class T>
struct node2
{
    T data;
    struct node2 *prev;
    struct node2 *next;
};

template<class T>
class DoublyLL
{
    public:
        struct node2<T> *Head;
        int Count;

    DoublyLL();
    ~DoublyLL();
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
DoublyLL<T>::DoublyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
DoublyLL<T>::~DoublyLL()
{
    delete []Head;
}

template<class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    struct node2<T> *newn=NULL;
    newn=new node2<T>;
    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;
    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    struct node2<T> *newn=NULL;
    newn=new node2<T>;
    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;
    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node2<T> *temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T iNo,int iPos)
{
    int Cnt=CountNode();
    if(iPos<1 || iPos>Cnt+1)
    {
        cout<<"Invalid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==Cnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node2<T> *temp=Head;
        struct node2<T> *newn=NULL;
        newn=new node2<T>;
        newn->data=iNo;
        newn->prev=NULL;
        newn->next=NULL;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->prev=temp;
        temp->next->prev=newn;
        temp->next=newn;
        Count++;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    int Cnt=CountNode();
    if(Head==NULL)
    {
        return;
    }
    else if(Cnt==1)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct node2<T> *temp=Head;
        Head=Head->next;
        Head->prev=NULL;
        delete temp;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    int Cnt=CountNode();
    if(Head==NULL)
    {
        return;
    }
    else if(Cnt==1)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct node2<T> *temp=Head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int Cnt=CountNode();
    if(iPos<1 || iPos>Cnt)
    {
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==Cnt)
    {
        DeleteLast();
    }
    else
    {
        struct node2<T> *temp=Head;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        struct node2<T> *temp2=temp->next;
        temp2->next->prev=temp;
        temp->next=temp2->next;
        delete temp2;
        Count--;
    }
}

template<class T>
void DoublyLL<T>::Display()
{
    struct node2<T> *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}