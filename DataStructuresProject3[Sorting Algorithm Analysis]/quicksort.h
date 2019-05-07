using std::vector;

const int & median3(vector<int> & a, int left, int right)
{
    int center = (left + right) / 2;

    if(a[center] < a[left])
        std::swap(a[left], a[center]);
    if(a[right] < a[left])
        std::swap(a[left], a[right]);
    if(a[right] < a[center])
        std::swap(a[center], a[right]);

    std::swap(a[center], a[right - 1]);
    return a[right - 1];
};

void quickSort(vector<int> & a, int left, int right)
{
    if(left + 2 <= right)
    {
        const int & pivot = median3(a, left, right);

        int i = left, j = right - 1;
        for( ; ; )
        {
            while(a[++i] < pivot){}
            while(pivot < a[--j]){}
            if(i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }

        std::swap(a[i], a[right - 1]);

        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else
    {
        if(a[left] > a[right])
            std::swap(a[right], a[left]);
    }
};


void quickSort(vector<int> & a)
{
    quickSort(a, 0, a.size()-1);
};
