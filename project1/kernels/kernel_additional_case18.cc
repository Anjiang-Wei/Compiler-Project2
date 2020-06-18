#include "../run.h"

void kernel_additional_case18(int (&B)[10][10], int (&C)[9][64], int &scalar,int (&A)[8][6]) {
	int _tmp0[8][6] = {0};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 6; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + 0;
		}
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 6; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
	int _tmp1[8][6] = {0};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (j * j < 64 && j * j >= 0) {
				if (i + 2 < 9 && i + 2 >= 0) {
					if (i + 1 < 10 && i + 1 >= 0) {
						_tmp1[i][j] = _tmp1[i][j] + (B[i][j] + B[i + 1][j] + C[i + 2][j * j]) % scalar;
					} else {
					}
				} else {
				}
			} else {
			}
		}
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 6; ++j) {
			A[i][j] = _tmp1[i][j];
		}
	}
}
