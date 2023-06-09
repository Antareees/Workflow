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

void del_node(list *&h, list *&t, list *r)
{                         // удаляем после r
    if (r == h && r == t) // единственный элемент списка
        h = t = NULL;
    else if (r == h)
    {                // удаляем голову списка
        h = h->next; // сдвигаем голову
        h->prev = NULL;
    }
    else if (r == t)
    {                // удаляем хвост списка
        t = t->prev; // сдвигаем хвост
        t->next = NULL;
    }
    else
    {
        r->next->prev = r->prev; // для следующего от r предыдущим становится r->prev
        r->prev->next = r->next; // для предыдущего от r следующим становится r->next
    }
    delete r;
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
    push(h, t, 1);
    push(h, t, 2);
    push(h, t, 3);
    push(h, t, 4);
    push(h, t, 5);
    push(h, t, 6);
    push(h, t, 7);
    push(h, t, 8);
    push(h, t, 9);
    list *p = h;
    list *res = NULL;
    list *res_t = NULL;
    while (p)
    {
        if (p->inf % 2 == 0)
        {
            push(res, res_t, p->inf);
        }
        p = p->next;
    }
    list *p1 = h;
    while (p1)
    {
        if (p1->inf % 2 == 1)
        {
            push(res, res_t, p1->inf);
        }
        p1 = p1->next;
    }
    h = res;
    t = res_t;
    print(h, t);
}