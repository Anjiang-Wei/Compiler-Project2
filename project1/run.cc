#include <iostream>
#include <random>

#include "run.h"

bool test_case18(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    int A[8][6] = {{0}};
    int B[10][10] = {{0}};
    int C[9][64] = {0};
    int scalar = int(dis(gen) * 1000);
    if (scalar == 0){
        scalar += 1;
    }
    int goldenA[8][6] = {{0}};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 6; ++j) {
            A[i][j] = int(dis(gen) * 1000);
            goldenA[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            B[i][j] = int(dis(gen) * 1000);
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 64; ++j) {
            C[i][j] = int(dis(gen) * 1000);
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            goldenA[i][j] = (B[i][j] + B[i+1][j] + C[i+2][j*j]) % scalar;
        }
    }
    try {
        kernel_additional_case18(B, C, scalar, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (std::abs(goldenA[i][j] - A[i][j]) >= 1e-5) {
                std::cout << std::abs(goldenA[i][j] - A[i][j]) << " " << i << " "<< j << std::endl;
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}
bool test_case17(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[5][5] = {{0}};
    float B[5][5] = {{0}};
    float C[7] = {0};
    float goldenA[5][5] = {{0}};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            B[i][j] = dis(gen);
            goldenA[i][j] = B[i][j];
        }
    }
    for (int i = 0; i < 7; ++i) {
        C[i] = dis(gen);
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; j++) {
            if (i + j < 7) {
                goldenA[i][j] += C[i + j];
            }
        }        
    }
    try {
        kernel_additional_case17(B, C, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (std::abs(goldenA[i][j] - A[i][j]) >= 1e-5) {
                std::cout << std::abs(goldenA[i][j] - A[i][j]);
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}



bool test_case16(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    int A[16][32] = {{0}};
    int B[16][32] = {{0}};
    int C[32][32] = {{0}};
    int D[16][32] = {{0}};
    int alpha = int(dis(gen) * 10000);
    int beta = int(dis(gen) * 10000);
    int golden[16][32] = {{0}};
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            B[i][j] = int(dis(gen) * 10000);
        }
    }
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            C[i][j] = int(dis(gen) * 10000);
        }
    }
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            D[i][j] = int(dis(gen) * 10000);
        }
    }
    // compute golden
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            for (int k = 0; k < 32; ++k) {
                golden[i][j] = golden[i][j] + alpha / (B[i][k] * C[k][j]);
            }
            //std::cout << (beta * 1000 - 500) << "/" << (D[i][j] * 10 + 100) << std::endl;
            golden[i][j] = golden[i][j] + int((beta * 1000 - 500) / (D[i][j] * 10 + 100));
        }
    }
    try {
        kernel_additional_case16(B, C, D, alpha, beta, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (std::abs(golden[i][j] - A[i][j]) >= 1e-5) {
                std::cout << std::abs(golden[i][j] - A[i][j]);
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_case15(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[2][2] = {0};
    float B[2][2] = {0};
    float C[2][2] = {0};
    float D[2][4] = {0};
    float E[4][2] = {0};
    float goldenC[2][2] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            D[i][j] = dis(gen);
            E[j][i] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                goldenC[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                goldenC[i][j] += D[i][k] * E[k][j];
            }
        }
    }
    try {
        kernel_additional_case15(A, B, D, E, C);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; j++) {
            if (std::abs(goldenC[i][j]- C[i][j]) >= 1e-5) {
            std::cout << "Wrong answer in A\n";
            return false;
            }
        }        
    }
    // correct
    return true;
}


bool test_case14(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
     float A[2][2] = {0};
    float B[2][2] = {0};
    float C[2][2] = {0};
    float D[2][4] = {0};
    float E[4][2] = {0};
    float goldenC[2][2] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            D[i][j] = dis(gen);
            E[j][i] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                goldenC[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                goldenC[i][j] += D[i][k] * E[k][j];
            }
        }
    }
    try {
        kernel_additional_case14(A, B, D, E, C);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; j++) {
            if (std::abs(goldenC[i][j]- C[i][j]) >= 1e-5) {
            std::cout << "Wrong answer in A\n";
            return false;
            }
        }        
    }
    // correct
    return true;
}

bool test_case13(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[3] = {0};
    float B[3] = {0};
    float C[3] = {0};
    float goldenA[3] = {0};
    for (int i = 0; i < 3; ++i) {
        A[i] = dis(gen);
        B[i] = dis(gen);
        C[i] = dis(gen);
    }
    // compute golden
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            goldenA[i] += B[j];
        }
        for (int k = 0; k < 3; k++) {
            goldenA[i] += C[k];
        }
    }
    try {
        kernel_additional_case13(B, C, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 3; ++i) {
        //std:: cout << "A[i]=" << A[i] << std::endl;
        //std:: cout << "goldentmp[j][i]=" << goldentmp[j][i] << std::endl;
        if (std::abs(goldenA[i]- A[i]) >= 1e-5) {
            std::cout << "Wrong answer in A\n";
            return false;
        }
    }
    // correct
    return true;
}


bool test_case12(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[3] = {0};
    float B[3] = {0};
    float C[3] = {0};
    float D[3] = {0};
    float goldenA[3] = {0};
    for (int i = 0; i < 3; ++i) {
        A[i] = dis(gen);
        B[i] = dis(gen);
        C[i] = dis(gen);
        D[i] = dis(gen);
    }
    // compute golden
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    goldenA[i] += (B[j] + C[k]) * D[l] / 3;
                }
            }
        }
    }
    try {
        kernel_additional_case12(B, C, D, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 3; ++i) {
        //std:: cout << "A[i]=" << A[i] << std::endl;
        //std:: cout << "goldentmp[j][i]=" << goldentmp[j][i] << std::endl;
        if (std::abs(goldenA[i]- A[i]) >= 1e-5) {
            std::cout << "Wrong answer in A\n";
            return false;
        }
    }
    // correct
    return true;
}

bool test_case11(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    int A[32][16] = {{0}};
    int goldenB[32][16] = {{0}};
    int goldentmp[16][32] = {{0}};
    int B[32][16] = {{0}};
    int tmp[16][32] = {{0}};
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            A[i][j] = (int) dis(gen) * 100000;
            B[i][j] = (int) dis(gen) * 100000;
            tmp[j][i] = (int) dis(gen) * 100000;
        }
    }
    // compute golden
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            goldenB[i][j] = A[i][j] * A[i][j];
            goldentmp[j][i] = goldenB[i][j];
        }
    }
    try {
        kernel_additional_case11(A, B, tmp);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            //std:: cout << "B[i][j]=" << B[i][j] << std::endl;
            //std:: cout << "goldentmp[j][i]=" << goldentmp[j][i] << std::endl;
            if (std::abs(goldenB[i][j] - B[i][j]) >= 1e-5) {
                std::cout << "Wrong answer in B\n";
                return false;
            }
            if (std::abs(goldentmp[j][i] - tmp[j][i]) >= 1e-5) {
                std::cout << "Wrong answer in tmp\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_example(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[32][16] = {{0}};
    float golden[32][16] = {{0}};
    float B[32][16] = {{0}};
    float C[32][16] = {{0}};
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            B[i][j] = dis(gen);
            C[i][j] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            golden[i][j] = B[i][j] * C[i][j];
        }
    }
    try {
        kernel_example(B, C, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (std::abs(golden[i][j] - A[i][j]) >= 1e-5) {
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_case1() {
    float A[32][16] = {{0}};
    float golden[32][16] = {{0}};
    // compute golden
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            golden[i][j] = 2;
        }
    }
    try {
        kernel_case1(A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (std::abs(golden[i][j] - A[i][j]) >= 1e-5) {
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_case4(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[16][32] = {{0}};
    float B[16][32] = {{0}};
    float C[32][32] = {{0}};
    float golden[16][32] = {{0}};
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            B[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            C[i][j] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            for (int k = 0; k < 32; ++k) {
                golden[i][j] = golden[i][j] + B[i][k] * C[k][j];
            }
        }
    }
    try {
        kernel_case4(B, C, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (std::abs(golden[i][j] - A[i][j]) >= 1e-5) {
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_case5(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[16][32] = {{0}};
    float B[16][32] = {{0}};
    float C[32][32] = {{0}};
    float D[16][32] = {{0}};
    float alpha = dis(gen);
    float beta = dis(gen);
    float golden[16][32] = {{0}};
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            B[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            C[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            D[i][j] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            for (int k = 0; k < 32; ++k) {
                golden[i][j] = golden[i][j] + alpha * (B[i][k] * C[k][j]);
            }
            golden[i][j] = golden[i][j] + beta * D[i][j];
        }
    }
    try {
        kernel_case5(B, C, D, alpha, beta, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (std::abs(golden[i][j] - A[i][j]) >= 1e-5) {
                std::cout << std::abs(golden[i][j] - A[i][j]);
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_case6(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[2][8][5][5] = {{{{0}}}};
    float B[2][16][7][7] = {{{{0}}}};
    float C[8][16][3][3] = {{{{0}}}};
    float golden[2][8][5][5] = {{{{0}}}};
    for (int n = 0; n < 2; ++n) {
        for (int c = 0; c < 16; ++c) {
            for (int h = 0; h < 7; ++h) {
                for (int w = 0; w < 7; ++w) {
                    B[n][c][h][w] = dis(gen);
                }
            }
        }
    }
    for (int k = 0; k < 8; ++k) {
        for (int c = 0; c < 16; ++c) {
            for (int r = 0; r < 3; ++r) {
                for (int s = 0; s < 3; ++s) {
                    C[k][c][r][s] = dis(gen);
                }
            }
        }
    }
    // compute golden
    for (int n = 0; n < 2; ++n) {
        for (int k = 0; k < 8; ++k) {
            for (int p = 0; p < 5; ++p) {
                for (int q = 0; q < 5; ++q) {
                    for (int c = 0; c < 16; ++c) {
                        for (int r = 0; r < 3; ++r) {
                            for (int s = 0; s < 3; ++s) {
                                golden[n][k][p][q] = golden[n][k][p][q] + B[n][c][p+r][q+s] * C[k][c][r][s];
                            }
                        }
                    }
                }
            }
        }
    }
    try {
        kernel_case6(B, C, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int n = 0; n < 2; ++n) {
        for (int k = 0; k < 8; ++k) {
            for (int p = 0; p < 5; ++p) {
                for (int q = 0; q < 5; ++q) {
                    if (std::abs(golden[n][k][p][q] - A[n][k][p][q]) >= 1e-5) {
                        std::cout << "Wrong answer\n";
                        return false;
                    }
                }
            }
        }
    }
    // correct
    return true;
}


bool test_case7(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[32][16] = {{0}};
    float B[16][32] = {{0}};
    float golden[16][32] = {{0}};
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            A[i][j] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            golden[i][j] = A[j][i];
        }
    }
    try {
        kernel_case7(A, B);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (std::abs(golden[i][j] - B[i][j]) >= 1e-5) {
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


bool test_case10(std::mt19937 &gen, std::uniform_real_distribution<float> &dis) {
    float A[8][8] = {{0}};
    float B[10][10] = {{0}};
    float golden[8][8] = {{0}};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            B[i][j] = dis(gen);
        }
    }
    // compute golden
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            golden[i][j] = (B[i][j] + B[i+1][j] + B[i+2][j])/3;
        }
    }
    try {
        kernel_case10(B, A);
    } catch (...) {
        std::cout << "Failed because of runtime error\n";
        return false;
    }

    // check
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (std::abs(golden[i][j] - A[i][j]) >= 1e-5) {
                std::cout << "Wrong answer\n";
                return false;
            }
        }
    }
    // correct
    return true;
}


int main() {
    std::random_device rd;  // get random seed
    std::mt19937 gen(rd()); // standard
    std::uniform_real_distribution<float> dis(-10, 10);
    std::cout << "Random distribution ready\n";
    // example
    std::cout << "Example ";
    bool res = test_example(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }
    // cases
    std::cout << "Case 1 ";
    res = test_case1();
    if (res) {
        std::cout << "Success!\n";
    }
    std::cout << "Case 2 is hidden\n";
    std::cout << "Case 3 is hidden\n";
    std::cout << "Case 4 ";
    res = test_case4(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }
    std::cout << "Case 5 ";
    res = test_case5(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }
    std::cout << "Case 6 ";
    res = test_case6(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }
    std::cout << "Case 7 ";
    res = test_case7(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }
    std::cout << "Case 8 is hidden\n";
    std::cout << "Case 9 is hidden\n";
    std::cout << "Case 10 ";
    res = test_case10(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 11 ";
    res = test_case11(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 12 ";
    res = test_case12(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 13 ";
    res = test_case13(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 14 ";
    res = test_case14(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 15 ";
    res = test_case15(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 16 ";
    res = test_case16(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 17 ";
    res = test_case17(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }

    std::cout << "Case additional 18 ";
    res = test_case18(gen, dis);
    if (res) {
        std::cout << "Success!\n";
    }
    return 0;
}