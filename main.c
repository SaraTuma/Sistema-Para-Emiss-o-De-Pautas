#include <stdio.h>
#include <stdlib.h>

#define MAXALUNO 50
#define MAXAVAL 6
int TAluno=0;
int pesoDasProvas[MAXAVAL],pesoDosProJectos[MAXAVAL],numeroDosAlunos[MAXALUNO];
float mediaFinal[MAXALUNO],notasDasProvas[MAXAVAL],notasDosProjectos[MAXAVAL];

// Declaração de todos os métodos do projecto
void menu();
void lerQuantidadeDeAlunos();
void cadastrarAlunos();

char *avalia(float mf); 
void imprimirEstatistica(int t);
void imprimir(int limite);
int somatorio(int v[],int t);
int comparar(char v1[], char v2[]);
void ordenar(float vector[], int tam);
float media(int qnt,int peso[],float notas[]);
float acharMediaFinalDoRecurso(float nf,float mP,float mpr,float mT,float mtr);
float acharMediaFinal(float mP,float mT);
int validarPeso(int peso);
float validarNota(float nota);
int achaValorMaiProximo(float pontoDeAprox,float valores[],int t);



void menu(){
	printf("\n\t1-Cadastrar Aluno\n\t2-Imprimir pauta em ordem decrescente\n\t3-Imprimir pauta com estatistica\n\t0-Sair\n\nEscolha a opcao: ");
}


char *avalia(float mf){
	if(mf>=0.0 && mf<=4.0)
		return "Mau";
	if(mf>4.0 && mf<=9.0)
		return "Mediucre";
	if(mf>9.0 && mf<=14.0)
		return "Suficiente";
	if(mf>14.0 && mf<=18.0)
		return "Muito Bom";
	if(mf>18.0 && mf<=20.0)
		return "Excelente";
	
	return "";
}

void imprimirEstatistica(int t){
	int i,m=0,me=0,s=0,mu=0,ex=0;
	float mau=0,med=0,suf=0,mb=0,exc=0;
	printf("/tEstatistica\n");
	for(i=0;i<t;i++)
	{
		if(comparar(avalia(mediaFinal[i]),"Mau")==1)
		{
			mau++;
		}else if(comparar(avalia(mediaFinal[i]),"Mediucre")==1)
		{
			med++;	
		}else 	if(comparar(avalia(mediaFinal[i]),"Suficiente")==1)
		{
			suf++;	s++;
		}else 	if(comparar(avalia(mediaFinal[i]),"Muito Bom")==1)
		{
			mb++;mu++;	
		}else 	if(comparar(avalia(mediaFinal[i]),"Excelente")==1)
		{
			exc++;	ex++;
		}
	}
	printf("Mau: %d\nMediucre: %d\nSuficiente %d\nMuito Bom: %d\nExcelente: %d\n\n",m,me,s,mu,ex);
	printf("Mau %0.2f %%\n",((mau*t)/100));
	printf("Muito Bom: %0.2f %%\nMediucre: %0.2f %%\nSuficiente %0.2f %% \nExcelente: %0.2f %%\n\n",((mb*t)/100),((med*t)/100),((suf*t)/100),((exc*t)/100));
}

void imprimirEstatisticaTESTE(){
	float mau=0,med=0,suf=0,mb=0,exc=0;
	printf("\tEstatistica\n");
	char teste[]="Mau";
	if(comparar(teste,"Mau")==1)
	{
		mau++;
		printf("\n %s \n",teste);
	}else if(comparar(teste,"Mediucre")==1)
	{
		med++;	
	}else 	if(comparar(teste,"Suficiente")==1)
	{
		suf++;
	}else 	if(comparar(teste,"Muito Bom")==1)
	{
		mb++;	
	}else 	if(comparar(teste,"Excelente")==1)
	{
		exc++;
	}
}

void imprimir(int limite){
	int i;
	for(i=0;i<limite;i++){
		printf("Numero: %d Nota final: %0.2f Avaliacao: %s\n",numeroDosAlunos[i],mediaFinal[i],avalia(mediaFinal[i]));
	}
}


int somatorio(int v[],int t){
	int s=0;
	int i=0;
	for(;i<t;i++){
		s+=v[i];
	}
	return s;
}

//--------------------------------HERE------------------------------------------

int comparar(char v1[], char v2[]){
	int i=0, j=0;
	
	for(; i!='\0'; i++, j++){
		if(v1[i]!=v2[j])
		return 0;
	}
	return 1;
}

void ordenar(float vector[], int tam) 
{
 	int i, j; int nf,na; 
 	for (j = 1; j < tam; ++j) 
	 {
  		nf = vector[j]; 
  		na=numeroDosAlunos[j];
  		i = j - 1;
  		while (vector[i] < nf && i >= 0)
	    { 
  			vector[i+1] = vector[i];
  			numeroDosAlunos[i+1]=numeroDosAlunos[i];
   			--i;	
   		}
		vector[i+1] = nf; 
   		numeroDosAlunos[i+1]=na;
	} 
}

float media(int qnt,int peso[],float notas[])
{
	int i=0;
	float somator=0;
	for(i=0;i<qnt;i++)
		somator+=(peso[i]*notas[i]);
	return (somator/somatorio(peso,qnt));
}

float acharMediaFinalDoRecurso(float nf,float mP,float mpr,float mT,float mtr){
	if(mP==mpr && mT==mtr)
		return nf;
	float m=(mP+2*mpr)/3;
	if(nf>m)
		return nf;
	return m;
}

float acharMediaFinal(float mP,float mT)
{
	if(mP>14 && mT>12)
	{
		return (mP*0.6+0.42*mT);
	}
	else if(mP<mT)
	{
		return mP;
	}
	return mT;
}


float validarNota(int numProva, char frase)
{
	float nota;
	printf("Informe a Nota %s %d : ",frase,(numProva+1));
	scanf("%f",&nota);
	while(nota<0.0 || nota>20.0){
		printf("Nota invalida!!,de estar [0;20], digite novamente: ");
		scanf("%f",&nota);
	}
	return nota;
}


int validarPeso(int numProva)
{
	int peso;
	printf("Informe o Peso da prova %d : ",(numProva+1));
	scanf("%d",&peso);
	while(peso<1 || peso>6){
		printf("Peso invalido,deve estar [1;6], insira novamente: ");
		scanf("%d",&peso);
	}
	return peso;
}


int achaValorMaiProximo(float pontoDeAprox,float valores[],int t){
	int i=0,pMaior=0;
	for(;i<t;i++){
		if(valores[i]>pMaior && pontoDeAprox>=valores[i]){
			pMaior=i;
		}
	}
	return pMaior;
}

void lerQuantidadeDeAlunos(){
	printf("Informe a quantidade de aluno a cadastrar: ");
	scanf("%d",&TAluno);
	while(TAluno<0 || TAluno>MAXALUNO){
		printf("Quantidade invalida!!, digite novamente: ");
		scanf("%d",&TAluno);
	}
}

int lerTotalDeProvasEProjectos(int opcao){
	int numProvas;
	if(opcao==1)
		printf("Informe o total de Provas: ");
	else
		printf("Informe o total de Projectos obrigatorio: ");
	scanf("%d",&numProvas);
	while(numProvas<0 || numProvas>(MAXAVAL-2)){
		printf("Quantidade invalida!!, digite novamente: ");
		scanf("%d",&numProvas);
	}
	return numProvas;
}

int lerNumeroDeEstudante(int num){
	int numero;
	printf("Informe o numero do estudante %d: ", num);
	scanf("%d",&numEstudante);
	while(numEstudante<0){
		printf("Numero de estudante invalido!!, digite novamente: ");
		scanf("%d",&numEstudante);
	}
	return numEstudante;
}

void cadastrarProvas(int numeroDaProva){
	int contador;
	char frase = "da Prova";
	for(contador=0;contador<numeroDaProva;contador++){
		notasDasProvas[contador]=validarNota(numeroDaProva, frase);
		pesoDasProvas[contador]=validarPeso(numeroDaProva, frase);
	}
}

void cadastrarProjectos(int numeroDoProjecto){
	int contador;
	char frase = "do Projecto";
	for( contador = 0 ; contador < numeroDoProjecto ; contador++ ){
		notasDosProjectos[contador] = validarNota(numeroDoProjecto, frase);
		pesoDosProJectos[contador] = validarNota(numeroDoProjecto, frase);
	}
}

void lerAlunos(int numeroDeProvas, int numeroDeProjectos){
	int i;
	float real=0,peso=1;
	for(i=0;i<TAluno;i++){
		numeroDosAlunos[i]=lerNumeroDeEstudante(i);
		cadastrarProvas(numeroDeProvas);
		cadastrarProjectos(numeroDeProjectos);

		// LIMPAR A TELA

		float mpr,mtr,mP=media(numeroDeProvas,pesoDasProvas,notasDasProvas);
		float mT=media(numeroDeProjectos,pesoDosProJectos,notasDosProjectos);//m�dia do trabalho
		mediaFinal[i]=acharMediaFinal(mP,mT);
		mpr=mP;mtr=mT;
		
		//Verificar se foi a recurso na prova
		if(mP>6 && mP<10 || mT>4 && mT<9){
		if(mP>6 && mP<10){
			printf("Prova de Recuperacao!!\n");
			printf("Informa a Nota da prova de recuperacao: ");
			scanf("%f",&real);
			notasDasProvas[MAXAVAL-1]=validarNota(real);
			printf("Informa o peso da prova de recuperacao: ");
			scanf("%f",&peso);
			pesoDasProvas[MAXAVAL-1]=validarPeso(peso);				
			int va=achaValorMaiProximo(mP,notasDasProvas,numeroDeProvas);//pegar a nota da prova que mais se aproxima a media das provas
			notasDasProvas[va]=real;//subistitui��o da nota que mais se aproxima da media pela nota da prova de recupera��o
			pesoDasProvas[va]=peso;
			mpr = (notasDasProvas[MAXAVAL-1]*pesoDasProvas[MAXAVAL-1])/pesoDasProvas[MAXAVAL-1];
		}
		//Verificar se foi a recurso no projecto
			if(mT>4 && mT<9){
			printf("Projecto de Recuperacao\n!!");
			printf("Informa a Nota do projecto de recuperacao: ");
			scanf("%f",&real);
			notasDosProjectos[MAXAVAL-1]=validarNota(real);
			printf("Informa o peso do projecto de recuperacao: ");
			scanf("%f",&peso);
			notasDosProjectos[MAXAVAL-1]=validarPeso(peso);		
			int va=achaValorMaiProximo(mT,notasDosProjectos,numeroDeProjecto);//pegar a nota do trabalho que mais se aproxima a media dos trabalhos
			notasDosProjectos[va]=real;//subistitui��o da nota que mais se aproxima da media pela nota da prova de recupera��o
			pesoDosProJectos[va]=peso;
			mtr = (notasDosProjectos[MAXAVAL-1]*pesoDosProJectos[MAXAVAL-1])/peso;
		}
		mediaFinal[i]=acharMediaFinalDoRecurso(mediaFinal[i],mP,mpr,mT,mtr);
	}	
	}
}

void cadastrarAlunos(){
	int numeroDeProvas,numeroDeProjectos;
	lerQuantidadeDeAlunos();
	numeroDeProvas = lerTotalDeProvasEProjectos(1);
	numeroDeProjectos = lerTotalDeProvasEProjectos(0);
	lerAlunos(numeroDeProvas, numeroDeProjectos);
}

void startGame(){
	int opcao=0,j,i,numEstudante,np,npr;
	float real=0,peso=1;
	
	do{
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				//Cadastrar
				cadastrarAlunos();
				break;
			case 2:
				//Imprimir pauta em ordem decrescente
				ordenar(mediaFinal,TAluno);
				imprimir(TAluno);
				break;
			case 3:
				//Imprimir pauta com estatistica
				imprimirEstatistica(TAluno);
				break;
			case 0:
			//Sair
			break;
			default:
				printf("Opcao invalida");
				break;
		}
	}while(opcao!=0);
}

int main(int argc, char *argv[]) 
{
	startGame();
	//imprimirEstatisticaTESTE();
	return 0;
}
