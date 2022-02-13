#include <stdio.h>
#define swap(x,y) {int temp=x; x=y; y=temp;}

int main(){
    char str[200001];
    int alpha[26], cur[26];
    int n, m; 
    char x, y;
    for(int i=0; i<26; i++) {alpha[i]=i; cur[i]=i;}
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    for(int i=0; i<m; i++){
        scanf(" %c %c", &x, &y);
        swap(alpha[cur[x-'a']], alpha[cur[y-'a']])
        swap(cur[x-'a'], cur[y-'a'])
    }
    for(int i=0; i<n; i++){
        printf("%c", alpha[str[i]-'a']+'a');
    }
    printf("\n");
    return 0;
}