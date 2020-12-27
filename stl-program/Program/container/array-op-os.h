template <typename T>   /* File: array-op-os.h */
ostream& operator<<(ostream& os, const Array<T>& x)
{
    os << "#elements stored = " << x.size() << endl;

    for (int j = 0; j < x.size(); ++j)
        os << x[j] << endl;

    return os;
}
