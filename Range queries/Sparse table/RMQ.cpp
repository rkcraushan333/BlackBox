// RMQ and similar (idemopotent queries like:-or,and,max,etc)
vector<vector<int>> table;
void buildTable(v64 &v, int n, int k)
{
    forn(i, 0, n)
    {
        table[0][i] = v[i];
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j + (1 << (i - 1)) < n; j++)
        {
            table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }
}
void inforkc()
{
    int n;
    cin >> n;
    int k = log2(n);
    table.resize(k + 1, v64(n));
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    buildTable(v, n, k);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int t = b - a + 1;
        if (t & (t - 1))
        {
            int c = log2(t);
            cout << min(table[c][a], table[c][b - (1 << c) + 1]) << ln;
        }
        else
        {
            cout << table[log2(t)][a] << ln;
        }
    }
}