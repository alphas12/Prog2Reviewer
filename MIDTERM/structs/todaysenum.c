#include <stdio.h>

int main(){

    enum week_days{sunday , monday = 3, tuesday, wednesday, thursday, friday};

    enum week_days today; //enums can only hold one value 
    today = tuesday;
    printf("%d", today);


    return 0;
}