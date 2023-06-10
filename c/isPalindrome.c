#include<stdio.h>
#include<stdbool.h>

bool ispalindrom(int x){
if (x < 0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}

int main(){
   int num;
   printf("Enter a number:");
   scanf("%d",&num);

   if (ispalindrom(num))
   {
    printf("%d is palindrom",num);
   }
   else
   {
    printf("%d is not palindrom",num);
   }
}
   /*
   int n,r,sum=0,temp;
    printf("Enter the number ");
    scanf("%d",&n);
    temp=n;
    while (n>0)
    {
        r=n%10;
        sum=(sum*10)+r;
        n=n/10;

    }
    if (temp==sum)
    printf("this is palindrome");
    else
    printf("this is not palindrome");

    return 0;
    */
