
void insertionSort(vector<int> &v)
{
    int r = 0;
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        int e = i;
        while (e > 0 && v[e - 1] > temp)
        {
            v[e] = v[e - 1];
            r++;
            e--;
        }
        v[e] = temp;
    }
}