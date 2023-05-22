#define SUCCESS 1
#define PATH_INVALID 0

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


const string notfound = "nie znaleziono klucza!";

struct TreeNode{

int value;
TreeNode* parent;
TreeNode* left;
TreeNode* right;


//konstruktor przyjmuje maksymalnie dwa argumenty - przechowywana wartosc i wskaznik rodzica
//wskaznik rodzica jest opcjonalny, poniewaz korzen drzewa go nie posiada
TreeNode(int nodeValue, TreeNode* nodeParent = NULL){
    this->parent = nodeParent;
    this->value = nodeValue;
    this->left = NULL;
    this->right = NULL;
}
//wstawianie elementu
//funkcja przyjmuje wartosc liczbowa oraz sciezke
//w postaci lancucha liter 'r' oznaczajacych wezel po prawej
//oraz 'l' oznaczajacych wezel po lewej
//zwraca 1 po poprawnym wstawieniu wezla,
//0 przy wykryciu sciezki zbyt krotkiej lub zbyt dlugiej
    int insert(string path, int value){
        if(path.length()==0) return PATH_INVALID;
        if(path.length()==1){
            if(path[0] == 'l'){
                if(this->left) return PATH_INVALID;
                else{
                    this->left = new TreeNode(value, this);
                    return SUCCESS;
                }
            }
            if(path[0] == 'r'){
                if(this->right) return PATH_INVALID;
                else{
                    this->right = new TreeNode(value, this);
                    return SUCCESS;
                }
            }
        }
        else{
            if(path[0]=='l'){
                if(!this->left) return PATH_INVALID;
                else{
                    path.erase(0,1);
                    return left->insert(path, value);
                }
            }
                if(path[0]=='r'){
                    if(!this->right) return PATH_INVALID;
                    else{
                        path.erase(0,1);
                        return right->insert(path, value);
                    }
                }
                else return PATH_INVALID;
        }
    }
    //usuwanie wezla oraz calej struktury pod nim
    void purge(){
        if(this->left){
            this->left->purge();
        }
        if(this->right){
            this->right->purge();
        }
        if(this->parent){
            if(this == this->parent->left) {this->parent->left = NULL; delete this;} //operacja "delete this" jest dozwolona, gdy obiekt wywolujacy
            else {this->parent->right = NULL; delete this;} //jest utworzony poprzez "new TreeNode"

        }
    }
    //liczenie glebokosci drzewa od wezla wywolujacego
    int depth(){
        int a = 0, b = 0;
        if(this->left) a = this->left->depth();
        else a = 0;
        if(this->right) b = this->right->depth();
        else b = 0;
        int out = 0;
        if(a>b) out = a + 1;
        else if(a<b) out = b + 1;
        else if(a == b && a) out = a + 1;
        if(!a && !b) out = 1;
        return out;
    }
    //wyszukiwanie wartosci
    //funkcja zwraca sciezke wzgledem wywolujacego wezla
    string treeLookup(int key, string curPath = ""){
        if(this->value == key) return curPath;
        string toTheLeft = curPath;
        toTheLeft.push_back('l');
        string toTheRight = curPath;
        toTheRight.push_back('r');
        if(this->left && this->left->treeLookup(key, toTheLeft)!= notfound) return this->left->treeLookup(key, toTheLeft);
        if(this->right && this->right->treeLookup(key, toTheRight)!= notfound) return this->right->treeLookup(key, toTheRight);
        return notfound;
    }
    //liczenie ilosci wezlow od wezla wywolujacego
    int nodeAmount(){
        int a = 0, b = 0;
        if(this->left) a = left->nodeAmount();
        if(this->right) b = right->nodeAmount();
        return (a+b+1);
    }
};

//funcja wypisywania drzewa
void printTree(string prefix, TreeNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "|__" );

        // print the value of the node
        cout << node->value << endl;

        // enter the next tree level - left and right branch
        printTree( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printTree( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

//ta funkcja sluzy do wywolania powyzszej funkcji
void printTree(TreeNode* root)
{
    cout << "wartosc wyzsza - lewe dziecko\nwartosc nizsza - prawe dziecko\n";
    printTree("", root, false);
}

int main()
{

    TreeNode* root = new TreeNode(5);
    root->insert("l", 2);
    root->insert("r", 8);
    root->insert("ll", 3);
    root->insert("lr", 1);
    root->insert("lrl", 6);
    root->insert("lrr", 0);
    root->insert("lll", 4);
    root->insert("llr", 9);
    root->insert("rl", 1);
    root->insert("rr", 2);
    root->insert("llll", 1);

    cout << endl;
    printTree(root);
    cout << "sciezka do elementu przechowujacego 6: " << root->treeLookup(6) << endl;
    root->left->left->left->purge();
    printTree(root);
    cout << endl << "ilosc wezlow: " << root->nodeAmount();
    return 0;
}
