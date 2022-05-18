class Solution {
public:
    int reverse(int x) {
        // -2147483648 to 2147483647 (10 digits)
        int multiplier = 1;
        if (x < 0) multiplier = -1;
        int y = abs(x);

        int arr[10]; // 0 is the highest
        int digits = 0;
        while (y > 0) {
            int rem = y % 10;
            y = y / 10;
            arr[digits] = rem;
            digits++;
        }

        // check for overflow
        if (digits == 10) {
            if (arr[0] > 2) { // first digit
                return 0;
            } else if (arr[0] == 2) {
                if (arr[1] > 1) { // second digit 
                    return 0;
                } else if (arr[1] == 1) {
                    if (arr[2] > 4) { // third digit 
                        return 0;
                    } else if (arr[2] == 4) {
                        if (arr[3] > 7) { // fourth digit 
                            return 0;
                        } else if (arr[3] == 7) {
                            if (arr[4] > 4) { // fifth digit 
                                return 0;
                            } else if (arr[4] == 4) {
                                if (arr[5] > 8) { // sixth digit 
                                    return 0;
                                } else if (arr[5] == 8) {
                                    if (arr[6] > 3) { // seventh digit 
                                        return 0;
                                    } else if (arr[6] == 3) {
                                        if (arr[7] > 6) { // eigth digit 
                                            return 0;
                                        } else if (arr[7] == 6) {
                                            if (arr[8] > 4) { // ninth digit 
                                                return 0;
                                            } else if (arr[8] == 4) {
                                                if (multiplier == -1 && arr[9] > 8) { // tenth digit and negative
                                                    return 0;
                                                } else if (multiplier == 1 && arr[9] > 7) { // tenth digit and positive
                                                    return 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //convert
        int res = 0;
        for (int i = digits - 1; i >= 0; i--) {
            // eg digits = 3, stored in index 0, 1, and 2
            // i goes from 2 to 1 to 0, we want to multiply by 10^0, 10^1, 10^2, so power is digits - 1 - i
            int power = pow(10, digits - 1 - i);
            res += arr[i] * power;
        }
        res = res * multiplier;

        return res;
    }
};