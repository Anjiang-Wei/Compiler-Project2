#include "../run.h"

void kernel_case3(int (&B)[16][32], int (&C)[16][32],int (&A)[16][32]) {
	int _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			if (j < 32 && j >= 0) {
				if (i < 16 && i >= 0) {
					if (j < 32 && j >= 0) {
						if (i < 16 && i >= 0) {
							_tmp0[i][j] = _tmp0[i][j] + B[i][j];
						} else {
						}
					} else {
					}
				} else {
				}
			} else {
			}
			if (j < 32 && j >= 0) {
				if (i < 16 && i >= 0) {
					_tmp0[i][j] = _tmp0[i][j] + C[i][j];
				} else {
				}
			} else {
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
