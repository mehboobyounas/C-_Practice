#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct subject {
    int creditHours;
    float GPA;
    float qualityGPA;
};
class Calculator {
private:
    vector<subject> subjects;
public:
    subject s;
    int numOfSubjects;
    void addDetails() {
        cout << "Enter Number of Subjects for CGPA Calculation: "; cin >> numOfSubjects;
        for (int i = 0; i < numOfSubjects; i++) {
            cout << "Enter GPA of subject "<<i+1<<": "; cin >> s.GPA;
            cout << "Enter Credit Hours of Subject "<< i+1<<": "; cin >> s.creditHours;
            s.qualityGPA = s.GPA*s.creditHours;
            subjects.push_back(s);}
    }
    int totalCreditHours() {
        int totalhours = 0;
        for (int i = 0; i < numOfSubjects; i++) {
            totalhours += subjects[i].creditHours;
        }
        return totalhours;
    }
    float qGPA() {
        float finalGPA =0;
        for (int i=0; i<numOfSubjects; i++) {
            finalGPA += subjects[i].qualityGPA;
        }
        return finalGPA;
    }
    float CGPA() {
        int totalhours =totalCreditHours();
        float finalGPA =qGPA();
        float CGPA;

        if (totalhours <= 0) {
            return 0.0f;
        };
        CGPA = qGPA()/totalhours;
        cout << "Your Final CGPA is " << CGPA << endl;
        return CGPA;
    }


};

int main() {
    Calculator c;
    c.addDetails();
    c.CGPA();
}