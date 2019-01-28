#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {

    int s;
    int invertedN;
    string file;
    string magic;
    string height;
    string width;
    string max;
    ifstream input;
    ofstream output;

    cout << "Enter relative file path:";        //User input relative file path
    cin >> file;





    input.open(file, ifstream::in);             //Opens original file

    if (!input.is_open()) {                     //Outputs error to the console if the file isn't found
        cerr << "File Cannot Be Found\n";
        exit(1);
    }

    output.open("invert." + file, ofstream::out);

    if (!output.is_open()) {
        cerr << "Could not open invert.file.txt\n";     //Outputs error to the console if the file isn't found
        exit(1);
    }





    input >> magic >> height>> width >> max;    //Getting the first 4 values that aren't being inverted

    int maxN = stoi(max);                       //Changes the max value string type to an integer in order to perform arithmetic operations
                                                //with that value

    output << magic << endl << height << " " <<width << endl<< max << endl;     //Outputting values in the correct format

    while (input >> s) {                        //Reads entire file
        invertedN= maxN - s;                    //Arithmetic operations to invert rgb values
        output << invertedN << " ";             //Outputs inverted values to invert.fileName
    }

    output.close();                             //Closing output file
    input.close();                              //Closing input file

    return 0;
}
