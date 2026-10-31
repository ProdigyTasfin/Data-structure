# Data Structures C Codebook

**Coverage:** The 5 uploaded lecture decks on time complexity/list ADT, singly/doubly linked lists, stacks, queues, and iterative vs recursive solutions.

**How to run one program:** `gcc -std=c11 -Wall -Wextra 03_singly_linked_list.c -o program` then `./program` (Windows CMD: `program.exe`). Each `.c` file has its own `main()`, so compile **one file at a time**.

**Important:** These are runnable teaching adaptations of the algorithms and pseudocode on the slides, not word-for-word slide transcriptions. Added missing edge-case checks, example `main()` functions, and a few teaching extensions (marked in source comments).

## 1-minute revision: the lines you must recall

| Topic | Core lines / condition |
|---|---|
| Singly insert beginning | `newNode->link = head; head = newNode;` |
| Singly insert end | `while (ptr->link != NULL) ptr = ptr->link; ptr->link = newNode;` |
| Singly insert position | `newNode->link = ptr->link; ptr->link = newNode;` |
| Singly delete first | `temp = head; head = head->link; free(temp);` |
| Singly delete last | `prev = ptr; ptr = ptr->link;` until last; `prev->link = NULL; free(ptr);` |
| Singly delete position | `temp = prev->link; prev->link = temp->link; free(temp);` |
| Singly reverse | `next = curr->link; curr->link = prev; prev = curr; curr = next;` |
| Doubly insert first | `temp->next = head; if (head) head->prev = temp; head = temp;` |
| Doubly insert end | `ptr->next = temp; temp->prev = ptr;` |
| Doubly delete first | `head = head->next; if (head) head->prev = NULL; free(temp);` |
| Doubly delete last | `temp->prev->next = NULL; free(temp);` (for 2+ nodes) |
| Doubly reverse | Swap each node's `prev` and `next`, then update `head` |
| Array stack | `A[++top] = x;` and `x = A[top--];` |
| Linked stack | `temp->next = top; top = temp;` and `top = top->next; free(temp);` |
| Simple queue | `front = rear = -1` initially; dequeue moves `front++` |
| Circular queue | `(rear + 1) % N` and `(front + 1) % N` |
| Linked queue enqueue | `rear->next = temp; rear = temp;` (not empty) |
| Linked queue dequeue | `if(front == rear) front = rear = NULL; else front = front->next;` |
| Recursive base case | `if (n == 0) return;` |
| Fibonacci | `fib(n - 1) + fib(n - 2)`; memo check `if (F[n] != -1)` |

## Edge-case traps

1. `head == NULL`: list empty. `head->link == NULL`: list has ONE node, provided `head != NULL`.
2. `ptr = ptr->link` MOVES a pointer. `ptr->link = newNode` CHANGES a node connection.
3. Insert-at-position uses a node at `pos-1`. This code enforces positions **1..n+1**, so insertion at `n+1` appends, positions greater than `n+1` are rejected. Lecture 5 page 25 describes oversize positions as appending; the stricter behavior here is deliberate.
4. Don't access a freed node. Save the next address or target value **before** `free`.
5. Singly delete-last: handle empty and single-node cases before dereferencing `prev`.
6. Linked-list queue: after removing the ONLY node, reset **both** `front` and `rear` to `NULL`.
7. Array stack underflow: `top == -1`; overflow: `top == MAX_SIZE - 1`.
8. Simple queue can report full with unused cells before `front`; circular queue fixes this.
9. In recursion, the caller waits at the recursive call; statements AFTER it run while returning.
10. Lecture 8 uses `int F[51]`, but `fib(47)` exceeds the range of common 32-bit `int`. The executable uses `long long` and checks `0 <= n <= 50` in `main`.

## Time complexity summary

| Operation | Time |
|---|---|
| Array List `get/set` | O(1) |
| Array List insert/remove at position | O(n) worst |
| Singly Linked List insert/delete at beginning | O(1) |
| Singly Linked List insert/delete at end (head only) | O(n) |
| Linked List insert/delete at position | O(n) |
| Linked List reverse | O(n) |
| Array/Linked Stack push/pop/peek | O(1) |
| Queue enqueue/dequeue/peek (all 3 implementations) | O(1) |
| Check balanced symbols / infix-to-postfix | O(n) |
| Fibonacci naive recursion | O(2^n) upper bound |
| Fibonacci iterative | O(n) time, O(1) extra space |
| Fibonacci memoization | O(n) time, O(n) extra space |

## All standalone code files

- **01_complexity_examples.c**: Time complexity examples. Slides: Complexity/List ADT, pp. 3, 7-12.
- **02_array_list_adt.c**: Array-based dynamic List ADT. Slides: Complexity/List ADT, pp. 14-18.
- **03_singly_linked_list.c**: Singly linked list: all core operations. Slides: Linked List, pp. 6-37.
- **04_doubly_linked_list.c**: Doubly linked list: key operations. Slides: Linked List, pp. 38-46.
- **05_stack_array.c**: Array stack: push, pop, peek. Slides: Stack, pp. 11-22.
- **06_stack_linked_list.c**: Linked-list stack. Slides: Stack, pp. 24-35.
- **07_balanced_symbols.c**: Balanced symbols using stack. Slides: Stack, pp. 39-44.
- **08_infix_to_postfix.c**: Infix to postfix using stack. Slides: Stack, pp. 46-51.
- **09_queue_simple_array.c**: Simple array queue. Slides: Queue, pp. 11-17.
- **10_queue_circular_array.c**: Circular array queue. Slides: Queue, pp. 18-24.
- **11_queue_linked_list.c**: Linked-list queue. Slides: Queue, pp. 27-34.
- **12_recursion_patterns.c**: Recursion: hello/bye, up/down. Slides: Iterative vs Recursive, pp. 2-11.
- **13_fibonacci_methods.c**: Fibonacci: iterative, recursive, memoized. Slides: Iterative vs Recursive, pp. 12-17.
- **14_linked_list_manual_creation.c**: Manual list creation, two methods. Slides: Linked List, pp. 7, 9-10.

## Full code, file by file

### 01_complexity_examples.c: Time complexity examples

*Basis: Complexity/List ADT, pp. 3, 7-12*

```c
/* Lecture 4, pages 3, 7, 8, 11-12. Time complexity examples. */
#include <stdio.h>

int sum(int a, int b) { return a + b; }              // O(1)

int sumOfList(const int a[], int n) {              // O(n)
    int total = 0;
    for (int i = 0; i < n; i++) total += a[i];
    return total;
}

long long sumMatrix(int n, int a[n][n]) {           // O(n^2)
    long long total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) total += a[i][j];
    return total;
}

int isPrimeSlow(int n) {                           // O(n)
    if (n < 2) return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int isPrimeFast(int n) {                           // O(sqrt(n))
    if (n < 2) return 0;
    for (int i = 2; i <= n / i; i++)  // avoids i*i overflow
        if (n % i == 0) return 0;
    return 1;
}

void threeFragments(int n) {                      // O(n^2)
    int a = 5; a++;
    for (int i = 0; i < n; i++) printf("%d ", i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) (void)j;
    printf("\nValue: %d\n", a);
}

void worstBranch(int n, int cond) {                // Worst O(n^2)
    if (cond) {
        for (int i = 0; i < n; i++) printf("%d ", i);
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) printf("%d ", j);
    }
    printf("\n");
}

int main(void) {
    int a[] = {2, 4, 7, 8};
    int m[2][2] = {{1, 2}, {3, 4}};
    printf("sum=%d\n", sum(3, 4));
    printf("list sum=%d\n", sumOfList(a, 4));
    printf("matrix sum=%lld\n", sumMatrix(2, m));
    printf("prime(29) slow=%d fast=%d\n", isPrimeSlow(29), isPrimeFast(29));
    threeFragments(2);
    worstBranch(2, 1);
    return 0;
}
```

### 02_array_list_adt.c: Array-based dynamic List ADT

*Basis: Complexity/List ADT, pp. 14-18*

```c
/* Lecture 4, pages 14-18. Array dynamic list, index-based positions (0-based). */
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int *a;
    int size;
    int capacity;
} List;

int initList(List *list) {
    list->a = malloc(INITIAL_CAPACITY * sizeof *list->a);
    if (!list->a) return 0;
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return 1;
}

int isEmpty(const List *list) { return list->size == 0; }
int count(const List *list) { return list->size; }

int grow(List *list) { // Extension of slide's doubling strategy
    int newCapacity = list->capacity * 2;
    int *b = malloc((size_t)newCapacity * sizeof *b);
    if (!b) return 0;
    for (int i = 0; i < list->size; i++) b[i] = list->a[i];
    free(list->a);
    list->a = b;
    list->capacity = newCapacity;
    return 1;
}

int insert(List *list, int pos, int val) { // O(n), 0 <= pos <= size
    if (pos < 0 || pos > list->size) return 0;
    if (list->size == list->capacity && !grow(list)) return 0;
    for (int i = list->size - 1; i >= pos; i--)
        list->a[i + 1] = list->a[i];
    list->a[pos] = val;
    list->size++;
    return 1;
}

int removeAt(List *list, int pos) { // O(n)
    if (pos < 0 || pos >= list->size) return 0;
    for (int i = pos; i < list->size - 1; i++)
        list->a[i] = list->a[i + 1];
    list->size--;
    return 1;
}

int get(const List *list, int pos, int *result) { // O(1)
    if (pos < 0 || pos >= list->size) return 0;
    *result = list->a[pos];
    return 1;
}

int set(List *list, int pos, int val) { // O(1)
    if (pos < 0 || pos >= list->size) return 0;
    list->a[pos] = val;
    return 1;
}

void printList(const List *list) {
    for (int i = 0; i < list->size; i++) printf("%d ", list->a[i]);
    printf("\n");
}

void destroyList(List *list) {
    free(list->a);
    list->a = NULL;
    list->size = list->capacity = 0;
}

int main(void) {
    List list;
    if (!initList(&list)) return 1;
    insert(&list, 0, 2);
    insert(&list, 1, 4);
    insert(&list, 2, 7);
    insert(&list, 3, 8);
    insert(&list, 2, 5); // [2,4,5,7,8], capacity doubles
    printList(&list);
    removeAt(&list, 0); // [4,5,7,8]
    printList(&list);
    int x;
    if (get(&list, 1, &x)) printf("get(1)=%d\n", x);
    set(&list, 1, 99);
    printf("size=%d empty=%d\n", count(&list), isEmpty(&list));
    printList(&list);
    destroyList(&list);
    return 0;
}
```

### 03_singly_linked_list.c: Singly linked list: all core operations

*Basis: Linked List, pp. 6-37*

```c
/* Lecture 5, pages 6-37. Singly linked list. Positions are 1-based. */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *addAtBeginning(struct node *head, int x) {
    struct node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) return head;
    newNode->data = x;
    newNode->link = head; // IMPORTANT: point to old first
    return newNode;       // new head
}

struct node *addAtEnd(struct node *head, int x) {
    struct node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) return head;
    newNode->data = x;
    newNode->link = NULL;
    if (head == NULL) return newNode; // empty-list case
    struct node *ptr = head;
    while (ptr->link != NULL) ptr = ptr->link;
    ptr->link = newNode;
    return head;
}

struct node *insertAtPosition(struct node *head, int x, int pos) {
    if (pos < 1) return head;
    if (pos == 1) return addAtBeginning(head, x);
    struct node *ptr = head;
    int i = 1;
    while (ptr != NULL && i < pos - 1) { // find pos-1
        ptr = ptr->link;
        i++;
    }
    if (ptr == NULL) return head; // strict invalid-position check
    struct node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) return head;
    newNode->data = x;
    newNode->link = ptr->link; // IMPORTANT: connect forward FIRST
    ptr->link = newNode;
    return head;
}

struct node *deleteFirst(struct node *head) {
    if (head == NULL) return NULL;
    struct node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

struct node *deleteLast(struct node *head) {
    if (head == NULL) return NULL;
    if (head->link == NULL) { // one node
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    struct node *prev = NULL;
    while (ptr->link != NULL) {
        prev = ptr;       // track node before ptr
        ptr = ptr->link;  // advance ptr
    }
    prev->link = NULL;
    free(ptr);
    return head;
}

struct node *deleteAtPosition(struct node *head, int pos) {
    if (head == NULL || pos < 1) return head;
    if (pos == 1) return deleteFirst(head);
    struct node *prev = head;
    for (int i = 1; i < pos - 1 && prev != NULL; i++)
        prev = prev->link;
    if (prev == NULL || prev->link == NULL) return head;
    struct node *temp = prev->link;
    prev->link = temp->link; // bypass target
    free(temp);
    return head;
}

struct node *reverseList(struct node *head) {
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    while (curr != NULL) {
        next = curr->link; // SAVE
        curr->link = prev; // REVERSE
        prev = curr;       // MOVE
        curr = next;       // MOVE
    }
    return prev;            // new head
}

int countNodes(const struct node *head) {
    int count = 0;
    while (head != NULL) { count++; head = head->link; }
    return count;
}

void printList(const struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

struct node *createList(struct node *head) {
    int n, x;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) return head;
    for (int i = 1; i <= n; i++) {
        printf("Node %d: ", i);
        if (scanf("%d", &x) != 1) break;
        head = addAtEnd(head, x);
    }
    return head;
}

int main(void) {
    struct node *head = NULL;
    head = addAtEnd(head, 10);
    head = addAtEnd(head, 20);
    head = addAtEnd(head, 30);
    head = addAtBeginning(head, 5);
    head = insertAtPosition(head, 15, 3);
    printList(head); // 5 10 15 20 30
    printf("Count: %d\n", countNodes(head));
    head = deleteFirst(head);
    head = deleteLast(head);
    head = deleteAtPosition(head, 2);
    printList(head); // 10 20
    head = reverseList(head);
    printList(head); // 20 10
    while (head != NULL) head = deleteFirst(head);
    return 0;
}
```

### 04_doubly_linked_list.c: Doubly linked list: key operations

*Basis: Linked List, pp. 38-46*

```c
/* Lecture 5, pages 38-46. DLL: empty, insert begin/end, delete first/last, reverse. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *addToEmpty(struct Node *head, int x) {
    if (head != NULL) return head;
    struct Node *temp = malloc(sizeof *temp);
    if (!temp) return head;
    temp->prev = NULL;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct Node *addAtBeg(struct Node *head, int x) {
    struct Node *temp = malloc(sizeof *temp);
    if (!temp) return head;
    temp->prev = NULL;
    temp->data = x;
    temp->next = head;
    if (head != NULL) head->prev = temp; // guard for empty list
    return temp;
}

struct Node *addAtEnd(struct Node *head, int x) {
    if (head == NULL) return addToEmpty(head, x);
    struct Node *temp = malloc(sizeof *temp);
    if (!temp) return head;
    temp->data = x;
    temp->next = NULL;
    struct Node *ptr = head;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct Node *delFirst(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

struct Node *delLast(struct Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) { free(head); return NULL; }
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node *reverseList(struct Node *head) {
    struct Node *curr = head, *tmp = NULL;
    while (curr != NULL) {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }
    if (tmp != NULL) head = tmp->prev;
    return head;
}

void printForward(const struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printBackward(const struct Node *head) {
    if (head == NULL) { printf("\n"); return; }
    while (head->next != NULL) head = head->next;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

struct Node *createList(struct Node *head) {
    int n, x;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) return head;
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        if (scanf("%d", &x) != 1) break;
        head = addAtEnd(head, x);
    }
    return head;
}

int main(void) {
    struct Node *head = NULL;
    head = addToEmpty(head, 45);
    head = addAtBeg(head, 34);
    head = addAtEnd(head, 9);
    printForward(head);  // 34 45 9
    printBackward(head); // 9 45 34
    head = delFirst(head);
    head = delLast(head);
    printForward(head);  // 45
    head = addAtEnd(head, 12);
    head = reverseList(head);
    printForward(head);  // 12 45
    while (head != NULL) head = delFirst(head);
    return 0;
}
```

### 05_stack_array.c: Array stack: push, pop, peek

*Basis: Stack, pp. 11-22*

```c
/* Lecture 6, pages 11-22. Stack using array; LIFO. */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int A[MAX_SIZE];
int top = -1;

int isEmpty(void) { return top == -1; }
int isFull(void) { return top == MAX_SIZE - 1; }

void push(int x) {
    if (isFull()) { printf("Stack Overflow\n"); return; }
    A[++top] = x;
}

int pop(void) {
    if (isEmpty()) { printf("Stack Underflow\n"); exit(1); }
    return A[top--];
}

int peek(void) {
    if (isEmpty()) { printf("Stack is empty\n"); exit(1); }
    return A[top];
}

void printStack(void) {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) printf("%d ", A[i]);
    printf("\n");
}

int main(void) {
    push(2); printStack();
    push(5); printStack();
    push(10); printStack();
    printf("Popped: %d\n", pop()); printStack();
    push(12); printStack();
    printf("Peek: %d\n", peek());
    return 0;
}
```

### 06_stack_linked_list.c: Linked-list stack

*Basis: Stack, pp. 24-35*

```c
/* Lecture 6, pages 24-35. Stack using linked list. */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *top = NULL;

int isEmpty(void) { return top == NULL; }

void push(int x) {
    struct Node *temp = malloc(sizeof *temp);
    if (temp == NULL) { printf("Memory allocation failed\n"); return; }
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(void) {
    if (isEmpty()) { printf("Stack Underflow\n"); exit(1); }
    struct Node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int peek(void) {
    if (isEmpty()) { printf("Stack empty\n"); exit(1); }
    return top->data;
}

void printStack(void) {
    struct Node *ptr = top;
    printf("top -> ");
    while (ptr != NULL) { printf("%d -> ", ptr->data); ptr = ptr->next; }
    printf("NULL\n");
}

int main(void) {
    push(30); push(12); push(47);
    printStack();
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printStack();
    printf("Peek: %d\n", peek());
    while (!isEmpty()) pop();
    return 0;
}
```

### 07_balanced_symbols.c: Balanced symbols using stack

*Basis: Stack, pp. 39-44*

```c
/* Lecture 6, pages 39-44. Balanced (), [], {} using a stack. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isOpening(char c) { return c == '(' || c == '[' || c == '{'; }
int isClosing(char c) { return c == ')' || c == ']' || c == '}'; }
int matches(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

int isBalanced(const char *exp) {
    size_t n = strlen(exp);
    char *stack = malloc(n + 1);
    if (stack == NULL) { fprintf(stderr, "Out of memory\n"); exit(1); }
    size_t top = 0;
    for (size_t i = 0; i < n; i++) {
        char c = exp[i];
        if (isOpening(c)) stack[top++] = c;
        else if (isClosing(c)) {
            if (top == 0 || !matches(stack[top - 1], c)) {
                free(stack);
                return 0;
            }
            top--; // pop matching opener
        }
    }
    int ok = (top == 0);
    free(stack);
    return ok;
}

int main(void) {
    const char *a = "[(p+q)*(r-s)]";
    const char *b = "{(a+b]}";
    printf("%s -> %s\n", a, isBalanced(a) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", b, isBalanced(b) ? "Balanced" : "Not Balanced");
    return 0;
}
```

### 08_infix_to_postfix.c: Infix to postfix using stack

*Basis: Stack, pp. 46-51*

```c
/* Lecture 6, pages 46-51. Infix to postfix (single-letter/digit operands).
 * Follows the slide's operator-stack algorithm; also handles right-associative ^. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int isOperator(char c) { return c=='+' || c=='-' || c=='*' || c=='/' || c=='^'; }

int infixToPostfix(const char *exp, char *out, size_t cap) {
    char stack[MAX];
    int top = -1;
    size_t k = 0;
    for (size_t i = 0; exp[i]; i++) {
        char t = exp[i];
        if (isspace((unsigned char)t)) continue;
        if (isalnum((unsigned char)t)) {
            if (k + 1 >= cap) return 0;
            out[k++] = t;
        } else if (t == '(') {
            if (top == MAX - 1) return 0;
            stack[++top] = t;
        } else if (t == ')') {
            while (top >= 0 && stack[top] != '(') {
                if (k + 1 >= cap) return 0;
                out[k++] = stack[top--];
            }
            if (top < 0) return 0; // unmatched )
            top--; // discard (
        } else if (isOperator(t)) {
            while (top >= 0 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(t) ||
                  (precedence(stack[top]) == precedence(t) && t != '^'))) {
                if (k + 1 >= cap) return 0;
                out[k++] = stack[top--];
            }
            if (top == MAX - 1) return 0;
            stack[++top] = t;
        } else return 0; // unsupported character
    }
    while (top >= 0) {
        if (stack[top] == '(') return 0; // unmatched (
        if (k + 1 >= cap) return 0;
        out[k++] = stack[top--];
    }
    out[k] = '\0';
    return 1;
}

int main(void) {
    char out[MAX];
    const char *exp = "A*(B+C)-D";
    if (infixToPostfix(exp, out, sizeof out))
        printf("Infix: %s\nPostfix: %s\n", exp, out); // ABC+*D-
    else printf("Invalid expression\n");
    return 0;
}
```

### 09_queue_simple_array.c: Simple array queue

*Basis: Queue, pp. 11-17*

```c
/* Lecture 7, pages 11-17. Simple (linear) array queue. FIFO. */
#include <stdio.h>
#include <stdlib.h>
#define N 5

int A[N];
int front = -1, rear = -1;

int isEmpty(void) { return front == -1 && rear == -1; }
int isFull(void) { return rear == N - 1; }

void enqueue(int x) {
    if (isFull()) { printf("Queue Overflow\n"); return; }
    if (isEmpty()) front = rear = 0;
    else rear++;
    A[rear] = x;
}

int dequeue(void) {
    if (isEmpty()) { printf("Queue Underflow\n"); exit(1); }
    int x = A[front];
    if (front == rear) front = rear = -1; // last element removed
    else front++;
    return x;
}

int peek(void) {
    if (isEmpty()) { printf("Queue empty\n"); exit(1); }
    return A[front];
}

void printQueue(void) {
    if (isEmpty()) { printf("Queue empty\n"); return; }
    for (int i = front; i <= rear; i++) printf("%d ", A[i]);
    printf("\n");
}

int main(void) {
    enqueue(10); enqueue(20); enqueue(30);
    printQueue();
    printf("Dequeued: %d\n", dequeue());
    enqueue(40); enqueue(50); enqueue(60);
    printQueue();
    printf("Front: %d\n", peek());
    // Important limitation: unused slots before front cannot be reused
    // until queue becomes completely empty.
    return 0;
}
```

### 10_queue_circular_array.c: Circular array queue

*Basis: Queue, pp. 18-24*

```c
/* Lecture 7, pages 18-24. Circular array queue. */
#include <stdio.h>
#include <stdlib.h>
#define N 5

int A[N];
int front = -1, rear = -1;

int isEmpty(void) { return front == -1 && rear == -1; }
int isFull(void) { return (rear + 1) % N == front; }

void enqueue(int x) {
    if (isFull()) { printf("Circular Queue Overflow\n"); return; }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % N;
    A[rear] = x;
}

int dequeue(void) {
    if (isEmpty()) { printf("Queue Underflow\n"); exit(1); }
    int x = A[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % N;
    return x;
}

int peek(void) {
    if (isEmpty()) { printf("Queue empty\n"); exit(1); }
    return A[front];
}

void printQueue(void) {
    if (isEmpty()) { printf("Queue empty\n"); return; }
    int i = front;
    while (1) {
        printf("%d ", A[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main(void) {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);
    printQueue();
    int first = dequeue();
    int second = dequeue();
    printf("Removed: %d %d\n", first, second);
    enqueue(60); enqueue(70); // wrap around
    printQueue();
    printf("front=%d rear=%d\n", front, rear);
    return 0;
}
```

### 11_queue_linked_list.c: Linked-list queue

*Basis: Queue, pp. 27-34*

```c
/* Lecture 7, pages 27-34. Linked-list queue, front and rear pointers. */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *front = NULL, *rear = NULL;

int isEmpty(void) { return front == NULL; }

void enqueue(int x) {
    struct Node *temp = malloc(sizeof *temp);
    if (temp == NULL) { printf("Memory allocation failed\n"); return; }
    temp->data = x;
    temp->next = NULL;
    if (front == NULL) front = rear = temp;
    else { rear->next = temp; rear = temp; }
}

int dequeue(void) {
    if (front == NULL) { printf("Queue Underflow\n"); exit(1); }
    struct Node *temp = front;
    int x = temp->data;
    if (front == rear) front = rear = NULL; // IMPORTANT: one node
    else front = front->next;
    free(temp);
    return x;
}

int peek(void) {
    if (front == NULL) { printf("Queue empty\n"); exit(1); }
    return front->data;
}

void printQueue(void) {
    struct Node *ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(void) {
    enqueue(10); enqueue(20); enqueue(30);
    printQueue();
    printf("Dequeued: %d\n", dequeue());
    printQueue();
    printf("Front: %d\n", peek());
    while (!isEmpty()) dequeue();
    printf("front=%p rear=%p\n", (void *)front, (void *)rear);
    return 0;
}
```

### 12_recursion_patterns.c: Recursion: hello/bye, up/down

*Basis: Iterative vs Recursive, pp. 2-11*

```c
/* Lecture 8, pages 2-11. Recursion, print before/after, downward/upward. */
#include <stdio.h>

void helloOnly(int n) {
    if (n == 0) return;
    printf("Hello World\n");
    helloOnly(n - 1);
}

void helloAndGoodbye(int n) {
    if (n == 0) return;
    printf("Hello World\n");
    helloAndGoodbye(n - 1); // PAUSE here until child call returns
    printf("Biday Prithibi\n"); // executes during UNWIND
}

void printDown(int n) {
    if (n == 0) return;
    printf("%d\n", n);
    printDown(n - 1);
}

void printUp(int n) {
    if (n == 0) return;
    printUp(n - 1);
    printf("%d\n", n);
}

int main(void) {
    puts("Hello only:"); helloOnly(2);
    puts("Hello and Goodbye:"); helloAndGoodbye(2);
    puts("Downward:"); printDown(3);
    puts("Upward:"); printUp(3);
    return 0;
}
```

### 13_fibonacci_methods.c: Fibonacci: iterative, recursive, memoized

*Basis: Iterative vs Recursive, pp. 12-17*

```c
/* Lecture 8, pages 12-17. Fibonacci: iterative, recursive, memoization. */
#include <stdio.h>
#define MAX_N 50

long long F[MAX_N + 1]; // long long prevents int overflow for fib(47..50)

long long fibIterative(int n) {             // O(n) time, O(1) space
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fibRecursive(int n) {             // O(2^n) upper bound
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

void init(void) {
    for (int i = 0; i <= MAX_N; i++) F[i] = -1;
}

long long fibMemo(int n) {                  // O(n) time, O(n) space
    if (F[n] != -1) return F[n];
    if (n <= 1) { F[n] = n; return n; }
    F[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return F[n];
}

int main(void) {
    int n = 10;
    if (n < 0 || n > MAX_N) return 1;
    init(); // IMPORTANT: before fibMemo!
    printf("fib(%d) iterative = %lld\n", n, fibIterative(n));
    printf("fib(%d) recursive = %lld\n", n, fibRecursive(n));
    printf("fib(%d) memoized = %lld\n", n, fibMemo(n));
    printf("fib(50) memoized = %lld\n", fibMemo(50));
    return 0;
}
```

### 14_linked_list_manual_creation.c: Manual list creation, two methods

*Basis: Linked List, pp. 7, 9-10*

```c
/* Lecture 5, pages 7, 9-10. Two methods for manually creating 45 -> 98 -> 3. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *link; };

struct node *makeNode(int data) {
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Allocation failed\n"); exit(1); }
    n->data = data;
    n->link = NULL;
    return n;
}

struct node *method1(void) {
    struct node *head = makeNode(45);
    struct node *n2 = makeNode(98);
    head->link = n2;
    struct node *n3 = makeNode(3);
    n2->link = n3;
    return head;
}

struct node *method2(void) {
    struct node *head = makeNode(45);
    struct node *current = makeNode(98);
    head->link = current;
    current = makeNode(3); // reuse local pointer, old node still linked
    head->link->link = current;
    return head;
}

void showAndFree(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
    printf("\n");
}

int main(void) {
    showAndFree(method1());
    showAndFree(method2());
    return 0;
}
```

