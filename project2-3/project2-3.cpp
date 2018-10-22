#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define SIZE 13

using namespace std;

struct HashStruct {
	uint64_t key;
	uint64_t val;
	bool c = false;
};

uint64_t N;
struct HashStruct * HashTable1;
struct HashStruct * HashTable2;

void Insert(uint64_t key, uint64_t val, ofstream & fout);
void Delete(uint64_t key, ofstream & fout);
void Find(uint64_t key, ofstream & fout);
void Print(void);
void getInput(char * line, uint64_t &key, uint64_t &val);
void getInput(char * line, uint64_t &key);
void outputFile(ofstream & fout, const char * n);
void outputFile(ofstream & fout, uint64_t n);

int main(int argc, char * argv[]) {
	char line[10];
	uint64_t key = 0;
	uint64_t val = 0;

	if (argc < 2)
		exit(0);

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
				Print();
				return 0;
			}
			else {
				N = atoi(line);
				HashTable1 = new HashStruct[3 * N]();
				HashTable2 = new HashStruct[3 * N]();
			}
		}
	}

	delete[] HashTable1;
	delete[] HashTable2;
	HashTable1 = NULL;
	HashTable2 = NULL;

	fin.close();
	fout.close();

	return 0;

}
uint64_t hash_func1(uint64_t key) {
	return key % SIZE;
}

uint64_t hash_func2(uint64_t key) {
	return(key/SIZE)%SIZE;
}

void Insert(uint64_t key, uint64_t val, ofstream & fout) {
	uint64_t index = hash_func1(key);
	struct HashStruct T;
	struct HashStruct HS;
	HS.key = index;
	HS.val = val;
	HS.c = true;

	if (!HashTable1[index].c && HashTable1[index].val == 0) {
		HashTable1[index] = HS;
		outputFile(fout, "Inserted");
	}
	else {
		T = HashTable1[index];
		HashTable1[index] = HS;
		index = hash_func2(key);
		T.key = index;
		HashTable2[index] = T;		
		outputFile(fout, "Duplicated");
	}
}

void Delete(uint64_t key, ofstream & fout) {
	uint64_t index = hash_func1(key);

	if (!HashTable1[index].c && HashTable1[index].val == 0) {
		if (!HashTable2[index].c && HashTable2[index].val == 0) {
			outputFile(fout, "Not Found");
		}
		else {
			HashTable2[index].key = 0;
			HashTable2[index].val = 0;
			HashTable2[index].c = false;
			outputFile(fout, "Deleted");	
		}
	}
	else {
		HashTable1[index].key = 0;
		HashTable1[index].val = 0;
		HashTable1[index].c = false;
		outputFile(fout, "Deleted");
	}
}
void Find(uint64_t key, ofstream & fout) {
	uint64_t index = hash_func1(key);

	if (HashTable1[index].c == true && HashTable1[index].key == key) {
		outputFile(fout, HashTable1[index].val);
	}
	else {
		if (HashTable2[index].c == true && HashTable2[index].key == key) {
			outputFile(fout, HashTable2[index].val);
		}
		else {
			outputFile(fout, "Not Found");
		}
	}
}
void Print() {
	cout << "------------PrintHashTable1-------------" << endl;
	for (uint64_t i = 0; i < N; i++) {
		if (HashTable1[i].val != 0) {
			cout << "(" << HashTable1[i].key << " , " << HashTable1[i].val << " )" << endl;
		}
	}
	cout << "------------PrintHashTable2-------------" << endl;
	for (uint64_t i = 0; i < N; i++) {
		if (HashTable2[i].val != 0) {
			cout << "(" << HashTable2[i].key << " , " << HashTable2[i].val << " )" << endl;
		}
	}
}

void getInput(char * line, uint64_t &key, uint64_t &val) {
	char * key_split = NULL;
	char * val_split = NULL;

	line = strtok(line, " ");
	key_split = strtok(NULL, " ");
	val_split = strtok(NULL, " ");

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
