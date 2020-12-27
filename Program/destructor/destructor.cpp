class Word              /* File: destructor.cpp */
{
  private:
    int frequency; char* str; 
  public:
    Word() : frequency(0), str(0) { };
    Word(const char* s, int k = 0): frequency(k) 
	    { str = new char [strlen(s)+1]; strcpy(str, s); }
    ~Word() { delete [] str; }
};
int main()
{
    Word* p = new Word("Titanic");
    Word* x = new Word [5];
    delete p;           // Destruct a single object
    delete [] x;        // Destruct an array of objects
    return 0;
}
