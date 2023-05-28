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
		fscanf(read, "%[^\n]\n", &data[N].prod);
		N++;
	}
	fclose(read);
}


void quicksort(char number[1000][1000],int first,int last){
   int i, j, pivot;
   char temp[1000];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(strcmp(number[i],number[pivot])<0 && i<last)
            i++;
         while(strcmp(number[j],number[pivot])>0)
            j--;
         if(i<j){
         	strcpy(temp,number[i]);
         	strcpy(number[i],number[j]);
         	strcpy(number[j],temp);
         }
      }
      strcpy(temp,number[pivot]);
      strcpy(number[pivot],number[j]);
      strcpy(number[j],temp);
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
	read();

	char s[1000][1000];
	int A[N];
	for(int i=0;i<N;i++){
		strcpy(s[i],data[i].prod);
	}
	
	quicksort(s,0,N-1);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(strcmp(s[i],data[j].prod)==0){
				struct data temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
			
		}
	}
	
	printf("Random Product List :\n");
	for(int k = 0; k < N; k++){
		printf("%d. %s\n", k+1, data[k].prod);
	}
	
	return 0;
}
