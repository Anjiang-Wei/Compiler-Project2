#include "../run2.h"

void grad_case3(float (&B)[16][16], float (&dC)[4][16],float (&dA)[4][16]) {
	float _tmp0[4][16] = {0};
	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 16; ++k) {
			for (int j = 0; j < 16; ++j) {
				if (j < 16 && j >= 0) {
					if (k < 16 && k >= 0) {
						if (j < 16 && j >= 0) {
							if (i < 4 && i >= 0) {
								if (k < 16 && k >= 0) {
									if (i < 4 && i >= 0) {
										_tmp0[i][k] = _tmp0[i][k] + dC[i][j] * B[k][j];
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
	}
	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 16; ++k) {
			dA[i][k] = _tmp0[i][k];
		}
	}
}
