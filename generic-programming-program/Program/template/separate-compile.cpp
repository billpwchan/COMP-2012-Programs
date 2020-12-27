/* File: max.h */
template <typename T> T my_max(const T& a, const T& b);

/* File: max.cpp */
template <typename T> T my_max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}
