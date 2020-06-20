#include "../run.h"

void kernel_additional_case15(float (&A)[2][2], float (&B)[2][2], float (&D)[2][4], float (&E)[4][2],float (&C)[2][2]) {
	float _tmp0[2][2] = {0};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (j < 2 && j >= 0) {
					if (k < 2 && k >= 0) {
						if (k < 2 && k >= 0) {
							if (i < 2 && i >= 0) {
								if (j < 2 && j >= 0) {
									if (i < 2 && i >= 0) {
										_tmp0[i][j] = _tmp0[i][j] + (A[i][k] * B[k][j]);
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
			for (int l = 0; l < 4; ++l) {
				if (j < 2 && j >= 0) {
					if (l < 4 && l >= 0) {
						if (l < 4 && l >= 0) {
							if (i < 2 && i >= 0) {
								_tmp0[i][j] = _tmp0[i][j] + (D[i][l] * E[l][j]);
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
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			C[i][j] = _tmp0[i][j];
		}
	}
}
