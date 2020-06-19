#include "../run2.h"

void grad_case1(float (&B)[4][16], float (&dC)[4][16],float (&dA)[4][16]) {
	float _tmp0[4][16] = {0};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 16; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + ((dC[i][j] * B[i][j]) + 0);
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 16; ++j) {
			dA[i][j] = _tmp0[i][j];
		}
	}
}
