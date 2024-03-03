#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
struct stack {
	stack* next; int data;
};
struct queue {
	stack* head{}; stack* tail{};
};
void PrintStack(stack* head);
void FillInc(stack** head, int n);
void FillDec(stack** head, int n);
void FillRand(stack** head, int n);
int CheckSum(stack* head);
int RunNumber(stack* head);
void Merge(stack* a, int q, stack* b, int r, stack** c_tail);
int C = 0, M = 0;

int main() {
	stack* a, * b;
	queue c;
	a = NULL, b = NULL;
	int q, r;
	cout<< "q=: ";
	cin >> q;
	FillRand(&a, q);
	PrintStack(a);
	cout<< "Sum = " << CheckSum(a) << endl; cout << "series = " << RunNumber(a) << endl; cout << "r=: ";
	cin >> r;
	FillRand(&b, r);
	PrintStack(b);
	cout << "Sum = " << CheckSum(b) << endl;
	cout << "series = " << RunNumber(b) << endl;
	c.tail = (stack*)&c.head;
	cout << "Merge" << endl;
	Merge(a, q, b, r, &c.tail);
	PrintStack(c.head);
	cout << "Sum = " << CheckSum(c.head) << endl; cout << "series = " << RunNumber(c.head)<< endl;
	cout << "\nfact\nC=" << C << "\nM=" << M;
	return 0;
}
void PrintStack(stack* head) {
	stack* p = head; while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void FillInc(stack** head, int n) {
	stack* p;
	for (int i = n - 1; i > -1;i--) {
		p = new stack;
		p->data = i;
		p->next = *head;
		*head = p;
	}
}

void FillDec(stack** head, int n) {
	stack* p;
	for (int i = 0; i < n; ++i) {
		p = new stack;
		p->data = i;
		p->next = *head; *head = p;
	}
}
void FillRand(stack** head, int n) {
	stack* p;
	srand(time(nullptr));
	for (int i = 0; i < n; ++i) {
		p = new stack;
		p->data = rand() % (2 * n); p->next = *head;
		*head = p;
	}
}
int CheckSum(stack* head) {
	int sum = 0;
	stack* p = head;
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}
int RunNumber(stack* head) {
	int i = 1;
	stack* p = head; while (p->next) {
		if (p->data > p->next->data) {
			i += 1;
		}
		p = p->next;
	}
	return i;
}
void Merge(stack* a, int q, stack* b, int r, stack** c_tail) {

	stack* p_tail = *c_tail; while (q != 0 && r != 0) {
		C++;
		if (a->data <= b->data) {
			p_tail->next = a; p_tail = a;
			a = a->next; ++M;
			--q;
		}
		else {
			p_tail->next = b; p_tail = b;
			b = b->next;
			++M;
			--r;
		}
	}
	while (q > 0) {
		p_tail->next = a; p_tail = a;
		a = a->next; ++M;
		--q;
	}
	while (r > 0) {
		++M;
		p_tail->next = b; p_tail = b;
		b = b->next;
		--r;
	}
}
