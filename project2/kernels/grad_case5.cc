#include "../run2.h"

void grad_case5(float (&C)[32][32], float (&D)[4][32], float (&dA)[16][32],float (&dB)[16][32][4]) {
	float _tmp0[16][32][4] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int k = 0; k < 32; ++k) {
			for (int l = 0; l < 4; ++l) {
				for (int j = 0; j < 32; ++j) {
					_tmp0[i][k][l] = _tmp0[i][k][l] + dA[i][j] * C[k][j] * D[l][j];
				}
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int k = 0; k < 32; ++k) {
			for (int l = 0; l < 4; ++l) {
				dB[i][k][l] = _tmp0[i][k][l];
			}
		}
	}
}
