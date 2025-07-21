#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end()); // 1. 오름차순 정렬
    int left = 0, right = 0;
    int sum = 0;

    while (right < d.size()) {
        sum += d[right];

        if (sum > budget) break;

        right++;
    }

    return right;  // right는 지원 가능한 부서의 수를 의미함
}