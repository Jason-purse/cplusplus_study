//
// Created by CQSF on 2022/7/21.
//

int idempoent(int x, int y) {
    for(int index = 0 ; index < y; index ++) {
        // 幂次方
        x *= x;
    }
    return x;
}