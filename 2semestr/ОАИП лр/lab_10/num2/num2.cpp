#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <iostream>

int ackermann(int m, int n) {
    if (m < 0 || n < 0) return -1;  

    if (m == 0) return n + 1;
    if (n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    setlocale(LC_ALL, "ru");
    int m, n;

    printf("������� m (������������� 0-3): ");
    if (scanf("%d", &m) != 1) {
        printf("������ ����� ��� m\n");
        return 1;
    }

    printf("������� n (������������� 0-10): ");
    if (scanf("%d", &n) != 1) {
        printf("������ ����� ��� n\n");
        return 1;
    }

    if (m < 0 || n < 0) {
        printf("������: m � n ������ ���� ����������������.\n");
        return 1;
    }

    if (m > 3 || (m == 3 && n > 10)) {
        printf("��������������: ����� ������� �������� ����� ������� ������������ �����!\n");
    }

    int result = ackermann(m, n);
    if (result == -1) {
        printf("������ ����������: ������������ ���������\n");
    }
    else {
        printf("A(%d, %d) = %d\n", m, n, result);
    }

    return 0;
}