using namespace std;

template<class T>
struct node6
{
    T data;
    struct node6 *next;
};

template<class T>
class Queue
{
    public:
        struct node6<T> *Head;
        int Count;

    Queue();
    void Enqueue(T);   //insertlast
    void Dequeue();       //deletefirst
    void Display();
    int CountNode();
};

template<class T>
Queue<T>::Queue()
{
    Head=NULL;
    Count=0;
}


template<class T>
void Queue<T>::Enqueue(T no)
{
    struct node6<T>*newn=NULL;
    newn=new node6<T>;
    newn->data=no;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node6<T> *temp=Head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    Count++;
}

template<class T>
void Queue<T>::Dequeue()       //delete first
{
    T no;
    if(Count==0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    no=Head->data;
    struct node6<T> *temp=Head;
    Head=Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;

}

template<class T>
void Queue<T>::Display()
{
    cout<<"elements from queue"<<endl;
    struct node6<T> *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
int Queue<T>::CountNode()
{
    return Count;
}