#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &sref) {
  Node* n = new Node;
  n->s = new Student(sref);
  n->next = NULL;
  if (tail == NULL) {
    head = tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
}

std::string StudentRoll::toString() const {
  std::string out = "[";
  bool first = true;
  for (Node* p = head; p != NULL; p = p->next) {
    if (!first) out += ",";
    out += p->s->toString();
    first = false;
  }
  out += "]";
  return out;
}


StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = NULL;
  for (Node* p = orig.head; p != NULL; p = p->next) {
    insertAtTail(*(p->s));
  }
}

StudentRoll::~StudentRoll() {
  // STUB
  Node* p = head;
  while (p != NULL) {
    Node* nxt = p->next;
    delete p->s;
    delete p;
    p = nxt;
  }
  head = tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* p = head;
  while (p != NULL) {
    Node* nxt = p->next;
    delete p->s;
    delete p;
    p = nxt;
  }
  head = tail = NULL;

  for (Node* q = right.head; q != NULL; q = q->next) {
    insertAtTail(*(q->s));
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}



