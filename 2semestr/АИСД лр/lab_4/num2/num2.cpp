#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); 

    int N;
    cout << "������� ���������� ����������: ";
    cin >> N;

    if (N <= 0 || N >= 10000) {
        cout << "������������ ���������� ����������!" << endl;
        return 1;
    }

    vector<int> scores(N);
    for (int& score : scores) {
        score = rand() % 100 + 1; 
    }

    sort(scores.rbegin(), scores.rend());

    cout << "\n����� ���������� (�� ��������):\n";
    for (int s : scores) cout << s << " ";
    cout << "\n\n";

    vector<int> unique_scores;
    if (!scores.empty()) {
        unique_scores.push_back(scores[0]);
        for (int i = 1; i < scores.size(); ++i) {
            if (scores[i] != unique_scores.back()) {
                unique_scores.push_back(scores[i]);
            }
        }
    }

    int third_grade_cutoff;
    if (unique_scores.size() >= 3) {
        third_grade_cutoff = unique_scores[2];
    }
    else {
        third_grade_cutoff = unique_scores.back();
    }

    int count = 0;
    for (int s : scores) {
        if (s >= third_grade_cutoff) {
            count++;
        }
        else {
            break;
        }
    }

    cout << "���������� �������: " << count << endl;

    return 0;
}