#include "../run.h"

void kernel_case8(float (&B)[8][16],float (&A)[8][2][16]) {
	float _tmp0[8][2][16] = {0};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 16; ++k) {
				if (k < 16 && k >= 0) {
					if (i < 8 && i >= 0) {
						if (k < 16 && k >= 0) {
							if (j < 2 && j >= 0) {
								if (i < 8 && i >= 0) {
									_tmp0[i][j][k] = _tmp0[i][j][k] + B[i][k];
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
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 16; ++k) {
				A[i][j][k] = _tmp0[i][j][k];
			}
		}
	}
}
