int func(int j) { return (3*j*j + 7*j - 3); }

int main()
{
    int k = 1;

    while (func(k) <= 120)
    	k++;

    printf("%d\t%d\n", k, func(k));
    return 0;
}
