/*************************************************************************************** 
Source : https://leetcode.com/problems/fizz-buzz/description/
Author : Jing Kuo

Description:
    Write a program that outputs the string representation of numbers from 1 to n.
    But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
    For numbers which are multiples of both three and five output “FizzBuzz”.

Example:
    n = 15,

    Return:
    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]

Complexity:
    Time:O(n)
    Space:O(n)

Beats:100% (not accurate, test time too short)
***************************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char buf[11]; //[11] is from 2^31=2147483648, 10*char + '\n'
    char** re_p = (char**)malloc(sizeof(char*)*n);
    int i = 0;
    for(i=0;i<n;i++)
    {
        if(((i+1)%3==0)&&((i+1)%5==0))
        {
            re_p[i]=malloc(sizeof("FizzBuzz"));  //if Q is not requiring malloc, it may using  re_p[i] = "FizzBuzz"
            memcpy(re_p[i],"FizzBuzz",sizeof("FizzBuzz"));
        }else if((i+1)%3==0){
            re_p[i]=malloc(sizeof("Fizz"));
            memcpy(re_p[i],"Fizz",sizeof("Fizz"));
        }else if((i+1)%5==0){
            re_p[i]=malloc(sizeof("Buzz"));
            memcpy(re_p[i],"Buzz",sizeof("Buzz"));
        }else{
            sprintf(buf,"%d",i+1);
            re_p[i]=malloc(sizeof(buf));
            memcpy(re_p[i],buf,sizeof(buf));
        }
    }

    return re_p;
}