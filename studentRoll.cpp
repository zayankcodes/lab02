#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {

  Node* n = new Node;
  n->stu = new Student(s);
  n->next = NULL;
  if (tail == NULL) {
    head = tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
}

std::string StudentRoll::toString() const {

  std::string out;
  for (Node* p = head; p != NULL; p = p->next) {

    if (!out.empty()) out += "\n";
    out += p->stu->toString();
  }
  return out;
}


StudentRoll::StudentRoll(const StudentRoll &orig) {

  head = tail = NULL;

  for (Node* p = orig.head; p != NULL; p = p->next) {

    insertAtTail(*(p->stu));
  }
}

StudentRoll::~StudentRoll() {
  Node* p = head;
  while (p != NULL) {
    Node* nxt = p->next;
    delete p->stu;
    delete p;
    p = nxt;
  }
  head = tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {


  if (&right == this) 

    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* p = head;

  while (p != NULL) {

    Node* nxt = p->next;

    delete p->stu;
    delete p;
    p = nxt;
  }
  head = tail = NULL;

  for (Node* q = right.head; q != NULL; q = q->next) {
    
    insertAtTail(*(q->stu));
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}




