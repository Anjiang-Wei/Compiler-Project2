#include "../run2.h"

void grad_case9(float (&dB)[4][6],float (&dA)[4]) {
	float _tmp0[4] = {0};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 6; ++j) {
			_tmp0[i] = _tmp0[i] + dB[i][j];
		}
	}
	for (int i = 0; i < 4; ++i) {
		dA[i] = _tmp0[i];
	}
}
