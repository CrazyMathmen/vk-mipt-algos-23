#include <iostream>

// реализован простой лист с функционалом для наших задач
// erase_val(listok, val); удалить элемент в листе по по значению val

struct Node {
  int value;
  Node* next;

  Node(int _value, Node* _next = nullptr) : value(_value), next(_next) {}
};

struct List {
  Node* Head;
  Node* Tail;
  size_t size = 0;
};

bool is_empty(List listok) { return listok.Head == nullptr; }

void push_back(int value, List* listok) {
  if (listok->size == 0) {
    listok->Head = new Node(value);
    listok->Tail = listok->Head;
  } else {
    listok->Tail->next = new Node(value);
    listok->Tail = listok->Tail->next;
  }
  ++listok->size;
}

void pop_front(List listok) {
  if (listok.size > 0) {
    Node* t = listok.Head;
    listok.Head = listok.Head->next;
    delete t;
    --listok.size;
  }
}

void pop_back(List listok) {
  if (listok.size == 1) {
    delete listok.Head;
    listok.Head == nullptr;
    --listok.size;
  } else if (listok.size > 1) {
    Node* i = listok.Head;
    Node* t = listok.Head;
    while (i->next != listok.Tail) {
      ++i;
    }
    i->next = nullptr;
    delete t;
    --listok.size;
  }
}

/*
void erase_n(List* listok, size_t n) {
  if (listok->size == 0) {
    return;
  }
  if (n == 0) {
    delete listok->Head;
    listok->Head == nullptr;
    --listok->size;
  } else {
    Node* prev_current = listok->Head;
    Node* current = listok->Head;
    for (size_t i = 1; i < n - 1; ++i) {
      ++prev_current;
    }
    ++(current = prev_current);
    prev_current->next = current->next;
    delete current;
    --listok->size;
  }
}
*/

void erase_value(List* listok, int value) {
  if (listok->size == 0) {
    return;
  }
  if (listok->size == 1 && listok->Head->value == value) {
    delete listok->Head;
    listok->Head = nullptr;
    return;
  }

  Node* current = listok->Head;
  while (current->next != nullptr) {
    if (current->value == value && current == listok->Head) {
      current = listok->Head->next;
      delete listok->Head;
      listok->Head = current;
      --listok->size;
    } else if (current->next->value == value) {
      // delete current->next;
      current->next = current->next->next;
      --listok->size;
    } else {
      current = current->next;
    }
  }
}

/*
void erase_n(List* listok, size_t n) {
  if (listok->size == 0) {
    return;
  }
  if (n == 0) {
    delete listok->Head;
    listok->Head == nullptr;
    --listok->size;
  } else {
    Node* prev_current = listok->Head;
    Node* current = listok->Head;
    for (size_t i = 1; i < n - 1; ++i) {
      ++prev_current;
    }
    ++(current = prev_current);
    prev_current->next = current->next;
    delete current;
    --listok->size;
  }
}
*/

/*
void reverse(List* listok) {
  if (listok->Head == nullptr) {
    return;
  } else if (listok->Head->next == nullptr) {
    return;
  }
  Node* prev_current = listok->Head;
  Node* current = listok->Head->next;
  Node* next_current = current->next;
  prev_current->next = nullptr;
  while (next_current != nullptr) {
    current->next = prev_current;
    prev_current = current;
    current = next_current;
    next_current = next_current->next;
  }
  current->next = prev_current;
  listok->Tail = listok->Head;
  listok->Head = current;
}
*/

/*
bool is_the_cycle(List listok) {
  if (listok.Head == nullptr) {
    return false;
  }
  Node* slow = listok.Head;
  Node* fast = listok.Head->next;
  while (fast != nullptr && fast != slow) {
    fast = fast->next;
    slow = slow->next;
    if (fast != nullptr && fast != slow) {
      fast = fast->next;
    }
  }
  if (fast == nullptr) {
    return false;
  } else {
    return true;
  }
}
*/

int main() {
  List listok;
  int value = 0;
  std::cin >> value;

  push_back(3, &listok);
  // push_back(3, &listok);
  push_back(0, &listok);
  push_back(1, &listok);
  push_back(2, &listok);
  push_back(3, &listok);
  push_back(3, &listok);

  for (Node* current = listok.Head; current != nullptr;
       current = current->next) {
    std::cout << current->value << " ";
  }
  std::cout << "\n";

  erase_value(&listok, value);

  for (Node* current = listok.Head; current != nullptr;
       current = current->next) {
    std::cout << current->value << " ";
  }
  std::cout << "\n";

  return 0;
}