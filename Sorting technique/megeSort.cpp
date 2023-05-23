void merge(vector<int> left, vector<int> right, vector<int> &v)
{
    int a = left.size(), b = right.size();
    int i = 0, j = 0, k = 0;
    while (i < a && j < b)
    {
        if (left[i] <= right[j])
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }
    while (i < a)
        v[k++] = left[i++];
    while (j < b)
        v[k++] = right[j++];
}
void merge_sort(vector<int> &v)
{
    int n = v.size();
    if (n < 2)
        return;
    int mid = n / 2;
    vector<int> left(mid);
    vector<int> right(n - mid);
    for (int i = 0; i < mid; i++)
        left[i] = v[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = v[i];
    merge_sort(left);
    merge_sort(right);
    merge(left, right, v);
}