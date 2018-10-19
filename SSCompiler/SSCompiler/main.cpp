#include <iostream>
#include "test.h"
#include "parse.h"

int main(void) {

	runTest(parse, "test01.in.txt", "test01.ans.txt");

	system("pause");
	return 0;
}
