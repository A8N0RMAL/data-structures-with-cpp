#include <iostream>
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
class doublylinkedlist
{
    struct node
    {
        int item;
        node*next;
        node*prev;
    };
    node*first;
    node*last;
    int c;

public:
    doublylinkedlist()
    {
        first=NULL;
        last=NULL;
        c=0;
    }

    bool isEmpty()
    {
        return (first==NULL);
    }

    void insertfirst(int element)
    {
        node*newnode=new node;
        newnode->item=element;
        if(c==0)
        {
            first=last=newnode;
            newnode->next=newnode->prev=NULL;
        }
        else
        {
            newnode->next=first;
            newnode->prev=NULL;
            first->prev=newnode;
            first=newnode;
        }
        c++;
    }

    void insertlast(int element)
    {
        node*newnode=new node;
        newnode->item=element;
        if(c==0)
        {
            first=last=newnode;
            newnode->next=newnode->prev=NULL;
        }
        else
        {
            newnode->next=NULL;
            newnode->prev=last;
            last->next=newnode;
            last=newnode;
        }
        c++;
    }

    void insertat(int pos, int element)
    {
        if(pos<0 || pos>c)
            cout<<"OUT OF RANGE\n";
        else
        {
            node*newnode=new node;
            newnode->item=element;
            if(pos==0)
                insertfirst(element);
            else if(pos==c)
                insertlast(element);
            else
            {
                node*curr=first;
                for(int i=1;i<pos;i++)
                {
                    curr=curr->next;
                }
                newnode->next=curr->next;
                newnode->prev=curr;
                curr->next->prev=newnode;
                curr->next=newnode;
            }
            c++;
        }
    }

    void removefirst()
    {
        if(c==0)
            return; //empty list
        else if(c==1)
        {
            delete first;
            first=last=NULL;
        }
        else
        {
            node*curr=first;
            first=first->next;
            first->prev=NULL;
            delete curr; // delete reference for first
        }
        c--;
    }

    void removelast()
    {
        if(c==0)
            return; // empty list
        else if(c==1)
        {
            delete first;
            first=last=NULL;
        }
        else
        {
            node*curr=last;
            last=last->prev;
            last->next=NULL;
            delete curr; // delete reference for last
        }
        c--;
    }

    void removeitem(int element)
    {
        if(c==0)
            return; // empty list
        else if(first->item==element)
            removefirst();
        else
        {
            node*curr=first->next;
            while(curr!=NULL && curr->item!=element)
                curr=curr->next;
            if(curr==NULL)
                return; // item is not there
            else if(curr->next==NULL)
                removelast();
            else
            {
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
            }
            c--;
        }
    }

    void display()
    {
        node*curr=first;
        while(curr!=NULL)
        {
            cout<<curr->item<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    void reversedisplay()
    {
        node*curr=last;
        while(curr!=NULL)
        {
            cout<<curr->item<<" ";
            curr=curr->prev;
        }
        cout<<endl;
    }

    ~doublylinkedlist()
    {
        node*temp;
        while(first!=NULL)
        {
            temp=first;
            first=first->next;
            delete temp;
        }
        last=NULL;
        c=0;
    }
};
int main()
{
    doublylinkedlist dl;
    dl.insertat(0,10);
    dl.insertat(1,20);
    dl.insertat(2,30);
    //dl.insertat(4,40); // OUT OF RANGE
    //dl.display();
    //dl.reversedisplay();
    //dl.insertfirst(0);
    //dl.insertlast(40);
    //dl.display();
    dl.removefirst();
    dl.removelast();
    dl.display();
    return 0;
}
