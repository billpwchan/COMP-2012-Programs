class Word              /* File: mil-word.h */
{
  private:
    char lang; int freq; char* str;

  public:
    Word() : lang('E'), freq(0), str(NULL) { };
    Word(const char* s, int f = 1, char g = 'E') : lang(g), freq(f)
        { str = new char [strlen(s)+1]; strcpy(str, s); }
    void print() const { cout << str << " : " << freq << "\n"; }
};
