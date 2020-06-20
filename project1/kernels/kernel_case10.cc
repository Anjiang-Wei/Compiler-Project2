#include "../run.h"

void kernel_case10(float (&B)[10][10],float (&A)[8][8]) {
	float _tmp0[8][8] = {0};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (j < 10 && j >= 0) {
				if (i + 2 < 10 && i + 2 >= 0) {
					if (j < 10 && j >= 0) {
						if (i + 1 < 10 && i + 1 >= 0) {
							if (j < 10 && j >= 0) {
								if (i < 10 && i >= 0) {
									_tmp0[i][j] = _tmp0[i][j] + (B[i][j] + B[i + 1][j] + B[i + 2][j]) / 3;
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
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
