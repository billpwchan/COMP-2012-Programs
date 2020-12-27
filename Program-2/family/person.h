#include <iostream>     /* File: person.h */
using namespace std;

class Person
{
  private:
    char* name;
    int age;
    Person *_father, *_mother, *_child; 

  public:
    Person(const char* Name, int Age,
           Person* Father = NULL, Person* Mother = NULL, Person* Child = NULL);
    ~Person();

    Person* father() const;
    Person* mother() const;
    Person* child() const;
    void have_child(Person* baby) ;
    void print_age() const;
    void print_name() const;
    void print_family() const;
};

