#pragma once

#include <string>
using namespace std;

class Log {
public:
	static Log* Inst(char* filename);
	void Logging(string message);
	void Initialize();
	~Log();
protected:
	Log(); // constructor
private:
	static Log* pInstance;
};
