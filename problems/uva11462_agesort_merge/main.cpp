#include <cstdio>
#include <cstring>

int cnt[100];

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n != 0){
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++){
            int age;
            scanf("%d", &age);
            cnt[age]++;
        }

        bool first = true;
        for(int age = 1; age <= 99; age++){
            for(int j = 0; j < cnt[age]; j++){
                if(!first) putchar(' ');
                printf("%d", age);
                first = false;
            }
        }
        putchar('\n');
    }
    return 0;
}
