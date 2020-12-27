#include <iostream>     /* File: student-non-static.h */
#include <vector>
#include <string>
using namespace std;

class Student
{
  private:              // Each student has his own memory
    string name;
    vector<string> memory;

  public:
    Student(string s) : name(s) { }
    void memorize(string txt) { memory.push_back(txt); }
    void do_exam();
};
