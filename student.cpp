#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->name = NULL;
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
}

void Student::setName(const char * const nm) {
  const char* src = nm ? nm : "";
  char* buf = new char[std::strlen(src) + 1];
  std::strcpy(buf, src);
  if (name) delete[] name;
  name = buf;
}

Student::Student(const Student &orig) {
  this->name = NULL;
  this->setName(orig.name);
  this->setPerm(orig.perm);
}

Student::~Student() {
  delete[] name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  this->setName(right.name);
  this->setPerm(right.perm);

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  return std::string(name ? name : "") + " (" + std::to_string(perm) + ")";
}
