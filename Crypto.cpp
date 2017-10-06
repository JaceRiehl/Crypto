#include <iostream>
#include <fstream>
#include <vector> 
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std; 
//GLOBAL VARIABLES 
vector<int> fileStringSpaces;
vector<int> ci,di; 


string callFile();
string removeSpaces(string s); 
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
vector<int> permutation(vector<int> bin, vector<int> perm);
vector<int> expansionPermutation(vector<int> bin);
vector<int> permutationP(vector<int> bin);
vector<int> sBoxes(vector<int> bin);
vector<int> inversePermutation(vector<int> bin);
int binToNum(string s);
string numToBin(int sint);
vector<int> encrypt(vector<int> bin, vector<int> key);
vector<int> decrypt(vector<int> bin, vector<int> key);
vector<int> xOR(vector<int> li, vector<int> ri); 

int main()
{
	//THE ERROR MIGHT HAVE SOMETHING TO DO WITH INPUT KEY NOT BEING CALLED 
	// int test[] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
   //    vector<int> t(test,test + sizeof(test)/sizeof(test[0]));
    //string test = "02468aceeca86420";

     int testText[] = {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1};
        vector<int> testText1(testText,testText + sizeof(testText)/sizeof(testText[0]));

	int testKey[] = {0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
        vector<int> testKey1(testKey,testKey + sizeof(testKey)/sizeof(testKey[0]));
     testKey1 = permutedChoiceOne(testKey1);

     for(int i = 0; i<testKey1.size();i++)
      	 cout << testKey1[i] << ",";

//11100001100110010101010111111010101011001100111100011110
        vector<int> result; 

    result = inputKey(testKey1);
        //result = encrypt(testText1,testKey1);

    // cout << "T " << t.size() << endl; 
    // cout << t[0] << endl;
    // vector<int> test2 = permutateKey(t,1);
    // vector<int> test3 = permutedChoiceTwo(test2);
     cout << "Result: " << endl;
     for(int i = 0; i<result.size();i++)
     	 cout << result[i];
     cout << endl; 



	vector<int> key1;
	vector<int> key2;
	vector<int> key3; 
	vector<int> IIPfd;
	string inputs = callFile(); 
	//string fileContents;
	//fileContents = removeSpaces(inputs);
	cout << "File contents: " << inputs << endl;
	//for(int i = 0; i<fileStringSpaces.size();i++)
	//	cout << fileStringSpaces[i];
	//cout << endl;
	vector<int> temp = fileToBinary(inputs);
	for(int i = 0; i<temp.size();i++)
		cout << "Temp[" << i << "]: " << temp[i] << endl;
	
	cout << endl;


	//vector<int> result = startPermutation(temp);

	key1 = getKeys(1);
	key2 = getKeys(2);
	key3 = getKeys(3);

	for(int i = 0; i<key1.size();i++)
		cout << "Key1[" << i << "]: " << key1[i] << endl;
	//cout <<  "Key1: " << key1 << endl;
	//cout << "Key2: " << key2 << endl; 
	//cout << "Key3: " << key3 << endl; 


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

string removeSpaces(string s)
{
	string temp = s; 
	string result;
	cout << "s.size: " << s.size() << endl; 
	for(int i = 0; i<s.size();i++)
	{
		temp = s[i];
		if(temp.compare(" ") == 0)
			fileStringSpaces.push_back(i);
		
		else 
			result.push_back(s[i]);
	}
	return result; 
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
	vector<int> temp,temp1,temp0;
	vector<int> result;


	//deal with keys 
	//problems with inputkey 
	//problems with permutatedchoiceone
	k0 = inputKey(key);
	temp0 = permutedChoiceOne(k0);
	cout << "Key0 ";
	//for(int i = 0; i<temp0.size();i++)
	//	cout << temp0[i];

	k1 = permutateKey(temp0,1);
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
	
	temp = initalPermutation(bin);
	for(int i = 0;i<32;i++)
		liMinusOne.push_back(bin[i]);
	for(int i = 32;i<64;i++)
		riMinusOne.push_back(bin[i]);



	l1 = liMinusOne;
	r1 = riMinusOne;

	l2 = r1;
	r2 = permutateText(r1,k1P2);
	r2 = xOR(l2,r2);

	l3 = r2;
	r3 = permutateText(r2,k2P2);
	r3 = xOR(l3,r3);

	l4 = r3;
	r4 = permutateText(r3,k3P2);
	r4 = xOR(l4,r4);

	l5 = r4;
	r5 = permutateText(r4,k4P2);
	r5 = xOR(l5,r5);

	l6 = r5;
	r6 = permutateText(r5,k5P2);
	r6 = xOR(l6,r6);

	l7 = r6;
	r7 = permutateText(r6,k6P2);
	r7 = xOR(l7,r7);

	l8 = r7;
	r8 = permutateText(r7,k7P2);
	r8 = xOR(l8,r8);


	l9 = r8;
	r9 = permutateText(r8,k8P2);
	r9 = xOR(l9,r9);

	l10 = r9;
	r10 = permutateText(r9,k9P2);
	r10 = xOR(l10,r10);


	l11 = r10;
	r11 = permutateText(r10,k10P2);
	r11 = xOR(l11,r11);


	l12 = r11;
	r12 = permutateText(r11,k11P2);
	r12 = xOR(l12,r12);


	l13 = r12;
	r13 = permutateText(r12,k12P2);
	r13 = xOR(l13,r13);


	l14 = r13;
	r14 = permutateText(r13,k13P2);
	r14 = xOR(l14,r14);


	l15 = r14;
	r15 = permutateText(r14,k14P2);
	r15 = xOR(l15,r15);

	l16 = r15;
	r16 = permutateText(r15,k15P2);
	r16 = xOR(l16,r16);

	l17 = r16;
	r17 = permutateText(r16,k16P2);
	r17 = xOR(l17,r17);



	 temp1.reserve(64);

	 //Swap l17 and r17
	 temp1.insert(temp1.end(),r17.begin(),r17.end()); 
	 temp1.insert(temp1.end(),l17.begin(),l17.end());

	 result = inversePermutation(temp1);

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
	vector<int> temp,temp1;
	vector<int> result;


	//deal with keys 
	k0 = permutedChoiceOne(key);
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
	
	temp = initalPermutation(bin);
	for(int i = 0;i<32;i++)
		liMinusOne.push_back(bin[i]);
	for(int i = 32;i<64;i++)
		riMinusOne.push_back(bin[i]);



	l1 = liMinusOne;
	r1 = riMinusOne;

	l2 = r1;
	r2 = permutateText(r1,k16P2);
	r2 = xOR(l2,r2);

	l3 = r2;
	r3 = permutateText(r2,k15P2);
	r3 = xOR(l3,r3);

	l4 = r3;
	r4 = permutateText(r3,k14P2);
	r4 = xOR(l4,r4);

	l5 = r4;
	r5 = permutateText(r4,k13P2);
	r5 = xOR(l5,r5);

	l6 = r5;
	r6 = permutateText(r5,k12P2);
	r6 = xOR(l6,r6);

	l7 = r6;
	r7 = permutateText(r6,k11P2);
	r7 = xOR(l7,r7);

	l8 = r7;
	r8 = permutateText(r7,k10P2);
	r8 = xOR(l8,r8);


	l9 = r8;
	r9 = permutateText(r8,k9P2);
	r9 = xOR(l9,r9);

	l10 = r9;
	r10 = permutateText(r9,k8P2);
	r10 = xOR(l10,r10);


	l11 = r10;
	r11 = permutateText(r10,k7P2);
	r11 = xOR(l11,r11);


	l12 = r11;
	r12 = permutateText(r11,k6P2);
	r12 = xOR(l12,r12);


	l13 = r12;
	r13 = permutateText(r12,k5P2);
	r13 = xOR(l13,r13);


	l14 = r13;
	r14 = permutateText(r13,k4P2);
	r14 = xOR(l14,r14);


	l15 = r14;
	r15 = permutateText(r14,k3P2);
	r15 = xOR(l15,r15);

	l16 = r15;
	r16 = permutateText(r15,k2P2);
	r16 = xOR(l16,r16);

	l17 = r16;
	r17 = permutateText(r16,k1P2);
	r17 = xOR(l17,r17);



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
	//cout << "Some Permutation ";
	for(int i = 0;i<perm.size();i++)
	{
		result.push_back(bin[perm[i]-1]);
		//cout << result[i];
	}
	//cout << endl;
	return result;
}



vector<int> permutateText(vector<int> bin,vector<int> key)
{
	//split into 64 bit blocks 
	//send through all permutations 
	//
	vector<int> result;
	vector<int> temp1,temp2,temp3,temp4;

	temp1 = expansionPermutation(bin);
	for(int i = 0; i<bin.size();i++)
	{
		if(bin[i] != key[i])
			temp2.push_back(1);
		else if(bin[i] == key[i])
			temp2.push_back(0);
		else 
			temp2.push_back(-1);
	}

	temp3 = sBoxes(temp2);
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
	result = permutation(bin,PC1);


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
		result.push_back(bin[i+8]);
		result.push_back(bin[i+16]);
		result.push_back(bin[i+24]);
		result.push_back(bin[i+32]);
		result.push_back(bin[i+40]);
		result.push_back(bin[i+48]);
		result.push_back(bin[i+56]);
	}
	// for(int i = 0; i<8)
	// for(int i = 9; i<16;i++)
	// 	result.push_back(bin[i]);
	// for(int i = 17; i<24;i++)
	// 	result.push_back(bin[i]);
	// for(int i = 25; i<32;i++)
	// 	result.push_back(bin[i]);
	// for(int i = 33; i<40;i++)
	// 	result.push_back(bin[i]);
	// for(int i = 41; i<48;i++)
	// 	result.push_back(bin[i]);
	// for(int i = 49; i<56;i++)
	// 	result.push_back(bin[i]);
	// for(int i = 57; i<64;i++)
	// 	result.push_back(bin[i]);

	cout << "result = " << result.size();
	return result;
}

vector<int> expansionPermutation(vector<int> bin)
{
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


	result = permutation(EP,bin);
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
	
	result = permutation(P,bin);
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
	result = permutation(IP,bin);
	return result; 

}



vector<int> sBoxes(vector<int> bin)
{
	vector<int> result;  
	string temp, temp1; 
	int row; 
	int column;
	int s1[4][16] = 
	{
		{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},//row 0
		{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}, // row1
		{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}, // row1
		{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13} // row3

	};

	int s2[4][16] = 
	{
		{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},//row 0
		{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5}, // row1
		{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15}, // row1
		{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9} // row3

	};

	int s3[4][16] = 
	{
		{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},//row 0
		{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1}, // row1
		{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7}, // row1
		{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12} // row3

	};

	int s4[4][16] = 
	{
		{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},//row 0
		{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9}, // row1
		{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4}, // row1
		{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14} // row3

	};

	int s5[4][16] = 
	{
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},//row 0
		{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6}, // row1
		{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14}, // row1
		{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3} // row3

	};

	int s6[4][16] = 
	{
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},//row 0
		{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8}, // row1
		{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6}, // row1
		{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13} // row3

	};

	int s7[4][16] = 
	{
		{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},//row 0
		{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6}, // row1
		{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2}, // row1
		{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12} // row3

	};

	int s8[4][16] = 
	{
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},//row 0
		{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2}, // row1
		{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8}, // row1
		{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} // row3

	};


	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[0]));
	temp.push_back(static_cast<char>(bin[5]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[1]));
	temp.push_back(static_cast<char>(bin[2]));
	temp.push_back(static_cast<char>(bin[3]));
	temp.push_back(static_cast<char>(bin[4]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s1[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[6]));
	temp.push_back(static_cast<char>(bin[11]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[7]));
	temp.push_back(static_cast<char>(bin[8]));
	temp.push_back(static_cast<char>(bin[9]));
	temp.push_back(static_cast<char>(bin[10]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s2[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[12]));
	temp.push_back(static_cast<char>(bin[17]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[13]));
	temp.push_back(static_cast<char>(bin[14]));
	temp.push_back(static_cast<char>(bin[15]));
	temp.push_back(static_cast<char>(bin[16]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s3[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));


	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[18]));
	temp.push_back(static_cast<char>(bin[23]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[19]));
	temp.push_back(static_cast<char>(bin[20]));
	temp.push_back(static_cast<char>(bin[21]));
	temp.push_back(static_cast<char>(bin[22]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s4[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[24]));
	temp.push_back(static_cast<char>(bin[29]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[25]));
	temp.push_back(static_cast<char>(bin[26]));
	temp.push_back(static_cast<char>(bin[27]));
	temp.push_back(static_cast<char>(bin[28]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s5[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));


	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[30]));
	temp.push_back(static_cast<char>(bin[35]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[31]));
	temp.push_back(static_cast<char>(bin[32]));
	temp.push_back(static_cast<char>(bin[33]));
	temp.push_back(static_cast<char>(bin[34]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s6[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));


	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[36]));
	temp.push_back(static_cast<char>(bin[41]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[37]));
	temp.push_back(static_cast<char>(bin[38]));
	temp.push_back(static_cast<char>(bin[39]));
	temp.push_back(static_cast<char>(bin[40]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s7[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));


	temp.push_back('0');
	temp.push_back('0');
	temp.push_back(static_cast<char>(bin[42]));
	temp.push_back(static_cast<char>(bin[47]));
	row = binToNum(temp);
	temp.clear(); 
	temp.push_back(static_cast<char>(bin[43]));
	temp.push_back(static_cast<char>(bin[44]));
	temp.push_back(static_cast<char>(bin[45]));
	temp.push_back(static_cast<char>(bin[46]));
	column = binToNum(temp);
	temp.clear();
	temp1 = numToBin(s8[row][column]);
	for(int i = 0;i<4;i++)
		result.push_back(static_cast<int>(temp1[i]));


	return result;

}

int binToNum(string s)
{
	int result = -1;
	
    if(s == "0000")
    	return 0;
    if(s == "0001")
    	return 1;
    if(s == "0010")
    	return 2;
    if(s == "0011")
    	return 3;
    if(s == "0100")
    	return 4;
    if(s == "0101")
    	return 5;
    if(s == "0110")
    	return 6;
    if(s == "0111")
    	return 7;
    if(s == "1000")
    	return 8;
    if(s == "1001")
    	return 9;
    if(s == "1010")
    	return 10;
    if(s == "1011")
    	return 11;
    if(s == "1100")
    	return 12;
    if(s == "1101")
    	return 13;
    if(s == "1110")
    	return 14;
    if(s == "1111")
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








	/*string filename = "file_example.txt";
	string line;
	cout << "What file would you like to compile? ";
	cin >> filename;
	cout << endl;
	
	ifstream file;
	file.open(filename);
	istream_iterator<int> start(file), end;
	vector<string> inputs(start, end);
	
	while(getline(file, line))
	{
		inputs.push_back(line);
		cout << "File: " << line<< endl; 
	}
	file.close();
	cout << "Read " << inputs.size() << " chars" << endl;

	cout << "numbers read in:\n";
    copy(inputs.begin(), inputs.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
	*/




/*
	string filename = "file_example.txt";
	char letter;
	cout << "What file would you like to compile? ";
	cin >> filename;
	cout << endl;
	
	ifstream file;
	file.open(filename);
	
	vector<char> inputs(100);
	
	while(file >> letter)
	{
		if(letter == ' ')
			inputs.push_back(' ');
		else{
		inputs.push_back(letter);
		cout << "File: " << letter  << endl; 
	}
	}
	file.close();
	cout << "Read " << inputs.size() << " chars" << endl;

	cout << "numbers read in:\n" << endl;

	return inputs;
	*/

