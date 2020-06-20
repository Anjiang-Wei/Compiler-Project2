#include "../run2.h"

void grad_case7(float (&dB)[16][32],float (&dA)[32][16]) {
	float _tmp0[32][16] = {0};
	for (int j = 0; j < 32; ++j) {
		for (int i = 0; i < 16; ++i) {
			if (j < 32 && j >= 0) {
				if (i < 16 && i >= 0) {
					if (i < 16 && i >= 0) {
						if (j < 32 && j >= 0) {
							_tmp0[j][i] = _tmp0[j][i] + dB[i][j];
						} else {
						}
					} else {
					}
				} else {
				}
			} else {
			}
		}
	}
	for (int j = 0; j < 32; ++j) {
		for (int i = 0; i < 16; ++i) {
			dA[j][i] = _tmp0[j][i];
		}
	}
}
