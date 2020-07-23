/*Constante que define o tamanho maximo da fila.*/
#define MAXFILA 10

struct tpFila{
	char fila[MAXFILA];
	int fim;	
};

/*Inicializa a fila tornando-a pronta para uso, recebe o parametro '@F' (fila) por referencia.*/
void inicializar(tpFila &F){
	F.fim = -1;
}

/*Recebe a posicao final da fila, verifica e retorna um char que informa se a mesma esta CHEIA ou nao.*/
char isCheia(int fim){
	return fim == MAXFILA-1;
}

/*Recebe a posicao final da fila, verifica e retorna um char que informa se a mesma esta VAZIA ou nao.*/
char isVazia(int fim){
	return fim == -1;
}

/*Insere um novo char no fim da fila. Recebe o parametro '@F' por referencia.*/
void enqueue(tpFila &F, char elem){
	F.fila[++F.fim] = elem;
}

/*Retira e retorna o primeiro elemento da fila. Recebe o parametro '@F' por referencia.*/
char dequeue(tpFila &F){
	char aux = F.fila[0];
	
	for(int i = 0; i < F.fim; i++)
		F.fila[i] = F.fila[i+1];	
	F.fim--;
		
	return aux;
}

/*Retorna o PRIMEIRO elemento da fila '@F' sem precisar retira-lo da mesma.*/
char elemInicio(tpFila F){
	return F.fila[0];
}

/*Retorna o ULTIMO elemento da fila '@F' sem precisar retira-lo da mesma.*/
char elemFim(tpFila F){
	return F.fila[F.fim];
}

/*Exibe todo o conteudo da fila.*/
void exibir(tpFila F){
	while(!isVazia(F.fim)){
		printf("%c ", dequeue(F));
	}
}

