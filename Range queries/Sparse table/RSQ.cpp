// Range sum queries and similar (Non idempotent queries like:- xor,gcd,lcm,etc)
vector<v64> table;
void buildTable(v64 &v, int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        table[0][i] = v[i];
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j + (1 << (i - 1)) < n; j++)
        {
            table[i][j] = table[i - 1][j] + table[i - 1][j + (1 << (i - 1))];
        }
    }
}
void inforkc()
{
    int n, q;
    cin >> n >> q;
    int k = log2(n);
    table.resize(k + 1, v64(n));
    v64 v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    buildTable(v, k, n);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int t = b - a + 1;
        int ans = 0;
        int cnt = 0;
        while (t)
        {
            if (t & 1)
            {
                b = (b - (1 << cnt)) + 1;
                ans += table[cnt][b];
                b--;
            }
            t >>= 1;
            cnt++;
        }
        cout << ans << ln;
    }
}