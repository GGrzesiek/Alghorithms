#include <iostream>

using namespace std;
struct node
{
    int key;
    node* parent;
    node* left;
    node* right;
};

node* make_node(int value)
{
    node* n = new node;
    n->key = value;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;
}

void add_node(int value, node* &root)
{
    if (root == nullptr)
    {
        root = make_node(value);
        return;
    }
    node* temp = root;
    while(true)
    {
        if (value >= root->key)
        {
            if (root->right == nullptr)
            {
                temp->right = make_node(value);
                temp->right->parent = temp;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            if (root->left == nullptr)
            {
                root->left = make_node(value);
                root->left->parent = temp;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
}
void preorder(node* root)
{
    if(root!=nullptr)
    {
        cout << root->key;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root!=nullptr)
    {   
        postorder(root->left);
        postorder(root->right);
        cout << root->key;
    }
}

void inorder(node* root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}

node* find_node(node* root,int value)
{
    while(root!=nullptr)
    {
        if(root->key==value)
        {
            return root;
        }
        if(value>root->key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }

    }
    return nullptr;
}

node* find_successor(node* n)
{
    if(n->right!=nullptr)
    {
        n=n->right;
        while(n->left!=nullptr)
        {
            n=n->left;
        }
    return n;
    }
    node* temp = n->parent;
    while(temp!=nullptr&&temp->left!=n)
    {
        n=temp;
        temp=temp->parent;
    }
    return temp;
}

void delete_node(node* &root,node* delete_node)
{
    node* temp1;
    node* temp2;
    if(delete_node->left==nullptr||delete_node->right==nullptr)
    {
        temp1=delete_node;
    }
    else
    {
        temp2 = find_successor(delete_node);
    }

    if(temp1->left!=nullptr)
    {
        temp2=temp1->left;
    }
    else
    {
        temp2=temp1->right;
    }

    if(temp2!=nullptr)
    {
        temp2->parent=temp1->parent;
    }
    
    if(temp1->parent==nullptr)
    {
        root=temp2;
    }
    else if(temp1==temp1->parent->left)
    {
        temp1->parent->left=temp2;
    }
    else
    {
        temp1->parent->right=temp2;
    }

    if(temp1!=delete_node)
    {
        delete_node->key=temp1->key;
    }
    delete temp1;
}

int main()
{
    node* tree=nullptr;
    bool flag=true;
    int choice;
    int value;
    while(flag)
    {
        cout << "1. Sprawdz czy drzewo jest puste" << endl;
        cout << "2. Dodaj element" << endl;
        cout << "3. Sprawdzenie czy klucz o podanej wartosci wezla znajduje sie w drzewie" << endl;
        cout << "4. Wyswietlenie liczby wystapien kluczy w drzewie" << endl;
        cout << "5. Wyswietlenie drzewa preorder" << endl;
        cout << "6. Wyswietlenie drzewa inorder" << endl;
        cout << "7. Wyswietlenie drzewa postorder" << endl;
        cout << "8. Usuniecie wezla o podanej wartosci " << endl;
        cout << "9. Usuniecie calego drzewa" << endl;
        cout << "10. Wyjscie z programu" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                if(tree==nullptr)
                {
                    cout << "Drzewo jest puste" << endl;
                }
                else
                {
                    cout << "Drzewo nie jest puste" << endl;
                }
                break;
            }
            case 2:
            {
                cout << "Podaj wartosc wezla" << endl;
                cin >> value;
                add_node(value,tree);
                break;
            }
            case 3:
            {
                cout << "Podaj wartosc wezla" << endl;
                cin >> value;
                if(find_node(tree,value)!=nullptr)
                {
                    cout << "W drzewie znajduje sie wezel o podanej wartosci" << endl;
                }
                else
                {
                    cout << "W drzewie nie znajduje sie wezel o podanej wartosci" << endl;
                }
                break;
            }
            case 4:
            {
                
            }
        }
    }
}