#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>

struct commandStruct{
	uint64_t id;
	char* name;
	char* desc;
	uint64_t cantArgs;
	
};
#define C_HELP 0
#define C_EXIT 1
#define C_TIME 2
#define C_PRINTMEM 3
#define C_INFOREG 4
#define C_ARACNOID 5
#define C_OPCODEEX 6
#define C_ZERODIVEX 7
#define C_CLEAR 8


void printMemASM(uint64_t address);
void printMem(char* address);
void infoReg();
void time();
void aracnoid();
void exit();
void zeroDivException();
void invalidopCodeException();
uint64_t getRegister(uint64_t reg);
void clear();

#endif