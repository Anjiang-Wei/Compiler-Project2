#include "../run2.h"

void grad_case10(float (&dA)[8][8],float (&dB)[10][8]) {
	float _tmp0[10][8] = {0};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + (((dA[i][j] + (dA[(i - 1)][j] + dA[(i - 2)][j]))) / 3);
		}
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			dB[i][j] = _tmp0[i][j];
		}
	}
}
