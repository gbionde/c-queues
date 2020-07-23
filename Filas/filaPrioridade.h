/*Constante que define o tamanho maximo da Fila.*/
#define MAXFILA 20

struct tpElemento{
	char info;
	int prioridade;
};

struct tpFilaP{
	int fim;
	tpElemento fila[MAXFILA];
};

/*Inicializa a fila tornando-a pronta para uso, recebe o parametro '@F' (fila) por referencia.*/
void inicializar(tpFilaP &f){
	f.fim = -1;
}

/*Recebe a posicao final da fila, verifica e retorna um char que informa se a mesma esta CHEIA ou nao.*/
char isCheia(int fim){
	return fim == MAXFILA-1;
}

/*Recebe a posicao final da fila, verifica e retorna um char que informa se a mesma esta VAZIA ou nao.*/
char isVazia(int fim){
	return fim == -1;
}

/*Retorna o PRIMEIRO elemento da fila '@F' sem precisar retira-lo da mesma.*/
tpElemento elemInicio(tpFilaP f){
	return f.fila[0];
}

/*Retorna o ULTIMO elemento da fila '@F' sem precisar retira-lo da mesma.*/
tpElemento elemFim(tpFilaP f){
	return f.fila[f.fim];
}

/*Insere um novo elemento na fila conforme a prioridade do mesmo. Recebe o parametro '@F' por referencia.*/
void enqueue(tpFilaP &f, tpElemento elem){
	f.fila[++f.fim] = elem;
	
	for(int i = f.fim; i > 0 && f.fila[i].prioridade < f.fila[i-1].prioridade; i--){
		elem = f.fila[i];
		f.fila[i] = f.fila[i-1];
		f.fila[i-1] = elem;
	}
}

/*Retira e retorna o primeiro elemento da fila. Recebe o parametro '@F' por referencia.*/
tpElemento dequeue(tpFilaP &f){
	tpElemento e = elemInicio(f);
	
	for(int i = 0; i < f.fim; i++)
		f.fila[i] = f.fila[i+1];
	f.fim--;
	
	return e;
}

/*Exibe todo o conteudo da fila.*/
void exibir(tpFilaP f){
	tpElemento e;
	
	printf("\n Informacao [Prioridade]\n\n");
	while(!isVazia(f.fim)){
		e = dequeue(f);
		printf("%c [%d]  ", e.info, e.prioridade);
	}
}
