#include <iostream>
#include <cstdio>
using namespace std;
const static int N = 7;


bool explore(int* sol, int gap, int len);
void explore_all(int* sol, int gap, int len);
bool explore1(int* sol, int gap, int len);

void print(int* sol, int N){
    if(sol == nullptr){
        cout << "Not exist a langford pair.\n";
        return;
    }

    printf("[ ");
    for(int i = 0; i < N; ++i){
        printf("%d ", sol[i]);
    }
    printf("]\n");
}

int* exist_langford(int N){
    int* langford = new int[2*N];
    if(explore(langford, N, 2*N)) return langford;
    return nullptr;
}

void get_all_langford(int N){
    int* langford = new int[2*N];

    explore_all(langford, N, 2*N);
}


bool explore(int* sol, int gap, int len){
    if(gap == 0){
        cout <<"Yes!\n";
        return true;
    }
    for(int i = len - 1; i - gap > 0 ; i--) {
        if(sol[i] == 0 && sol[i - gap - 1] == 0){
            sol[i] = gap;
            sol[i - gap - 1] = gap;
            if(explore(sol, gap - 1, len)) return true;
            else{
                sol[i] = 0;
                sol[i - gap - 1] = 0;
            }
        }
    }
    return false;
}

void explore_all(int* sol, int gap, int len){
    if(gap == 0){
        print(sol, 2*N);
        return;
    }
    for(int i = len - 1; i - gap > 0 ; i--) {
        if(sol[i] == 0 && sol[i - gap - 1] == 0){
            sol[i] = gap;
            sol[i - gap - 1] = gap;
            explore_all(sol, gap - 1, len); //return true;
            sol[i] = 0;
            sol[i - gap - 1] = 0;
            // if(gap - 1 == 0) return;
        }
    }
    return;
}

int *exist_langford1(int N){
    int * sol = new int[2*N];
    if(explore1(sol, 1, 2*N)) return sol;
    return nullptr;

}

bool explore1(int *a, int gap, int len){

    // printf("len=%d, gap=%d\n", len, gap);

    if(gap == len/2 + 1){
        cout << "gap = " << gap << endl;
        return true;
    }
    for(int i = 0; i < len - gap - 1; ++i){
        if(a[i] == 0 && a[i + gap + 1] == 0){
            a[i] = a[i + gap + 1] = gap;
            if(explore1(a, gap + 1, len)) return true;
            else{
                a[i] = 0;
                a[i + gap + 1] = 0;
            }
        }
    }
    return false;
}



int main(){

    // exist_langford(N);
    get_all_langford(N);
    // int *sol = exist_langford(N);
    // print(sol, 2*N);

    // int *sol1 = exist_langford1(N);
    // print(sol1, 2*N);

    return 0;
}

