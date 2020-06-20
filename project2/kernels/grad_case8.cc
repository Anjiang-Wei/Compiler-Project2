#include "../run2.h"

void grad_case8(float (&dB)[32],float (&dA)[2][16]) {
	float _tmp0[2][16] = {0};
	for (int z0 = 0; z0 < 2; ++z0) {
		for (int z1 = 0; z1 < 16; ++z1) {
			if ((z0 * 16 + z1) < 32 && (z0 * 16 + z1) >= 0) {
				_tmp0[z0][z1] = _tmp0[z0][z1] + dB[(z0 * 16 + z1)];
			} else {
			}
		}
	}
	for (int z0 = 0; z0 < 2; ++z0) {
		for (int z1 = 0; z1 < 16; ++z1) {
			dA[z0][z1] = _tmp0[z0][z1];
		}
	}
}
