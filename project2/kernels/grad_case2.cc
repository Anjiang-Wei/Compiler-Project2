#include "../run2.h"

void grad_case2(float (&A)[4][16], float (&dB)[4][16],float (&dA)[4][16]) {
	float _tmp0[4][16] = {0};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 16; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + ((dB[i][j] * A[i][j] + A[i][j] * dB[i][j]));
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 16; ++j) {
			dA[i][j] = _tmp0[i][j];
		}
	}
}
