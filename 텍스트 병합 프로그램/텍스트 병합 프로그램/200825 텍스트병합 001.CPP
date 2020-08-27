#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class textCombiner {
	string fileNameRet;
	int Month;
	int Year;
	int dayMax;
	string combinedStr;
public:
	textCombiner() {

	}
	textCombiner(string name, int M, int Y = 2020) {
		fileNameRet = name;
		Month = M;
		Year = Y%100;
		combinedStr = name + "\n"; 
		setDayMax();
	}
	void setDayMax() {
		switch (Month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			dayMax = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			dayMax = 30;
			break;
		case 2:
			if (Year % 4 == 0)
				dayMax = 29;
			else
				dayMax = 28;
			break;
		}
	}
	void startCombineInput() {
		for (int day = 1; day <= dayMax; day++) {
			string tmpLines;
			string zeroDay="";
			if (day < 10)
				zeroDay = "0";
			string filenameIn = to_string(Year) + to_string(Month) +zeroDay+ to_string(day);
			ifstream readFile;
			readFile.open(filenameIn);

			if (readFile.is_open()) {
				while (!readFile.eof()) {
					getline(readFile, tmpLines);
				}
			}
			else {
				cout << filenameIn << " Not Found";
			}
			tmpLines += "\n";

			combinedStr += tmpLines;
		}
	}
	void makeFile() {
		ofstream writeFile;
		writeFile.open(fileNameRet);

		writeFile.write(combinedStr.c_str(), combinedStr.size());

		writeFile.close();
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
	case01.startCombineInput();
	case01.makeFile();
	
  
}