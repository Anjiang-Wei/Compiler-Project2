#include "../run2.h"

void grad_case6(float (&C)[8][16][3][3], float (&dA)[2][8][5][5],float (&dB)[2][16][7][7]) {
	float _tmp0[2][16][7][7] = {0};
	for (int n = 0; n < 2; ++n) {
		for (int c = 0; c < 16; ++c) {
			for (int z0 = 0; z0 < 7; ++z0) {
				for (int z1 = 0; z1 < 7; ++z1) {
					for (int k = 0; k < 8; ++k) {
						for (int r0 = 0; r0 < 3; ++r0) {
							for (int r1 = 0; r1 < 3; ++r1) {
								if (z1 - r1 < 5 && z1 - r1 >= 0) {
									if (z0 - r0 < 5 && z0 - r0 >= 0) {
										_tmp0[n][c][z0][z1] = _tmp0[n][c][z0][z1] + dA[n][k][z0 - r0][z1 - r1] * C[k][c][r0][r1];
									} else {
									}
								} else {
								}
							}
						}
					}
				}
			}
		}
	}
	for (int n = 0; n < 2; ++n) {
		for (int c = 0; c < 16; ++c) {
			for (int z0 = 0; z0 < 7; ++z0) {
				for (int z1 = 0; z1 < 7; ++z1) {
					dB[n][c][z0][z1] = _tmp0[n][c][z0][z1];
				}
			}
		}
	}
}
