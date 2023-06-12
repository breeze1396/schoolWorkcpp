#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include <iomanip>
using namespace std;


struct Student {
    string name;
    int score;
    Student(string n, int s) :
        name(n), score(s)
    { }
};

void print_ranks_and_scores(vector<Student>& students) {
    cout << setw(10) << right << "name" << " "
        << setw(4) << "score" << " "
        << setw(2) << "rank" << endl;
    sort(students.begin(), students.end(), [](Student& a, Student& b) { return a.score > b.score; });
    int rank = 0;
    int prev_score = -1;
    for (Student& student : students) {
        if (student.score != prev_score) rank++;
        cout << setw(10) << right << student.name << " "
            << setw(4) << student.score << " "
            << setw(2) << rank << endl;
        prev_score = student.score; 
    }
}

int main()
{
    vector<Student> students;
    students.push_back(Student("zhangsan", 95));
    students.push_back(Student("lisi", 85));
    students.push_back(Student("liwenjie", 35));
    students.push_back(Student("chenhao", 55));
    students.push_back(Student("zhaoqi", 65));

    print_ranks_and_scores(students);
}