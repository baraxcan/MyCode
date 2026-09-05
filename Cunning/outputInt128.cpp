std::ostream& operator << (std::ostream& dest, __int128_t value) {
    if (value == 0) return dest << 0;
    if (value < 0) {
        dest << '-';
        value = -value;
    }
    __int128_t t = value;
    char buffer[64];
    char* d = std::end(buffer);
    while (t > 0) {
        --d;
        *d = "0123456789"[t % 10];
        t /= 10;
    }
    return dest.write(d, std::end(buffer) - d);
}