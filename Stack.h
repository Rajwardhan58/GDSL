using namespace std;

template<class T>
struct node5
{
    T data;
    struct node5 *next;
};

template<class T>
class Stack
{
    public:
        struct node5<T> *Head;
        int Count;

    Stack();
    void Push(T);   //insertfirst
    void Pop();       //deletefirst
    void Display();
    int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head=NULL;
    Count=0;
}


template<class T>
void Stack<T>::Push(T no)
{
    struct node5<T>*newn=NULL;
    newn=new node5<T>;
    newn->data=no;
    newn->next=NULL;

    newn->next=Head;
    Head=newn;
    Count++;
}

template<class T>
void Stack<T>::Pop()       //delete first
{
    T no;
    if(Count==0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    no=Head->data;
    struct node5<T> *temp=Head;
    Head=Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;

}

template<class T>
void Stack<T>::Display()
{
    cout<<"elements from stack"<<endl;
    struct node5<T> *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}