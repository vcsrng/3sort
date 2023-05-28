#include <stdio.h>
#include <string.h>

int N = 0;

struct data{
	char prod[100];
};
struct data data[100];

void read(){
	FILE *read;
	read = fopen("randomproduct.in", "r");
	while(!feof(read)){
		fscanf(read, "%[^\n]\n", &data[N].prod);
		N++;
	}
	fclose(read);
}

void msort(char a[][100],int low ,int high){
 	if(low < high){
  		int mid = (low+high)/2;
  		msort(a,low,mid);
  		msort(a,mid+1,high);
  	int i=low,j=mid+1,k=low;
  	char temp[100][100];
  	while(i<= mid && j <= high){
   		if(strcmp(a[i], a[j])<0){
    		strcpy(temp[k],a[i]);
    		k++;
    		i++;
   		}else{
    		strcpy(temp[k],a[j]);
    		k++;
    		j++;
   		}
 	}
  	while(i <= mid){
   		strcpy(temp[k],a[i]);
   		k++;
   		i++;
  	}
  	while(j<=high){
   		strcpy(temp[k],a[j]);
   		k++;
   		j++;
  	}
  	for(i=low;i<=high;i++)
   		strcpy(a[i],temp[i]);
 	}
}

int main(){
	read();

	char s[100][100];
	int A[N];
	for(int i=0;i<N;i++){
		strcpy(s[i],data[i].prod);
	}
	
	msort(s,0,N-1);
	
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
