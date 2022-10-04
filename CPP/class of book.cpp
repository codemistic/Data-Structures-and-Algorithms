#include <iostream>
using namespace std;

class book {
	int pages;
	int ISSN;
	public:
	//Special member function => Constructor
	//No parameter constructor => Default Constructor
	book() {
		pages = 103;
		ISSN = 4;
	}

	//Parameterised Constructor
	book(int page, int issn) {
		pages = page;
		ISSN = issn;
	}

	void display() {
		cout<<"pages: "<<pages<<endl;
		cout<<"issn: "<<ISSN<<endl;
	}
};

int main() {
	// your code goes here
	book holy, sherlock(8, 500), madman;
	holy.display();
	sherlock.display();
	madman.display();
	return 0;
}
/*#include <iostream>
using namespace std;

class book {
	int pages;
	int ISBN;
	public:
	//Default constructor
	book() {
		pages = 350;
		ISBN = 1234;
	}

	//Parameterised constructor
	book(int Pages, int isbn) {
		pages = Pages;
		ISBN = isbn;
	}

	void display() {
		cout<<"Pages : "<<pages<<endl;
		cout<<"ISBN : "<<ISBN<<endl;
	}

};

int main() {
	// your code goes here
	book OOPS, OOPS1(300, 4567);
	OOPS.display();
	OOPS1.display();
	return 0;
}*/

