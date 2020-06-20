#include "../run.h"

void kernel_case1(float (&A)[32][16]) {
	float _tmp0[32][16] = {0};
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (j < 16 && j >= 0) {
				if (i < 32 && i >= 0) {
					_tmp0[i][j] = _tmp0[i][j] + 2;
				} else {
				}
			} else {
			}
		}
	}
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 16; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
