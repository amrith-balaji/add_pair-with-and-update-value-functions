#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
int pair_count=0;
struct pair {
    char *key;
    char *value;
};
struct pair hash_table[MAX_SIZE];
int hash(char *key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % MAX_SIZE;
}
void add_pair(char *key, char *value) {
    int index = hash(key);
    hash_table[index].key = strdup(key);
    hash_table[index].value = strdup(value);
	pair_count++;
}
char *get_value(char *key) {
    int index = hash(key);
    return hash_table[index].value;
}
int update_value(char *key, char *value) {
    int index = hash(key);
    hash_table[index].value = strdup(value);
    return 1;
}
int main () {
	char *str;
	char *res;

	add_pair("the","1");	
	update_value("the", "2");
	update_value("the", "3");
	update_value("the", "100");
	res= get_value("the");

	printf("total records %d\n",pair_count);
	printf("value is  %d\n",atoi(res));

	return 0;
}
