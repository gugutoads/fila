#include <stdio.h>
#include <stdlib.h>

typedef struct Processo{ //struct para criar o processo
     int dado;
     struct Processo* prox;
}Processo;

typedef struct Queue{ //struct para criar a fila
	Processo* primeiro;
	Processo* ultimo;
} Queue;

typedef struct Stack{ // struct para criar a pilha
     Processo* topo;
}Stack;


Queue* InicializaQueue(){//função para inicilizar a fila
   Queue* queue = (Queue*)malloc(sizeof(Queue));
   queue->primeiro = NULL;
   queue->ultimo = NULL;
   return queue;
}

Stack* InicializaStack(){ //função para inicilizar a pilha
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->topo= NULL;
    return stack;
}

void enqueue(Queue* queue, int dado){ // coloca na fila
     Processo* NovoProcesso = (Processo*)malloc(sizeof(Processo));
	 NovoProcesso->dado = dado;
	 NovoProcesso->prox = NULL;
	  
    if (queue->ultimo) {
        queue->ultimo->prox = NovoProcesso;
    } else {
        queue->primeiro = NovoProcesso;
    }
    queue->ultimo = NovoProcesso;
}


int MostrarFila(Queue* queue){
	Processo* ProcessoAtual = queue->primeiro;
	
	printf("Processos na fila de prontos: \n");
	while(ProcessoAtual != NULL){
		printf("Processo numero: %d\n", ProcessoAtual->dado);
		ProcessoAtual = ProcessoAtual->prox;
	}
}


int dequeue (Queue* queue){	
	if(queue->primeiro ==NULL){
		printf("Fila vazia");
		return NULL;
	}
	Processo* ProcessoRemover = queue->primeiro;
	int dado = ProcessoRemover->dado;
	queue->primeiro = queue->primeiro->prox;
	free(ProcessoRemover);
	return dado;
}

void push(Stack* stack, int dado){
	
}

int pop(Stack* stack){
	
}

int main(){
    Queue* queue = InicializaQueue();	
    Stack* stack = InicializaStack();   

	enqueue(queue, 10); //coloca na fila
	enqueue(queue, 20); //coloca na fila
	enqueue(queue, 34); //coloca na fila
	enqueue(queue, 40); //coloca na fila
	
	MostrarFila(queue); //mostra os processos
	
	printf("\n");
	for(int i=0; i<4 ; i++){ //percorre toda a fila
		int dado = dequeue(queue); // tira da fila e guarda o dado
		if(dado != NULL){ //se a fila não estiver vazia 
		    printf("Processo numero %d sendo executado \n", dado);
			push(stack, dado); //coloca o dado na pilha;
		}
	}
	
	printf("\n");
	for(int i=0; i<4; i++){ //loop para desempilhat
	    int dado = pop(stack);
		printf("Processo numero %d finalizado \n", dado);
	}

}
