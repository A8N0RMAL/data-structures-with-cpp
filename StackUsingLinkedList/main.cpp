#include <iostream>
//#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
template <class t>
class stack
{
private:
    struct node
    {
        t item;
        node*next;
    };
    node*topptr,*curptr;
public:
    stack()
    {
        topptr = NULL;
    }

    bool isEmpty()
    {
        return topptr==NULL;
    }

    void push(t newitem)
    {
        node*newptr=new node;
        if(newptr==NULL)
        {
            cout<<"Stack push cannot allocate memory\n";
        }
        else
        {
            newptr->item=newitem;
            newptr->next=topptr;
            topptr=newptr;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty on pop\n";
        }
        else
        {
            node*temp=topptr;
            topptr=topptr->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void pop(t stacktop)
    {
        if(isEmpty())
        {
            cout<<"Stack is empty on pop\n";
        }
        else
        {
            stacktop=topptr->item;
            node*temp=topptr;
            topptr=topptr->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void gettop(t stacktop)
    {
        if(isEmpty())
        {
            cout<<"Stack is empty on gettop\n";
        }
        else
        {
            stacktop=topptr->item;
            cout<<"\nTop element of the stack is "<<stacktop<<endl;
        }
    }

    void display()
    {
        curptr=topptr;
        cout<<"\nItems in the stack : [ ";
        while(curptr != NULL)
        {
            cout<<curptr->item<<" ";
            curptr=curptr->next;
        }
        cout<<"]\n";
    }
};
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    s.pop();
    int x;
    s.gettop(x);
    s.display();
    return 0;
}
