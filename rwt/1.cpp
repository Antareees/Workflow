// номер 15
#include <iostream>
#include <vector>

using namespace std;

enum RBTColor
{
    Black,
    Red
};
struct RBTNode
{
    int key;
    RBTColor color;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;
    RBTNode(int k, RBTColor c, RBTNode* p, RBTNode*l, RBTNode*r):
    key(k), color(c), parent(p), left(l), right(r) { };
};

void inorder(RBTNode *tr) // СЃРёРјРјРµС‚СЂРёС‡РЅС‹Р№ РѕР±С…РѕРґ (Р›-Рљ-Рџ)
{
    if (tr)
    {
        inorder(tr->left);      // Р»РµРІРѕРµ
        cout << tr->key << '(' << tr->color << ") "; // РєРѕСЂРµРЅСЊ
        inorder(tr->right);     // РїСЂР°РІРѕРµ
    }
}

void res(RBTNode *tr) // СЃРёРјРјРµС‚СЂРёС‡РЅС‹Р№ РѕР±С…РѕРґ (Р›-Рљ-Рџ)
{
    if (tr)
    {
        res(tr->left);      // Р»РµРІРѕРµ
        if (tr->left==NULL && tr->right==NULL)
            cout << tr->key << '(' << tr->color << ") "; // РєРѕСЂРµРЅСЊ
        res(tr->right);     // РїСЂР°РІРѕРµ
    }
}


void leftRotate(RBTNode *&root, RBTNode *x)
{
    RBTNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else
    {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
};

void rightRotate(RBTNode *&root, RBTNode *y)
{
    RBTNode *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else
    {
        if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
};

void InsertFixUp(RBTNode *&root, RBTNode *node)
{
    RBTNode *parent;
    parent = node->parent;
    while (node != root && parent->color == Red)
    {
        RBTNode *gparent = parent->parent;
        if (gparent->left == parent)
        {
            RBTNode *uncle = gparent->right;
            if (uncle != NULL && uncle->color == Red)
            {
                parent->color = Black;
                uncle->color = Black;
                gparent->color = Red;
                node = gparent;
                parent = node->parent;
            }
            else
            {
                if (parent->right == node)
                {
                    leftRotate(root, parent);
                    swap(node, parent);
                }
                rightRotate(root, gparent);
                gparent->color = Red;
                parent->color = Black;
                break;
            }
        }
        else
        {
            RBTNode *uncle = gparent->left;
            if (uncle != NULL && uncle->color == Red)
            {
                gparent->color = Red;
                parent->color = Black;
                uncle->color = Black;

                node = gparent;
                parent = node->parent;
            }
            else
            {
                if (parent->left == node)
                {
                    rightRotate(root, parent);
                    swap(parent, node);
                }
                leftRotate(root, gparent);
                parent->color = Black;
                gparent->color = Red;
                break;
            }
        }
    }
    root->color = Black;
}

void insert(RBTNode *&root, RBTNode *node)
{
    RBTNode *x = root;
    RBTNode *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (node->key > x->key)
            x = x->right;
        else
            x = x->left;
    }
    node->parent = y;
    if (y != NULL)
    {
        if (node->key > y->key)
            y->right = node;
        else
            y->left = node;
    }
    else
        root = node;
    node->color = Red;
    InsertFixUp(root, node);
};

void removeFixUp(RBTNode *&root, RBTNode *node, RBTNode *parent)
{
    RBTNode *othernode;
    while ((!node) || node->color == Black && node != root)
    {
        if (parent->left == node)
        {
            othernode = parent->right;
            if (othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                leftRotate(root, parent);
                othernode = parent->right;
            }
            else
            {
                if (!(othernode->right) || othernode->right->color == Black)
                {
                    othernode->left->color = Black;
                    othernode->color = Red;
                    rightRotate(root, othernode);
                    othernode = parent->right;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->right->color = Black;
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            othernode = parent->left;
            if (othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                rightRotate(root, parent);
                othernode = parent->left;
            }
            if ((!othernode->left | othernode->left->color == Black) && (!othernode->right | othernode->right->color == Black))
            {
                othernode->color = Red;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!(othernode->left) || othernode->left->color == Black)
                {
                    othernode->right->color = Black;
                    othernode->color = Red;
                    leftRotate(root, othernode);
                    othernode = parent->left;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->left->color = Black;
                rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        node->color = Black;
}

void remove(RBTNode *&root, RBTNode *node)
{
    RBTNode *child, *parent;
    RBTColor color;
    // Левый и правый узлы удаленного узла не пусты (не конечные узлы)
    if (node->left != NULL && node->right != NULL)
    {
        RBTNode *replace = node;
        // Найти узел-преемник (самый нижний левый узел правого поддерева текущего узла)
        replace = node->right;
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        // Случай, когда удаленный узел не является корневым узлом
        if (node->parent != NULL)
        {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }
        // Ситуация с корневым узлом
        else
            root = replace;
        // child - это правильный узел, который заменяет узел и является узлом, который требует последующей корректировки
        // Поскольку замена является преемником, он не может иметь левого дочернего узла
        // Аналогично, у узла-предшественника не может быть правого дочернего узла
        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        // Удаленный узел является родительским узлом замещающего узла (repalce)
        if (parent == node)
            parent = replace;
        else
        {
            // Существование дочернего узла
            if (child != NULL)
                child->parent = parent;
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        if (color == Black)
            removeFixUp(root, child, parent);

        delete node;
        return;
    }
    // Когда в удаленном узле только левый (правый) узел пуст, найдите дочерний узел удаленного узла
    if (node->left != NULL)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;
    if (child)
    {
        child->parent = parent;
    }
    // Удаленный узел не является корневым узлом
    if (parent)
    {
        if (node == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }
    // Удаленный узел является корневым узлом
    else
        root = child;

    if (color == Black)
    {
        removeFixUp(root, child, parent);
    }
    delete node;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    RBTNode* tr = NULL;
    int n;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    cout << "Введите элементы: ";
    for (int i=0; i < n; i++)
    {
        int x;
        cin >> x;
        RBTNode*z = new RBTNode(x, Red, NULL, NULL, NULL);
        insert(tr, z);
    }
    inorder(tr);
    cout << endl;
    cout << "Ответ: ";
    res(tr);
}