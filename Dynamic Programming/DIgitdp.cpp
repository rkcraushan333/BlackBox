int cnt(string &s, int idx, int tight)
{
    if (!tight)
        return pow(10, s.size() - idx);
    if (idx == s.size())
        return 1;
    int limit = s[i] - '0';
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        ans += cnt(s, idx + 1, tight & (i == limit));
    }
    return ans;
}
int f(string &s, int idx = 0, int tight = 1)
{
    if (i == s.size())
        return 1;
    int limit = tight ? s[idx] - '0' : 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        ans += (i * cnt(s, idx + 1, )) + f(s, idx + 1, tight & (limit == i));
    }
    return ans;
}
int f1(int n)
{
    memset(dp, -1, sizeof(dp));
    memset(cntdp, -1, sizeof(cntdp));
    string s = to_string(n);
    return f(s);
}