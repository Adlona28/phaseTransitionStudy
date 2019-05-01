#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
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
    // find root and make root as parent of i (path compression) 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
} 
  
// A function that does union of two sets of x and y 
// (uses union by rank) 
//https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
void Union(struct subset subsets[], int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree 
    // (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
  
    // If ranks are same, then make one as root and increment 
    // its rank by one 
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
}


bool percolar(float prob) {
	//q=probabilidad de abrir un nodo
	q=prob;
	q=1-q; //1-q de cerrarlo

	int N=1000; //tiene que ser suficientemente larga para que de el valor del pdf

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

   	bool percola=false;


   	for(int i=N;i<(N*N)-N;++i){
   		if(find(subsets,V-1)==find(subsets,V-2)){
   			cout << "Percola para " << 1-q << endl;
   			percola=true;
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


   	if(!percola) cout << "No percola para " << 1-q << endl;
   	return false;





}

int main(){
	float q = 0;
	while(q<=1){
		q+=0.1;
		if(percolar(q)){
			float qnext=q;
			q-=0.1;
			while(q<qnext){
				q+=0.01;
				if(percolar(q)){
					float qnext2=q;
					q-=0.01;
					while(q<qnext2){
						q+=0.001;
						if(percolar(q)){
							cout << "Valor de transcision de fase para percolacion " << q << endl;
							exit(0);
						}
					}
				}
			}
		}
	}
}