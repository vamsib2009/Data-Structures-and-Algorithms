#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstring>




int main(){
    char A[]="finding";
    int H[26], i;
    memset(H, 0, sizeof(H));


    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-'a'] += 1; //increment in hash table
    }
    for (int i=0;i<26;i++){
        if(H[i]>1){
            printf("%c ",(i+97));
            printf("%d instances \n", H[i]);
        }
    }

}


/*
#include <iostream>
#include <cstring>

int main() {
    char A[] = "Finding";
    int H[52] = {0}; // initialize all elements to 0
    int i;
    
    for (i = 0; A[i] != '\0'; i++) {
        if (A[i] >= 'a' && A[i] <= 'z') { // lowercase letters
            H[A[i] - 'a']++;
        } else if (A[i] >= 'A' && A[i] <= 'Z') { // uppercase letters
            H[A[i] - 'A' + 26]++;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (H[i] > 1) {
            std::cout << static_cast<char>(i + 'a') << H[i] << std::endl;
        }
    }
    
    for (i = 26; i < 52; i++) {
        if (H[i] > 1) {
            std::cout << static_cast<char>(i - 26 + 'A') << H[i] << std::endl;
        }
    }
    
    return 0;
}
*/