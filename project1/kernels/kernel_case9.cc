#include "../run.h"

void kernel_case9(float (&B)[16][32][8], float (&C)[32][32], float (&D)[8][32],float (&A)[16][32]) {
	float _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			if (j < 32 && j >= 0) {
				if (i < 16 && i >= 0) {
					if (j < 32 && j >= 0) {
						if (i < 16 && i >= 0) {
							_tmp0[i][j] = _tmp0[i][j] + A[i][j];
						} else {
						}
					} else {
					}
				} else {
				}
			} else {
			}
			for (int k = 0; k < 32; ++k) {
				for (int l = 0; l < 8; ++l) {
					if (j < 32 && j >= 0) {
						if (l < 8 && l >= 0) {
							if (j < 32 && j >= 0) {
								if (k < 32 && k >= 0) {
									if (l < 8 && l >= 0) {
										if (k < 32 && k >= 0) {
											if (i < 16 && i >= 0) {
												_tmp0[i][j] = _tmp0[i][j] + B[i][k][l] * C[k][j] * D[l][j];
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
					} else {
					}
				}
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
