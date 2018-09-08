#include <iostream>
#include "solver.hpp"
using namespace std;
void menu() {
      system("clear");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      //char* str="7/4*((a+b)^4*a)+3";
}


int main(int argc, char const *argv[]) {
    menu();
	Node** test = new Node*[3];
	test[0] = new NodeTree<Character>('x');
	test[1] = new NodeTree<Integer>(4);
	test[0]->right = new NodeTree<Integer>(99);
	test[0]->printSelf();
	Solver m("lkasldj");
    cout << "\nPress enter to continue ..."; 
    cin.get(); 
    return EXIT_SUCCESS;
}

