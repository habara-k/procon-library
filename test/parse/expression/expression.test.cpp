#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109"

#include "../../../lib/parse/expression.cpp"

int main()
{
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        State begin = s.begin();
        cout << expression(begin) << endl;
    }
}
