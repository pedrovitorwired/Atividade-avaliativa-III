#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ordem {
private:
    int *Lista;
    int tam;

public:
    Ordem();
    ~Ordem();
    void Entrada(int n);
    void Saida(int n);
    void Bubble(int n);
    void Insertion(int n);
    void Selection(int n);
    void Intercala(int p, int q, int r);
    void Merge(int p, int r);
    int Separa(int p, int r);
    void Quick(int p, int r);
    void Aleatorio(int n);
    int MenuOrdenar();
};

Ordem::Ordem() {
    Lista = NULL;
    tam = 0;
}

Ordem::~Ordem() {
    delete[] Lista;
}

void Ordem::Entrada(int n) {
    tam = n;
    Lista = new int[tam];

    cout << "\nDigite os " << n << " valores:\n";
    for (int i = 0; i < n; i++)
        cin >> Lista[i];
}

void Ordem::Saida(int n) {
    cout << "\nVetor: ";
    for (int i = 0; i < n; i++)
        cout << Lista[i] << " ";
    cout << endl;
}

void Ordem::Bubble(int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (Lista[j] > Lista[j + 1])
                swap(Lista[j], Lista[j + 1]);
}

void Ordem::Insertion(int n) {
    for (int i = 1; i < n; i++) {
        int key = Lista[i];
        int j = i - 1;
        while (j >= 0 && Lista[j] > key) {
            Lista[j + 1] = Lista[j];
            j--;
        }
        Lista[j + 1] = key;
    }
}

void Ordem::Selection(int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++)
            if (Lista[j] < Lista[menor])
                menor = j;
        swap(Lista[i], Lista[menor]);
    }
}

void Ordem::Intercala(int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = Lista[p + i];
    for (int j = 0; j < n2; j++) R[j] = Lista[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            Lista[k++] = L[i++];
        else
            Lista[k++] = R[j++];
    }

    while (i < n1) Lista[k++] = L[i++];
    while (j < n2) Lista[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void Ordem::Merge(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Merge(p, q);
        Merge(q + 1, r);
        Intercala(p, q, r);
    }
}

int Ordem::Separa(int p, int r) {
    int x = Lista[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (Lista[j] <= x) {
            i++;
            swap(Lista[i], Lista[j]);
        }
    }
    swap(Lista[i + 1], Lista[r]);
    return i + 1;
}

void Ordem::Quick(int p, int r) {
    if (p < r) {
        int q = Separa(p, r);
        Quick(p, q - 1);
        Quick(q + 1, r);
    }
}

void Ordem::Aleatorio(int n) {
    tam = n;
    Lista = new int[tam];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        Lista[i] = rand() % 100;

    cout << "\nVetor gerado aleatoriamente!\n";
}

int Ordem::MenuOrdenar() {
    int Opc;
    system("cls");

    cout << "=============================================\n";
    cout << "      ESCOLHA UMA OPCAO NO MENU LISTA\n";
    cout << "=============================================\n";
    cout << "[1] INSERIR DADO NA LISTA\n";
    cout << "[2] ORDENACAO BUBBLESORT\n";
    cout << "[3] ORDENACAO INSERTIONSORT\n";
    cout << "[4] ORDENACAO SELECTIONSORT\n";
    cout << "[5] ORDENACAO MERGESORT\n";
    cout << "[6] ORDENACAO QUICKSORT\n";
    cout << "[7] SAIR DO PROGRAMA\n";
    cout << "=============================================\n";
    cout << "OPCAO ESCOLHIDA: ";

    cin >> Opc;
    return Opc;
}

int main() {
    Ordem obj;
    int opc, n;

    do {
        opc = obj.MenuOrdenar();
        switch (opc) {
        case 1:
            cout << "\nQuantos valores deseja inserir? ";
            cin >> n;
            obj.Entrada(n);
            break;

        case 2:
            obj.Bubble(n);
            obj.Saida(n);
            break;

        case 3:
            obj.Insertion(n);
            obj.Saida(n);
            break;

        case 4:
            obj.Selection(n);
            obj.Saida(n);
            break;

        case 5:
            obj.Merge(0, n - 1);
            obj.Saida(n);
            break;

        case 6:
            obj.Quick(0, n - 1);
            obj.Saida(n);
            break;

        case 7:
            cout << "\nSaindo...\n";
            break;

        default:
            cout << "\nOpcao invalida!\n";
        }

        system("pause");
    } while (opc != 7);

    return 0;
}