#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int n){
	int *v = (int *)(malloc(sizeof(int)*n));
	return v;
}
void trocaElemento(int *v, int i, int j){
	int	aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}
void inicializaVetor(int *v, int n){
	int i;
	if(v!=NULL){
		for(i=0;i<n;i++)
			v[i] = i+1;
	}
	else{
		printf("Vetor Nulo!\n");
	}
}
void permuta(int *v, int n, int i){
	int	j;
	if(i==n){
		for(j=0;j<n;j++){
			printf ("%d ", v[j]);
		}
		printf ("\n");
	}
	else{
		for(j=i;j<n;j++){
			trocaElemento(v,i,j);
			permuta(v,n,i+1);
			trocaElemento(v,i,j);
		}
	}
}
int main(void){
	int	*v, i, n;
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &n);
	v = alocaVetor(n);
	inicializaVetor(v,n);
	permuta(v,n,0);
	return 0;
}
