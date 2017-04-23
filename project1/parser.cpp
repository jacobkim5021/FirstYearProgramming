#include <iostream>
#include <fstream>

using namespace std;

char clearInput(char* input, int size){
	for(int j = 0 ; j < size ; j++){
			input[j] = '\0';
		}
	return input[size];
}

int checkRegister(char* input, int i){
	if(input[i] == 'R'){					
		if(input[i+1] == '1'||input[i+1] == '2'||input[i+1] == '3'||input[i+1] == '4'||input[i+1] == '5'||input[i+1] == '6'||input[i+1] == '7'||input[i+1] == '8'||input[i+1] == '9'){
			if(input[i+2] == '0'||input[i+2] == '1'||input[i+2] == '2'||input[i+2] == '3'||input[i+2] == '4'||input[i+2] == '5'||input[i+2] == '6'||input[i+2] == '7'||input[i+2] == '8'||input[i+2] == '9'||input[i+2] == ','||input[i+2] == '\0'||input[i+2] == '\t'||input[i+2] == ' '||input[i+2] == '\n'){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}

int checkNumber(char* input, int i){
	if(input[i] == '1'||input[i] == '2'||input[i] == '3'||input[i] == '4'||input[i] == '5'||input[i] == '6'||input[i] == '7'||input[i] == '8'||input[i] == '9'||input[i] == '-'||input[i] == '0'){
		while(input[i+1] == '1'||input[i+1] == '2'||input[i+1] == '3'||input[i+1] == '4'||input[i+1] == '5'||input[i+1] == '6'||input[i+1] == '7'||input[i+1] == '8'||input[i+1] == '9'||input[i+1] == '0'){
			i++;
		}
		if(input[i+1] != ',' && input[i+1] != ' ' && input[i+1] != '\t' && input[i+1] != '\0'){
			return 0;
		}
		else{
			return 1;
		}
		
	}
	else{
		return 0;
	}
}

bool labelAtEnd(char* input, int lineCounter){
	if(input[7] == 'O' && input[8] == 'n' &&lineCounter == 1){
		return true;
	}
	else{
		return false;
	}
}

int convertToInt(char* input, int i){
	int labelValue = 0;
	int g = 0;
	while(input[i] != ' ' && input[i] != '\t' && input[i] != '\0' && input[i] != '\n'){
		g *= 10;
		g += input[i] - 48;
		i++;
	}
	return g;
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

void ErrorMsg(int d){
	cerr << "Error on line " << d << ": opcode operand missing invalid extra directive duplicate." << endl;
	cerr << "Error on line 8: opcode operand missing invalid extra directive duplicate." << endl;
}

int checkLabel(char* input,int i, char* letters, char* LETTERS){

	for(int k = 0 ; k < 27 ; k++){
		if(input[i] == letters[k] || input[i] == LETTERS[k]){
			while(input[i] != ':' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
				i++;
				
			}
			
			if(input[i] == ':'){
				return 1;
			}
			else{
				return 0;
			}
		}
		
	}
	return 0;
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
	
	bool code = false;
	bool EndCode = false;
	
	
	char input[100];
	int comments = 0;
	int lineCounter = 0;
	int codeLineCounter = 0;
	int opcodeCounter = 0;
	int registers = 0;
	int operands = 0;
	int CodeLabelValue;
	
	char LETTERS[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
	char letters[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
	
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
	
	char labels[15][100];
	int labelcount = 0;
	int z = 0;
	bool labelAtEndBool = false;
	for(int w = 0 ; w < 15 ; w++){
		for(int q = 0 ; q < 100 ; q++){
			labels[w][q] = '\0';
		}
	}
	
	clearInput(input, 100);
	
	while(fin.getline(input, 100)){
		lineCounter++;
		
		if(labelAtEnd(input, lineCounter) == true){
			labelAtEndBool = true;
		}
		if(labelAtEndBool == false){
			ErrorMsg(lineCounter);
		}
		
			int m = 0;
			m = skipWhiteSpace(input, m);
			if(checkRegister(input, m) == 1){
				cerr << "Error on line " << lineCounter << ": Invalid / missing  opcode " << endl;
			}
			else if(checkNumber(input, m) == 1){
				cerr << "Error on line " << lineCounter << ": Invalid / missing  opcode " << endl;
			}
			else if(input[m] == '['){
				cerr << "Error on line " << lineCounter << ": Invalid / missing  opcode " << endl;
			}
				
			for(int i = 0 ; i < 100 ; i++){		//counts comments
				if(input[i] == '#'){
					comments++;
					i = 100;						//go get next line
				}
				
				else if(input[i] == '\t' || input[i] == ' '){	//get next line
					i = skipWhiteSpace(input, i);
					if(input[i] == '#'){
						comments++;
						i = 100;						//go get next line
					}
				}
				
				if(input[i] == 'E' && input[i+1] == 'n' && input[i+2] == 'd' && input[i+3] == 'C' && input[i+4] == 'o' && input[i+5] == 'd' && input[i+6] == 'e'){
					cout << "EndCode: 406" << endl;
					EndCode = true;
					i+=8;
				}
				
				if(input[i] == 'C' && input[i+1] == 'o' && input[i+2] == 'd' && input[i+3] == 'e'){
					while(input[i] != ':'){
						i++;
					}
					if(input[i] == ':'){
						i++;
					}
					i = skipWhiteSpace(input, i);
					if(checkNumber(input, i) == 1){
						CodeLabelValue = convertToInt(input, i);
						cout << "Code: " << CodeLabelValue << endl;
						codeLineCounter = CodeLabelValue;
					}
					code = true;
				}
				else if(input[i] == 'D' && input[i+1] == 'a' && input[i+2] == 't' && input[i+3] == 'a'){
					while(input[i] != ':'){
						i++;
					}
					if(input[i] == ':'){
						i++;
					}
					i = skipWhiteSpace(input, i);
					if(checkNumber(input, i) == 1){
						cout << "Data: " << convertToInt(input, i) << endl;
					}
				}
				
				else if(checkLabel(input, i, letters, LETTERS) == 1 && EndCode == false){
					labelcount++;
					
					while(input[i] != ':'){
						labels[labelcount-1][z] = input[i];
						cout << labels[labelcount-1][z];
						i++;
						z++;
					}
					
					z = 0;
					cout << ": " << codeLineCounter << endl;
					
					
				}
				EndCode = false;
				
				for(int o = 0; o < 20; o++){
					char* g = OPCODE[o];
					int mm = opcode(input, g, i);
					
					
					
					switch(opcode(input, g, i)){
						case 0:
							
							break;
						case 1:
							if(code == false){
								cerr << "Error on line " << lineCounter << ": no directive found." << endl;
							}
							codeLineCounter++;
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
								case 1:		//ADD	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid register as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 0:		//ADDi	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid integer as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 3:		//SUB
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 2:		//SUBi	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid integer as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 18:	//MUL	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 4:		//MULi	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid integer as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 19:	//DIV	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 5:		//DIVi	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid integer as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as third operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 6:		//JMP 
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
								/*if(input[i] != '['){
									cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
								}
								i++;
								
								for(int k = 0 ; k < 27 ; k++){
									if(input[i] == letters[k] || input[i] == LETTERS[k]){
										while(input[i] != ']'){
										
											i++;
										
										}
									}
								}
								
								if(input[i] != ']'){
									cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
								}
								i++;*/
								if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
									cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
								}
									break;
								case 7:		//JZ
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / extra invalid address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									
									
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 8:		//JNZ
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid extra address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 11:	//JGZ
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid extra address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 12:	//JGEZ
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / extra invalid address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 9:		//JLZ
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / extra invalid address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 10:	//JLEZ
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(input[i] == '['){
										i++;
										for(int k = 0 ; k < 27 ; k++){
											if(input[i] == letters[k] || input[i] == LETTERS[k]){
												while(input[i] != ']'){
												
													i++;
												
												}
											}
										}
										if(input[i] != ']'){
											cerr << "Error on line " << lineCounter << ": Invalid / missing format / label." << endl;
										}
										i++;
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / extra invalid address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 16:	//SD	
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid register as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'&& input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing or invalid register or address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 14:	//LD	//can have registers OR integers following them
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing or invalid register or address as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'&& input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing/invalid register as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 13:	//LDi
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid integer as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid register as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
									}
									break;
								case 15:	//SDi	//LDi and SDi must have integer following them
									if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										if(input[i] == ','){
											i++;
										}
										else{
											cerr << "Error on line " << lineCounter << ": Missing operands / Invalid format. Missing a comma." << endl;
										}
										i = skipWhiteSpace(input, i);
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing / invalid integer as first operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'){
											i++;
										}
										if(input[i] == ','){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(checkRegister(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else if(checkNumber(input, i) == 1){
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t'&& input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
										
									}
									else{
										cerr << "Error on line " << lineCounter << ": Missing or invalid register or address as second operand." << endl;
										while(input[i] != ',' && input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
											i++;
										}
										i = skipWhiteSpace(input, i);
									}
									if(input[i] != ' '&&input[i] != '#'&&input[i] != '\t'&&input[i] != '\0'){
										cerr << "Error on line " << lineCounter << ": Missing / invalid / extra operands." << endl;
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
				i = skipWhiteSpace(input, i);
				
				}
				

		clearInput(input, 100);
	
	
	
	
	
	
	
	
	}
	cout << "Total number of assembly instructions: " << opcodeCounter << endl;
	cout << "Number of Load/Store: " << loadstore << endl;
	cout << "Number of ALU: " << ALU << endl;
	cout << "Number of Compare/Jump: " << jumps << endl;
	
	fin.close();
}