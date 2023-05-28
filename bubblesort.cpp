#include <stdio.h>
#include <string.h>

int N = 0;

struct data{
	char prod[1000];
};
struct data data[1000];

void read(){
	FILE *read;
	read = fopen("randomproduct.in", "r");
	while(!feof(read)){
		fscanf(read, "%s\n", &data[N].prod);
		N++;
	}
	fclose(read);
}

int main(){
	read();

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N - 1; j++){
			if(strcmp(data[j].prod, data[j+1].prod) > 0){
				struct data temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	printf("Random Product List :\n");
	for(int k = 0; k < N; k++){
		printf("%d. %s\n", k+1, data[k].prod);
	}
	
	return 0;
}
