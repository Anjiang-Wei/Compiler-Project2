#include "../run.h"

void kernel_additional_case12(float (&B)[3], float (&C)[3], float (&D)[3],float (&A)[3]) {
	float _tmp0[3] = {0};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					if (l < 3 && l >= 0) {
						if (k < 3 && k >= 0) {
							if (j < 3 && j >= 0) {
								if (i < 3 && i >= 0) {
									_tmp0[i] = _tmp0[i] + (B[j] + C[k]) * D[l] / 3;
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
	for (int i = 0; i < 3; ++i) {
		A[i] = _tmp0[i];
	}
}
