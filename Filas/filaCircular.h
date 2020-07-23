/*Constante que define o tamanho maximo da fila.*/
#define MAXFILA 10

struct tpFilaC{
	int inicio, fim, qtd;
	char fila[MAXFILA];
};

/*Inicializa a fila tornando-a pronta para uso, recebe o parametro '@F' (fila) por referencia.*/
void inicializar(tpFilaC &f){
	f.inicio = 0;
	f.fim = -1;
	f.qtd = 0;	
}

/*Retorna o PRIMEIRO elemento da fila '@F' sem precisar retira-lo da mesma.*/
char elemInicio(tpFilaC f){
	return f.fila[f.inicio];
}

/*Retorna o ULTIMO elemento da fila '@F' sem precisar retira-lo da mesma.*/
char elemFim(tpFilaC f){
	return f.fila[f.fim];
}

/*Recebe a posicao final da fila, verifica e retorna um char que informa se a mesma esta CHEIA ou nao.*/
char isCheia(int qtd){
	return qtd == MAXFILA;
}

/*Recebe a posicao final da fila, verifica e retorna um char que informa se a mesma esta VAZIA ou nao.*/
char isVazia(int qtd){
	return qtd == 0;
}

/*Insere um novo elemento no fim da fila. Recebe o parametro '@F' por referencia.*/
void enqueue(tpFilaC &f, char elem){
	if(f.fim == MAXFILA-1)
		f.fim = 0;
	else
		f.fim++;
	
	f.qtd++;
	f.fila[f.fim] = elem;
}

/*Retira e retorna o primeiro elemento da fila. Recebe o parametro '@F' por referencia.*/
char dequeue(tpFilaC &f){
	char aux = f.fila[f.inicio];

	if(f.inicio == MAXFILA-1)
		f.inicio = 0;
	else
		f.inicio++;
	
	f.qtd--;
	return aux;
}

/*Exibe todo o conteudo da fila.*/
void exibeFila(tpFilaC f){
	while(!isVazia(f.qtd)){
		printf("%c ", dequeue(f));
	}
}
