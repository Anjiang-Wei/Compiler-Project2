#include "../run2.h"

void grad_case4(float (&B)[16][32], float (&C)[32][32], float (&dA)[16][32],float (&dB)[16][32], float (&dC)[32][32]) {
	float _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int k = 0; k < 32; ++k) {
			for (int j = 0; j < 32; ++j) {
				if (j < 32 && j >= 0) {
					if (k < 32 && k >= 0) {
						if (j < 32 && j >= 0) {
							if (i < 16 && i >= 0) {
								if (k < 32 && k >= 0) {
									if (i < 16 && i >= 0) {
										_tmp0[i][k] = _tmp0[i][k] + dA[i][j] * C[k][j];
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
	for (int i = 0; i < 16; ++i) {
		for (int k = 0; k < 32; ++k) {
			dB[i][k] = _tmp0[i][k];
		}
	}
	float _tmp1[32][32] = {0};
	for (int k = 0; k < 32; ++k) {
		for (int j = 0; j < 32; ++j) {
			for (int i = 0; i < 16; ++i) {
				if (j < 32 && j >= 0) {
					if (i < 16 && i >= 0) {
						if (k < 32 && k >= 0) {
							if (i < 16 && i >= 0) {
								if (j < 32 && j >= 0) {
									if (k < 32 && k >= 0) {
										_tmp1[k][j] = _tmp1[k][j] + B[i][k] * dA[i][j];
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
	for (int k = 0; k < 32; ++k) {
		for (int j = 0; j < 32; ++j) {
			dC[k][j] = _tmp1[k][j];
		}
	}
}
