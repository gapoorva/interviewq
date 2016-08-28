template <typename T>
struct node {
  node* left;
  node* right;
  T data;
};

template <typename T>
node<T>* createtree(T a[], int start, int end) {
  if(start >= end) return nullptr;
  else {
    node<T>* n = new node<T>;
    n->data = a[start+((end-start)/2)];
    n->left = createtree(a, start, (end-start)/2);
    n->right = createtree(a, start+((end-start)/2)+1, end);
    return n;
  }
}
