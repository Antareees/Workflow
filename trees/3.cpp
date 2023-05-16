#include <iostream>

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

void find(tree *tr, int &count)
{
    if (tr)
    {
        if (tr->left == NULL && tr->right == NULL) // РїРѕРґРґРµСЂРµРІСЊСЏ РЅСѓР»РµРІС‹Рµ Р·РЅР°С‡РёС‚ СЌС‚Рѕ Р»РёСЃС‚
        {
            count += 1;
        }
        else
        {
            find(tr->left, count); // СЂРµРєСѓСЂСЃРёРІРЅС‹Р№ РѕР±С…РѕРґ
            find(tr->right, count);
        }
    }
}

int main()
{
    tree *tr = NULL;
    int n, x, count = 0;
    cin >> n;
    create(tr, n);
    cout << endl;
    preorder(tr);
    find(tr, count);
    cout << endl << count;
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
