#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731"

#include "../../../lib/number/permutation.cpp"
#include "../../../lib/parse/parser.cpp"

int N, L;
string S;

int number(State& begin) {
    int ret = 0;
    while ('0' <= *begin and *begin <= '9') {
        ret *= 10;
        ret += *begin - '0';
        ++begin;
    }
    return ret;
}


Permutation operation(State& begin) {
    char ch = *begin;
    int num = number(++begin) - 1;
    Permutation ord(N*N);
    if (ch == 'R') {
        int buff = ord[N-1 + num*N];
        for (int i = N-1; i > 0; --i) {
            ord[i + num*N] = ord[i-1 + num*N];
        }
        ord[num*N] = buff;
    }
    if (ch == 'L') {
        int buff = ord[0 + num*N];
        for (int i = 0; i < N-1; ++i) {
            ord[i + num*N] = ord[i+1 + num*N];
        }
        ord[N-1 + num*N] = buff;
    }
    if (ch == 'D') {
        int buff = ord[num + (N-1)*N];
        for (int i = N-1; i > 0; --i) {
            ord[num + i*N] = ord[num + (i-1)*N];
        }
        ord[num] = buff;
    }
    if (ch == 'U') {
        int buff = ord[num];
        for (int i = 0; i < N-1; ++i) {
            ord[num + i*N] = ord[num + (i+1)*N];
        }
        ord[num + (N-1)*N] = buff;
    }
    return ord;
}

Permutation sequence(State& begin);

Permutation repetition(State& begin) {
    assert(*begin == '(');
    Permutation ret = sequence(++begin);
    assert(*begin == ')');
    int num = number(++begin);
    return ret.pow(num);
}

Permutation rep_or_op(State& begin) {
    if (*begin == '(') {
        return repetition(begin);
    } else {
        return operation(begin);
    }
}

Permutation sequence(State& begin) {
    Permutation ret = rep_or_op(begin);
    while (*begin != ')' and *begin != '\0') {
        ret = ret * rep_or_op(begin);
    }
    return ret;
}


int main()
{
    cin >> N >> L >> S;
    State begin = S.begin();

    Permutation perm = sequence(begin);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j) cout << " ";
            cout << perm[i*N + j] + 1;
        }
        cout << endl;
    }

    return 0;
}
