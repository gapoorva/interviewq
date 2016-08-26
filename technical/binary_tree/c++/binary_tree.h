#include <stack>
#include <iostream>

template <typename T>
// Expects type T to have an operator overload for <. 
class binary_tree {
  friend class iterator;
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
  // modifying the tree invalidates the iterator
  class iterator {
    friend class binary_tree;
  private:
    std::stack<node*> nodes;
  public:
    iterator();
    iterator(const iterator&); //cpy-ctor
    iterator operator=(const iterator&);
    iterator operator++();
    T& operator*(); // get data at this node
    bool operator!=(const iterator&);
    bool operator==(const iterator&);
  };
  binary_tree();
  ~binary_tree();
  void add(T);
  bool find(T);
  bool empty();
  iterator first();
  iterator end();
  void print();
  void remove(T);
};

// constructor
template <typename T>
binary_tree<T>::binary_tree(): root(nullptr) {}

// Deletes all nodes, used in the destructor
template <typename T>
void binary_tree<T>::delete_helper(binary_tree<T>::node* n) {
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
binary_tree<T>::~binary_tree() {
  delete_helper(root);
}

// adds value to node where it belongs in the tree.
// if it's already there, nothing is added.
template <typename T>
void binary_tree<T>::add_helper(T val, binary_tree<T>::node* & n) {
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
void binary_tree<T>::add(T val) {
  add_helper(val, root);
}

// determines if a value exists in the tree.
template <typename T>
bool binary_tree<T>::find_helper(T val, binary_tree<T>::node* n) {
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
bool binary_tree<T>::find(T val) {
  return find_helper(val, root);
}

template <typename T>
bool binary_tree<T>::empty() {
  return root == nullptr;
}

// return an iterator to the in-order first element
template <typename T> 
typename binary_tree<T>::iterator binary_tree<T>::first() {
  iterator i;
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

// return an iterator pointing to the "end" of the tree
template <typename T>
typename binary_tree<T>::iterator binary_tree<T>::end() {
  return iterator();
}

// prints node value
template <typename T>
void binary_tree<T>::print_helper(node* n) {
  if(n) {
    print_helper(n->left);
    std::cout << n->data << " ";
    print_helper(n->right);
  }
}

template <typename T>
void binary_tree<T>::print() {
  std::cout << "[ ";
  print_helper(root);
  std::cout << "]\n";
}

// returns a pointer to the node that contains the value
// if the value exists in the tree.
template <typename T>
typename binary_tree<T>::node*& binary_tree<T>::find_node(T val, binary_tree<T>::node*& n) {
  if(!n) return n;
  else if(n->data < val) {
    return find_node(val, n->right);
  } else if (val < n->data) {
    return find_node(val, n->left);
  } else return n;
}

// return the in-order successor as a pointer
template <typename T>
typename binary_tree<T>::node* binary_tree<T>::in_order_successor(binary_tree<T>::node* n) {
  if(!n->right) return nullptr;
  binary_tree<T>::node* candidate = n->right;
  while(candidate->left) {
    candidate = candidate->left;
  }
  return candidate;
} 

// return the in-orer successor as a pointer
template <typename T>
typename binary_tree<T>::node* binary_tree<T>::in_order_predecessor(binary_tree<T>::node* n){
  if (!n->left) return nullptr;
  binary_tree<T>::node* candidate = n->left;
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
void binary_tree<T>::remove_helper(binary_tree<T>::node* & n) {
  if(!n) return;
  binary_tree<T>::node* successor = in_order_successor(n);
  if(successor) {
    n->data = successor->data;
    remove_helper(successor);
    return;
  }
  binary_tree<T>::node* predecessor = in_order_predecessor(n);
  if(predecessor) {
    n->data = predecessor->data;
    remove_helper(predecessor);
    return;
  }
  // n is a leaf node. Just delete.
  binary_tree<T>::node* parent = n->parent;
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
void binary_tree<T>::remove(T val) {
  binary_tree<T>::node* to_delete = find_node(val, root);
  if(!to_delete) return;
  remove_helper(to_delete);
}



/// ITERATOR CLASS IMPLEMENTATION


template <typename T>
binary_tree<T>::iterator::iterator() {}

// copy ctor
template <typename T>
binary_tree<T>::iterator::iterator(const iterator& other) {
  nodes = other.nodes;
}

// assignment operator
template <typename T>
typename binary_tree<T>::iterator binary_tree<T>::iterator::operator=(const iterator& other) {
  nodes = other.nodes;
  return *this;
}

// increment
template <typename T>
typename binary_tree<T>::iterator binary_tree<T>::iterator::operator++() {
  if(!nodes.empty()) {
    binary_tree<T>::node* me = nodes.top();
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
T& binary_tree<T>::iterator::operator*() {
  if(this->nodes.empty()) throw "tried to deference null iterator";
  else return nodes.top()->data;
}

// check if the iterator is at the same position as another iterator.
template <typename T>
bool binary_tree<T>::iterator::operator!=(const iterator& other) {
  return (nodes.empty() && other.nodes.empty())
   || (!nodes.empty() && !other.nodes.empty() && nodes.top() == other.nodes.top());
}

template <typename T>
bool binary_tree<T>::iterator::operator==(const iterator& other) {
  return !(this->operator!=(other));
}

