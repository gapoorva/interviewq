#include <stack>
#include <iostream>

template <typename T>
// Expects type T to have an operator overload for <. 
class BinaryTree {
  friend class Iterator;
private:
  struct node {
    T data;
    node* left;
    node* right;
    node* parent;
    node(T val, node* parent): data(val), left(nullptr), right(nullptr), parent(parent) {}
  };
  node* root;
  void delete_helper(node*);
  void add_helper(T, node* &);
  bool find_helper(T, node*);
  void print_helper(node*);
  node*& find_node(T, node*&);
  node* in_order_successor(node*);
  node* in_order_predecessor(node*);
  void remove_helper(node*&);
public:
  // does an in-order traversal of the tree
  // modifying the tree invalidates the Iterator
  class Iterator {
    friend class BinaryTree;
  private:
    std::stack<node*> nodes;
  public:
    Iterator();
    Iterator(const Iterator&); //cpy-ctor
    Iterator operator=(const Iterator&);
    Iterator operator++();
    T& operator*(); // get data at this node
    bool operator!=(const Iterator&);
    bool operator==(const Iterator&);
  };
  BinaryTree();
  ~BinaryTree();
  void add(T);
  bool find(T);
  bool empty();
  Iterator first();
  Iterator end();
  void print();
  void remove(T);
};

// constructor
template <typename T>
BinaryTree<T>::BinaryTree(): root(nullptr) {}

// Deletes all nodes, used in the destructor
template <typename T>
void BinaryTree<T>::delete_helper(BinaryTree<T>::node* n) {
  if(!n) return;
  if (n->left) delete_helper(n->left);
  n->left = nullptr;
  if (n->right) delete_helper(n->right);
  n->right = nullptr;
  delete n;
  n = nullptr;
}

// destructor
template <typename T>
BinaryTree<T>::~BinaryTree() {
  delete_helper(root);
}

// adds value to node where it belongs in the tree.
// if it's already there, nothing is added.
template <typename T>
void BinaryTree<T>::add_helper(T val, BinaryTree<T>::node* & n) {
  if(!n) {
    n = new node(val, nullptr);
    return;
  } else if (n->data < val) {
    if (n->right) add_helper(val, n->right);
    else n->right = new node(val, n);
  } else if (val < n->data) {
    if (n->left) add_helper(val, n->left);
    else n->left = new node(val, n);
  }
  // if n contains data then we already have the value
}

// add operator
template <typename T>
void BinaryTree<T>::add(T val) {
  add_helper(val, root);
}

// determines if a value exists in the tree.
template <typename T>
bool BinaryTree<T>::find_helper(T val, BinaryTree<T>::node* n) {
  if(!n) return false;
  else if (n->data < val) {
    return find_helper(val, n->right);
  } else if (val < n->data) {
    return find_helper(val, n->left);
  } else {
    return true; // this node contains val so val exists in tree.
  }
}


template <typename T>
bool BinaryTree<T>::find(T val) {
  return find_helper(val, root);
}

template <typename T>
bool BinaryTree<T>::empty() {
  return root == nullptr;
}

// return an Iterator to the in-order first element
template <typename T> 
typename BinaryTree<T>::Iterator BinaryTree<T>::first() {
  Iterator i;
  node* first = root;
  while(first) {
    i.nodes.push(first);
    if (first->left) {
      first = first->left;
    }
    first = first->right;
  }
  return i;
}

// return an Iterator pointing to the "end" of the tree
template <typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::end() {
  return Iterator();
}

// prints node value
template <typename T>
void BinaryTree<T>::print_helper(node* n) {
  if(n) {
    print_helper(n->left);
    std::cout << n->data << " ";
    print_helper(n->right);
  }
}

template <typename T>
void BinaryTree<T>::print() {
  std::cout << "[ ";
  print_helper(root);
  std::cout << "]\n";
}

// returns a pointer to the node that contains the value
// if the value exists in the tree.
template <typename T>
typename BinaryTree<T>::node*& BinaryTree<T>::find_node(T val, BinaryTree<T>::node*& n) {
  if(!n) return n;
  else if(n->data < val) {
    return find_node(val, n->right);
  } else if (val < n->data) {
    return find_node(val, n->left);
  } else return n;
}

// return the in-order successor as a pointer
template <typename T>
typename BinaryTree<T>::node* BinaryTree<T>::in_order_successor(BinaryTree<T>::node* n) {
  if(!n->right) return nullptr;
  BinaryTree<T>::node* candidate = n->right;
  while(candidate->left) {
    candidate = candidate->left;
  }
  return candidate;
} 

// return the in-orer successor as a pointer
template <typename T>
typename BinaryTree<T>::node* BinaryTree<T>::in_order_predecessor(BinaryTree<T>::node* n){
  if (!n->left) return nullptr;
  BinaryTree<T>::node* candidate = n->left;
  while(candidate->right) {
    candidate = candidate->right;
  }
  return candidate;
}

// removes a node
// simply removes if leaf node.
// places the in order successor in it's place if it exists
// otherwise, it places the in order predecessor in it's place
template <typename T>
void BinaryTree<T>::remove_helper(BinaryTree<T>::node* & n) {
  if(!n) return;
  BinaryTree<T>::node* successor = in_order_successor(n);
  if(successor) {
    n->data = successor->data;
    remove_helper(successor);
    return;
  }
  BinaryTree<T>::node* predecessor = in_order_predecessor(n);
  if(predecessor) {
    n->data = predecessor->data;
    remove_helper(predecessor);
    return;
  }
  // n is a leaf node. Just delete.
  BinaryTree<T>::node* parent = n->parent;
  if(!parent) {
    if(n == root) {
      delete root;
      root = nullptr;
    } else {
      delete n;
      n = nullptr;
    }
  } else if(parent->left == n) {
    delete parent->left;
    parent->left = nullptr;
  } else {
    delete parent->right;
    parent->right = nullptr; 
  }
}

template <typename T>
void BinaryTree<T>::remove(T val) {
  BinaryTree<T>::node* to_delete = find_node(val, root);
  if(!to_delete) return;
  remove_helper(to_delete);
}



/// Iterator CLASS IMPLEMENTATION


template <typename T>
BinaryTree<T>::Iterator::Iterator() {}

// copy ctor
template <typename T>
BinaryTree<T>::Iterator::Iterator(const Iterator& other) {
  nodes = other.nodes;
}

// assignment operator
template <typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::Iterator::operator=(const Iterator& other) {
  nodes = other.nodes;
  return *this;
}

// increment
template <typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::Iterator::operator++() {
  if(!nodes.empty()) {
    BinaryTree<T>::node* me = nodes.top();
    nodes.pop();
    if(me->right) {
      nodes.push(me->right);
      me = me->right;
      while(me->left) {
        nodes.push(me->left);
        me = me->left;
      }
    }
  }
  return *this;
}

// get a reference to the underlying value
template <typename T>
T& BinaryTree<T>::Iterator::operator*() {
  if(this->nodes.empty()) throw "tried to deference null Iterator";
  else return nodes.top()->data;
}

// check if the Iterator is at the same position as another Iterator.
template <typename T>
bool BinaryTree<T>::Iterator::operator!=(const Iterator& other) {
  return (nodes.empty() && other.nodes.empty())
   || (!nodes.empty() && !other.nodes.empty() && nodes.top() == other.nodes.top());
}

template <typename T>
bool BinaryTree<T>::Iterator::operator==(const Iterator& other) {
  return !(*this != other);
}

