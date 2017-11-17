#include <iostream>
#include <fstream>
#include <vector> 
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std; 
//GLOBAL VARIABLES 


//calls file 
string callFile();
//retrieves keys and calls functions to convert it to binary 
vector<int> getKeys(int i);
const char* hexToBin(char c);
string hexStringToBin(const string& hex);
vector<int> fileToBinary(string s);
vector<int> permutateText(vector<int> bin,vector<int>key);
vector<int> initalPermutation(vector<int> bin);
vector<int> permutateKey(vector<int> bin, int shift);
vector<int> permutedChoiceOne(vector<int> bin);
vector<int> permutedChoiceTwo(vector<int> bin);
vector<int> inputKey(vector<int> bin);
//this is generalized to permutate any vector with any other vector
vector<int> permutation(vector<int> bin, vector<int> perm);
vector<int> expansionPermutation(vector<int> bin);
vector<int> permutationP(vector<int> bin);
vector<int> sBoxes(vector<int> bin);
vector<int> inversePermutation(vector<int> bin);
int binToNum(string s);
string numToBin(int sint);
//full encryption algorithm 
vector<int> encrypt(vector<int> bin, vector<int> key);
//full decryption algorithm 
vector<int> decrypt(vector<int> bin, vector<int> key);
//used to xor two different vectors 
vector<int> xOR(vector<int> li, vector<int> ri); 
//this splits the binary text into 64 bit chunks and then performs triple DES on them (ede) and returns the result in hex form 
string split(vector<int> bin, vector<int> key1, vector<int> key2, vector<int> key3, char ed);
string binToString(string bin);

int main()
{
	ofstream out("output_hex.txt");
	char ed = 'n';
	// int test[] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
   //    vector<int> t(test,test + sizeof(test)/sizeof(test[0]));
    //string test = "02468aceeca86420";
	//int testText[] = {1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1};
    int testText[] = {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1};
        vector<int> testText1(testText,testText + sizeof(testText)/sizeof(testText[0]));

    int testText2a[] = {1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1};
        vector<int> testText2(testText2a,testText2a + sizeof(testText2a)/sizeof(testText2a[0]));



	int testKey[] = {0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
     //int testKey[] = {0,0,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0};
        vector<int> testKey1(testKey,testKey + sizeof(testKey)/sizeof(testKey[0]));


    int testKey2a[] = {1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,1};
     //int testKey[] = {0,0,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0};
        vector<int> testKey2(testKey2a,testKey2a + sizeof(testKey2a)/sizeof(testKey2a[0]));

    int testKey3a[] = {1,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,1};
     //int testKey[] = {0,0,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0};
        vector<int> testKey3(testKey3a,testKey3a + sizeof(testKey3a)/sizeof(testKey3a[0]));


     
    

        vector<int> result; 
        string result1,result2;
    //result = inputKey(testKey1);
    //testKey2 = permutedChoiceOne(testKey1);
    //testKey3 = permutateKey(testKey2,1);
    //result = permutedChoiceTwo(testKey3);
    //result = encrypt(testText1,testKey1);
    //result = initalPermutation(testText1);
    //result = encrypt(testText1,testKey1);
    //result = decrypt(testText1,testKey1);
    result1 = split(testText1,testKey1,testKey2,testKey3,'e');
    //cout << "converter size: " << testConverter.size() << endl;
    //result1 = binToString(testConverter);
    // cout << "T " << t.size() << endl; 
    // cout << t[0] << endl;
    // vector<int> test2 = permutateKey(t,1);
    // vector<int> test3 = permutedChoiceTwo(test2);
    


    result2 = split(testText1,testKey1,testKey2,testKey3,'d');
	cout << "Result: " << result1 << endl;
    cout << "Result decrypt: " << result2 << endl; 
      // for(int i = 0; i<result1.size();i++)
      // 	 cout << result1[i];
      // cout << endl; 



	vector<int> key1,key2,key3; 
	
	string inputs = callFile(); 
	vector<int> temp = fileToBinary(inputs);
	for(int i = 0; i<temp.size();i++)
		cout << "Temp[" << i << "]: " << temp[i] << endl;
	
	cout << endl;



	key1 = getKeys(1);
	key2 = getKeys(2);
	key3 = getKeys(3);

	while(1)
	{
		cout << "Do you want to encrypt or decrypt (e/d)? ";
		cin >> ed; 
		cout << endl; 
		if(ed == 'e' || ed == 'd' || ed == 'D' || ed == 'E')
			break;
	}


	string finalResult = split(temp,key1,key2,key3,ed);
	cout << "Final result = " << finalResult << endl; 
	out << finalResult;
	out.close();

	return 0; 


}



string callFile()
{

	string filename;
	string line;
	cout << "What file would you like to compile? ";
	cin >> filename;
	cout << endl;
	
	ifstream file;
	file.open(filename);
	
	string inputs;
	
	while(file >> line)
	{
		inputs += line + " ";
		cout << "File: " << line  << endl; 
	
	}
	file.close();
	cout << "Read " << inputs.size() << " chars" << endl;


	return inputs;
}



vector<int> getKeys(int i)
{ 
	string key;
	string result;
	vector<int> finalKey(64);
	while(1)
	{
	cout << "Enter key " << i << ": ";
	cin >> key;
	if(key.length() == 16)
		break;
	else 
		cout << "Enter a valid key" << endl;
	}

	result = hexStringToBin(key);

	for(int i = 0; i<result.size();i++)
		if(result[i] == '1')
			finalKey[i] = 1; //static_cast<int>(result[i]);
		if(result[i] == '0')
			finalKey[i] = 0; //static_cast<int>(result[i]);

	return finalKey; 
	
}


const char* hexToBin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    return "null";
}

string hexStringToBin(const string& hex)
{
    // TODO use a loop from <algorithm> or smth
    string bin;
    
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hexToBin(hex[i]);
    return bin;
}

vector<int> fileToBinary(string s)
{
	//turn ascii characters into ascii values 
	//convert them to binary 
	int temp1;
	int temp2; 
	int bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7; 
	int div0,div1,div2,div3,div4,div5,div6,div7;
	vector<int> bin;
	vector<int> asciiValues; 

	if(s.size() % 8 != 0)
		for(int i = 0; i < (s.size() % 64); i++)
			s.push_back('~');


	for(int i = 0; i< s.length(); i++)
	{
		cout << "S[i] == " << s[i] << endl; 
		cout << endl; 
		cout << endl;
		int temp = s[i];
		asciiValues.push_back(temp);
		cout << "Ascii value = " << temp << endl;
		cout << endl;
	}

	cout << "Ascii vector size = " << asciiValues.size() << endl;
	
	for(int i = 0; i<asciiValues.size();i++)
	{
		bit0 = asciiValues[i] % 2; 
		div0 = asciiValues[i] / 2;

		bit1 = div0  % 2;
		div1 = div0 / 2;

		bit2 = div1  % 2;
		div2 = div1 / 2;

		bit3 = div2 % 2;
		div3 = div2 / 2;

		bit4 = div3  % 2;
		div4 = div3 / 2;

		bit5 = div4 % 2;
		div5 = div4 / 2;

		bit6 = div5 % 2;
		div6 = div5 / 2;

		bit7 = div6 % 2;


		bin.push_back(bit7);
		bin.push_back(bit6);
		bin.push_back(bit5);
		bin.push_back(bit4);
		bin.push_back(bit3);
		bin.push_back(bit2);
		bin.push_back(bit1);
		bin.push_back(bit0);

	}
	cout << "Bin size: " << bin.size() << endl; 
	return bin;
}




vector<int> encrypt(vector<int> bin, vector<int> key)
{
	vector<int> r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r17Swapped;
	vector<int> l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l17Swapped;
	vector<int> k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16;
	vector<int> k1P2,k2P2,k3P2,k4P2,k5P2,k6P2,k7P2,k8P2,k9P2,k10P2,k11P2,k12P2,k13P2,k14P2,k15P2,k16P2;
	vector<int> liMinusOne;
	vector<int> riMinusOne;
	vector<int> li;
	vector<int> ri;
	vector<int> temp,temp1,temp0, temp2;
	vector<int> result;


	//generate all of the keys beforehand 
	temp0 = key;
	k0 = permutedChoiceOne(temp0);
	cout << "Key0 ";
	cout << endl; 
	

	k1 = permutateKey(k0,1);
	k1P2 = permutedChoiceTwo(k1);
	k2 = permutateKey(k1,1);
	k2P2 = permutedChoiceTwo(k2);
	k3 = permutateKey(k2,2);
	k3P2 = permutedChoiceTwo(k3);
	k4 = permutateKey(k3,2);
	k4P2 = permutedChoiceTwo(k4);
	k5 = permutateKey(k4,2);
	k5P2 = permutedChoiceTwo(k5);
	k6 = permutateKey(k5,2);
	k6P2 = permutedChoiceTwo(k6);
	k7 = permutateKey(k6,2);
	k7P2 = permutedChoiceTwo(k7);
	k8 = permutateKey(k7,2);
	k8P2 = permutedChoiceTwo(k8);
	k9 = permutateKey(k8,1);
	k9P2 = permutedChoiceTwo(k9);
	k10 = permutateKey(k9,2);
	k10P2 = permutedChoiceTwo(k10);
	k11 = permutateKey(k10,2);
	k11P2 = permutedChoiceTwo(k11);
	k12 = permutateKey(k11,2);
	k12P2 = permutedChoiceTwo(k12);
	k13 = permutateKey(k12,2);
	k13P2 = permutedChoiceTwo(k13);
	k14 = permutateKey(k13,2);
	k14P2 = permutedChoiceTwo(k14);
	k15 = permutateKey(k14,2);
	k15P2 = permutedChoiceTwo(k15);
	k16 = permutateKey(k15,1);
	k16P2 = permutedChoiceTwo(k16);
	
	cout << "R1" << endl; 
	temp = initalPermutation(bin);
	for(int i = 0;i<32;i++)
		liMinusOne.push_back(temp[i]);
	for(int i = 32;i<64;i++)
	{
		riMinusOne.push_back(temp[i]);
		cout << " temp[" << i << "] = " << temp[i];
	}
	cout << endl;

	//go through algorithm 

	l1 = liMinusOne;
	r1 = riMinusOne;

	cout << "R1" << endl; 
	l2 = r1;
	temp2 = permutateText(r1,k1P2);
	r2 = xOR(l1,temp2);
	cout << "L1 = ";
	for(int i = 0;i<l1.size();i++)
		cout << l1[i];
	cout << endl;
	cout << "New R2 = ";
	for(int i = 0;i<r2.size();i++)
		cout << r2[i];
	cout << endl;
	temp2.clear();
	
	l3 = r2;
	temp2 = permutateText(r2,k2P2);
	r3 = xOR(l2,temp2);
	temp2.clear();

	l4 = r3;
	temp2 = permutateText(r3,k3P2);
	r4 = xOR(l3,temp2);
	temp2.clear();

	l5 = r4;
	temp2 = permutateText(r4,k4P2);
	r5 = xOR(l4,temp2);
	temp2.clear();

	l6 = r5;
	temp2 = permutateText(r5,k5P2);
	r6 = xOR(l5,temp2);
	temp2.clear();

	l7 = r6;
	temp2 = permutateText(r6,k6P2);
	r7 = xOR(l6,temp2);
	temp2.clear();

	l8 = r7;
	temp2 = permutateText(r7,k7P2);
	r8 = xOR(l7,temp2);
	temp2.clear();

	l9 = r8;
	temp2 = permutateText(r8,k8P2);
	r9 = xOR(l8,temp2);
	temp2.clear();

	l10 = r9;
	temp2 = permutateText(r9,k9P2);
	r10 = xOR(l9,temp2);
	temp2.clear();

	l11 = r10;
	temp2 = permutateText(r10,k10P2);
	r11 = xOR(l10,temp2);
	temp2.clear();

	l12 = r11;
	temp2 = permutateText(r11,k11P2);
	r12 = xOR(l11,temp2);
	temp2.clear();

	l13 = r12;
	temp2 = permutateText(r12,k12P2);
	r13 = xOR(l12,temp2);
	temp2.clear();

	l14 = r13;
	temp2 = permutateText(r13,k13P2);
	r14 = xOR(l13,temp2);
	temp2.clear();

	l15 = r14;
	temp2 = permutateText(r14,k14P2);
	r15 = xOR(l14,temp2);
	temp2.clear();

	l16 = r15;
	temp2 = permutateText(r15,k15P2);
	r16 = xOR(l15,temp2);
	temp2.clear();

	l17 = r16;
	temp2 = permutateText(r16,k16P2);
	r17 = xOR(l16,temp2);
	temp2.clear();



	 temp1.reserve(64);

	 //Swap l17 and r17

	 temp1.insert(temp1.end(),r17.begin(),r17.end()); 
	 temp1.insert(temp1.end(),l17.begin(),l17.end());

	 result = inversePermutation(temp1);

	 cout << "Result: " << endl;
     for(int i = 0; i<result.size();i++)
     	 cout << result[i];
     cout << endl; 

	return result; 


}



vector<int> decrypt(vector<int> bin, vector<int> key)
{
	vector<int> r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r17Swapped;
	vector<int> l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l17Swapped;
	vector<int> k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16;
	vector<int> k1P2,k2P2,k3P2,k4P2,k5P2,k6P2,k7P2,k8P2,k9P2,k10P2,k11P2,k12P2,k13P2,k14P2,k15P2,k16P2;
	vector<int> liMinusOne;
	vector<int> riMinusOne;
	vector<int> li;
	vector<int> ri;
	vector<int> temp,temp1,temp0, temp2;
	vector<int> result;



	//Generate all of the keys beforehand 
	temp0 = key;
	k0 = permutedChoiceOne(temp0);
	cout << "Key0 ";
	cout << endl; 


	k1 = permutateKey(k0,1);
	k1P2 = permutedChoiceTwo(k1);
	k2 = permutateKey(k1,1);
	k2P2 = permutedChoiceTwo(k2);
	k3 = permutateKey(k2,2);
	k3P2 = permutedChoiceTwo(k3);
	k4 = permutateKey(k3,2);
	k4P2 = permutedChoiceTwo(k4);
	k5 = permutateKey(k4,2);
	k5P2 = permutedChoiceTwo(k5);
	k6 = permutateKey(k5,2);
	k6P2 = permutedChoiceTwo(k6);
	k7 = permutateKey(k6,2);
	k7P2 = permutedChoiceTwo(k7);
	k8 = permutateKey(k7,2);
	k8P2 = permutedChoiceTwo(k8);
	k9 = permutateKey(k8,1);
	k9P2 = permutedChoiceTwo(k9);
	k10 = permutateKey(k9,2);
	k10P2 = permutedChoiceTwo(k10);
	k11 = permutateKey(k10,2);
	k11P2 = permutedChoiceTwo(k11);
	k12 = permutateKey(k11,2);
	k12P2 = permutedChoiceTwo(k12);
	k13 = permutateKey(k12,2);
	k13P2 = permutedChoiceTwo(k13);
	k14 = permutateKey(k13,2);
	k14P2 = permutedChoiceTwo(k14);
	k15 = permutateKey(k14,2);
	k15P2 = permutedChoiceTwo(k15);
	k16 = permutateKey(k15,1);
	k16P2 = permutedChoiceTwo(k16);
	
	cout << "R1" << endl; 
	temp = initalPermutation(bin);
	for(int i = 0;i<32;i++)
		liMinusOne.push_back(temp[i]);
	for(int i = 32;i<64;i++)
	{
		riMinusOne.push_back(temp[i]);
		cout << " temp[" << i << "] = " << temp[i];
	}
	cout << endl;

	//go through algorithm 

	l1 = liMinusOne;
	r1 = riMinusOne;

	cout << "R1" << endl; 
	l2 = r1;
	temp2 = permutateText(r1,k16P2);
	r2 = xOR(l1,temp2);
	cout << "L1 = ";
	for(int i = 0;i<l1.size();i++)
		cout << l1[i];
	cout << endl;
	cout << "New R2 = ";
	for(int i = 0;i<r2.size();i++)
		cout << r2[i];
	cout << endl;
	temp2.clear();
	
	l3 = r2;
	temp2 = permutateText(r2,k15P2);
	r3 = xOR(l2,temp2);
	temp2.clear();

	l4 = r3;
	temp2 = permutateText(r3,k14P2);
	r4 = xOR(l3,temp2);
	temp2.clear();

	l5 = r4;
	temp2 = permutateText(r4,k13P2);
	r5 = xOR(l4,temp2);
	temp2.clear();

	l6 = r5;
	temp2 = permutateText(r5,k12P2);
	r6 = xOR(l5,temp2);
	temp2.clear();

	l7 = r6;
	temp2 = permutateText(r6,k11P2);
	r7 = xOR(l6,temp2);
	temp2.clear();

	l8 = r7;
	temp2 = permutateText(r7,k10P2);
	r8 = xOR(l7,temp2);
	temp2.clear();

	l9 = r8;
	temp2 = permutateText(r8,k9P2);
	r9 = xOR(l8,temp2);
	temp2.clear();

	l10 = r9;
	temp2 = permutateText(r9,k8P2);
	r10 = xOR(l9,temp2);
	temp2.clear();

	l11 = r10;
	temp2 = permutateText(r10,k7P2);
	r11 = xOR(l10,temp2);
	temp2.clear();

	l12 = r11;
	temp2 = permutateText(r11,k6P2);
	r12 = xOR(l11,temp2);
	temp2.clear();

	l13 = r12;
	temp2 = permutateText(r12,k5P2);
	r13 = xOR(l12,temp2);
	temp2.clear();

	l14 = r13;
	temp2 = permutateText(r13,k4P2);
	r14 = xOR(l13,temp2);
	temp2.clear();

	l15 = r14;
	temp2 = permutateText(r14,k3P2);
	r15 = xOR(l14,temp2);
	temp2.clear();

	l16 = r15;
	temp2 = permutateText(r15,k2P2);
	r16 = xOR(l15,temp2);
	temp2.clear();

	l17 = r16;
	temp2 = permutateText(r16,k1P2);
	r17 = xOR(l16,temp2);
	temp2.clear();



	 temp1.reserve(64);

	 //Swap l17 and r17

	 temp1.insert(temp1.end(),r17.begin(),r17.end()); 
	 temp1.insert(temp1.end(),l17.begin(),l17.end());

	 result = inversePermutation(temp1);

	return result; 
	


}



 

vector<int> permutation(vector<int> bin, vector<int> perm)
{
	vector<int> result;
	cout << "Some Permutation ";
	for(int i = 0;i<perm.size();i++)
	{
		result.push_back(bin[perm[i]-1]);
		cout << result[i];
	}
	cout << endl;
	return result;
}



vector<int> permutateText(vector<int> bin,vector<int> key)
{
	//split into 64 bit blocks 
	//send through all permutations 
	//
	vector<int> result;
	vector<int> temp1,temp2,temp3,temp4;
	cout << "Expanding " << endl;
	temp1 = expansionPermutation(bin);
	temp2 = xOR(temp1,key);
	cout << "XOR WITH KEY" << endl; 
	for(int i = 0; i<temp2.size(); i++)
	{
		cout << temp2[i];
	}
	cout << endl;
	// for(int i = 0; i<bin.size();i++)
	// {
	// 	if(bin[i] != key[i])
	// 		temp2.push_back(1);
	// 	else if(bin[i] == key[i])
	// 		temp2.push_back(0);
	// 	else 
	// 		temp2.push_back(-1);
	// }

	temp3 = sBoxes(temp2);
	cout << "SBoxes = " << endl; 
	for(int i = 0; i<temp3.size(); i++)
	{
		cout << temp3[i];
	}
	cout << endl;

	result = permutationP(temp3);

	return result;



}


vector<int> permutateKey(vector<int> key, int shift)
{
	vector<int> result;
	vector<int> ci;
	vector<int> di; 
	string tempC, tempD;
	vector<int> temp = key;
	cout << "D: ";
	

	for(int i = 0; i<28;i++)
	{
		ci.push_back(temp[i]);
		di.push_back(temp[i+28]);
		cout << di[i];

	}
	cout << endl;
	/*for(int i = 0; i<56; i++)
	{
		if(i < 28)
		{
			ci.push_back(key[i]);
			
		}
		else 
		{
			di.push_back(key[i]);
			cout << di[i] << endl;
			cout << "I = " <<  i << endl;
		}
	}
	cout << endl;
	*/
	for(int i = 0;i<shift; i++)
	{
		tempC = static_cast<char>(ci[0]);
		ci.erase(ci.begin(),ci.begin()+1);
		ci.push_back(static_cast<int>(tempC[0]));
		tempC.clear();
		tempD = static_cast<char>(di[0]);
		di.erase(di.begin(),di.begin()+1);
		di.push_back(static_cast<int>(tempD[0]));
		tempD.clear();
		
	}


	result.reserve(56);

	result.insert(result.end(),ci.begin(),ci.end()); 
	result.insert(result.end(),di.begin(),di.end());

	return result;

}

vector<int> initalPermutation(vector<int> bin)
{
	int IPa[] = {
		58,50,42,34,26,18,10,2,
		60,52,44,36,28,20,12,4,
		62,54,46,38,30,22,14,6,
		64,56,48,40,32,24,16,8,
		57,49,41,33,25,17,9,1,
		59,51,43,35,27,19,11,3,
		61,53,45,37,29,21,13,5,
		63,55,47,39,31,23,15,7};
	vector<int> IP(IPa,IPa + sizeof(IPa)/sizeof(IPa[0]));

	vector<int> result;
	result = permutation(bin,IP);
	return result;
}

vector<int> permutedChoiceOne(vector<int> bin)
{
	vector<int> temp = bin;

	int PC1a[] = {
		57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,
		19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4};
	vector<int> PC1(PC1a,PC1a + sizeof(PC1a)/sizeof(PC1a[0]));

	vector<int> result;
	result = permutation(temp,PC1);


	return result;
}

vector<int> permutedChoiceTwo(vector<int> bin)
{
	int PC2a[] = {
		14,17,11,24,1,5,3,28,
		15,6,21,10,23,19,12,4,
		26,8,16,7,27,20,13,2,
		41,52,31,37,47,55,30,40,
		51,45,33,48,44,49,39,56,
		34,53,46,42,50,36,29,32};
	vector<int> PC2(PC2a,PC2a + sizeof(PC2a)/sizeof(PC2a[0]));
	
	vector<int> result;
	result = permutation(bin,PC2);


	return result;
}

vector<int> inputKey(vector<int> bin)
{
	//gets rid of 8th bit
	vector<int> result;

	for(int i = 0; i<7;i++)
	{
		//if((i%7)!= 0)
		result.push_back(bin[i]);
	}
	for(int i = 8; i<15;i++)
	 	result.push_back(bin[i]);
	for(int i = 16; i<23;i++)
		result.push_back(bin[i]);
	for(int i = 24; i<31;i++)
		result.push_back(bin[i]);
	for(int i = 32; i<39;i++)
		result.push_back(bin[i]);
	for(int i = 40; i<47;i++)
		result.push_back(bin[i]);
	for(int i = 48; i<55;i++)
		result.push_back(bin[i]);
	for(int i = 56; i<63;i++)
		result.push_back(bin[i]);

	cout << "result = " << result.size();
	return result;
}

vector<int> expansionPermutation(vector<int> bin)
{
	cout << "Expansion: " << endl; 
	vector<int> result;
	int EPa[] = {
		32,1,2,3,4,5,
		4,5,6,7,8,9,
		8,9,10,11,12,13,
		12,13,14,15,16,17,
		16,17,18,19,20,21,
		20,21,22,23,24,25,
		24,25,26,27,28,29,
		28,29,30,31,32,1};
	vector<int> EP(EPa,EPa + sizeof(EPa)/sizeof(EPa[0]));


	result = permutation(bin,EP);
	return result; 
}

vector<int> permutationP(vector<int> bin)
{
	vector<int> result;
	int Pa[] = {
		16,7,20,21,29,12,28,17,
		1,15,23,26,5,18,31,10,
		2,8,24,14,32,27,3,9,
		19,13,30,6,22,11,4,25};
	vector<int> P(Pa,Pa + sizeof(Pa)/sizeof(Pa[0]));
	
	result = permutation(bin,P);
	return result;
}

vector<int> inversePermutation(vector<int> bin)
{
	vector<int> result;
	int IPa[] = {
		40,8,48,16,56,24,64,32,
		39,7,47,15,55,23,63,31,
		38,6,46,14,54,22,62,30,
		37,5,45,13,53,21,61,29,
		36,4,44,12,52,20,60,28,
		35,3,43,11,51,19,59,27,
		34,2,42,10,50,18,58,26,
		33,1,41,9,49,17,57,25,
		};
	vector<int> IP(IPa, IPa + sizeof(IPa)/sizeof(IPa[0]));
	result = permutation(bin,IP);
	return result; 

}



vector<int> sBoxes(vector<int> bin)
{
	cout << "Sboxes: " << endl; 
	vector<int> result;  
	string temp, temp1;
	char  tempR,tempE; 
	int row; 
	int column;


	cout << "What im working with in sboxes" << endl;
	for(int i = 0;i<bin.size();i++)
		cout << bin[i];
	cout << endl;

	int s[8][4][16] = 
	{
		{
			{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},//row 0
			{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}, // row1
			{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}, // row1
			{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13} // row3

		},

		{
			{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},//row 0
			{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5}, // row1
			{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15}, // row1
			{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9} // row3

		},

		
		{
			{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},//row 0
			{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1}, // row1
			{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7}, // row1
			{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12} // row3

		},

		{
			{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},//row 0
			{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9}, // row1
			{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4}, // row1
			{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14} // row3

		},

		
		{
			{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},//row 0
			{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6}, // row1
			{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14}, // row1
			{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3} // row3

		},


		{
			{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},//row 0
			{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8}, // row1
			{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6}, // row1
			{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13} // row3

		},


		{
			{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},//row 0
			{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6}, // row1
			{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2}, // row1
			{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12} // row3

		},

		
		{
			{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},//row 0
			{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2}, // row1
			{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8}, // row1
			{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} // row3

		}
	};



	int increment = 0;
	for(int i = 0;i<8;i++)
	{
		temp.push_back('0');
		temp.push_back('0');
		if(bin[0 + increment] == 0)
			temp.push_back('0');
		else if(bin[0 + increment] == 1)
			temp.push_back('1');
		if(bin[5 + increment] == 0)
			temp.push_back('0');
		else if(bin[5 + increment] == 1)
			temp.push_back('1');
		//temp.push_back(static_cast<char>(bin[0]));
		//tempE = static_cast<char>(bin[5]);
		//temp.push_back(tempE);
		// temp.push_back(static_cast<char>(bin[5]));
		cout << "temp row = " << endl; 
		for(int i = 0; i<4;i++)
			cout << temp[i];
		cout << endl;
		row = binToNum(temp);
		cout << "Row = " << row << endl;	
		temp.clear(); 
		if(bin[1 + increment] == 0)
			temp.push_back('0');
		else if(bin[1 + increment] == 1)
			temp.push_back('1');
		if(bin[2 + increment] == 0)
			temp.push_back('0');
		else if(bin[2 + increment] == 1)
			temp.push_back('1');
		if(bin[3 + increment] == 0)
			temp.push_back('0');
		else if(bin[3 + increment] == 1)
			temp.push_back('1');
		if(bin[4 + increment] == 0)
			temp.push_back('0');
		else if(bin[4 + increment] == 1)
			temp.push_back('1');

		column = binToNum(temp);
		cout << "Column = " << column << endl;
		temp.clear();
		temp1 = numToBin(s[i][row][column]);
		cout << "S1 = " << endl;
		for(int i = 0;i<4;i++)
		{
			if(temp1[i] == '0')
				result.push_back(0);
			else if(temp1[i] == '1')
				result.push_back(1);
			cout << temp1[i] << endl;
		}
		temp1.clear();
		increment+=6;
	}
	


	 return result;

}

int binToNum(string s)
{
	int result = -1;
	
	string zero,one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen;
	zero = "0000";
	one = "0001";
	two = "0010";
	three = "0011";
	four = "0100";
	five = "0101";
	six = "0110";
	seven = "0111";
	eight = "1000";
	nine = "1001";
	ten = "1010";
	eleven = "1011";
	twelve = "1100";
	thirteen = "1101";
	fourteen  = "1110";
	fifteen = "1111";

	if(s == zero)
    	return 0;
    if(s == one)
    	return 1;
    if(s == two)
    	return 2;
    if(s == three)
    	return 3;
    if(s == four)
    	return 4;
    if(s == five)
    	return 5;
    if(s == six)
    	return 6;
    if(s == seven)
    	return 7;
    if(s == eight)
    	return 8;
    if(s == nine)
    	return 9;
    if(s == ten)
    	return 10;
    if(s == eleven)
    	return 11;
    if(s == twelve)
    	return 12;
    if(s == thirteen)
    	return 13;
    if(s == fourteen)
    	return 14;
    if(s == fifteen)
    	return 15;
    
    
	return result;
}

string numToBin(int sint)
{

    switch(sint)
    {
        case 0: return "0000";
        case 1: return "0001";
        case 2: return "0010";
        case 3: return "0011";
        case 4: return "0100";
        case 5: return "0101";
        case 6: return "0110";
        case 7: return "0111";
        case 8: return "1000";
        case 9: return "1001";
        case 10: return "1010";
        case 11: return "1011";
        case 12: return "1100";
        case 13: return "1101";
        case 14: return "1110";
        case 15: return "1111";
    }
    return "null";

}

vector<int> xOR(vector<int> li, vector<int> ri)
{
	cout << "XOR: " << endl; 
	vector<int> result; 
	for(int i = 0; i<ri.size();i++)
	{
		if(li[i] != ri[i])
			result.push_back(1);
		else if(li[i] == ri[i])
			result.push_back(0);
		else 
			result.push_back(-2);
	}

	return result;
}

string split(vector<int> bin, vector<int> key1, vector<int> key2, vector<int> key3, char ed, char ah)
{

	int increment = 0;
	int innerIncrement = 0;
	string result,splittingTemp;
	vector<int> temp, encryptTemp, encryptTemp1, encryptTemp2, decryptTemp, decryptTemp1, decryptTemp2; 
	if(ed == 'e' || ed == 'E')
	{
		for(int i = 0; i<(bin.size()/64);i++)
		{
			for(int n = 0;n<64;n++)
			{
				temp.push_back(bin[n+increment]);
			
			}
			stringstream ss;
    		
			encryptTemp = encrypt(temp,key1);
			encryptTemp1 = decrypt(encryptTemp,key2);
			encryptTemp2 = encrypt(encryptTemp1,key3);
			copy( encryptTemp2.begin(), encryptTemp2.end(), ostream_iterator<int>(ss, ""));
			string s = ss.str();
    		//s = s.substr(0, s.length());
    		cout << "S = " << s << endl;
    		for(int j = 0; j < 16;j++)
    		{ 
	    		for(int k = 0; k < 4;k++)
	    		{
	    			splittingTemp += s[k + innerIncrement];
	    			cout << splittingTemp << endl;
	    		}
				result += binToString(splittingTemp);
				splittingTemp.clear();
				innerIncrement += 4;
			}
			innerIncrement = 0;
			increment += 64; 
			ss.clear();
			s.clear();
			temp.clear();
	 	}

	// int increment = 0;
	// int innerIncrement = 0;
	// string result,splittingTemp;
	// vector<int> temp, encryptTemp, encryptTemp2; 
	// if(ed == 'e' || ed == 'E')
	// {
	// 	for(int i = 0; i<((bin.size()/64)-1);i++)
	// 	{
	// 		for(int i = 0;i<64;i++)
	// 		{
	// 			temp.push_back(bin[i+increment]);
			
	// 		}
	// 		stringstream ss;
    		
	// 		encryptTemp = encrypt(temp,key1);
	// 		copy( encryptTemp.begin(), encryptTemp.end(), ostream_iterator<int>(ss, ""));
	// 		string s = ss.str();
 //    		s = s.substr(0, s.length()-1);
 //    		cout << "S = " << s << endl;
 //    		for(int j = 0; j < 16;j++)
 //    		{ 
	//     		for(int i = 0; i < 4;i++)
	//     		{
	//     			splittingTemp += s[i + innerIncrement];
	//     			cout << splittingTemp << endl;
	//     		}
	// 			result += binToString(splittingTemp);
	// 			splittingTemp.clear();
	// 			innerIncrement += 4;
	// 		}
	// 		innerIncrement = 0;
	// 		increment += 64; 
	// 		ss.clear();
	// 		s.clear();



	// 	}
	}


	else if(ed == 'd' || ed != 'D')
	{
		for(int i = 0; i<(bin.size()/64);i++)
		{
			for(int i = 0;i<64;i++)
			{
				temp.push_back(bin[i+increment]);
			
			}
			stringstream ss;
    		
			decryptTemp = encrypt(temp,key3);
			decryptTemp1 = decrypt(decryptTemp,key2);
			decryptTemp2 = encrypt(decryptTemp1,key1);
			copy( decryptTemp2.begin(), decryptTemp2.end(), ostream_iterator<int>(ss, ""));
			string s = ss.str();
    		s = s.substr(0, s.length());
    		cout << "S = " << s << endl;
    		for(int j = 0; j < 16;j++)
    		{ 
	    		for(int k = 0; k < 4;k++)
	    		{
	    			splittingTemp += s[k + innerIncrement];
	    			cout << splittingTemp << endl;
	    		}
				result += binToString(splittingTemp);
				splittingTemp.clear();
				innerIncrement += 4;
			}
			innerIncrement = 0;
			increment += 64; 
			ss.clear();
			s.clear();
			temp.clear();

		}
	
	}
	cout << "RESULT = " << result << endl;
	return result; 
}


// string binToString(string bin)
// {

    
//     stringstream sstream(bin);
//     string output;
//     while(sstream.good())
//     {
//         bitset<8> bits;
//         sstream >> bits;
//         char c = char(bits.to_ulong());
//         output += c;
//     }
//     cout << "Output = " << output;
 	
//     return output;  

// }

	string binToString(string s)
	{
	string result = "null";
	
	string zero,one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen;
	zero = "0000";
	one = "0001";
	two = "0010";
	three = "0011";
	four = "0100";
	five = "0101";
	six = "0110";
	seven = "0111";
	eight = "1000";
	nine = "1001";
	ten = "1010";
	eleven = "1011";
	twelve = "1100";
	thirteen = "1101";
	fourteen  = "1110";
	fifteen = "1111";

	if(s == zero)
    	return "0";
    if(s == one)
    	return "1";
    if(s == two)
    	return "2";
    if(s == three)
    	return "3";
    if(s == four)
    	return "4";
    if(s == five)
    	return "5";
    if(s == six)
    	return "6";
    if(s == seven)
    	return "7";
    if(s == eight)
    	return "8";
    if(s == nine)
    	return "9";
    if(s == ten)
    	return "A";
    if(s == eleven)
    	return "B";
    if(s == twelve)
    	return "C";
    if(s == thirteen)
    	return "D";
    if(s == fourteen)
    	return "E";
    if(s == fifteen)
    	return "F";



    
	return result;
	}





