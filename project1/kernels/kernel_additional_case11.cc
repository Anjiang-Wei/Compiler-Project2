#include "../run.h"

void kernel_additional_case11(int (&A)[32][16],int (&B)[32][16], int (&tmp)[16][32]) {
	int _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + A[j][i] * A[j][i];
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			tmp[i][j] = _tmp0[i][j];
		}
	}
	int _tmp1[32][16] = {0};
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 16; ++j) {
			_tmp1[i][j] = _tmp1[i][j] + tmp[j][i];
		}
	}
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 16; ++j) {
			B[i][j] = _tmp1[i][j];
		}
	}
}
