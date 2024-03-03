#include <cmath>

#include <ctime>

#include <iostream>

using namespace std;

struct stack {

stack *next;

int data;

};

struct queue {

stack *head{};

stack *tail{};

};

void PrintList(stack *head);

void FillInc(stack** head, int n);

void FillDec(stack **head, int n);

void FillRand(stack **head, int n);

int CheckSum(stack *head);

int RunNumber(stack *head);

void Merge(stack *a, int q, stack *b, int r, stack **c_tail);

int C = 0, M = 0;

int main() {

stack *head_a, *head_b, *head;

queue head_c;

head_a = NULL, head_b = NULL;

int q, r;

cout << "q=: ";

cin >> q;

FillInc(&head_a, q);

PrintList(head_a);

cout << "Sum = " << CheckSum(head_a) << endl;

cout << "series = " << RunNumber(head_a) << endl;

cout << "r=: ";

cin >> r;

FillInc(&head_b, r);

PrintList(head_b);

cout << "Sum = " << CheckSum(head_b) << endl;

cout << "series = " << RunNumber(head_b) << endl;

head_c.tail = (stack *) &head_c.head;

cout << "Merge" << endl;

Merge(head_a, q, head_b, r, &head_c.tail);

PrintList(head_c.head);

cout << "Sum = " << CheckSum(head_c.head) << endl;

cout << "series = " << RunNumber(head_c.head) << endl;

C = 0, M = 0;

return 0;

}

void PrintList(stack *head) {

stack *p = head;

while (p) {

cout << p->data << " ";

p = p->next;

}

cout << endl;

}

void FillInc(stack** head, int n) {

stack* p;

for (int i = n - 1; i > -1; --i) {

p = new stack;

p->data = i;

p->next = *head;

*head = p;

}

}

void FillDec(stack **head, int n) {

stack *p;

for (int i = 0; i < n; ++i) {

p = new stack;

p->data = i;

p->next = *head;

*head = p;

}

}

void FillRand(stack **head, int n) {

stack *p;

srand(time(nullptr));

for (int i = 0; i < n; ++i) {

p = new stack;

p->data = rand() % (2 * n);

p->next = *head;

*head = p;

}

}

int CheckSum(stack *head) {

int sum = 0;

stack *p = head;

while (p) {

sum += p->data;

p = p->next;

}

return sum;

}

int RunNumber(stack *head) {

int i = 1;

stack *p = head;

while (p->next) {

if (p->data > p->next->data) {

i+=1;

}

p = p->next;

}

return i;

}

void Merge(stack *a, int q, stack *b, int r, stack **c_tail) {

stack *p_tail = *c_tail;

while (q != 0 && r != 0) {

++C;

if (a->data <= b->data) {

p_tail->next = a;

p_tail = a;

a = a->next;

++M;

--q;

} else {

p_tail->next = b;

p_tail = b;

b = b->next;

++M;

--r;

}

}

while (q > 0) {

p_tail->next = a;

p_tail = a;

a = a->next;

++M;

--q;

}

while (r > 0) {

++M;

p_tail->next = b;

p_tail = b;

b = b->next;

--r;

}

}
