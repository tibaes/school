#include <bits/stdc++.h>

typedef struct Student { int id, grade; } Student;

int main() {
  int N;
  std::cin >> N;
  while (N--) {
    int M;
    std::cin >> M;
    std::vector<Student> students;
    for (int sid = 0; sid < M; ++sid) {
      int g;
      std::cin >> g;
      students.push_back(Student{sid, g});
    }
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) {
                return (a.grade >= b.grade);
              });
    int unchanged = 0;
    for (int sid = 0; sid < M; ++sid) {
      if (students[sid].id == sid)
        unchanged++;
    }
    std::cout << unchanged << std::endl;
  }
  return 0;
}
