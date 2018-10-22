#include <iostream>
#include <fstream>
#include <cstring>
#define SIZE 701

using namespace std;

struct HashStruct {
	uint64_t key;
	uint64_t val;
	bool c = false;
};

uint64_t N;
struct HashStruct * HashTable;

void Insert(uint64_t key, uint64_t val, ofstream & fout);
void Delete(uint64_t key, ofstream & fout);
void Find(uint64_t key, ofstream & fout);
void Print(void);
void getInput(char * line, uint64_t &key, uint64_t &val);
void getInput(char * line, uint64_t &key);
void outputFile(ofstream & fout, const char * n);
void outputFile(ofstream & fout, uint64_t n);

int main(int argc, char * argv[]) {
	char line[15];
	uint64_t key = 0;
	uint64_t val = 0;

	if (argc < 2){
		exit(0);
	}

	ifstream fin(argv[1]);
	ofstream fout("output.txt");

	if (fin.is_open())
	{

	while (fin.getline(line, sizeof(line))) {
	if (line[0] == 'I') {
				getInput(line, key, val);
				Insert(key, val, fout);
			}
			else if (line[0] == 'D') {
				getInput(line, key);
				Delete(key, fout);
			}
			else if (line[0] == 'F') {
				getInput(line, key);
				Find(key, fout);
			}
			else if (line[0] == 'P') {
				Print();
			}
			else if (line[0] == 'Q') {
				return 0;
			}
			else {
				N = atoi(line);
				HashTable = new HashStruct[3 * N]();
			}
		}
	}
	delete [] HashTable;
	HashTable = NULL;

	fin.close();
	fout.close();

	return 0;

}
uint64_t hash_func(uint64_t key) {
	return key % SIZE;
}

void Insert(uint64_t key, uint64_t val, ofstream & fout) {
	uint64_t index = hash_func(key);

	struct HashStruct HS;
	HS.key = index;
	HS.val = val;
	HS.c = true;

	if (!HashTable[index].c &&HashTable[index].val == 0) {
		HashTable[index] = HS;
		outputFile(fout, "Inserted");
	}
	else {
		HashTable[index].val = HS.val;
		outputFile(fout, "Duplicated");
	}
}
void Delete(uint64_t key, ofstream & fout) {
	uint64_t index = hash_func(key);

	if (!HashTable[index].c && HashTable[index].val == 0) {
		outputFile(fout, "Not Found");
	}
	else {
		HashTable[index].val = 0;
		HashTable[index].c = false;
		outputFile(fout, "Deleted");
	}
}
void Find(uint64_t key, ofstream & fout) {
	uint64_t index = hash_func(key);

	if (HashTable[index].c == true && HashTable[index].key == key) {
		outputFile(fout, HashTable[index].val);
	}
	else {
		outputFile(fout, "Not Found"); 
	}
}
void Print() {
	cout << "------------PrintTable-------------" << endl;
	for (uint64_t i = 0; i < 3*N; i++) {
		if (HashTable[i].val != 0) {
			cout << "(" << HashTable[i].key << " , " << HashTable[i].val << " )" << endl;
		}
	}
}

void getInput(char * line, uint64_t &key, uint64_t &val) {
	char * key_split = NULL;
	char * val_split = NULL;

	line = strtok(line, " ");
	key_split= strtok(NULL," ");
	val_split = strtok(NULL," ");

	key = strtoull(key_split, NULL, 10);
	val = strtoull(val_split, NULL, 10);
}

void getInput(char * line, uint64_t &key) {
	char * key_split = NULL;
	line = strtok(line, " ");
	key_split = strtok(NULL, " ");

	key = strtoull(key_split, NULL, 10);
}

void outputFile(ofstream & fout, const char * n) {
	if (fout.is_open()) {
		fout << n << endl;
	}
}

void outputFile(ofstream & fout, uint64_t n) {
	if (fout.is_open()) {
		fout << n << endl;
	}
}
