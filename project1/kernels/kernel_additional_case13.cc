#include "../run.h"

void kernel_additional_case13(float (&B)[3], float (&C)[3],float (&A)[3]) {
	float _tmp0[3] = {0};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			_tmp0[i] = _tmp0[i] + B[j];
		}
		for (int k = 0; k < 3; ++k) {
			_tmp0[i] = _tmp0[i] + C[k];
		}
	}
	for (int i = 0; i < 3; ++i) {
		A[i] = _tmp0[i];
	}
}
