#include <iostream>
#include <string.h>
using namespace std;

typedef struct st { char f[10]; int a; int b; int c; int d; struct st* next; };

st* create(int n)
{
	st* p, * pred, * h;
	h = new st;
	pred = h;

	for (int i = 0; i < n; i++)
	{
		p = new st;
		p->next = NULL;
		cin >> p->f >> p->a >> p->b >> p->c >> p->d;
		pred->next = p;
		pred = p;
	}
	return h->next;
}

void sort(st** head, int n)
{
	st* cur;
	st* next;
	st* prev = NULL;
	int unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		cur = *head;
		while (cur != NULL && cur->next != NULL)
		{
			next = cur->next;
			if (strcmp(cur->f, next->f) > 0)
			{
				int a, b, c, d;
				char f[10];
				a = cur->a;
				b = cur->b;
				c = cur->c;
				d = cur->d;
				strcpy_s(f, cur->f);
				cur->a = next->a;
				cur->b = next->b;
				cur->c = next->c;
				cur->d = next->d;
				strcpy_s(cur->f, next->f);
				next->a = a;
				next->b = b;
				next->c = c;
				next->d = d;
				strcpy_s(next->f, f);
				unsorted = 1;
			}
			cur = cur->next;
		}
	}

}

void printst(st* head)
{
	st* p;
	p = head;
	while (p != NULL)
	{
		cout << p->f << p->a << p->b << p->c << p->d;
		p = p->next;
		cout << endl;
	}
	cout << "\n\n";
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n = 0;
	cout << "������� �������?";
	cin >> n;
	st* head;
	head = create(n);
	printst(head);
	sort(&head, n);
	printst(head);



	return 0;
}
