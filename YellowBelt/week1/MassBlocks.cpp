#include <iostream>

using namespace std;

int main() {
	int32_t N = 0;
	int16_t R;

	cin >> N >> R;
	int64_t mass = 0;
	int32_t W = 0, H = 0, D = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> W >> H >> D;
		mass += W * H * D * R;
	}
	cout << mass << endl;

	return 0;
}
