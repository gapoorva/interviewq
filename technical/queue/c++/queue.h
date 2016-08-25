template <typename T>
class queue {
private:
  struct node {
    node* next;
    node* prev;
    T data;
  };
  node* head;
  node* tail;
public:
  queue<T>();
  ~queue<T>();
  bool empty();
  void push_front(T);
  T pop_front();
  void push_back(T);
  T pop_back();
};

template <typename T>
queue<T>::queue() : head(nullptr), tail(nullptr) {}

template <typename T>
queue<T>::~queue() {
  while(!empty()) pop_front();
}

template <typename T> 
bool queue<T>::empty() {
  return !head && !tail;
}

template <typename T>
void queue<T>::push_front(T val) {
  if(empty()) {
    head = tail = new node;
    head->next = head->prev = nullptr;
    head->data = val;
  } else {
    node* tmp = head;
    tmp->prev = head = new node;
    head->next = tmp;
    head->prev = nullptr;
    head->data = val;
  }
}

template <typename T>
T queue<T>::pop_front() {
  if(empty()) {
    throw "popped empty list"; // exception tried to pop empty list
  } else if(head == tail) {
    T data = head->data;
    delete head;
    head = tail = nullptr;
    return data;
  } else {
    T data = head->data;
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    return data;
  }
}

template <typename T>
void queue<T>::push_back(T val) {
  if(empty ()) {
    head = tail = new node;
    tail->prev = tail->next = nullptr;
    tail->data = val;
  } else {
    node* tmp = tail;
    tmp->next = tail = new node;
    tail->next = nullptr;
    tail->prev = tmp;
    tail->data = val;
  }
}

template <typename T>
T queue<T>::pop_back() {
  if(empty()) {
    throw "popped empty list";
  } else if (head == tail) {
    T data = tail->data;
    delete tail;
    head = tail = nullptr;
    return data;
  } else {
    T data = tail->data;
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    return data;
  }
}