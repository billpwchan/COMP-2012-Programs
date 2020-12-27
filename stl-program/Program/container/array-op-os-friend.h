template <typename T>   /* File: array-op-os-friend.h */
ostream& operator<<(ostream& os, const Array<T>& x)
{
    os << "#elements stored = " << x._size << endl;

    for (int i = 0; i < x._size; ++i)
        os << x._value[i] << endl;

    return os;
}
