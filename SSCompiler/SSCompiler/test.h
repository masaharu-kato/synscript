#pragma once
#include <string>
#include <functional>

bool runTest(
	std::function<std::string(std::string)> target_func,
	const char* input_file_path,
	const char* answer_file_path
);
