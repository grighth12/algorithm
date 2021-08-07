#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class EGResult {
public:
	long long s;
	long long t;
	long long gcd;

	EGResult(long long s, long long t, long long r) {
		this->s = s;
		this->t = t;
		this->gcd = r;
	}
};

EGResult extendedGcd(long long a, long long b) {
	long long s0 = 1, t0 = 0, r0 = a;
	long long s1 = 0, t1 = 1, r1 = b;

	long long temp;
	while (r1 != 0) {
		long long q = r0 / r1;

		temp = r0 - q * r1;
		r0 = r1;
		r1 = temp;

		temp = s0 - q * s1;
		s0 = s1;
		s1 = temp;

		temp = t0 - q * t1;
		t0 = t1;
		t1 = temp;
	}

	return EGResult(s0, t0, r0);
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long A;
		long long B;
		cin >> A >> B;

		EGResult result = extendedGcd(A, B);
		//cout << result.r << "\n";
		// D = gcd(A,B)
		// Ax +By = C일 때 C %D == 0 이어야 해를 가질 수 있음 :베주 항등식
		if (result.gcd != 1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			//x0 = s * C/D
			// y0 = t * C/D

			long long x0 = result.s;
			long long y0 = result.t;

			//x = x0 + B/D * k
			//y = y0 - A/D * k
			

			// x <0
			// x0 + B * K <0
			// k < -x0 /B

			// 0 < y <= 1e9
			// 0 < y0-A * k <= 1e9
			// -y0 < -A * k <= 1e9 -y0

			// (y0 - 1e9 / A) < k < y0 /A
			//                  k < -x0 /B

			// k : 일반해를 만들 수 있는 k 


			long long kFromY = (long long) ceil(((double)y0 / (double)A)) - 1;
			long long kFromX = (long long) ceil((double)-x0 / (double)B) - 1;
			long long k = min(kFromX, kFromY);

			long long y = y0 - A * k;
			if (y <= 1000000000) {
				cout << y << "\n";
			}
			else {
				cout << "IMPOSSIBLE" << "\n";
			}
			/*
			double y_max = y0 / A;
			double x_max = -x0 / B;
			double y_min = (y0 - 1000000000) / A;
			long long M = min(ceil(y_max) - 1, ceil(x_max) - 1);
			long long m = ceil(y_min);

			if (M - m > 0) {
				long long count = 0;
				for (int i = m; i <= M; i++) {
					long long y = y0 - A * i;
					if (y > 0) count++;
				}
				cout << count << "\n";

			}
			else {
				cout << "IMPOSSIBLE" << "\n";
			}
			*/
		}
	}

	return 0;
}
