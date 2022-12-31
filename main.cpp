#include<iostream>
#include"SinglyLL.h"
#include"DoublyLL.h"
#include"DoublyCLL.h"
#include"SinglyCLL.h"
using namespace std;

int main()
{
    SinglyLL<int> obj;
    obj.InsertFirst(10);
    obj.Display();

    DoublyLL<int> obj1;
    obj1.InsertFirst(12);
    obj1.InsertFirst(13);
    obj1.Display();
    DoublyLL<int> obj4;
    obj4.InsertFirst(12);
    obj4.InsertFirst(13);
    obj4.Display();

    SinglyCLL<int> obj2;
    obj2.InsertFirst(11);
    obj2.Display();

    
    return 0;
}