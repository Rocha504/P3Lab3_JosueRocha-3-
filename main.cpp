#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int menu(){
	
	int op;
	cout<<"          MENU            "<<endl;
	cout<<"1-Descomprimir una cadena"<<endl;
	cout<<"2-Crear Matriz con obstaculos"<<endl;
	cout<<"3-Hacer un recorrido"<<endl;
	cout<<"4-SALIR"<<endl<<endl;
	cout<<"Porfavor ingrese una opcion: ";
	cin>>op;
	
	return op;
}
char * descomprimir(char * arreglo,int size){
	char * descomprimido;
	int num,acum=0;
	char caracter;
	for(int i=0;i<size;i++){
		if(i%2==0){
			num = arreglo[i] - '0';
		}	 
		i++;
		if(i%2!==0){
			caracter = arreglo[i];
		}
		int aux=acum;	
		for(int x=0;x<num;x++){
			descomprimido[aux]=caracter;	 
			aux++;	
		} 
		acum=acum+num;			
}
	cout<<"[";
	for(int y=0;y<acum;y++){
		cout<<descomprimido[y]<<",";
	}
	cout<<"]"<<endl;
	
	return descomprimido;

}

int main(int argc, char** argv) {
	
	int op=0;
	
	while (op!= 4){
    	op=menu();
    	switch(op){
    		case 1:{
    			char* arreglo;
				int size;
				char entry;
				cout<<"Ingrese el size de la cadena"<<endl;
				cin>>size;	
				arreglo=new char[size];			
				cout<<"A continuacion debera de llenar el arreglo con los Caracteres siguientes: "<<endl;
				cout<<"D-Down"<<endl;
				cout<<"U-Up"<<endl;
				cout<<"L-Left"<<endl;
				cout<<"R-Right"<<endl;
				for(int i=0;i<size;i++){
					cout<<"Ingrese un numero"<<endl;
					cin>>entry;
					if(isdigit(entry)){
						arreglo[i]=entry;
					}
					else{
						cout<<"Ingrese un numero"<<endl;
						cin>>entry;	
					}
					i++;
					cout<<"Ingrese uno de los caracteres permitidos"<<endl;
					cin>>entry;
					if(entry=='D'||entry=='U'||entry=='L'||entry=='R'){
						arreglo[i]=entry;
					}
					else{
						cout<<"caracter invalido vuelva a ingresar uno valido (D,U,L,R)"<<endl;
						cin>>entry;
					}
				}
				descomprimir(arreglo,size);	
				delete [] arreglo;	
			}
			break;
    			
		}
	 
	
	}
	
		return 0;
	
	
	
 
 
 
	
	
	
	
}