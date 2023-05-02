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

int minimum(list *h)
{
    list *p = h; // укзатель на голову
    int min = p->inf;
    while (p)
    { // пока не дошли до конца списка
        if (p->inf < min)
            min = p->inf;
        p = p->next;
    }
    return min;
}

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

void push(list *&h, list *&t, int x)
{                       // вставка элемента в конец списка
    list *r = new list; // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t)
    {                   // если список пуст
        r->prev = NULL; // первый элемент
        h = r;          // это голова
    }
    else
    {
        t->next = r; // r - следующий для хвоста
        r->prev = t; // хвост - предыдущий для r
    }
    t = r; // r теперь хвост
}

list *find(list *h, list *t, int x)
{                // печать элементов списка
    list *p = h; // укзатель на голову
    while (p)
    { // пока не дошли до конца списка
        if (p->inf == x)
            break;   // если нашли, прекращаем цикл
        p = p->next; // переход к следующему элементу
    }
    return p; // возвращаем указатель
}

void insert_after(list *&h, list *&t, list *r, int y)
{                       // вставляем после r
    list *p = new list; // создаем новый элемент
    p->inf = y;
    if (r == t)
    {                   // если вставляем после хвоста
        p->next = NULL; // вставляемый эл-т - последний
        p->prev = r;    // вставляем после r
        r->next = p;
        t = p; // теперь хвост - p
    }
    else
    {                      // вставляем в середину списка
        r->next->prev = p; // для следующего за r эл-та предыдущий - p
        p->next = r->next; // следующий за p - следующий за r
        p->prev = r;       // p вставляем после r
        r->next = p;
    }
}

void print(list *h, list *t)
{                // печать элементов списка
    list *p = h; // укзатель на голову
    while (p)
    { // пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; // переход к следующему элементу
    }
}

int main()
{
    list *h = NULL, *t = NULL;
    push(h, t, 2);
    push(h, t, 8);
    push(h, t, 2);
    push(h, t, 1);
    push(h, t, 6);
    push(h, t, 8);
    push(h, t, 8);
    push(h, t, 1);
    push(h, t, 2);
    push(h, t, 2);
    push(h, t, 8);
    push(h, t, 2);
    push(h, t, 1);
    list *p = h;
    int m = minimum(h);
    int n = last(h);
    while (p)
    {
        if (p->inf == m)
            insert_after(h, t, p, n);
        p = p->next;
    }
    print(h, t);
}