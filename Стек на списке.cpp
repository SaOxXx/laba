#include <iostream>

using namespace std;

// Declare linked list node

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top;


// data in the stack insert at the beginning
void push(int data)
{

    
    struct Node* temp;
    temp = new Node();

    // Check if stack (heap) is full.
    
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;
}

//function to check if
// the stack is empty or not
int isEmpty()
{
    return top == NULL;
}

//  function to return top element in a stack
int peek__take_top()
{

    // Check for empty stack
    if (!isEmpty())        
        return top->data;
    else
        exit(1);
}

//  function to pop top
// element from the stack
void pop()
{
    struct Node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\n Stack Underflow" << endl;
        exit(1);
    }
    else
    {

        // Top assign into temp
        temp = top;

        // Assign second node to top
        top = top->link;
         
        // Destroy connection between
        // first and second
        temp->link = NULL;

        // Release memory of top node
        free(temp);
    }
}

// Function to print all the
// elements of the stack
void display()
{
    struct Node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            cout << temp->data << "-> ";

            // Assign temp link to temp
            temp = temp->link;
        }
    }
}

// Driver Code
int main()
{

    // Push the elements of stack
    push(11);
    push(22);
    push(33);
    push(44);

    // Display stack elements
    display();

    // Print top element of stack
    cout << "\nTop element is "
        << peek__take_top() << endl;

    // Delete top elements of stack
    pop();
    pop();

    // Display stack elements
    display();

    // Print top element of stack
    cout << "\nTop element is "
        << peek__take_top() << endl;

    return 0;
}