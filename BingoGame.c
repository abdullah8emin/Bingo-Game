#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bingo() {
	int i;
	for(i=0;i<50;i++) printf("-");
	printf("\n");
	for(i=0;i<39;i++) {
		printf("-");
		if(i==19) printf("Bingo Game!");
	}
	printf("\n");
	for(i=0;i<50;i++) printf("-");
	printf("\n\n");	
}

int main() {
	
	int j,kontrol=1,array[8],sayi,secim;
	char liste[8],X[1]="X"; 
	srand(time(NULL)); //farklý random sayýlar üretmeye yarýyor.
	
	while(1) {
		int i=0,tries=0;
		bingo();
		while(i<8) {
			sayi = rand() %100;	
			for(j=0;j<8;j++) {
				if(sayi==array[j]) {
					kontrol = 0;
					break;
				}
				else kontrol = 1;
				}
			if (kontrol==1) {
				array[i] = sayi;
				i++;
			}
		}
		for(i=0;i<8;i++) liste[i] = (char) array[i]; //oluþturulan arrayin elemanlarýný char olarak bir listeye atamaya yarýyor.
		while(1){
			
			for(i=0;i<8;i++) {
				if(liste[i]=='X') printf("%5c",liste[i]);
				else printf("%5d",liste[i]);
			}
			
			printf("\n\nEnter a number (0 for random number/-1 to quit): ");
			scanf("%d",&secim);
			
			if (secim==-1) exit(0);
			else if (secim==0)  {
				sayi = rand() %100;
				for(i=0;i<8;i++) {
					if (sayi==array[i]) liste[i] = X[0]; 
				}
				tries++;
			}
			else {
				for(i=0;i<8;i++) {
					if (secim==array[i]) liste[i] = X[0];
				}
				tries++;
			}
			for(i=0;i<8;i++) {
				if(liste[i]=='X') kontrol = 1;
				else {
					kontrol = 0;
					break;
				}
			}
			if (kontrol==1) {
				for(i=0;i<8;i++) printf("%5c",liste[i]);
				printf("\nBINGO! You Won!");
				printf("\nTotal number of tries: %d\n",tries);
				break;
			}
		}
		printf("Do you wanna play again? (1-Yes/0-No): ");
		scanf("%d",&kontrol);
		if (kontrol==0) break;
	}
	system("pause");
	return 0;
}
