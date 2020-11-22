#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
using namespace std;
struct A {
    bool operator <(const A& o) const {
        int i=0;
        if (keyWord != o.keyWord) return keyWord > o.keyWord;
        else {
            i = 0;
            while (word[i] == o.word[i]) {
                i++;
            }
            return word[i] < o.word[i];
        }
    }
    char word[1000];
    int keyWord=0;
};
A a[10000];
void findKeyWord(char* ptr,int n) {
    int i, j, k;
    for (i = 0;i < n;i++) {
        for (j = 0;j < strlen(a[i].word);j++) {
             if (tolower(a[i].word[j]) == tolower (ptr[0])) {
                  for (k = j;k < strlen(ptr)+ j;k++) {
                      if (tolower(a[i].word[k]) != tolower(ptr[k-j])) {
                           break;
                      }
                      if (k == strlen(ptr) - 1 + j) {
                           a[i].keyWord++;
                      }
                  }
             }
        }
    }
}
int main()
{
    int n=0,i=0;
    char key[10];
    scanf("%d", &n);
    for (i = 0;i < n;i++) {
        scanf(" %s", a[i].word);
    }
    printf("Input KeyWord : ");
    scanf(" %s", key);
    findKeyWord(key,n);
    sort(a, a + n);
    for (i = 0;i < n;i++) {
        printf("%s %d\n", a[i].word, a[i].keyWord);
    }
    return 0;
}
