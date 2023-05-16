#include <iostream>
#include <vector>

using namespace std;

struct tree
{
    int inf;
    tree *left;
    tree *right;
    tree *parent;
};

tree *node(int x)
{ // РЅР°С‡Р°Р»СЊРЅС‹Р№ СѓР·РµР»
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void inorder(tree *tr) // СЃРёРјРјРµС‚СЂРёС‡РЅС‹Р№ РѕР±С…РѕРґ (Р›-Рљ-Рџ)
{
    if (tr)
    {
        inorder(tr->left);      // Р»РµРІРѕРµ
        cout << tr->inf << ' '; // РєРѕСЂРµРЅСЊ
        inorder(tr->right);     // РїСЂР°РІРѕРµ
    }
}

void insert(tree *&tr, int x) // РІСЃС‚Р°РІРєР°
{
    tree *n = node(x);
    if (!tr)
        tr = n; // РµСЃР»Рё РґРµСЂРµРІРѕ РїСѓСЃС‚РѕРµ - РєРѕСЂРµРЅСЊ
    else
    {
        tree *y = tr;
        while (y)
        {                        // РёС‰РµРј РєСѓРґР° РІСЃС‚Р°РІР»СЏС‚СЊ
            if (n->inf > y->inf) // РїСЂР°РІР°СЏ РІРµС‚РєР°
                if (y->right)
                    y = y->right;
                else
                {
                    n->parent = y; // СѓР·РµР» СЃС‚Р°РЅРѕРІРёС‚СЃСЏ РїСЂР°РІС‹Рј СЂРµР±РµРЅРєРѕРј
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf) // Р»РµРІР°СЏ РІРµС‚РєР°
                if (y->left)
                    y = y->left;
                else
                {
                    n->parent = y; // СѓР·РµР» СЃС‚Р°РЅРѕРІРёС‚СЃСЏ Р»РµРІС‹Рј СЂРµР±РµРЅРєРѕРј
                    y->left = n;
                    break;
                }
        }
    }
}

tree *find(tree *tr, int x)
{                            // РїРѕРёСЃРє
    if (!tr || x == tr->inf) // РЅР°С€Р»Рё РёР»Рё РґРѕС€Р»Рё РґРѕ РєРѕРЅС†Р° РІРµС‚РєРё
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); // РёС‰РµРј РїРѕ Р»РµРІРѕР№ РІРµС‚РєРµ
    else
        return find(tr->right, x); // РёС‰РµРј РїРѕ РїСЂР°РІРѕР№ РІРµС‚РєРµ
}

tree *Min(tree *tr)
{ // РїРѕРёСЃРє min
    if (!tr->left)
        return tr; // РЅРµС‚ Р»РµРІРѕРіРѕ СЂРµР±РµРЅРєР°
    else
        return Min(tr->left); // РёРґРµРј РїРѕ Р»РµРІРѕР№ РІРµС‚РєРµ РґРѕ РєРѕРЅС†Р°
}

tree *Next(tree *tr, int x)
{ // РїРѕРёСЃРє СЃР»РµРґСѓСЋС‰РµРіРѕ
    tree *n = find(tr, x);

    if (n->right)             // РµСЃР»Рё РµСЃС‚СЊ РїСЂР°РІС‹Р№ СЂРµР±РµРЅРѕРє
        return Min(n->right); // min РїРѕ РїСЂР°РІРѕР№ РІРµС‚РєРµ
    tree *y = n->parent;      // СЂРѕРґРёС‚РµР»СЊ
    while (y && n == y->right)
    {          // РїРѕРєР° РЅРµ РґРѕС€Р»Рё РґРѕ РєРѕСЂРЅСЏ РёР»Рё СѓР·РµР» - РїСЂР°РІС‹Р№ СЂРµР±РµРЅРѕРє
        n = y; // РёРґРµРј РІРІРµСЂС… РїРѕ РґРµСЂРµРІСѓ
        y = y->parent;
    }
    return y; // РІРѕР·РІСЂР°С‰Р°РµРј СЂРѕРґРёС‚РµР»СЏ
}

void Delete(tree *&tr, tree *v)
{ // СѓРґР°Р»РµРЅРёРµ СѓР·Р»Р°
    tree *p = v->parent;
    // if (!p)
    //    tr = NULL; // РґРµСЂРµРІРѕ СЃРѕРґРµСЂР¶РёС‚ РѕРґРёРЅ СѓР·РµР»
    if (!v->left && !v->right)
    {                     // РµСЃР»Рё РЅРµС‚ РґРµС‚РµР№
        if (p->left == v) // СѓРєР°Р·Р°С‚РµР»СЊ Сѓ СЂРѕРґРёС‚РµР»СЏ РјРµРЅСЏРµРј РЅР° NULL
            p->left = NULL;
        if (p->right == v)
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right)
    { // РµСЃР»Рё С‚РѕР»СЊРєРѕ РѕРґРёРЅ СЂРµР±РµРЅРѕРє
        if (!p)
        { // РµСЃР»Рё СѓРґР°Р»СЏРµРј РєРѕСЂРµРЅСЊ, Сѓ РєРѕС‚РѕСЂРѕРіРѕ 1 СЂРµР±РµРЅРѕРє
            if (!v->left)
            {                  // РµСЃР»Рё РµСЃС‚СЊ РїСЂР°РІС‹Р№ СЂРµР±РµРЅРѕРє
                tr = v->right; // РѕРЅ СЃС‚Р°РЅРѕРІРёС‚СЃСЏ РєРѕСЂРЅРµРј
                v->parent = NULL;
            }
            else
            { // Р°РЅР°Р»РѕРіРёС‡РЅРѕ РґР»СЏ Р»РµРІРѕРіРѕ
                tr = v->left;
                v->parent = NULL;
            }
        }
        else
        {
            if (!v->left)
            {                           // РµСЃР»Рё РµСЃС‚СЊ РїСЂР°РІС‹Р№ СЂРµР±РµРЅРѕРє
                if (p->left == v)       // РµСЃР»Рё СѓРґР°Р»СЏРµРјС‹Р№ СѓР·РµР» СЏРІР». Р»РµРІС‹Рј СЂРµР±РµРЅРєРѕРј
                    p->left = v->right; // СЂРµР±РµРЅРѕРє СѓРґР°Р»СЏРµРјРѕРіРѕ СѓР·Р»Р° СЃС‚Р°РЅРѕРІРёС‚СЃСЏ Р»РµРІС‹Рј СЂРµР±РµРЅРєРѕРј СЃРІРѕРµРіРѕ "РґРµРґР°"
                else
                    p->right = v->right; ////СЂРµР±РµРЅРѕРє СѓРґР°Р»СЏРµРјРѕРіРѕ СѓР·Р»Р° СЃС‚Р°РЅРѕРІРёС‚СЃСЏ РїСЂР°РІС‹Рј СЂРµР±РµРЅРєРѕРј СЃРІРѕРµРіРѕ "РґРµРґР°"
                v->right->parent = p;    // СЂРѕРґРёС‚РµР»РµРј СЂРµР±РµРЅРєР° СЃС‚Р°РЅРѕРІРёС‚СЃСЏ РµРіРѕ "РґРµРґ"
            }
            else
            { // Р°РЅР°Р»РѕРіРёС‡РЅРѕ РґР»СЏ Р»РµРІРѕРіРѕ СЂРµР±РµРЅРєР°
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
            delete v;
        }
    }
    else
    {                                  // РµСЃС‚СЊ РѕР±Р° СЂРµР±РµРЅРєР°
        tree *succ = Next(tr, v->inf); // СЃР»РµРґСѓСЋС‰РёР№ Р·Р° СѓРґР°Р»СЏРµРјС‹Рј СѓР·Р»РѕРј
        v->inf = succ->inf;            // РїСЂРёСЃРІР°РёРІР°РµРј Р·РЅР°С‡РµРЅРёРµ
        if (succ->parent->left == succ)
        {                                           // РµСЃР»Рё succ Р»РµРІС‹Р№ СЂРµР±РµРЅРѕРє
            succ->parent->left = succ->right;       // РµРіРѕ РїСЂР°РІС‹Р№ СЂРµР±РµРЅРѕРє СЃС‚Р°РЅРѕРІРёС‚СЃСЏ Р»РµРІС‹Рј СЂРµР±РµРЅРєРѕРј СЃРІРѕРµРіРѕ "РґРµРґР°"
            if (succ->right)                        // РµСЃР»Рё СЌС‚РѕС‚ СЂРµР±РµРЅРѕРє СЃСѓС‰РµСЃС‚РІСѓРµС‚
                succ->right->parent = succ->parent; // РµРіРѕ СЂРѕРґРёС‚РµР»РµРј СЃС‚Р°РЅРѕРІРёС‚СЃСЏ "РґРµРґ"
        }
        else
        { // Р°РЅР°Р»РѕРіРёС‡РЅРѕ РµСЃР»Рё succ - РїСЂР°РІsq СЂРµР±РµРЅРѕРє
            succ->parent->right = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        delete succ;
    }
}

int main()
{
    int n, q, x;
    cin >> n;
    tree *tr = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        insert(tr, q);
    }
    inorder(tr);
    cout << endl;
    cin >> x;
    while (tr->inf != x)
    {
        cout << tr->inf << " ";
        if (x<tr->inf)
            tr = tr->left;
        else 
            tr = tr->right;
    }
    cout << tr->inf;
}
/*
10
5 3 7 1 9 4 2 8 6 0
            5
         /     \         
        3       7
       / \    /  \
      1   4   6   9
     / \         /
    0   2       8
*/