#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr auto eps = double{ 1E-9 };
	constexpr auto maxIter = int{ 10000 };

	double n, l, w, h;
	cin >> n >> l >> w >> h;

	auto x = double{ 0 };
	auto y = static_cast<double>(max({ l, w, h }));
	auto mid = (x + y) / 2;
	auto iter = int{ 0 };
	while (iter++ < maxIter && eps < y - x) {
		auto lc = static_cast<ll>(l / mid);
		auto wc = static_cast<ll>(w / mid);
		auto hc = static_cast<ll>(h / mid);
		if (0 == lc || 0 == wc || 0 == hc) {
			y = mid;
		}
		else {
			if (n <= lc || n <= wc || n <= hc ||
				n <= lc * wc ||
				n <= wc * hc ||
				n <= hc * lc ||
				n <= lc * wc * hc) {
				x = mid;
			}
			else {
				y = mid;
			}
		}

		mid = (x + y) / 2;
	}

	cout << fixed << setprecision(10) << mid;

	return 0;
}