#ifndef HACKER_H        /* File: hacker.h */
#define HACKER_H 

class Hacker
{
  private:
    string name;

  public:
    Hacker(const string& s) : name(s) { }
    void add_course(Student& s) { s.GPA = 0.0; }
};

#endif
