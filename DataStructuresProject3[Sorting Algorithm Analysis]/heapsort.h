using std::vector;

inline int leftChild(int i)
{
    return 2 * i + 1;
};

void percDown(vector<int> & a, int i, int n)
{
    int child;
    int tmp;

    for(tmp = std::move(a[i]); leftChild(i) < n; i = child)
    {
        child = leftChild(i);

        if(child != n - 1 && a[child] < a[child + 1])
            ++child;

        if(tmp < a[child])
            a[i] = std::move(a[child]);
        else
            break;

    }

    a[i] = std::move(tmp);
};


void heapSort(vector<int> & a)
{
    for(int i = a.size() / 2 - 1; i >= 0; --i)
        percDown(a, i, a.size());

    for(int j = a.size() - 1; j > 0; --j)
    {
        std::swap(a[0], a[j]);

        percDown(a, 0, j);
    }
};




