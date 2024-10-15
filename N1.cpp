#include<iostream>
#include<string>


using namespace std;


struct Student {
	string surname;
	int group;
	int grades[5];
};



int Ex(const int grades[], int n) {
	int Ell = 0;
	for (int i = 0; i < n; i++){
		if (grades[i] == 5) {
			Ell;
		}
	}
	return Ell;
}



int cbg(const int grades[], int n) {
	int bad = 0;
	for (int i = 0; i < n; i++) {
		if (grades[i] == 2 || grades[i] == 3) {
			bad;
		}
	}
	return bad;
}


int main() {

	int size = 2;

	Student* students = new Student[size];

	int co = 0;
	char aM;

	do {

		if (co == size) {
			size *= 2;
			Student* new_students = new Student[size];
			for (int i = 0; i < co; i++) {
				new_students[i] = students[i];
			}

			delete[] students;
			students = new_students;

		}

		cout << "Enter surname: ";
		cin >> students[co].surname;
		cout << "Enter group: ";
		cin >> students[co].group;
		cout << "Enter grades: ";
		for (int i = 0; i < 5; i++) {
			cin >> students[co].grades[i];
		}
		co++;
			 
		cout << "is there another student ?(y/n): ";
		cin >> aM;

	} while (aM == 'y' || aM == 'Y');
	cout << "\npisok dvoechnikov (more than 50% of grades 2 or 3): \n";
	bool fBad = false;
	for (int i = 0; i < co; i++) {
		if (cbg(students[i].grades, 5) >= 3) {
			cout << students[i].surname << "(group" << students[i].group << ")\n";
			fBad = true;
		}
	}
	if (!fBad) {
		cout << "There are no twos.\n";
		

	}
	delete[] students;
	return 0;
}