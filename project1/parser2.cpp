#include <iostream>
#include <fstream>

using namespace std;

char clearInput(char* input, int size){
	for(int j = 0 ; j < size ; j++){
			input[j] = '\0';
		}
	return input[size];
}

int opcode(char* input, char* compare, int i){
	for(int j = 0 ; j < 5 ; j++){
		if(input[i+j] == compare[j] || compare[j] == '\0'){
			
		}
		else{
			return 0;
		}
	}
	return 1;
}

int label(char* input, int i){
	int j = i;
	int ret = 0;
	while(input[j] > 64 && input[j] < 123){
		ret = 1;
		
		j++;
	}
	return ret;
}

int skipWhiteSpace(char* input, int i){
	if(input[i] == '\t' || input[i] == ' '){
		while(input[i] == '\t' || input[i] == ' '){
			i++;
		}
	}
	return i;
}



int main(int argc, char* argv[]){
	
	if(argc > 2 || argc == 1){
		cerr << "Error: Invalid argument format." << endl;
		return -1;
	}
	
	ifstream fin;
	
	fin.open(argv[1]);
	
	if(!fin.is_open()){
		cerr << "Error: FILE NOT FOUND";
		return -1;
	}
	int loadstore = 0;
	int ALU = 0;
	int jumps = 0;
	
	char input[100];
	int lineCounter = 0;
	int comments = 0;
	int opcodeCounter = 0;
	int registers = 0;
	int operands = 0;
	//char LETTERS[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	//char letters[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char ADDi[5] = {'A', 'D', 'D', 'i'};
	char ADD[5] = {'A', 'D', 'D', '\0'};
	char SUBi[5] = {'S', 'U', 'B', 'i'};
	char SUB[5] = {'S', 'U', 'B', '\0'};
	char MULi[5] = {'M', 'U', 'L', 'i'};
	char DIVi[5] = {'D', 'I', 'V', 'i'};
	char JMP[5] = {'J', 'M', 'P', '\0'};
	char JZ[5] = {'J', 'Z', '\0', '\0'};
	char JNZ[5] = {'J', 'N', 'Z', '\0'};
	char JLZ[5] = {'J', 'L', 'Z', '\0'};
	char JLEZ[5] = {'J', 'L', 'E', 'Z'};
	char JGZ[5] = {'J', 'G', 'Z', '\0'};
	char JGEZ[5] = {'J', 'G', 'E', 'Z'};
	char LDi[5] = {'L', 'D', 'i', '\0'};
	char LD[5] = {'L', 'D', '\0', '\0'};
	char SDi[5] = {'S', 'D', 'i', '\0'};
	char SD[5] = {'S', 'D', '\0', '\0'};
	char HALT[5] = {'H', 'A', 'L', 'T'};
	char MUL[5] = {'M', 'U', 'L', '\0'};
	char DIV[5] = {'D', 'I', 'V', '\0'};
	char* OPCODE[21] = {ADDi, ADD, SUBi, SUB, MULi, DIVi, JMP, JZ, JNZ, JLZ, JLEZ, JGZ, JGEZ, LDi, LD, SDi, SD, HALT, MUL, DIV};
	
	

	clearInput(input, 100);
	
	while(fin.getline(input, 100)){
	lineCounter++;						
	
		for(int i = 0 ; i < 100 ; i++){		//counts comments
			if(input[i] == '#'){
				comments++;
				i = 100;						//go get next line
			}
			
			else if(input[i] == '\t' || input[i] == ' '){
				i = skipWhiteSpace(input, i);
				if(input[i] == '#'){
					comments++;
					i = 100;						//go get next line
				}
			}
			
			
			
			for(int o = 0; o < 20; o++){
				char* g = OPCODE[o];
				int mm = opcode(input, g, i);
				
				
				
				switch(opcode(input, g, i)){
					case 0:
						/*if(o == 19 && i<100 && input[i] != '\0' && input[i] != ' ' && input[i] != '\t'){
							int f = label(input, i);
							if(f == 1){
								while(input[i] > 64 && input[i] < 123){
									i++;
								}
								if(input[i] != ':'){
									cerr << "Error: junk code on line " << lineCounter << endl;
									i+=100;
								}
								else{
									i = skipWhiteSpace(input, i);
									
								}
							}
							else{
								cerr << "Error: junk on line " << lineCounter << endl;
								i+=100;
							}
							
						}
						*/
						break;
					case 1:
						//cout << "Line " << lineCounter << " opcode: " << OPCODE[o] << endl;
						
						opcodeCounter++;
						int x = 0;
						
						for(int t = 0 ; t < 6 ; t++){
							if(g[t] != '\0'){
								x++;
							}
						}
						i += x;
						
						if(input[i] == '\t' || input[i] == ' '){
							while(input[i] == '\t' || input[i] == ' '){
								i++;
							}
						}
						
						if(o <= 5 || o == 18 || o == 19){
							ALU++;
						}
						else if(o >= 13 && o <= 16){
							loadstore++;
						}
						else if(o >= 6 && o <= 12){
							jumps++;
						}
						
						
						switch(o){	//FIRST OPERAND STAGE
							case 1:		//ADD	-
							case 0:		//ADDi	-
							case 3:		//SUB	-
							case 2:		//SUBi	-
							case 18:	//MUL	-
							case 4:		//MULi	-
							case 19:	//DIV	-
							case 5:		//DIVi	-
							case 7:		//JZ
							case 8:		//JNZ
							case 11:	//JGZ
							case 12:	//JGEZ
							case 9:		//JLZ
							case 10:	//JLEZ
							case 16:	//SD	
								
								if(input[i] == 'R'){					//just counts registers
									for(int k = 1 ; k < 10 ; k++){
									char temp1 = '0'+k;
										if(input[i+1] == temp1){
											registers++;
										}
									}
									i += 2;
									if(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
										cerr << "Error on line " << lineCounter << ": Expected Register for first OPERAND opcode operand missing duplicate extra invalid";
										i+=100;
									}
									i++;
								}
								/*else if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
									while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										i++;
									}
									if(input[i] != ',' && input[i] != ' '){
										cerr << "Error on line " << lineCounter << endl;
										i+=100;
									}
									else if(input[i] == ' ' || input[i] == '\t'){
										i = skipWhiteSpace(input, i);
										if(input[i] != ',' && input[i] != ' '){
											cerr << "Error on line2 " << lineCounter << endl;
											i+=100;
										}
										else{
											i++;
											operands++;
										}
									}
									else{
										i++;
										operands++;
									}
									
								}*/
								else{
									cerr << "Error:  opcode operand missing duplicate extra invalid Invalid: First operand must be a register on line " << lineCounter << endl;
									i+=100;
								}
								
								i = skipWhiteSpace(input, i);	//SECOND OPERAND
								
								///////////////////////////////////////////////////////////////////
								
								if(o == 1||o == 3||o == 18||o == 19){	//ALU
									//ALU++;
									if(input[i] == 'R'){					//just counts registers
										for(int k = 1 ; k < 10 ; k++){
										char temp6 = '0'+k;
											if(input[i+1] == temp6){
												registers++;
											}
										}
										i += 2;
										if(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											cerr << "Invalid register on line " << lineCounter << endl;
											i+=100;
										}
										i++;
									}
									else{
										cerr << "Error: opcode operand missing duplicate extra invalid Invalid Must have a register as second operand of line " << lineCounter << endl;
										i+=100;
									}
									i = skipWhiteSpace(input, i);	////THIRD OPERAND FOR ALU
									/*if(o==1||o==3||o==18||0==19){ */				//ADD, SUB, MUL, DIV
									if(input[i] == 'R'){					//just counts registers
										for(int k = 1 ; k < 10 ; k++){
										char temp6 = '0'+k;
											if(input[i+1] == temp6){
												registers++;
											}
										}
										i += 2;
										if(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											cerr << "Invalid register on line " << lineCounter << endl;
											i+=100;
										}
									i++;
									}
									else{
										cerr << "Error:  opcode operand missing duplicate extra invalid Invalid Third operand of this line must be a register" << endl;
										i += 100;
									}
									/*}	
									else{										
										if(input[i] != ' ' && input[i] != '\t' && input[i] != '\0' && input[i] != '#'){
											cerr << "Wrong LD format on line " << lineCounter << endl;
											i += 100;
										}
									}*/
								}
								
								if(o == 0||o == 2||o == 4||o == 5){		//INTEGER ALUs
									//ALU++;
									if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
											i++;
										}
										if(input[i] != ',' && input[i] != ' ' && input[i] != '\0' && input[i] != '\n'){
											cerr << "Error: opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
											i+=100;
										}
										else if(input[i] == ' ' || input[i] == '\t'){
											i = skipWhiteSpace(input, i);
											if(input[i] != ',' && input[i] != ' '){
												cerr << "Error: opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
												i+=100;
											}
											else{
												i++;
												operands++;
											}
										}
										else{
											i++;
											operands++;
										}
										
									}
									else{
										cerr << "Error: opcode operand missing duplicate extra invalid  Invalid: Second operand must be a integer on line " << lineCounter << endl;
										i+=100;
									}
								
									i = skipWhiteSpace(input, i);	////////THIRD OPERAND FOR INTEGER ALUs
									
									if(input[i] == 'R'){					//just counts registers
										for(int k = 1 ; k < 10 ; k++){
										char temp1 = '0'+k;
											if(input[i+1] == temp1){
												registers++;
											}
										}
										i += 2;
										if(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											cerr << "Invalid register on line " << lineCounter << endl;
											i+=100;
										}
										i++;
									}
									else{
										cerr << "Error:  opcode operand missing duplicate extra invalid  Invalid Third operand must be a register on line " << lineCounter << endl;
										i+=100;
									}

								}
								
								if(o == 16){	//SD
									//loadstore++;
									if(input[i] == 'R'){					//just counts registers
										for(int k = 1 ; k < 10 ; k++){
										char temp1 = '0'+k;
											if(input[i+1] == temp1){
												registers++;
											}
										}
										i += 2;
										if(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											cerr << "Error:  opcode operand missing duplicate extra invalid Invalid register on line " << lineCounter << endl;
											i+=100;
										}
										i++;
									}
									else if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
											i++;
										}
										if(input[i] != ',' && input[i] != ' '&&input[i] != '\t' && input[i] != '\0'){
											cerr << "Error: opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
											i+=100;
										}
										else if(input[i] == ' ' || input[i] == '\t'){
											i = skipWhiteSpace(input, i);
											if(input[i] != ',' && input[i] != ' '){
												cerr << "Error: opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
												i+=100;
											}
											else{
												i++;
												operands++;
												
											}
										}
										else{
											i++;
											operands++;
											
										}
									
									}
									else{
										cerr << "Error: opcode operand missing duplicate extra invalid  Invalid First operand must be a register on line " << lineCounter << endl;
										i+=100;
									}
								}
								
								if(o == 7||o == 8||o == 9||o == 10||o == 11||o == 12){	//CONDITIONAL JUMPS
									//jumps++;
								}
								/*
								if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
									while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										i++;
									}
									if(input[i] != ',' && input[i] != ' ' && input[i] != '\0' && input[i] != '\n'){
										cerr << "Error1 on line " << lineCounter << endl;
										i+=100;
									}
									else if(input[i] == ' ' || input[i] == '\t'){
										i = skipWhiteSpace(input, i);
										if(input[i] != ',' && input[i] != ' '){
											cerr << "Error2 on line " << lineCounter << endl;
											i+=100;
										}
										else{
											i++;
											operands++;
										}
									}
									else{
										i++;
										operands++;
									}
									
								}
								*/
								break;
							case 14:	//LD	-//can have registers OR integers following them
								//loadstore++;
								if(input[i] == 'R'){					//just counts registers
									for(int k = 1 ; k < 10 ; k++){
									char temp1 = '0'+k;
										if(input[i+1] == temp1){
											registers++;
										}
									}
									i += 2;
									if(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
										cerr << "Error: opcode operand missing duplicate extra invalid Invalid register on line " << lineCounter << endl;
										i+=100;
									}
									i++;
								}
								else if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
									while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										i++;
									}
									if(input[i] != ',' && input[i] != ' '&& input[i] != '\t'){
										cerr << "Error:  opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
										i+=100;
									}
									else if(input[i] == ' ' || input[i] == '\t'){
										i = skipWhiteSpace(input, i);
										if(input[i] != ',' && input[i] != ' '){
											cerr << "Error:  opcode operand missing duplicate extra invalid  Invalid on line2 " << lineCounter << endl;
											i+=100;
										}
										else{
											i++;
											operands++;
											
										}
									}
									else{
										i++;
										operands++;
										
									}
									
								}
								else{
									cerr << "Error:  opcode operand missing duplicate extra invalid Invalid First operand on line " << lineCounter << endl;
									i+=100;
								}
								
								i = skipWhiteSpace(input, i);	//SECOND OPERAND
								
								if(input[i] == 'R'){					//just counts registers
									for(int k = 1 ; k < 10 ; k++){
									char temp1 = '0'+k;
										if(input[i+1] == temp1){
											registers++;
										}
									}
									i += 2;
									if(input[i] != ',' && input[i] != ' ' && input[i] != '\t'&& input[i] != '\0'){
										cerr << "Error:  opcode operand missing duplicate extra invalid Invalid register on line " << lineCounter << endl;
										i+=100;
									}
									i++;
								}
								else{
									cerr << "Error:  opcode operand missing duplicate extra invalid Invalid, Second operand must be a register on line " << lineCounter << endl;
									i+=100;
								}
								
								break;
							case 13:	//-//STILL FIRST OPERAND STAGE
							case 15:	//-//LDi and SDi must have integer following them
								//loadstore++;
								if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
									while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										i++;
									}
									if(input[i] != ',' && input[i] != ' '){
										cerr << "Error: opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
										i+=100;
									}
									else if(input[i] == ' ' || input[i] == '\t'){
										i = skipWhiteSpace(input, i);
										if(input[i] != ',' && input[i] != ' '){
											cerr << "Error: opcode operand missing duplicate extra invalid  Invalid on line " << lineCounter << endl;
											i+=100;
										}
										else{
											i++;
											operands++;
										}
									}
									else{
										i++;
										operands++;
									}
								}
								else{
									cerr << "Error: opcode operand missing duplicate extra invalid  Invalid format on line " << lineCounter << endl;
									i += 100;
								}
								
								i = skipWhiteSpace(input, i);
								
								if(o == 13){ //LDi - SECOND OPERAND
									if(input[i] == 'R'){					//just counts registers
										for(int k = 1 ; k < 10 ; k++){
											char temp3 = '0'+k;
											if(input[i+1] == temp3){
												registers++;
											}
										}
										i += 2;
									}
									else{
										cerr << "Error: opcode operand missing duplicate extra invalid  Invalid format on line " << lineCounter << endl;
										i += 100;
									}
								}
								else if(o == 15){	//SDi - SECOND OPERAND
									if(input[i] == 'R'){					//just counts registers
										for(int k = 1 ; k < 10 ; k++){
											char temp3 = '0'+k;
											if(input[i+1] == temp3){
												registers++;
											}
										}
										i += 2;
									}
									else if(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
										while(input[i] == '-'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='0'){
											i++;
										}
										if(input[i] != ' ' && input[i] != '\t' && input[i] != '\n' && input[i] != '\0' && input[i] != '#'){
											cerr << "Error: opcode operand missing duplicate extra invalid  Invalid SDi format on line " << lineCounter << endl;
											i+=100;
										}
										operands++;
									}
									else{
										cerr << "Error: opcode operand missing duplicate extra invalid  Invalid format on line " << lineCounter << endl;
										i += 100;
									}
								}
								
								break;
							case 17:	//HALT
								cout << "End of code." << endl;
								i+=100;
								break;
						}
					//cout << registers << endl;
					break;	
				}
			
			}
			
		}

		clearInput(input, 100);
	}
	
	//cout << comments << " comments" << endl;
	cout << "Total number of assembly instructions: " << opcodeCounter << endl;
	cout << "Number of Load/Store: " << loadstore << endl;
	cout << "Number of ALU: " << ALU << endl;
	cout << "Number of Compare/Jump: " << jumps << endl;
	
	//cout << registers << " registers" << endl;
	/*operands = operands + registers;*/
	//cout << operands << " operands excluding registors" << endl;
	fin.close();

	
	return 0;
}