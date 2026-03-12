#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    list<int> lst;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        lst.push_back(x);
    }

    list<int>::iterator virus = lst.begin();

    for(int j = 0; j < M; j++){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            virus = lst.begin();

        } else if(cmd == 2){
            ++virus;
            if(virus == lst.end()) virus = lst.begin();

        } else if(cmd == 3){
            int x; cin >> x;
            lst.insert(virus, x);


        } else {
            int x; cin >> x;
            list<int>::iterator after = virus;
            ++after;
            lst.insert(after, x);
        }
    }

    for(int v : lst)
        cout << v << '\n';

    return 0;
}
