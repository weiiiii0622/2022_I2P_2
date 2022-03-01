#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

typedef struct _line{
    char* data;
    struct _line *next;
} Line;

Line *arr[100000+9];
Line *bck[100000+9];

void init(int n){
    for(int i=1; i<=n; i++){
        arr[i] = (Line*) malloc(sizeof(Line));
        arr[i]->next = NULL;
        bck[i] = arr[i];
    }
    return;
}

void front(int a, int b){
    if(arr[a] == bck[a]) return;
    bck[a]->next = arr[b]->next;
    arr[b]->next = arr[a]->next;
    arr[a]->next = NULL;
    if(bck[b]==arr[b])
        bck[b] = bck[a];
    bck[a] = arr[a];
    return;
}

void back(int a, int b){
    if(arr[a] == bck[a]) return;
    bck[b]->next = arr[a]->next;
    arr[a]->next = NULL;
    bck[b] = bck[a];
    bck[a] = arr[a];
    return;
}

void swap(int a, int b){
    Line *temp = arr[a]->next;
    arr[a]->next = arr[b]->next;
    arr[b]->next = temp;
    if(bck[a]==arr[a] && bck[b]==arr[b]){
        return;
    }
    else if(bck[a] == arr[a]){
        bck[a] = bck[b];
        bck[b] = arr[b];
    }
    else if(bck[b] == arr[b]){
        bck[b] = bck[a];
        bck[a] = arr[a];
    }
    else{
        temp = bck[a];
        bck[a] = bck[b];
        bck[b] = temp;
    }
    return;
}

void print(int n){
    for(int i=1; i<=n; i++){
        Line *cur=arr[i], *temp=arr[i];
        cur = cur->next;
        free(temp);
        while(cur != NULL){
            printf("%s", cur->data);
            temp = cur;
            cur = cur->next;
            free(temp->data);
            free(temp);
        }
        printf("\n");
    }
    return;
}

void test(int n){
    printf("\narr[i]:\n");
    for(int i=1; i<=n; i++){
        printf("arr[%d]=%s, next=%s\n", i, arr[i]->data, arr[i]->next==NULL?NULL:arr[i]->next->data);
    }
    printf("\nbck[i]:\n");
    for(int i=1; i<=n; i++){
        printf("bck[%d]=%s\n", i, bck[i]->data);
    }
    return;
}


int main(){
    int n, q; scanf("%d", &n);
    init(n);
    for(int i=1; i<=n; i++){
        int s; scanf("%d ", &s);
        if(s!=0){
            Line* new = (Line*) malloc(sizeof(Line));
            (new->data) = (char*) malloc(sizeof(char)*(s+1));
            new->next = NULL;
            scanf("%s\n", new->data);
            new->data[s] = '\0';
            arr[i]->next = new;
            bck[i] = arr[i]->next;
        }
    }

    scanf("%d", &q);
    int type, a, b;
    test(n);
    while(q--){
        scanf("%d %d %d", &type, &a, &b);
        
        switch(type){
            case 1:
                front(a, b);
                break;
            case 2:
                back(a, b);
                break;
            case 3:
                swap(a, b);
                break;
        }
        test(n);
    }
    print(n);
    return 0;
}