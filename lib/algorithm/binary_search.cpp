#include "../template.cpp"

pair<int,int> my_binary_search(
        int ng, int ok,
        function<bool(int)> check) {

    while (abs(ok - ng) > 1) {
        int mid = (ng + ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    return { ng, ok };
}

