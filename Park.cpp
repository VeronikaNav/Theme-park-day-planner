#include <iostream>
#include <string>
#include <vector>
#include < iomanip >
using namespace std;

class Children {
private:
	string name;
	int age;
	char vegetarion;
	char likescheese;
	string atraction;
	double costAtr;
	string eat;
	double eatCost;
public:
	Children() = default;
	string getNa() const { return name; }
	int getAg() const { return age; }
	char getVeg() const { return vegetarion; }
	char getLik() const { return likescheese; }
	string getAtr() const { return atraction; }
	double getCo() const { return costAtr; }
	string getEa() const { return eat; }
	double getEc() const { return eatCost; }



	void setNa(string n) { name = n; }
	void setAg(int a) { age = a; }
	void setVeg(char v) { vegetarion = v; }
	void setLik(char l) { likescheese = l; }
	void setAtr(string at) { atraction = at; }
	double setCo(double co) { costAtr = co; }
	void setEa(string ea) { eat = ea; }
	double setEc(double ec) { eatCost = ec; }


	void infAboutchildren (int numchild) {
		cout << "Child" << numchild << ":" << endl;
		cout << "Name:" << endl;
		cin >> name;
		cout << "Age:" << endl;
		cin >> age;
		cout << "Vegetarion? (Y/N):" << endl;
		cin >> vegetarion;
		cout << "Like cheese? (Y/N):" << endl;
		cin >> likescheese;

	}

	//стоимость атракциона и сам атракцион
	void costAtracAndPlace() {
		if (age < 5) {
			atraction = "Ferris wheel / Contact zoo with sheep";
			costAtr = 0.0;
		}
		else if (age >= 5 && age <= 12) {
			atraction = "Cups / Laser Tag";
			costAtr = 15.0;
		}
		else if (age>15){
			atraction = "Roller Coaster / Zipline";
			costAtr = 20.0;
		}
	}

	//стоимость обеда и подходит ребенку или нет
	void costEatAndwhat() {
		if (vegetarion =='N') {
			if (likescheese=='Y') {
				eat = "Cheeseburger";
				eatCost = 3.50;
			}
			else {
				eat = "Hamburger";
				eatCost = 3.25;
			}
		}
		else {
			if (likescheese=='Y') {
				eat = "Cheese Pizza";
				eatCost = 2.50;
			}
			else {
				eat="Happy Garden meal";
				eatCost = 1.75;
			}
		}
	}


	//выводим для каждого ребенка информацию куда и что 
	void displayInf() const {
		cout << name << " will be going on the " << atraction << "." << endl;
		cout << "Pack a " << eat << " for " << name << "!\n" << endl;
	}
	
	//Расчет общей стоимости втрвкцион + обед
	double CulcAll() const {
		return costAtr + eatCost;
	}
};

// класс для заполнения информации и нумерацмии о ребенке 
vector<Children> inputchild(int numchild) {
	vector<Children> child;
	child.reserve(numchild);
	cout << "Welcome to the Theme Park Planner! Please input each kid's information.\n" << endl;

	for (int i = 0; i < numchild; i++) {
		Children children;
		children.infAboutchildren(i + 1);
		children.costAtracAndPlace();
		children.costEatAndwhat();
		child.push_back(children);

	}
	return child;
}

//фунция для отображения информации о ребенке 

void displayInfAbChild(const vector<Children>& child) {
	for (const auto& children : child) {
			children.displayInf();
	}
}

//функция для расчета общей стоимости 

double staryculc(const vector<Children>& child) {
	double  staryculc = 0.0;

	for (const auto& children : child) {
		staryculc += children.CulcAll();
	}
	return staryculc;
}

	void displaySummary(const vector<Children>&child, double  staryculc) {
	cout<<fixed<<setprecision(2);
	cout << "The total cost for the day is: " << staryculc << "$" << endl;
	cout << "The average cost per kid is: " << staryculc / child.size() << "&" << endl;
}



int main(){
	const int maxchild = 10;
	vector<Children> child = inputchild(maxchild);
	displayInfAbChild(child);
	double CulcAll = staryculc(child);
	displaySummary(child, CulcAll);
	return 0;
}