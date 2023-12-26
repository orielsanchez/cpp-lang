int summation(int num) {
    int res = 0;
    for (int i = 0; i <= num; ++i) {
        res += i;
    }
    return res;
}

int bettersummation(int num) { return num * (num + 1) / 2; }
