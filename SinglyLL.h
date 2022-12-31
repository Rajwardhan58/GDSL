//singly ll generic


using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
        struct node<T> *Head;
        int Count;
    
    SinglyLL();
    ~SinglyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    void DeleteAtPos(int iPos);
    int CountNode();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
SinglyLL<T>::~SinglyLL()
{
    delete []Head;
}

template<class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new node<T>;
    newn->data=iNo;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T iNo)
{
    struct node<T>*newn=NULL;
    newn=new node<T>;
    newn->data=iNo;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node<T>*temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T iNo,int iPos)
{
    int Cnt=CountNode();
    if((iPos<1) || (iPos>Cnt+1))
    {
        cout<<"Invalid position"<<endl;
        return; 
    }

    if(iPos==1)
    {
        InsertLast(iNo);
    }
    else if(iPos==Cnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node<T>*temp=Head;
        struct node<T>*newn=NULL;
        newn=new node<T>;
        newn->data=iNo;
        newn->next=NULL;

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
void SinglyLL<T>::DeleteFirst()
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
        struct node<T> *temp=Head;
        Head=Head->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
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
        struct node<T> *temp=Head;
    
        for(int i=1;i<Cnt-1;i++)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int Cnt=CountNode();
    if((iPos<1) || (iPos>Cnt))
    {
        cout<<"Invalid position"<<endl;
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
        struct node<T> *temp=Head;
        struct node<T> *temp2=NULL;

        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;
        Count--;
    }
    
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements are"<<endl;
    struct node<T>*temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}
