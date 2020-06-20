#include "../run2.h"

void grad_case1(float (&B)[4][16], float (&dC)[4][16],float (&dA)[4][16]) {
	float _tmp0[4][16] = {0};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (j < 16 && j >= 0) {
				if (i < 4 && i >= 0) {
					if (j < 16 && j >= 0) {
						if (i < 4 && i >= 0) {
							if (j < 16 && j >= 0) {
								if (i < 4 && i >= 0) {
									_tmp0[i][j] = _tmp0[i][j] + dC[i][j] * B[i][j];
								} else {
								}
							} else {
							}
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
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 16; ++j) {
			dA[i][j] = _tmp0[i][j];
		}
	}
}
