#include <iostream>
#include <map>


using namespace std;

int N, M;
int const MAX_N = 200010;
map <int, int> books;
map <int, int> bookIdx;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int start = 100005;
    int end = 100005;

    for ( int i = 1; i <= N; i++ ) {
        int b;
        cin >> b;
        books[end] = b;
        bookIdx[b] = end;
        end++;
    }

    for ( int j = 1; j <= M; j++ ) {
        int cmd;
        cin >> cmd;
        int b;
        if ( cmd == 1 ) {
            cin >> b;
            start--;
            books[start] = b;
            bookIdx[b] = start;
        } else if ( cmd == 2 ) {
            cin >> b;
            end++;
            books[end] = b;
            bookIdx[b] = end;
        } else if ( cmd == 3 ) {
            cin >> b;
            books[bookIdx[b]]  = 0;
        } else if ( cmd == 4 ) {
            cin >> b;
            books[bookIdx[b]]  = 0;
            start--;
            books[start] = b;
            bookIdx[b] = start;

        }
    }

    // cout << start << '\n';
    // cout << end << '\n';

    for ( int i = start; i <= end; i++ ) {
        if ( books[i] != 0 ) {
            cout << books[i] << '\n';
        }
    }

    return 0;
}
