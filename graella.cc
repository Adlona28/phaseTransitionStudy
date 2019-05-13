#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;



//info Union-Find
struct subset 
{ 
    int parent;
    int rank;
    pair<int,int> posGraella; //posicion que ocupa
    bool abierto;
}; 

float q;

bool seBorra(){
    int prob = (int) (q*1000);
    return (rand()%1000)<prob;
}

int find(struct subset subsets[], int i) 
{ 
    // encuentra la raíz y hazla padre de i (path compression)
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
} 
  
// Una función que une dos sets x y y
// por union by rank
void Union(struct subset subsets[], int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    //Junta el rango del arbol pequeño debajo de la raiz del arbol grande
    //Union by rank
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 

    //Si los rangos son iguales, entonces marca uno como raíz e incremeta su rango por uno
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
}


bool percolarVertices(float prob,int N) {
	//q=probabilidad de abrir un nodo
	q=prob;
	q=1-q; //1-q de cerrarlo

	//int N=1000; //tiene que ser suficientemente larga para que de el valor del pdf

	 // Allocate memory for creating V sets
	int V=N*N+2;
    struct subset *subsets = (struct subset*) malloc(V* sizeof(struct subset) );

    int k = 0;

	for(int i=0; i<N;++i){
		for(int j=0;j<N;++j){
    		//inicialización estructura subsets de Union-Find
    		subsets[k].parent = k;
    		subsets[k].rank = 0;
    		subsets[k].posGraella=make_pair(i,j);
    		subsets[k].abierto=false; //al principio todos los nodos cerrados

    		++k;
		}
	}


   	//establezco un top y un bottom virtuales
   	subsets[V-1].parent=V-1;  //top
   	subsets[V-1].rank=0;
   	subsets[V-1].abierto=true;

   	subsets[V-2].parent=V-2; //bottom
   	subsets[V-2].rank=0;
   	subsets[V-2].abierto=true;

   	int aux=N*N;
   	for(int i=0;i<N;++i){//i recorre primera fila
   		--aux; //recorre ultima fila
   		if(!seBorra()){
   			Union(subsets,i,V-1);//top
   			subsets[i].abierto=true;
   		}
   		if(!seBorra()){
   			Union(subsets,aux,V-2);//bottom
   			subsets[aux].abierto=true;
   		}
   	}

   /**
   	for(int i=0;i<N*N+2;++i){
   		cout << "Representante de " << i << " " << find(subsets,i) << " " << subsets[i].abierto << endl;
   	}
   	*/

   	//comienza la percolación de lo que queda de tablero sin contar la fila inicial y la última

   	//bool percola=false;


   	for(int i=N;i<(N*N)-N;++i){
   		if(find(subsets,V-1)==find(subsets,V-2)){
   			//cout << "Percola para " << 1-q << endl;
   			//percola=true;
   			return true;
   			break;
   		}
   		if(!seBorra()){
   			//cout << "Abrimos el nodo " << i << endl;
   			subsets[i].abierto=true;

   			int auxi=subsets[i].posGraella.first;
   			int auxj=subsets[i].posGraella.second;
   			//cout << "Su posicion es " << auxi << " , " << auxj << endl;
   			//arriba
   			if(auxi-1>=0 && subsets[i-N].abierto){
   				Union(subsets,i,i-N);
   			}

   			//abajo
   			if(auxi+1<=N-1 && subsets[i+N].abierto){
   				Union(subsets,i,i+N);
   			}

   			//izquierda
   			if(auxj-1>=0 && subsets[i-1].abierto){
   				Union(subsets,i,i-1);
   			}

   			//derecha
   			if(auxj+1<=N && subsets[i+1].abierto){
   				Union(subsets,i,i+1);
   			}
   		}

   	}


   	//if(!percola) cout << "No percola para " << 1-q << endl;
   	return false;
}



bool percolarAristas(float prob, int N) {
	//q=probabilidad de abrir un nodo
	q=prob;
	q=1-q; //1-q de cerrarlo

	 // Allocate memory for creating V sets
	int V=N*N+2;
    struct subset *subsets = (struct subset*) malloc(V* sizeof(struct subset) );

    int k = 0;

	for(int i=0; i<N;++i){
		for(int j=0;j<N;++j){
    		//inicialización estructura subsets de Union-Find
    		subsets[k].parent = k;
    		subsets[k].rank = 0;
    		subsets[k].posGraella=make_pair(i,j);
    		subsets[k].abierto=true; //al principio todos los nodos estan abiertos, vamos a decidir las conexiones de aristas

    		++k;
		}
	}


   	//establezco un top y un bottom virtuales
   	subsets[V-1].parent=V-1;  //top
   	subsets[V-1].rank=0;
   	subsets[V-1].abierto=true;

   	subsets[V-2].parent=V-2; //bottom
   	subsets[V-2].rank=0;
   	subsets[V-2].abierto=true;

   	int aux=N*N;
   	for(int i=0;i<N;++i){//i recorre primera fila
   		--aux; //recorre ultima fila
   		//todos se conectan con el vértice ficticio ya que son aristas ficticias
   		Union(subsets,i,V-1);//top
   		Union(subsets,aux,V-2);//bottom
   	}

   	/**
   	for(int i=0;i<N*N+2;++i){
   		cout << "Representante de " << i << " " << find(subsets,i) << " " << subsets[i].abierto << endl;
   	}
   	*/
   	
   	

   	//comienza la percolación de lo que queda de tablero sin contar la fila inicial y la última

   	//bool percola=false;

   	//ahora recorro todos
   	for(int i=0;i<(N*N);++i){
   		if(find(subsets,V-1)==find(subsets,V-2)){
   			//cout << "Percola para " << 1-q << endl;
   			//percola=true;
   			return true;
   			break;
   		}

   			int auxi=subsets[i].posGraella.first;
   			int auxj=subsets[i].posGraella.second;
   			//cout << "Su posicion es " << auxi << " , " << auxj << endl;
   
   			//abajo posicion permitida? siempre que no se borre
   			if(auxi+1<=N-1 && !seBorra()){
   				Union(subsets,i,i+N);
   			}

   			//derecha
   			if(auxj+1<=N && !seBorra()){
   				Union(subsets,i,i+1);
   			}
 
   	}


   	//if(!percola) cout << "No percola para " << 1-q << endl;
   	return false;
}



void mainVertices(int N){
	float q = 0;
	while(q<=1){
		q+=0.1;
		if(percolarVertices(q,N)){
			float qnext=q;
			q-=0.1;
			while(q<qnext){
				q+=0.01;
				if(percolarVertices(q,N)){
					float qnext2=q;
					q-=0.01;
					while(q<qnext2){
						q+=0.001;
						if(percolarVertices(q,N)){
							cout << "Valor de transcision de fase por percolacion vertices " << q << endl;
              return;
						}
					}
				}
			}
		}
	}
}

void mainAristas(int N){
	float q = 0;
	while(q<=1){
		q+=0.1;
		if(percolarAristas(q,N)){
			float qnext=q;
			q-=0.1;
			while(q<qnext){
				q+=0.01;
				if(percolarAristas(q,N)){
					float qnext2=q;
					q-=0.01;
					while(q<qnext2){
						q+=0.001;
						if(percolarAristas(q,N)){
							cout << "Valor de transcision de fase por percolacion aristas " << q << endl;
							exit(0);
						}
					}
				}
			}
		}
	}
}

void monteCarloVertices(int N) { //tiene que ser suficientemente larga para que de el valor del pdf

	 // Allocate memory for creating V sets
	int V=N*N+2;
  struct subset *subsets = (struct subset*) malloc(V* sizeof(struct subset) );

  int k = 0;

  //inicialización estructura subsets de Union-Find
	for(int i=0; i<N;++i){
		for(int j=0;j<N;++j){
    		subsets[k].parent = k;
    		subsets[k].rank = 0;
    		subsets[k].posGraella=make_pair(i,j);
    		subsets[k].abierto=false; //al principio todos los nodos cerrados


    		++k;
		}
	}


   	//establezco un top y un bottom virtuales
   	subsets[V-1].parent=V-1;  //top
   	subsets[V-1].rank=0;
   	subsets[V-1].abierto=true;

   	subsets[V-2].parent=V-2; //bottom
   	subsets[V-2].rank=0;
   	subsets[V-2].abierto=true;

   	int abiertos = 0; 
   	for(int i=0;i<N;++i){//i recorre primera fila
   		int index = rand() % N; // pick a random index

   		Union(subsets,index,V-1);//top
   		if(!subsets[index].abierto){
   			subsets[index].abierto=true;
   			++abiertos;
   		}

   		index = rand() % N;
   		Union(subsets,(N*N)-index,V-2);//bottom
   		if(!subsets[(N*N)-index].abierto){
	   		subsets[(N*N)-index].abierto=true;
	   		++abiertos;
	   	}
   	}

   	/**
 
   	for(int i=0;i<N*N+2;++i){
   		cout << "Representante de " << i << " " << find(subsets,i) << " " << subsets[i].abierto << endl;
   	}
   	*/
   	

   	//comienza la percolación de lo que queda de tablero sin contar la fila inicial y la última

   	int size=N*N;

   	while (find(subsets,V-1)!=find(subsets,V-2)){
   			int index = rand() % size;
   			//cout << "Abrimos el nodo " << i << endl;
   			if(!subsets[index].abierto==true){
	   			subsets[index].abierto=true;
	   			++abiertos;

	   			int auxi=subsets[index].posGraella.first;
	   			int auxj=subsets[index].posGraella.second;
	   			//cout << "Su posicion es " << auxi << " , " << auxj << endl;
	   			//arriba
	   			if(auxi-1>=0 && subsets[index-N].abierto){
	   				Union(subsets,index,index-N);
	   			}

	   			//abajo
	   			if(auxi+1<=N-1 && subsets[index+N].abierto){
	   				Union(subsets,index,index+N);
	   			}

	   			//izquierda
	   			if(auxj-1>=0 && subsets[index-1].abierto){
	   				Union(subsets,index,index-1);
	   			}

	   			//derecha
	   			if(auxj+1<=N && subsets[index+1].abierto){
	   				Union(subsets,index,index+1);
	   			}

	   			
	   		}
   	}
   	float valor = (float)abiertos / (float)size;
   	cout << "La propiedad se cumple para el valor " << valor << endl;

}



/**
Experimento tiempo de ejecución y valores MonteCarlo
*/
int main(){
  for(int i = 100; i<=1500; i+=100){
    cout << "Tamaño " << i << endl;
    clock_t startTime;
    float medidas=0;
    for(int j = 0; j<4;++j){
      startTime = clock();
    	monteCarloVertices(i);
      medidas+=float(clock()-startTime)/CLOCKS_PER_SEC;
    }
    cout << "Media de tiempo de 4 ejecuciones " << medidas/4.0 << endl;
  }
}


/**
Experimento valores percolación Vertices
int main(){
  for(int i = 100; i <= 1500; i+=100){
    cout << "Tamaño " << i << endl;
    clock_t startTime;
    startTime = clock();
    mainVertices(i);
    cout << (float(clock()-startTime)/CLOCKS_PER_SEC)*1000.0 << endl;
  }
}
*/

/*
Experimento version 2 para encontrar la transcisión de fase
con un pequeño arreglo para mejorar eficiencia
int main(){

  cout << fixed;
  cout << setprecision(3);

  float aux = 0;
  while(aux<0.500){
    cout << aux << " " << "0.000" << endl;
    aux+=0.001;
  }
  int si = 0;
  float i = 0.500;
  while(i<0.650){
    for(int j=0; j<100;++j){
      if(percolarAristas(i,100)) ++si;
    }
    cout << float(i) << " " << float(si)/100.0 << endl;
    i+=0.001;
    si=0;
  }

  aux=0.651;
  while(aux<1){
     cout << aux << " " << "1.000" << endl;
     aux+=0.001;
  }
}
*/


/**
Sources
//https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
*/