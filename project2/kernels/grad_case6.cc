#include "../run2.h"

void grad_case6(float (&B)[2][16][7][7], float (&C)[8][16][3][3], float (&dA)[2][8][5][5],float (&dB)[2][16][7][7]) {
	float _tmp0[2][16][7][7] = {0};
	for (int n = 0; n < 2; ++n) {
		for (int c = 0; c < 16; ++c) {
			for (int p = 0; p < 5; ++p)  + (int r = 0; r < 3; ++r) {
				for (int q = 0; q < 5; ++q)  + (int s = 0; s < 3; ++s) {
					for (int k = 0; k < 8; ++k) {
						if (q + s < 7 && q + s >= 0) {
							if (p + r < 7 && p + r >= 0) {
								if (q + s < 7 && q + s >= 0) {
									if (p + r < 7 && p + r >= 0) {
										_tmp0[n][c][p + r][q + s] = _tmp0[n][c][p + r][q + s] + (dA[n][k][p][q] * C[k][c][r][s] + B[n][c][p + r][q + s] * 0);
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
	}
	for (int n = 0; n < 2; ++n) {
		for (int c = 0; c < 16; ++c) {
			for (int p = 0; p < 5; ++p)  + (int r = 0; r < 3; ++r) {
				for (int q = 0; q < 5; ++q)  + (int s = 0; s < 3; ++s) {
					dB[n][c][p + r][q + s] = _tmp0[n][c][p + r][q + s];
				}
			}
		}
	}
}
