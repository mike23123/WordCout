// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 256

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return 1;
    }

    char* parameter = argv[1];
    char* input_file_name = argv[2];

    FILE* fp = fopen(input_file_name, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", input_file_name);
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    int in_word = 0;

    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        }
        else {
            if (!in_word) {
                in_word = 1;
            }
            char_count++;
        }
    }

    if (in_word) {
        word_count++;
    }

    fclose(fp);

    if (strcmp(parameter, "-c") == 0) {
        printf("字符数: %d\n", char_count);
    }
    else if (strcmp(parameter, "-w") == 0) {
        printf("单词数: %d\n", word_count);
    }
    else {
        printf("Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return 1;
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
