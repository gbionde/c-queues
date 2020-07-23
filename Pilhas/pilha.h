/*Constante que define o tamanho maximo da pilha.*/
#define MAXPILHA 10

struct tpPilha{
	char pilha[MAXPILHA];
	int topo;
};

/*Inicializa a pilha tornando-a pronta para uso, recebe o parametro '@P' por referencia.*/
void inicializar(tpPilha &P){
	P.topo = -1;
}

/*Recebe a posicao topo da pilha, verifica e retorna um char que informa se a mesma esta CHEIA ou nao.*/
char isCheia(int topo){
	return topo == MAXPILHA-1;
}

/*Recebe a posicao topo da pilha, verifica e retorna um char que informa se a mesma esta VAZIA ou nao.*/
char isVazia(int topo){
	return topo == -1;
}

/*Insere um novo char no topo da pilha. Recebe o parametro '@P' por referencia.*/
void push(tpPilha &P, char elem){
	P.pilha[++P.topo] = elem;
}

/*Retira e retorna o elemento do topo da pilha. Recebe o parametro '@P' por referencia.*/
char pop(tpPilha &P){
	return P.pilha[P.topo--];
}

/*Retorna o elemento do topo da pilha '@P' sem precisar retira-lo da mesma.*/
char elemTopo(tpPilha P){
	return P.pilha[P.topo];
}

/*Exibe todo o conteudo da pilha.*/
void exibir(tpPilha P){
	while(!isVazia(P.topo)){
		printf("\n%c", pop(P));
	}
}

