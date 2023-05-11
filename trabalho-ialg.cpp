// HEITOR SABINO
// BRYAN NANETI
// RAFAEL FURTADO

#include <iostream>
using namespace std;

//STRUCT

struct roupas {
	int id;
	string tipo;
	int tam;
	string cor, marca;
	bool flagStruct;
};

//. . . . . . . . . . . . . . . . . . .
//CASE 5: ORDENAR
//. . . . . . . . . . . . . . . . . . .

//ORDENA POR ID

int dividir_ID (roupas *vet, int esq, int dir){
	int cont=esq;
	
	for(int i=esq+1; i<=dir; i++){
		if(vet[i].id < vet[esq].id){
			cont++;
			swap(vet[i],vet[cont]);
		}
	}
	swap(vet[esq],vet[cont]);
	
	return cont;
}

void QuickSort_ID(roupas *vet, int esq, int dir){
	int pos;
	if(esq < dir){
		pos = dividir_ID(vet,esq,dir);
		QuickSort_ID(vet,esq,pos-1);
		QuickSort_ID(vet,pos+1,dir);
	}
}

//ORDENA POR TIPO

int dividir_TIPO (roupas *vet, int esq, int dir){
	int cont=esq;
	
	for(int i=esq+1; i<=dir; i++){
		if(vet[i].tipo < vet[esq].tipo){
			cont++;
			swap(vet[i],vet[cont]);
		}
	}
	swap(vet[esq],vet[cont]);
	
	return cont;
}

void QuickSort_TIPO(roupas *vet, int esq, int dir){
	int pos;
	if(esq < dir){
		pos = dividir_TIPO(vet,esq,dir);
		QuickSort_TIPO(vet,esq,pos-1);
		QuickSort_TIPO(vet,pos+1,dir);
	}
}

//ORDENA POR TAMANHO

int dividir_TAMANHO (roupas *vet, int esq, int dir){
	int cont=esq;
	
	for(int i=esq+1; i<=dir; i++){
		if(vet[i].tam < vet[esq].tam){
			cont++;
			swap(vet[i],vet[cont]);
		}
	}
	swap(vet[esq],vet[cont]);
	
	return cont;
}

void QuickSort_TAMANHO(roupas *vet, int esq, int dir){
	int pos;
	if(esq < dir){
		pos = dividir_TAMANHO(vet,esq,dir);
		QuickSort_TAMANHO(vet,esq,pos-1);
		QuickSort_TAMANHO(vet,pos+1,dir);
	}
}

//ORDENA POR COR

int dividir_COR (roupas *vet, int esq, int dir){
	int cont=esq;
	
	for(int i=esq+1; i<=dir; i++){
		if(vet[i].cor < vet[esq].cor){
			cont++;
			swap(vet[i],vet[cont]);
		}
	}
	swap(vet[esq],vet[cont]);
	
	return cont;
}

void QuickSort_COR(roupas *vet, int esq, int dir){
	int pos;
	if(esq < dir){
		pos = dividir_COR(vet,esq,dir);
		QuickSort_COR(vet,esq,pos-1);
		QuickSort_COR(vet,pos+1,dir);
	}
}

//ORDENA POR MARCA

int dividir_MARCA (roupas *vet, int esq, int dir){
	int cont=esq;
	
	for(int i=esq+1; i<=dir; i++){
		if(vet[i].marca < vet[esq].marca){
			cont++;
			swap(vet[i],vet[cont]);
		}
	}
	swap(vet[esq],vet[cont]);
	
	return cont;
}

void QuickSort_MARCA(roupas *vet, int esq, int dir){
	int pos;
	if(esq < dir){
		pos = dividir_MARCA(vet,esq,dir);
		QuickSort_MARCA(vet,esq,pos-1);
		QuickSort_MARCA(vet,pos+1,dir);
	}
}

//UM MENU QUE MOSTRA OS CAMPOS DA STRUCT, PARA O USUARIO ESCOLHER A PARTIR DE QUAL CAMPO ELE QUER ORDENAR
void MenuStruct (){
	cout << endl << "_" << endl << endl;
	cout << "Por qual campo deseja ordenar?" << endl;
	cout << " [ 1 ] - ORDENAR POR ID" << endl;
	cout << " [ 2 ] - ORDENAR POR TIPO" << endl;
	cout << " [ 3 ] - ORDENAR POR TAMANHO" << endl;
	cout << " [ 4 ] - ORDENAR POR COR" << endl;
	cout << " [ 5 ] - ORDENAR POR MARCA" << endl;
	cout << endl << "_" << endl << endl << endl;
}

//SWITCH QUE DETERMINARA QUAL CAMPO SERA ORDENADO A PARTIR DA ESCOLHA DO USUARIO
void SwitchStruct (roupas *vet, int posicao, int campo){
	switch (campo){
		case 1:
			QuickSort_ID(vet, 0, posicao-1);
			break;
		case 2:
			QuickSort_TIPO(vet, 0, posicao-1);
			break;
		case 3:
			QuickSort_TAMANHO(vet, 0, posicao-1);
			break;
		case 4:
			QuickSort_COR(vet, 0, posicao-1);
			break;
		case 5:
			QuickSort_MARCA(vet, 0, posicao-1);
			break;
	}
}


//. . . . . . . . . . . . . . . .
//CASE 4: ALTERAR
//. . . . . . . . . . . . . . . .

//PROCEDIMENTO PRINCIPAL  "Altera"
void Altera (roupas *v, int posicao, int QueroAlterar, int &VerificaLista){
	int verifica = 0;
	for (int i = 0; i < posicao; i++){
		if (QueroAlterar == v[i].id){
//CONDICAO QUE VERIFICA SE A ROUPA JA FOI EXCLUIDA, SE SIM, INCREMENTA NA VARIAVEL "VerificaLista".
//QUE, COMO EXPLICADO, CONTABILIZA ROUPAS EXCLUIDAS.			
			if (not v[i].flagStruct)
				VerificaLista++;
				
			verifica++;
			cin.ignore();
			cout << "Tipo da roupa: ";
			getline(cin, v[i].tipo);
	
			cout <<"Tamanho da roupa (UM NUMERO): ";
			while(!(cin >> v[i].tam and v[i].tam > 0)){
				cout << endl <<"Digite um tamanho valido: ";
				cin.clear();
				cin.ignore(100, '\n');
			}
	
			cout << "Cor da roupa: ";
			cin.ignore();
			getline(cin, v[i].cor);
	
			cout << "Marca da roupa: ";
			getline(cin, v[i].marca);
	
			cout << endl;
			v[i].flagStruct = true;
		}
	}
//VERIFICA SE O ID DIGITADO EXISTE OU EXISTIU, JA QUE O PROCEDIMENTO "ALTERA" TAMBEM RECUPERA "ROUPAS" QUE FORAM EXCLUIDA
	if (verifica == 0)
		cout << "ERRO: O ID que voce digitou nao existe!" << endl << "Tente novamente:" << endl;	
		
	cout << endl << "_" << endl << endl << endl;
}


//LISTA OS ID'S DISPONIVEIS PARA O USUARIO ALTERAR, NESSE CASO CONSTA ID'S EXCLUIDOS TAMBEM, POIS, COMO JA DITO, A "ALTERA" TAMBEM RECUPERA "ROUPAS" EXCLUIDAS
void ListaID_altera (roupas *v, int posicao){
	cout << endl << "_" << endl;
	cout << endl << "Digite o ID da roupa que voce deseja alterar: " << endl << "Lembrete: voce pode alterar uma roupa que ja foi excluida!" << endl << "Assim, voce pode recupera-la, alem de poder, obviamente, alterar seus campos." << endl << endl;
	for (int i = 0, r = 0; i < posicao; i++){
		if (v[i].flagStruct){
			cout << "-> Roupa " << r << ": "<< v[i].id << endl;
//ESSA VARIAVEL "r" É USADA PARA MOSTRAR AS QUANTIDADES DE ROUPAS VALIDAS, OU SEJA, QUE NAO FORAM EXCLUIDAS
			r++;
		} else {
//AQUI TEMOS AS ROUPAS QUE FORAM EXCLUIDAS, FIZEMOS DESSA FORMA PARA ESPECIFICAR BEM PARA O USUARIO
			cout << "ROUPA EXCLUIDA" << ": " << v[i].id << endl;
		}
	}
	cout << endl << "_" << endl << endl << endl;
}

//. . . . . . . . . . . . . . . .
//CASE 2: EXCLUIR
//. . . . . . . . . . . . . . . .

//LISTA ID'S EXISTENTES PARA SEREM EXCLUIDOS
void ListaID_exclue (roupas *v, int posicao){
	cout << endl << "_" << endl;
	cout << endl << "Digite o ID da roupa que voce deseja excluir: " << endl;
	for (int i = 0, r = 0; i < posicao; i++)
		if (v[i].flagStruct){
			cout << "-> Roupa " << r << ": "<< v[i].id << endl;
			r++;
		}
	cout << endl;
}

//PROCEDIMENTO PRINCIPAL "Exclue", NELE USAMOS AS FLAGS DECLARADAS NA STRUCT PARA "EXCLUIR" UM DADO, DECLARANDO ELE COMO FALSE.  
//ASSIM, ATRAVES DE UMA EXCLUSAO LOGICA, APENAS DESABILITAMOS/OMITIMOS ELE, PARA QUE O USUARIO POSSA RECUPERA-LO, CASO QUEIRA.
void Exclue (roupas *v, int posicao, int QueroExcluir, int &VerificaLista){
	int verifica = 0;
	for(int i = 0; i < posicao; i++){
		if (QueroExcluir == v[i].id){
			v[i].flagStruct = false;
			verifica++;
			cout << "Removido com sucesso!" << endl;	
		}  
	}
//CONDICAO QUE VERIFICA SE O ID DIGITADO CONSTA NA LISTA MENCIONADA
	if (verifica == 0){
		cout << "ERRO: O ID que voce digitou nao existe!" << endl << "Tente novamente:" << endl;
		VerificaLista++;
	}

	cout << endl << "_" << endl << endl << endl;
}

//. . . . . . . . . . . . . .
//CASE 3: LISTAR
//. . . . . . . . . . . . . .


//PROCEDIMENTO PRINCIPAL "Lista", NELE APENAS LISTAMOS OS DADOS VALIDOS PREENCHIDOS PELO USUARIO,
// VERIFICANDO SE O DADO EXISTE ATRAVES DA "flagStruct"
void Lista (roupas *v,int posicao){
	cout << endl << "_" << endl;
	cout << endl <<"~~~~~ CLOSET ~~~~~" << endl;
	
	for (int i = 0, r = 0; i < posicao; i++)
		if(v[i].flagStruct){
			cout << endl << "     Roupa " << r << "     " << endl;
			cout << "ID: "<< v[i].id << endl;
			cout << "Tipo: " << v[i].tipo << endl;;
			cout << "Tamanho: " << v[i].tam << endl;
			cout << "Cor: " << v[i].cor << endl;
			cout << "Marca: " << v[i].marca << endl;
			r++;
		}
		
	cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl << "_" << endl << endl << endl;
}


//. . . . . . . . . . . . . . . 
//CASE 1: INCLUIR
//. . . . . . . . . . . . . . . 

//FUNCAO "Expande" QUE AUMENTA O TAMANHO DO VETORR DINAMICO DECLARADO NO INT MAIN(), ESSA FUNCAO E CHAMADA TODA VEZ QUE O VETOR E PREENCHIDO, 
//COMO MENCIONADO NO TRABALHO, ELA AUMENTA O TAMANHO TOTAL EM 20% A PARTIR DO TAMANHO TOTAL INICIAL, QUE E 5 
roupas* Expande (roupas *v, int &tamanho){
	int tamanhonovo = tamanho * 1.2;
	roupas *novo = new roupas [tamanhonovo];
	for (int i = 0; i < tamanho; i++){
		novo[i].id = v[i].id;
		novo[i].tipo = v[i].tipo;
		novo[i].tam = v[i].tam;
		novo[i].cor = v[i].cor;
		novo[i].marca = v[i].marca;
		novo[i].flagStruct = v[i].flagStruct;
	}
	for (int i = tamanho; i < tamanhonovo; i++){
		novo[i].id = 0;
		novo[i].tipo = " ";
		novo[i].tam = 0;
		novo[i].cor = " ";
		novo[i].marca = " "; 
		novo[i].flagStruct = true;
	}
	
	tamanho = tamanhonovo;
//DESALOCANDO VETOR ANTIGO. POIS, ALEM DE NAO POSSUIR O TAMANHO ATUALIZADO, FOI FEITA UMA COPIA SUA NO NOVO VETOR .
	delete [] v;
	return novo;
}


//PROCEDIMENTO "Insere", NELE ADICIONAMOS NOVAS "ROUPAS", INCREMENTANDO NA VARIAVEL POSICAO QUE DETERMINA POSICOES OCUPADAS NO VETOR
void Insere (roupas *v, int &tamanho, int &posicao){
	cout << endl << "_" << endl;
	cout << endl << "   Inserindo roupa   " << endl;
	v[posicao].id = posicao + 120;
	
	cin.ignore();
	cout << "Tipo da roupa: ";
	getline(cin, v[posicao].tipo);
	
	
	cout <<"Tamanho da roupa (UM NUMERO): ";
	while(!(cin >> v[posicao].tam and v[posicao].tam > 0)){
		cout << endl <<"Digite um tamanho valido: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	
	cout << "Cor da roupa: ";
	cin.ignore();
	getline(cin, v[posicao].cor);
		
	cout << "Marca da roupa: ";
	getline(cin, v[posicao].marca);
	
	cout << endl << "_" << endl << endl << endl;
	v[posicao].flagStruct = true;
	
	posicao++;
}


void menu () {
	cout << ". . . . . . . . ." << endl;
	cout << " . . . . . . . . " << endl << endl;
	cout << " [ 1 ] - incluir" << endl;
	cout << " [ 2 ] - excluir" << endl;
	cout << " [ 3 ] - listar" << endl;
	cout << " [ 4 ] - alterar" << endl;
	cout << " [ 5 ] - ordenar" << endl;
	cout << " [ 6 ] - sair" << endl << endl;
	cout << " . . . . . . . . " << endl;
	cout << ". . . . . . . . ." << endl << endl;
	cout << "Digite um numero: ";
}

//. . . . . . . . . . . 
//INT MAIN()
//. . . . . . . . . . .

int main(){
	int tamanho = 5, posicao = 0, VerificaLista = 0;
	roupas *vetor = new roupas [tamanho];
	
//MENU INTERATIVO, TODO O CODIGO RODA EM FUNCAO DESSE WHILE E DESSE SWITCH. 
//A CONDICAO USADA NO WHILE FOI UMA FLAG QUE ATINGE VALOR FALSO SOMENTE NO CASE 6, QUE POSSUI A FINALIDADE DE SAIR DO PROGRAMA. 
	int opc;
	bool flagParada = true;
	while (flagParada){
		
		menu();
//TESTA SE O QUE FOI DIGITADO E DO TIPO DA VARIAVEL "opc"
		while(!(cin >> opc)){
			cout << endl << "_" << endl;
			cout << endl << "Parece que voce digitou algo que nao esperavamos!" << endl;
			cout << "Tente novamente: ";
			cin.clear();
			cin.ignore(100, '\n');
		}			
		
		switch (opc){
			
//INCLUIR
			case 1: 
				Insere(vetor, tamanho, posicao);
//VERIFICANDO SE O TAMANHO FOI PREENCHIDO E, SE FOI, EXPANDE O TAMANHO TOTAL DO VETOR EM 20%
				if (posicao == tamanho)
					vetor = Expande (vetor, tamanho);
				break;
				
//EXCLUIR
			case 2: 
				int QueroExcluir;
//VERIFICANDO SE HA ALGUMA ROUPA PARA SER EXCLUIDA, UTILIZANDO DA VARIAVEL "VerifcaLista", QUE DECREMENTA TODA VEZ QUE A FUNCAO EXCLUE E CHAMADA,
//COMPARANDO COM A VARIAVEL "posicao", QUE SAO AS POSICOES OCUPADAS NO VETOR.
				if (posicao + VerificaLista > 0){
					ListaID_exclue(vetor, posicao);
					while(!(cin >> QueroExcluir)){
						cout << endl <<"Digite uma opcao valida: ";
						cin.clear();
						cin.ignore(100, '\n');
					}
					Exclue(vetor, posicao, QueroExcluir, VerificaLista);
					VerificaLista--;
				} else
					cout << "Nao ha nada para excluir!" << endl << endl;
				break;
				
//LISTAR
			case 3:
//VERIFICANDO SE HA ALGUMA PARA LISTAR SEGUINDO A LOGICA EXPLICADA ANTERIORMENTE
				if (posicao + VerificaLista > 0){
					Lista(vetor, posicao);
				} else
					cout << "A lista esta vazia!" << endl << endl;	
				break;
				
//ALTERAR
			case 4: 
				int QueroAlterar;
//VERIFICANDO SE HA ALGO PARA ALTERAR, NESTE CASI USAMOS SOMENTE A VARIAVEL "posicao", POIS A FUNCAO "Altera" 	TAMBEM ALTERA "ROUPAS" EXCLUIDAS.
				if (posicao > 0){
					ListaID_altera(vetor, posicao);
					while(!(cin >> QueroAlterar)){
						cout << endl <<"Digite uma opcao valida: ";
						cin.clear();
						cin.ignore(100, '\n');
					}
					Altera(vetor, posicao, QueroAlterar, VerificaLista);
				} else
					cout << "Nao e possivel alterar!" << endl << "E necessario ao menos 1 item para esta acao!" << endl << endl;
				break;
				
//ORDENAR
			case 5:
				int campo;
//VERIFICANDO SE HA AO MENOS DUAS ROUPAS PARA ORDENAR.
				if (posicao + VerificaLista > 1){
					MenuStruct();
					while(!(cin >> campo)){
						cout << endl <<"Digite uma opcao valida: ";
						cin.clear();
						cin.ignore(100, '\n');
					}
					SwitchStruct(vetor, posicao, campo);
					cout << endl <<"Ordenado com sucesso!" << endl << endl;
				}  else
					cout << "Nao e possivel ordenar!" << endl << "E necessario ao menos 2 itens para esta acao!" << endl << endl;
				break;
				
//SAIR
			case 6: 
				flagParada = false;
				break;
			
//CASO ERRO
			default:
				cout << endl << "_" << endl;
				cout << endl << "Parece que voce digitou algo que nao esperavamos!" << endl;
				cout << "Tente novamente." << endl << endl;
				
		}
	
	}
	
	cout << endl << "_" << endl;
	cout << endl << "Obrigado por confiar as suas roupas conosco! Volte sempre!" << endl;
	cout << "Sessao finalizada com sucesso.";
	cout << endl << "_" << endl;
	
//DESALOCANDO O VETOR
	delete [] vetor;
	
	return 0;
}
