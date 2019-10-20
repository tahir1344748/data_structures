#include "stack.h"
#include <iostream>

using namespace std;
stack::stack(int size)
{
    this->size=size;
    array = new int[size];
}

bool stack::isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else return false;
}

bool stack::isfull()
{
    if(top==size-1)
    {
        return true;
    }
    else return false;
}

void stack::push(int value)
{
    if(!this->isfull())
    {
        array[++top]=value;
    }
    else return;
}

int stack::pop()
{
    if(!this->isEmpty())
    {
        return array[top--];
    }
    else 
    {
        cout<<"stack UnderFlow"<<endl;
    }
}

int stack::top_value()
{
    if(!this->isEmpty())
        return array[top];
    else
        cout<<"Stack is Empty"<<endl;
}

int stack::bottom_value()
{
    if(!this->isEmpty())
        return array[0];
}

int stack::middle_value()
{
    if(!this->isEmpty())
    {
        if(this->size%2==0)
        {
            int mid = this->size/2;
            // we subtract 1 because index counting starts with 0
            return array[mid-1];
        }
        else
        {
            int mid = this->size/2;
            return array[mid];
        }
    }
}

void stack::display()
{
    int top_copy = top;
    for(; top_copy!=-1; top_copy--)
    {
        cout<<array[top_copy]<<endl;
    }
}

void stack::remove(int value)
{
    if(!this->isEmpty())
    {
        int value_found;
        int index=0;
        for(int i=0; i<size; i++)
        {
            if(array[i]==value)
            {
                value_found = value;
                index = i;
            }
        }
        
        //checking whether the value is found or not
        if(value_found!=value)
        {
            return;
        }
        else if(index==top)
        {
            top--;
            return;
        }
        else
        {
            for(; index!=top; index++)
            {
                array[index]=array[index+1];
            }
            top--;
            return;
        }
    }
}

void stack::del(int index)
{
    index = index-1;
    if(!this->isEmpty())
    {
        if(index<=top)
        {
            for(; index!=top; index++)
            {
                array[index]=array[index+1];
            }
            top--;
            return;
        }
        else return;
    }
    else return;
}

void stack::head()
{
    int quarter = size % 4;
    int top_copy = top;
    
    if(!this->isEmpty())
    {
        if(size != 4)
        {
            while(quarter!=0)
            {
                cout<<array[top_copy--]<<endl;
                quarter--;
            }
        }
        else if(size == 4)
        {
            cout<<array[top]<<endl;
        }
    }
}

void stack::tail()
{
    int quarter = (size % 4) - 1;
    if(!this->isEmpty())
    {
        if(size != 4)
        {
            while(quarter!=-1)
            {
                cout<<array[quarter--]<<endl;
            }
        }
        else if(size == 4)
        {
            cout<<array[0]<<endl;
        }
    }
}

bool stack::ispresent(int value)
{
    bool result = false;
    if(!this->isEmpty())
    {
        for(int i=0; i<size; i++)
        {
            if(value == array[i])
                result = true;
        }
        
        if(result)
            return result;
        else
            return false;
    }
    else return false;
}