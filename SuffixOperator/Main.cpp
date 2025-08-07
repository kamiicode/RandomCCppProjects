#include <iostream>

class Test {
public:
	unsigned long long x = 0;

	constexpr Test(decltype(x) x) : x(x) {}
};

constexpr Test operator ""_t(unsigned long long t) noexcept {
	return Test(t);
}

int main() {
	std::cout << (10_t).x << std::endl;
}
