#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct list
{
    int inf;
    list *next;
    list *prev;
};

int last(list *h)
{
    list *p = h; // укзатель на голову
    int l = 0;
    while (p)
    { // пока не дошли до конца списка
        if (p->inf % 2 == 0)
            l = p->inf;
        p = p->next;
    }
    return l;
}

void push(list *&h, int x)
{                       // вставка элемента в конец списка
    list *r = new list; // создаем новый элемент
    r->inf = x;
    r->next = h; // всегда последний
    r->prev = h->prev;       // первый элемент
    h->prev = r;
    r->prev->next = r;
}

list *find(list *h, int k)
{                // печать элементов списка
    list *p = h; // укзатель на голову
    for (int i = 0; i < k; i++)
    {
        p = p->next; // переход к следующему элементу
    }
    return p; // возвращаем указатель
}

void insert_after(list *&r, int y)
{                       // вставляем после r
    list *p = new list; // создаем новый элемент
    p->inf = y;         // вставляем в середину списка
    r->next->prev = p;  // для следующего за r эл-та предыдущий - p
    p->next = r->next;  // следующий за p - следующий за r
    p->prev = r;        // p вставляем после r
    r->next = p;
}

void del_node(list *&h, list *r)
{
    if (r == h)
    { // удаляем голову списка
        h = h->next;
    }
    r->prev->next = r->next;
    r->next->prev = r->prev;
    delete r; // удаляем r
}

void print(list *h)
{                // печать элементов списка
    list *p = h; // укзатель на голову
    cout << h->inf << " ";
    p = h->next;
    while (p != h)
    { // пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; // переход к следующему элементу
    }
    cout << endl;
}

int main()
{
    list *h = new list;
    int n, q, k;
    cin >> n >> q;
    h->inf = q;
    h->next = h;
    h->prev = h;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> q;
        push(h, q);
    }
    print(h);
    cin >> k;
    while (h->next != h)
    {
        del_node(h, find(h, k));
        print(h);
    }
    print(h);
}