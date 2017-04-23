#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool readTahoeData(char* filename, float lake[420][210]){
    float input;
    char temp;
    /*for(int i = 0 ; i < 10 ; i++){
        input[i] = '\0';
    }*/
    ifstream fin;
    fin.open(filename);


    int row = 0;
    int column = 0;

    if(fin.good()){
        int length;
        int width;
        fin >> length;
        fin >> width;
        if(length != 420){
            cerr << "Error: Wrong row dimensions." << endl;
            return false;
        }
        if(width != 210){
            cerr << "Error: Wrong column dimensions." << endl;
            return false;
        }


        //cout << length << " " << width << endl;
        while(row < 420){

            if(column > 209){
                column = 0;
                row++;
            }

            if (row == 420) {
                break;
            }

            fin >> lake[row][column];
            //cout << lake[row][column] << endl;

            while (fin.peek() == ',' || fin.peek() == ' ')
            {
                temp = fin.get();
            }

            column++;
            /*
            for(int i = 0 ; i < 10 ; i++){
                input[i] = '\0';
            }*/

        }
    }
    return true;
}

void cleanData(float lake[420][210]){
    float average = 0;
    float lake2[420][210];
    for(int i = 0 ; i < 420 ; i++){
        for(int j = 0 ; j < 210 ; j++){
            lake2[i][j] = lake[i][j];
        }
    }

    for(int i = 1 ; i < 419 ; i++){
        for(int j = 1 ; j < 209 ; j++){
            average = lake2[i-1][j-1] + lake2[i-1][j] + lake2[i-1][j+1] + lake2[i][j-1] + lake2[i][j+1] + lake2[i+1][j-1] + lake2[i+1][j] + lake2[i+1][j+1];
            average /= 8;
            average = round(average*10)/10;
            if(abs(lake2[i][j] - average) > 100){
                lake[i][j] = average;
            }
            average = 0;
        }
    }
}

float area(float lake[420][210]){
    float area = 0;
    for(int i = 0 ; i < 420 ; i++){
        for(int j = 0 ; j < 210 ; j++){
            if(lake[i][j] < 0){
                area++;
            }
        }
    }
    area *= 10000;
    return area;
}

float volume(float lake[420][210]){
    float volume = 0;
    for(int i = 0 ; i < 420 ; i++){
        for(int j = 0 ; j < 210 ; j++){
            if(lake[i][j] < 0){
                volume += lake[i][j];
            }
        }
    }
    volume *= 10000;
    return -volume;
}
/*
int main(int argc, char* argv[]){
    float input[420][210];
    char filename[] = "LakeTahoeDEM.csv";
    readTahoeData(filename, input);


    cout << area(input) << endl << volume(input) << endl;
    cleanData(input);
    cout << area(input) << endl << volume(input) << endl;






    return 0;
}
*/
