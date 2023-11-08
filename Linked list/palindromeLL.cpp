//Palindrome in LL
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

void InsertAtTail(Node *&tail,int d){

    //new node to insert
    Node* newNode = new Node(d);

    //empty list
    if(tail== NULL)
    {
        tail = newNode;
        return;
    }
    else{

        tail->next = newNode;
        tail = newNode;
    }
}

Node* getMid(Node* head){

    Node* slow = head;
    Node* fast = head->next;

    while (fast!=NULL && fast->next!=NULL )
    {
        fast = fast->next->next;
       

        slow = slow->next;
    }
    return slow;
}

Node* revLL(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while (curr!=NULL)
    {   
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

    }
    
    return prev;
}

bool ispalindrome2(Node* head)
{
    //empty list or 1-element list
    if(head==NULL && head->next!=NULL)
    return true;

    //step 1. Find middle
    Node* middle = getMid(head);

    //step 2. Reverse list after middle
    Node* temp = middle->next;
    middle->next = revLL(temp);

    //step 3. Compare both halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while (head2!=NULL)
    {
        if(head1->data!=head2->data)
        return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    //step 4. perform step 2 again
    middle->next = revLL(middle->next);
    
    return true;
}

bool ispalindrome1(Node* head)
{
    //empty list or 1-element list
    if(head == NULL || head->next == NULL)
    return true;

    vector<int> ans;
    Node* temp = head;
    while (temp!=NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0;
    int e = ans.size()-1;
    while (s<e)
    {
        if(ans[s]!=ans[e])
        return false;
        s++;
        e--;

    }
    
    return true;
    
}

void print(Node* temp)
{
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(1);
    Node* tail = node1;
    Node* head = node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);;
    InsertAtTail(tail,1);;
    print(head);
    bool one = ispalindrome1(head);
    bool two = ispalindrome2(head);
    cout<<"________________BY APPROACH 1____________________"<<endl;
    if(one)
    cout<<"Given LL is palindrome"<<endl;
    else
    cout<<"Sorry! its not a palindrome"<<endl;
    cout<<"________________BY APPROACH 2____________________"<<endl;
    if(two)
    cout<<"Given LL is palindrome"<<endl;
    else
    cout<<"Sorry! its not a palindrome"<<endl;
    print(head);
    return 0;
};
