#include <string>       /* File: person.h */
using namespace std;

class Person
{
  public: 
    static Person* head; // Head of the whole linked list!

    Person(string s);
    Person(const Person &p);
    ~Person();

    string get_name() const { return name; }
    const Person* get_next() const { return next; }

  private:
    string name;
    Person* next;
};
