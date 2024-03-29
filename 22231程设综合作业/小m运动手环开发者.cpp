#include <iostream>
#include <sstream>
#include <iomanip>
class SportRun: public Sport {
	public:
		SportRun(int m, int l): Sport(m, l) {}
		string getDescription() {
			std::stringstream ss;
			ss<< minutes;
			string s=ss.str();
			return("You're running for "+ s+" minute(s)");
		} int getSportIntensity() {
			return ((minutes/10)*level);
		}
};

class SportBicycle: public Sport {
	public:
		SportBicycle(int m, int l): Sport(m, l) {}
		string getDescription() {
			std::stringstream ss;
			ss<< minutes;
			string s=ss.str();
			return("You're riding for "+ s+" minute(s)");
		} int getSportIntensity() {
			return ((minutes/5)*level*(minutes/5));
		}
};

class SportRun: public Sport {
	public:
		SportRun(int m, int l): Sport(m, l) {}
		string getDescription() {//将数值转化为字符串
			string s=to_string(minutes);
			return ("You're running for "+s+" minute(s)");

		}
		int getSportIntensity() {

			return minutes/10*level;
		}
};

class SportBicycle: public Sport {
	public:
		SportBicycle(int m, int l): Sport(m, l) {}
		string getDescription() {//将数值转化为字符串
			return ("You're riding for "+to_string(minutes)+" minute(s)");
		}
		int getSportIntensity() {
			return (minutes/5)*(minutes/5)*level;
		}
};


