#include <bits/stdc++.h>
using namespace std;

const int ROZMIAR_STOSU=1e4;
const int BLAD=INT_MAX;
class stos_dynamiczny{
    private:
        int* zawartosc;
        int indeks_szczytu;
        int rozmiar;
    public:
        void init(int rozmiar_stosu){
            indeks_szczytu=-1;
            zawartosc=new int[rozmiar_stosu];
            rozmiar=rozmiar_stosu;
        }
        void destroy(){
            indeks_szczytu=-1;
            delete [] zawartosc;
        }
        bool empty(){
            if(indeks_szczytu==-1)return true;
            return false;
        }
        bool full(){
            if(indeks_szczytu==rozmiar-1)return true;
            return false;
        }
        void push(int dokladana_liczba){
            if(full()){
                cerr<<"Brakuje miejsca na stosie, aby dodac element\n";
                return;
            }
            ++indeks_szczytu;
            zawartosc[indeks_szczytu]=dokladana_liczba;
        }
        void pop(){
            if(empty()){
                cerr<<"Nie mozna usunac elementu, poniewaz stos jest pusty\n";
                return;
            }
            --indeks_szczytu;
        }
        int top(){
            if(empty()){
                cerr<<"Nie mozna pobrac elementu, poniewaz stos jest pusty\n";
                return BLAD;
            }
            return zawartosc[indeks_szczytu];
        }
        stos_dynamiczny(int rozmiar_stosu){
            cout<<"Wywolano konstruktor 1-parametrowy\n";
            cout<<this<<"\n";
            init(rozmiar_stosu);
        }
        stos_dynamiczny(){
            cout<<"Wywolano konstruktor bezparametrowy\n";
            cout<<this<<"\n";
            init(ROZMIAR_STOSU);
        }
        ~stos_dynamiczny(){
            cout<<"Wywolano destruktor\n";
            cout<<this<<"\n";
            destroy();
        }
        stos_dynamiczny(const stos_dynamiczny& s){
            this->indeks_szczytu=s.indeks_szczytu;
            this->rozmiar=s.rozmiar;
            this->zawartosc=new int[rozmiar];
            for(int i=0;i<=indeks_szczytu;++i){
                this->zawartosc[i]=s.zawartosc[i];
            }
            cout<<"Wywolano konstruktor kopiujacy\n";
            cout<<this<<"\n";
        }
};

void f(stos_dynamiczny s, int a) {
   s.push(a);
}
int main(){
    stos_dynamiczny s;
    s.push(0);
    f(s, 1);
    f(s, 2);
    while (!s.empty()) {
        cout <<s.top();
        s.pop();
    }
    return 0;
}
