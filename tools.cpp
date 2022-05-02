#include "tools.h"

void warn(std::string& tmp){
	std::cout << FONT_COLOR_RED + tmp + END_COLOR;
}

void warn(char const* tmp){
	printf("\033[0;31m%s\033[0m", tmp);
}