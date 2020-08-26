#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class textCombiner {
	string fileName;
	int Month;
	int Year;

public:
	textCombiner() {

	}
	textCombiner(string name, int M, int Y=2020) {
		fileName = name;
		Month = M;
		Year = Y;
	}

};
int main() {


	// 기초 입력 시스템 
	int destMonth,destYear;
	cout << "합병할 파일들을 같은 폴더에 삽입하고, 합병할 월을 입력하시오.(07월, 12월) >> ";
	cin >> destMonth;
	cout << endl<< "연도를 입력하시오. 기본 년도는 2020년으로 간주합니다. >> ";
	cin >> destYear;
	// 기초 입력 종료
	string destName = to_string(destYear) + "년도" + to_string(destMonth)+"월차 일기";

	textCombiner case01(destName, destMonth, destYear);

  
}