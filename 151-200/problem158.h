//
// Created by brayden on 2020-08-02.
//

#ifndef INC_151_200_PROBLEM158_H
#define INC_151_200_PROBLEM158_H

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    char tmp[4];
    int tmpPtr = 0;
    int tmpCnt = 0;
    int read(char *buf, int n) {
        int total = 0;
        while (total < n) {
            if (tmpPtr == 0) {
                tmpCnt = read4(tmp);
            }
            while (total < n && tmpPtr < tmpCnt) {
                buf[total++] = tmp[tmpPtr++];
            }
            if (tmpPtr == tmpCnt) tmpPtr = 0;
            if (tmpCnt < 4) break;
        }
        return total;
        // Write your code here
    }
};
#endif //INC_151_200_PROBLEM158_H
