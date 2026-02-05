///////////////////////////////////////////////////
//      Generalised Data Structure Library
///////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Stack                    Stacknode                   Stack              Done
Queue                    Queuenode                   Queue              Done
---------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> *first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at Last position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Delete First
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node at first position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                     
    {
        return;
    }
    else if(this->first->next == NULL)         
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;    
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete  node at last position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                     
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display 
//  Input :             Data of node
//  Output :            connection of node (|->|),represent last node was (NULL)
//  Description :       Used to Display the all node
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count 
//  Input :             just return iCount 
//  Output :            Nothing
//  Description :       Used to count the numbers of node 
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            if position is less then 1 or greater then iCount then it Display "Invalid Position"
//  Description :       Used to insert node at any position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            if position is less then 1 or greater then iCount then it Display "Invalid Position"
//  Description :       Used to Delete the node at any position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert  node at first position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Insert node at last position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertLast(T no) 
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)                    
    {
        this->first = newn;
    }
    else                                   
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            if position is less then 1 or greater then iCount then it Display "Invalid Position"
//  Description :       Used to insert the node at any position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node at first position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if(this->first == NULL)               
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else                                  
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeletetLast 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)     
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPost
//  Input :             Data of node
//  Output :            if position is less then 1 or greater then iCount then it Display "Invalid Position"
//  Description :       Used to Insert node at last position
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display  
//  Input :             Data of node
//  Output :            represent the connection betwwen nodes(NULL<=>NULL)
//  Description :       Used to Display the all node
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count 
//  Input :             just retrun iCount 
//  Output :            Nothing
//  Description :       Used to count the all node
//  Author :            Shruti Jalindar Girigosavi 
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Stack Using Genric Approch
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T>* next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{

    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);            // Insert First
        T pop();                 // Delete First
        T peep();
        void Display();
        int Count();
};

template <class T>
 Stack<T>::Stack()
 {
    cout<<"stack get created succefully\n";

    this->first = NULL;
    this->iCount = 0;
 }

template <class T>
void Stack<T>::push(T no)
{
    Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T>:: pop()
{
    T value = 0;
    Stacknode<T> *temp = this->first;
    if(this->first == NULL)
    {
        cout<<"stack is empty\n";
        return -1;
    }

    value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return value;
}

template <class T>
T Stack<T>::peep()
{
    T value = 0;
   
    if(this->first == NULL)
    {
        cout<<"stack is empty\n";
        return -1;
    }

    value = this->first->data;
    return value;
}

template <class T>
void Stack<T>::Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////
//          Queue Using Genric Approch
//////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T>* next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{

    private:
        Queuenode<T> *first;
        Queuenode<T> *last;

        int iCount;

    public:
        Queue();

        void enqueue(T);            
        T dequeue();                
        void Display();
        int  Count();
};

template <class T>
Queue<T>::Queue()
 {

    cout<<"Queue get created succefully\n";
    this->first = NULL;
     this->last = NULL;
    this->iCount = 0;
 }

template <class T>
void Queue<T>::enqueue(T no)
{
    
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
       this->last->next = newn;
       this->last = this->last->next;
    }

    this->iCount++;

}

template <class T>
T Queue<T>:: dequeue()
{
    T value = 0;
    Queuenode<T> *temp = this->first;
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return value;
}

template <class T>
void Queue<T>::Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return this->iCount;
}

//////////////////////////////// End of Library //////////////////////////////////

int main()
{

// Object are created 
    SinglyLLL<int> *obj = new SinglyLLL<int>();

    int iRet = 0;

//  In InsertFirst function 3 nodes are inserted in first position
    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

//  In Insertlast function 3 nodes are inserted in last position
    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

//  In DeleteFirst function first node was deleted 
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

//  In DeleteLast function last node was deleted
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

//  In InsertAtPos function node was inserted at 4th position 
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
//  In DeleteAtPos function node was deleted at 4th position 
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
//  Object was deleted
    delete obj;

/////////////////////////////////////////////////////////////////////////////

//  Object are created 
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

//  In InsertFirst function 3 nodes are inserted at first position
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

//  In InsertLast function 3 nodes are inserted at last position 
    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

//  In DeleteFirst function first node was deleted 
    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

//  In DeleteLast function last node was deleted 
    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

//  In InsertAtPos function node was inserted at 4th position 
    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

//  In DeleteAtPos function node was deleted at 4th position 
    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
//  Object was deleted
    delete dobj;

 //////////////////////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');

    sobj->Display();

    cout<<"Numbers of element stack :"<<sobj->Count()<<"\n";

    cout<<"Return value of Peep is :"<<sobj->peep()<<"\n";

    sobj->Display();

    cout<<"Numbers of element stack :"<<sobj->Count()<<"\n";

    cout<<"Pop element is :"<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Numbers of element stack :"<<sobj->Count()<<"\n";

    cout<<"Pop element is :"<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Numbers of element stack :"<<sobj->Count()<<"\n";

    sobj->push('E');

    sobj->Display();

    cout<<"Numbers of element stack :"<<sobj->Count()<<"\n";

    delete sobj;

/////////////////////////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.7637738);
    qobj->enqueue(21.63536);
    qobj->enqueue(51.736373);
    qobj->enqueue(101.733638);

    qobj->Display();

    cout<<"Numbers of element Queue :"<<qobj->Count()<<"\n";


    cout<<"removed element is :"<<qobj->dequeue()<<"\n";

    qobj->Display();
  
    cout<<"Numbers of element Queue :"<<qobj->Count()<<"\n";

    cout<<"removed element is :"<<qobj->dequeue()<<"\n";

    qobj->Display();

    cout<<"Numbers of element Queue :"<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout<<"Numbers of element Queue :"<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}