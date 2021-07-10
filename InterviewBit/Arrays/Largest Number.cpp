//Remember we can't sort a const array so we have to make another array to
//to do our work

bool static com(const int &x, const int &y)
{
    string xy = to_string(x) + to_string(y);
    string yx = to_string(y) + to_string(x);
    return xy > yx;
}

string Solution::largestNumber(const vector<int> &b)
{
    vector<int> a(b); //thats why we make non const vector copy here and do our work with that
    sort(a.begin(), a.end(), com);
    if (a[0] == 0)
        return "0";
    string ans = "";
    for (auto i : a)
    {
        ans += to_string(i);
    }
    return ans;
}
