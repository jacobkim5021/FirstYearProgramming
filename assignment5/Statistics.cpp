#include <iostream>
#include <climits>
using namespace std;

int maxIndexInArray(int a[], int start, int end){
	if(start > end || start < 0 || end < 0){
		return -1;
	}
	int ret = start;
	for(int i = start+1; 1 <= end; i++){
		if(a[i] > a[ret]){
			ret = i;
		}
	}
	return ret;
}

int StrToInt(char* a, int* i){
	int j = 0;
	while(a[j] != '\0'){
		i[j] = a[j] - 48; 
		j++;
	}
	return j;
}

int convertToIntArray(int argc, char* argv[], int array[]){
	int j = 1;	//index of argv
	if(argc > 21){
		cerr << "Error: too many input arguments; maximum 20 permitted." << endl;
		return -21;
	}
	
	
	while(argv[j] != '\0'){
		int k = 0;	//index of argv[j]
		bool negative = false;
		if(argv[j][0] == '-'){
			negative = true;
			k++;
		}
		int m = 0;
		while(argv[j][k] != '\0'){
			if(argv[j][k] != '0' && argv[j][k] != '1' && argv[j][k] != '2' && argv[j][k] != '3' && argv[j][k] != '4' && argv[j][k] != '5' && argv[j][k] != '6' && argv[j][k] != '7' && argv[j][k] != '8' && argv[j][k] != '9'){
				cerr << "Error: Argument " << j << " is not an integer." << endl;
				return -j;
			}
			if(m > INT_MAX/10){
				cerr << "Error: Argument " << j << " is not an integer." << endl;
				return -j;
			}
			
			m *= 10;
			m += argv[j][k] - 48;
			k++;
		}
		array[j-1] = m;
		if(negative == true){
			array[j-1] = array[j-1]*(-1);
		}
		j++;
	}
	
	
	return j-1;
}

int findMax(int array[], int numElements){
	int max = INT_MIN;
	for(int i = 0 ; i < numElements-1 ; i++){
		if(max <= array[i]){
			max = array[i];
		}
	}
	return max;
}

int findMin(int array[], int numElements){
	int min = INT_MAX;
	for(int i = 0 ; i < numElements-1 ; i++){
		if(min >= array[i]){
			min = array[i];
		}
	}
	return min;
}

float average(int array[], int numElements){
	float avg = 0;
	for(int i = 0 ; i < numElements-1 ; i++){
		avg += array[i];
	}
	avg = avg/(numElements-1);
	return avg;
}

int main(int argc, char* argv[]){
	
	if(argc < 2){
		cerr << "Error: No integers." << endl;
		return -1;
	}
	
	int array[argc];
	
	if(convertToIntArray(argc, argv, array) >= 0){
		for(int i = 0 ; i < argc-1 ; i++){
			cout << array[i] << endl;
		}
		
		cout << "Maximum: " << findMax(array, argc) << endl;
		cout << "Minimum: " << findMin(array, argc) << endl;
		cout << "Average: " << average(array, argc) << endl;
		
	}
	return 0;
}