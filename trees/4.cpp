#include <iostream>
#include <vector>

using namespace std;

struct tree
{
    int inf;
    tree *left;
    tree *right;
};

tree *node(int x)
{
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
}

void create(tree *&tr, int n)
{
    int x;
    if (n > 0)
    {
        cin >> x;
        tr = node(x);
        int nl = n / 2;
        int nr = n - nl - 1;
        create(tr->left, nl);
        create(tr->right, nr);
    }
}

void preorder(tree *tr)
{

    if (tr)
    {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

void find(tree *tr, int k, int n)
{
    if (tr)
    {
        if (k == n)
        {                           // РµСЃР»Рё С‚РµРєСѓС‰РёР№ СѓСЂРѕРІРµРЅСЊ СЃРѕРІРїР°РґР°РµС‚ СЃ Р·Р°РґР°РЅРЅС‹Рј
            cout << tr->inf << ' '; // РІС‹РІРѕРґРёРј
        }
        else
        {
            n++; // РїРµСЂРµС…РѕРґРёРј РЅР° СЃР»РµРґСѓСЋС‰РёРµ РїРѕРґРґРµСЂРµРІСЊСЏ Р·РЅР°С‡РёС‚ РїРѕРІС‹С€Р°РµРј СѓСЂРѕРІРµРЅСЊ
            find(tr->left, k, n);
            find(tr->right, k, n);
        }
    }
}

int main()
{
    tree *tr = NULL;
    int n, k;
    cin >> n;
    cout << endl;
    create(tr, n);
    preorder(tr);
    cout << endl;
    cin >> k;
    find(tr, k, 0);
}
/*
10
4 5 3 7 8 6 9 1 2 0
            4
         /     \
        5       9
      /   \    /  \
     3    8   1    0
    /    /   /
   7    6   2
*/