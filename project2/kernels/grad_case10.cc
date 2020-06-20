#include "../run2.h"

void grad_case10(float (&dA)[8][8],float (&dB)[10][8]) {
	float _tmp0[10][8] = {0};
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (j < 8 && j >= 0) {
				if (i < 8 && i >= 0) {
					if (j < 8 && j >= 0) {
						if (i < 10 && i >= 0) {
							_tmp0[i][j] = _tmp0[i][j] + dA[i][j] / 3;
						} else {
						}
					} else {
					}
				} else {
				}
			} else {
			}
			if (j < 8 && j >= 0) {
				if (i - 1 < 8 && i - 1 >= 0) {
					_tmp0[i][j] = _tmp0[i][j] + dA[i - 1][j] / 3;
				} else {
				}
			} else {
			}
			if (j < 8 && j >= 0) {
				if (i - 2 < 8 && i - 2 >= 0) {
					_tmp0[i][j] = _tmp0[i][j] + dA[i - 2][j] / 3;
				} else {
				}
			} else {
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			dB[i][j] = _tmp0[i][j];
		}
	}
}
