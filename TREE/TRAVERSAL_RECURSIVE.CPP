#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *create_node(struct node *head, char data)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->left = NULL;
    head->right = NULL;

    return head;
}

struct node *build_tree(struct node *head)
{
    char data;
    cout << "enter the data ";
    cin >> data;
    head = create_node(head, data);
    if (data == 'Z')
    {
        cout << " 0 for NULL " << endl;
        return NULL;
    }

    cout << "node inserted at left " << head->data << endl;
    head->left = build_tree(head->left);
    cout << "node inserted at right " << head->data << endl;
    head->right = build_tree(head->right);

    return head;
}
void Post_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Post_order(root->left);
    Post_order(root->right);
    cout << " the element = " << root->data << endl;
}

void Pre_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << " the element = " << root->data << endl;
    Pre_order(root->left);
    Pre_order(root->right);
}

void In_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    In_order(root->left);
    cout << " the element = " << root->data << endl;
    In_order(root->right);
}

int main()
{
    int arr[100], a = 12, b, tem;
    struct node *root = NULL;

    root = build_tree(root);
    cout << "enter the type of TRAVERSAL " << endl;
    cout << "1. preorder  2. inorder  3. postorder " << endl;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        cout << "PREORDER TRAVERSAL ";
        Pre_order(root);
    }
    break;
    case 2:
    {
        cout << "INORDER TRAVERSAL ";
        In_order(root);
    }
    break;

    case 3:
    {
        cout << "POSTORDER TRAVERSAL ";
        Post_order(root);
    }
    break;

    default:
        break;
    }

    return 0;
}
/*
EXAMPLE :-
           A
         /   \
        B     C
      /  \   /  \
     D    E  F   G

     OUTPUT :-
     PREORDER = A,B,D,E,C,F,G
     INORDER  = D,B,E,A,F,C,G
    POSTORDER = D,E,B,F,G,C,A

*/