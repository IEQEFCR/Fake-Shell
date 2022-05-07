#ifndef TOOLS
#define TOOLS

#include <cstring>
#include <iostream>

#define FONT_COLOR_KAI "\033[38;5;43m"
#define FONT_COLOR_RED "\033[0;31m"
#define FONT_COLOR_BLUE "\033[38;5;69m"
#define END_COLOR "\033[0m"

void warn(std::string& tmp);
void warn(char const* tmp);



#endif