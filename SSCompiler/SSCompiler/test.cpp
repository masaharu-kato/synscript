#include "test.h"
#include <iostream>
#include <fstream>
#include <string>
#include <functional>

bool runTest(
	std::function<std::string(std::string)> target_func,
	const char* input_file_path,
	const char* answer_file_path) {

	std::ifstream ifile(input_file_path);
	if(ifile.fail()) { std::cout << "[Error] Failed to load input file.\n";  return false; }
	
	std::ifstream afile(answer_file_path);
	if(afile.fail()) { std::cout << "[Error] Failed to load answer file.\n"; return false; }

	int index = 1;
	int n_correct = 0;
	while(true){

		std::string istr, astr;
		auto ist = (bool)getline(ifile, istr);
		auto ast = (bool)getline(afile, astr);
		if(!ist && !ast) break;
		if(!ist || !ast) { std::cout << "[Error] Number of cases not match.\n"; break; }

		auto rstr = target_func(istr);

		std::cout << "#" << index << ":";

		if(rstr == astr) {
			std::cout << " OK\n";
			n_correct++;
		}else{
			std::cout << "\n";
			std::cout << "[I] " << istr << "\n";
			std::cout << "[R] " << rstr << "\n";
			std::cout << "[A] " << astr << "\n";
			std::cout << "\n";
		}

		index++;
	}

	int n_case = index;
	int n_fail = n_case - n_correct;

	std::cout << "\n";
	std::cout << n_case << " cases, ";
	std::cout << n_correct << " (" << int((double)n_correct / n_case * 100) << "%) ok, ";
	std::cout << n_fail    << " (" << int((double)n_fail    / n_case * 100) << "%) fails.\n";

	if(index == n_correct) {
		std::cout << "Congratulations!\n";
		return true;
	}
	
	return false;
}
