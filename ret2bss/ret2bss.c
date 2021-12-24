#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char globalbuff[256];

void function(char* input) {
	char localbuf[256];
	strcpy(localbuf, input);
	strcpy(globalbuf, localbuf);
}

int main(int argc, char** argv) {
	function(argv[1]);
}