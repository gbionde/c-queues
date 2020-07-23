/*Constante que define o tamanho maximo da pilha.*/
#define MAXPILHA 10

struct tpPilhaM{
	int topoA, topoB;
	char pilha[MAXPILHA];
};

/*Inicializa a pilha tornando-a pronta para uso, recebe o parametro '@P' por referencia.*/
void inicializar(tpPilhaM &p){
	p.topoA = -1;
	p.TopoB = MAXPILHA;
}

/*Recebe os topos das pilhas internas, verifica e retorna um char que informa se a mesma esta CHEIA ou nao.*/
char isCheia(int topoA, topoB){
	return topoA+1 == topoB;
}

/*Recebe a posicao topo e o ID da pilha, verifica e retorna um char que informa se a mesma esta VAZIA ou nao.*/
char isVazia(int topo, int np){
	if(np == 1)
		return topo == -1;
	else
		return topo == MAXPILHA;
}

/*Insere um novo char no topo da pilha identificada por NP. Recebe o parametro '@P' por referencia.*/
void push(tpPilhaM &p, char elem, int np){
	if(np == 1)
		p.pilha[++topoA] = elem;
	else
		p.pilha[--topoB] = elem;
}

/*Retira e retorna o elemento do topo da pilha identificada por NP. Recebe o parametro '@P' por referencia.*/
char pop(tpPilhaM &p, int np){
	if(np == 1)
		return p.pilha[p.topoA--];
	else	
		return p.pilha[p.topoB++];	
}

/*Retorna o elemento do topo da pilha NP sem precisar retira-lo da mesma.*/
char elemTopo(tpPilhaM p, int np){
	if(np == 1)
		return p.pilha[p.topoA];
	else	
		return p.pilha[p.topoB];	
}

/*Exibe todo o conteudo da pilha.*/
void exibir(tpPilhaM p, int np){
	if(np == 1){
		while(!isVazia(p.topoA, np))
			printf("%c ", pop(p, np));
	}else{
		while(!isVazia(p.topoB, np))
			printf("%c ", pop(p, np));
	}
}
