#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

struct BANH
{
    char ten[20];
    int HSD;
    char XX[20];
    bool CON;
};

void AN1 (struct BANH *HH1)
{

    printf ("\nthực hiện ăn bánh : %s\n", (*HH1).ten);
    (*HH1).CON = false; 
    return ;
}

int main (){

    struct BANH STORE [5] =
    {
    {"MY", 2,"VN", true },
    {"BAO", 10, "CN", true},
    {"QUY", 2, "USA",true}
    };
    

    char buffer[20];
    int n;
    scanf ("%d", &n);
   
    strcpy ((buffer), STORE[n].CON ? "còn bánh" : "hết bánh" );
    printf ("trước khi ăn,  %s\n", buffer);

    AN1 (&STORE[n]);

    strcpy ((buffer), STORE[n].CON ? "còn bánh" : "hết bánh" );
    printf ("sau khi ăn,  %s\n", buffer);

    return 0 ; 

}