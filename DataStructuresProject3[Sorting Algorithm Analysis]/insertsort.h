using std::vector;

void insertionSort(vector<int> & a)
{
    for(int p = 1; p < a.size(); ++ p)
    {
        int tmp = std::move(a[p]);

        int j;

        for(j = p; j > 0 && tmp < a[j-1]; --j) a[j] = std::move(a[j-1]);

        a[j] = std::move(tmp);
    }
};

