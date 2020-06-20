#include "../run.h"

void kernel_case2(float (&A)[16][8]) {
	float _tmp0[16][8] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 8; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + A[i][j];
			_tmp0[i][j] = _tmp0[i][j] + 2;
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 8; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
