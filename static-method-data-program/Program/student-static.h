#include <iostream>     /* File: student-static.h */
#include <vector>
#include <string>
using namespace std;

class Student
{
  private:
    string name;
    static vector<string> memory; // Students share memory!

  public:
    Student(string s) : name(s) { }
    void memorize(string txt) { memory.push_back(txt); }
    void do_exam();
};
