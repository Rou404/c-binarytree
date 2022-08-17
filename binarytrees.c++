#include <iostream>

using namespace std;

class node {
  public:
    int data;
  node * left;
  node * right;
  node();
  node(int value);
};

node::node() {}

node::node(int value) {
  data = value;
  left = NULL;
  right = NULL;
}

class binary_tree {
  node * root = new node;
  public:
    binary_tree();
  node * search(node * root, int value);
  node * insert(node * traveler, int value);
  void insert_helper(int value);
  void search_helper(int value);
  void remove(int value);
  void remove_case_1(node * &location, node * &parent);
  void remove_case_2(node * &location, node * &parent);
  void remove_case_3(node * &location, node * &parent);
  void find(node * &location, node * &parent, int value);


};

binary_tree::binary_tree() {
  root = NULL;
}

node * binary_tree::search(node * traveler, int value) {
  if (traveler -> data == value) {
    return traveler;
  }
  if (traveler -> left != NULL && traveler -> data > value)
    return search(traveler -> left, value);
  if (traveler -> right != NULL && traveler -> data < value)
    return search(traveler -> right, value);
  return root;
}

void binary_tree::search_helper(int value) {
  if (root == NULL) {
    cout << "Root does not exist \n";
  } else {
    if (search(root, value) -> data == value)
      cout << "Found\n";
    else
      cout << "Not found \n";
  }

}
node * binary_tree::insert(node * traveler, int value) {
  if (traveler -> data == value) //Check weather or not the node already exists
  {
    cout << "Node already exists\n";
  }

  if (traveler == NULL) //If leaf is found, create new node on that leaf
  {
    cout << "Found leaf node\n";
    node * new_node = new node(value);
  }

  if (value > traveler -> data) //If number is bigger, go to right
  {
    if (traveler -> right != NULL)
      return (insert(traveler -> right, value));
    else //if right child does not exist place node
    {
      node * new_node = new node(value);
      traveler -> right = new_node;
      cout << "Node added to right\n";
    }
  }

  if (value < traveler -> data) //If number is smaller, go to left
  {
    if (traveler -> left != NULL)
      return (insert(traveler -> left, value));
    else //if left child does not exist place node
    {
      node * new_node = new node(value);
      traveler -> left = new_node;
      cout << "Node added to left\n";
    }
  }
}

void binary_tree::remove_case_1(node * &location, node * &parent)   //no children
{
    if(parent == NULL)
    {
        root = NULL;
    }
    else
    {
        if(location == parent->left)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
}

void binary_tree::remove_case_2(node * &location, node * &parent)   //one children
{
    node * child;
    if(location->right)
        child = location->right;
    else
        child = location->left;

    if(parent == NULL)
    {
        root = child;
    }
    else
    {
        if(parent->left == location)
            parent->right = child;
        else
            parent->right = child;
    }
}

void binary_tree::remove_case_3(node * &location, node * &parent)   //2 children
{

}
void binary_tree::find(node * &location, node * &parent, int value)
{
    
}
void binary_tree::remove(int value){

    node * parent;
    node * location;

    if(root == NULL)
    {
        cout<<"Tree is empty \n";
    }
    if(root->data == value)
    {
        cout<<"Root node has been deleted \n";
        free(root);
    }

    find(location, parent, value);
    
    if(location->left == NULL && location->right == NULL) //if the node has no children
        remove_case_1(location, parent);
    if(location->left == NULL && location->right != NULL) //1 chuldren
        remove_case_2(location, parent);
    if(location->left !=NULL && location->right == NULL) //1 children
        remove_case_2(location, parent);
    if(location->left !=NULL && location->right != NULL) //2 children
        remove_case_3(location, parent);
}
void binary_tree::insert_helper(int value) {
  if (root == NULL) {
    node * new_node = new node(value);
    root = new_node;
    cout << "Node " << root -> data << " inserted at root \n";
  } else
    insert(root, value);
}
int main() {
  binary_tree tree;
  tree.insert_helper(10);
  tree.insert_helper(9);
  tree.insert_helper(11);
  tree.insert_helper(12);
  tree.search_helper(1000);
  return 0;
}