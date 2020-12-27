#include "person.h"     /* File: person.cpp */

Person::Person(const char* Name, int Age,
               Person* Father, Person* Mother, Person* Child)
{
    name = new char [strlen(Name)+1];
    strcpy(name, Name);
    age = Age;
    _father = Father;
    _mother = Mother;
    _child = Child;
};

Person::~Person() { delete [] name; }

Person* Person::father() const { return _father; }

Person* Person::mother() const { return _mother; }

Person* Person::child() const { return _child; }

void Person::have_child(Person* baby) { _child = baby; }

void Person::print_age() const { cout << age; }

void Person::print_name() const
{
    cout << (name ? name : "unknown");
}




// Helper function
void print_parent(Person* parent)
{
    if (parent)
        parent->print_name();
    else
        cout << "unknown";
}
    





void Person::print_family() const
{
    Person *f_grandfather = NULL, *f_grandmother = NULL,
        *m_grandfather = NULL, *m_grandmother = NULL;

    if (_father) {
        f_grandmother = _father->mother();
        f_grandfather = _father->father();
    }

    if (_mother) {
        m_grandmother = _mother->mother(); 
        m_grandfather = _mother->father();
    }

    cout << "Name: "; print_name(); cout << endl;
    cout << "Father: "; print_parent(_father); cout << endl;
    cout << "Mother: "; print_parent(_mother); cout << endl;

    cout << "Grand Fathers: "; print_parent(f_grandfather);
    cout << ", "; print_parent(m_grandfather); cout << endl;
    cout << "Grand Mothers: "; print_parent(f_grandmother);
    cout << ", "; print_parent(m_grandmother); cout << endl;
}
