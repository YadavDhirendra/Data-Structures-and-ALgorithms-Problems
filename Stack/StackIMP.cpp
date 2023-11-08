//Stack Implementation in Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Stack{
    Node* top;

    public:
    Stack(){ top = NULL;}

    void push(int data){

        //create new Node temp and allocate memory in heap
        Node* temp = new Node(data);

        //check if stack(heap) is full
        //then inserting an element would lead to overflow
        if(!temp){
        cout<<"Stack Overflow!"<<endl;
        exit(1);
        }

        //Put top pointer reference into temp link
        temp->next = top;

        //make temp as top
        top = temp;
    }

    //Utility func. to check if stack is empty or not
    bool isEmpty()
    {
        if(top==NULL)
        return 1;
        else
        return 0;
    }

    //Utility func. to return top element 
    int peek()
    {
        //if stack is empty or not
        if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        exit(1);
        }
        else
        return top->data;
    }

    //func to remove a key from given stack
    void pop()
    {
        Node* temp = NULL;

        //check for stack unserflow
        if(top == NULL)
        cout<<"Stack Underflow"<<endl;
        else{
            //Assign top to temp
            temp = top;
        //Assign second Node to temp
            top = top->next;

            free(temp);
        }

    }

    //Func. to display all elements in stack
    void display()
    {
        Node* temp = NULL;

        //check for underflow
        if(top == NULL)
        {
            cout<<"Stack underflow"<<endl;
        }

        else{
            temp = top;
            while (temp!=NULL)
            {
                cout<<temp->data;
                temp = temp->next;
                if(temp!=NULL)
                cout<<" -> ";
        
            }
            cout<<endl;
        }
    }
};

int main()
{
   Stack s;

   //Push elements of stack
   s.push(11);
   s.push(22);
   s.push(33);
   s.push(44);
   s.push(55);

   //display stack elements
   s.display();

   cout<<"Top element is "<<s.peek()<<endl;

   //delete top elements of stack
   s.pop();
   s.pop();

   //Display stack elements
   s.display();

   //Print top element of Stack
   cout<<"Top element is "<<s.peek()<<endl;
   
    return 0;
}