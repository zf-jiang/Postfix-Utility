#include <iostream>
#include <string>
#include <iomanip>

#include "postfixUtility.h"

using namespace std;
postFix calc;

int main(int argc, char** argv)
{
	char* infix = argv[1];
	string postfix = calc.getPostfix(infix);
	float result = calc.evaluatePostfix(postfix);
	cout << fixed << setprecision(1) << result << endl;

	return 0;
}
