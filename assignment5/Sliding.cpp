#include <iostream>
#include <climits>
using namespace std;

int convertToIntArray(int argc, char* argv[], int array[]){
	int j = 1;	//index of argv
	if(argc > 22){
		cerr << "Error: too many input arguments; maximum 21 permitted." << endl;
		return -22;
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

int slideAvg(int inputVoltages[], int sampleSize, 
			 int windowSize, float slidingAverage[]){
	if(windowSize > sampleSize){
			cerr << "Error: Window Size too big." << endl;
			return -1;
		}
	int k = 0;
	while((k + windowSize-1) < sampleSize){
		float oneWindow = 0;

		for(int i = k ; i < (k +windowSize) ; i++){
			oneWindow += inputVoltages[i];
		}
		
		slidingAverage[k] = oneWindow/windowSize;
		
		k++;
	}
	
	return k;

}

void displayHistogram(int numElements, float array[]){
	cout << "100V------105V------110V------115V------120V------125V------130V------135V------140V" << endl;
	
	float pointFive = 0.5;
	
	float copyOfArray[numElements];
	
	for(int i = 0 ; i < numElements ; i++){
		copyOfArray[i] = array[i];
	}
	
	for(int i = 0 ; i < numElements ; i++){
		float m = 0;
		while(copyOfArray[i]/0.5 >= 0.5){
			m += 0.5;
			copyOfArray[i] -= 0.5;
		}
		if(copyOfArray[i] >= 0.25){
			m += 0.5;
		}
		copyOfArray[i] = m;
	}
	
	
	for(int i = 0 ; i < numElements ; i++){
		if(array[i]>140){
			cout << "#################################################################################+" << endl;	
		}
		else if(array[i]<100){
			cout << "!" << endl;
		}
		else{
			copyOfArray[i] -= 100;
			cout << "#";
			while(copyOfArray[i] / pointFive > 0){
				cout << "#";
				copyOfArray[i] -= 0.5;
			}
			cout << endl;
		}
	}
}

int main(int argc, char* argv[]){
	if(argc < 2){
		cerr << "Error: No arguments." << endl;
		return -1;
	}
	
	int array[argc];
	
	if(convertToIntArray(argc, argv, array) >= 0){
		int inputVoltage[argc-2];
		int sampleSize = argc - 2;
		int windowSize =  array[0];
		float slidingAverage[argc - windowSize];
	
		if(windowSize > sampleSize || windowSize > 20 || windowSize == 0){
			cerr << "Error: Window Size too big." << endl;
			return -1;
		}
		else if(windowSize < 0){
			cerr << "Error: Can't have negative window size." << endl;
			return -1;
		}
		for(int i = 0 ; i < argc-2 ; i++){	//inputVoltage setup
			inputVoltage[i] = array[i+1];
		}
		
		/*for(int i = 0 ; i < argc-2 ; i++){
			cout << inputVoltage[i] << endl;
		}
		
		for(int i = 0 ; i < argc-1 ; i++){
			cout << array[i] << endl;
		}*/
		
		cout << slideAvg(inputVoltage, sampleSize, windowSize, slidingAverage) << endl;
		
		for(int i = 0 ; i < argc - windowSize-1 ; i++){
			cout << slidingAverage[i] << endl;
		}
		
		//////CONVERT inputVoltage TO floatInputVoltage ///////
		
		float floatInputVoltage[argc];
		
		for(int i = 0 ; i < argc ; i++){
			floatInputVoltage[i] = (float)inputVoltage[i];
		}
		
		displayHistogram(sampleSize, floatInputVoltage);
		displayHistogram(argc - windowSize - 1, slidingAverage);
	}
	return 0;
	
	
	

	return 0;
}