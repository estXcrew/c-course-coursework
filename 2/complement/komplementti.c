#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* input_str;
    int input_strlen;
    int output_sum;
    int cur_pow;
    int is_negative;
    int max_value;
    int i;

    input_str = argv[1];
    input_strlen = strlen(input_str);
    output_sum = 0;
    cur_pow = 0;
    is_negative = 0;


    if (input_str[0] == '1') {
        is_negative = 1;
    }

    for (i = input_strlen - 1; i >= 0; i--) {
        if (input_str[i] == '1') {
            output_sum += (int)pow(2, cur_pow);
        }
        cur_pow++;
    }

    if (is_negative) {
        max_value = (int)pow(2, input_strlen); 
        output_sum = output_sum - max_value;
    }

    printf("%d\n", output_sum);

    return 0;
}
