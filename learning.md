
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int A[MAX_SIZE];
int end = -1;

// 1. isEmpty
int isEmpty()
{
    return end == -1;
}

// 2. size / count
int size()
{
    return end + 1;
}

// 3. get
int get(int pos)
{
    if (pos < 0 || pos > end)
        exit(1);

    return A[pos];
}

// 4. set
void set(int pos, int val)
{
    if (pos < 0 || pos > end)
        return;

    A[pos] = val;
}

// 5. insert at position
void insert(int pos, int val)
{
    if (end == MAX_SIZE - 1)
        return;

    if (pos < 0 || pos > end + 1)
        return;

    for (int i = end; i >= pos; i--)
    {
        A[i + 1] = A[i];
    }

    A[pos] = val;
    end++;
}

// 6. remove at position
void removeAt(int pos)
{
    if (pos < 0 || pos > end)
        return;

    for (int i = pos; i < end; i++)
    {
        A[i] = A[i + 1];
    }

    end--;
}

// 7. add at end
void addEnd(int val)
{
    if (end == MAX_SIZE - 1)
        return;

    A[++end] = val;
}

// 8. search (additional helper)
int search(int val)
{
    for (int i = 0; i <= end; i++)
    {
        if (A[i] == val)
            return i;
    }

    return -1;
}

int main()
{
    addEnd(10);
    addEnd(20);
    addEnd(30);

    insert(1, 15);
    removeAt(2);
    set(0, 5);

    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    } 


    InfixToPostfix(exp)

    S = empty stack
    output = ""

    FOR each token t in exp

        IF t is operand
            append t to output

        ELSE IF t == '('
            Push(S, t)

        ELSE IF t == ')'
            WHILE Top(S) != '('
                append Pop(S) to output
            Pop(S)     // remove '('

        ELSE IF t is operator
            WHILE S not empty
                  AND Top(S) != '('
                  AND precedence(Top(S)) >= precedence(t)

                append Pop(S) to output

            Push(S, t)

    END FOR

    WHILE S not empty
        append Pop(S) to output

    RETURN output 


    #include <stdio.h>
#include <stdlib.h>

#define N 5

int A[N];
int front = -1;
int rear = -1;

// Check if queue is empty
int isEmpty()
{
    return (front == -1 && rear == -1);
}

// Check if queue is full
int isFull()
{
    return (rear == N - 1);
}

// Insert at rear
void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    // First element
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }

    A[rear] = x;
}

// Remove from front
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    int x = A[front];

    // Only one element exists
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = front + 1;
    }

    return x;
}

// Return front value without removing
int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        exit(1);
    }

    return A[front];
}

// Print queue
void printQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printQueue();

    printf("Dequeued: %d\n", dequeue());
    printQueue();

    enqueue(40);
    enqueue(50);

    printQueue();

    printf("Front: %d\n", peek());

    return 0;
}

#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    return 0;
}

int isBalanced(char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1)
            {
                return 0;
            }

            if (!isMatching(peek(), ch))
            {
                return 0;
            }

            pop();
        }
    }

    return (top == -1);
}

int main(void)
{
    char exp[] = "[[(}}";

    if (isBalanced(exp))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }

    return 0;
}

    return 0;
}
