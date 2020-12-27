template <typename T>   /* File: array-op=.h */
Array<T>& Array<T>::operator=(const Array<T>& x)
{
    if (&x != this)       // Avoid self-assignment: e.g., a = a
    {
        delete [] _value; // First remove the old data

        _size = x._size;
        _value = new T [_size]; // Re-allocate memory for new data

        for (int j = 0; j <_size; ++j) // Copy the new data
            _value[j] = x[j];
    }

    return (*this);
}
