////////////////////////////////////////////
/// /////////abir/////17.02.04.106//////////
////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

char inputString[100];
char arr[50];
int top=-1;
char outputString[100];

///for char
void push(char ch){
    if(top<50){
        top++;
        arr[top]=ch;
    }
}
///for char
char pop(){
    char ch;
    if(top!=-1){
        ch= arr[top];
        top--;
        return ch;
    }
}
///for char
char topp(){
    char ch;
    if(top!=-1){
        ch =arr[top];
        return ch;
    }
}
int prec(char ch){
    if(ch=='+'||ch=='-')
        return 1;
        else if(ch=='*'||ch=='/')
            return 2;
            else return 0;
}
///
void postfixNotation(char* inputString){
    int n= strlen(inputString);
    char temporary;
    int j=0;
    for(int i=0; i<n;i++){
        ///opening_parenthesis
        if(inputString[i]=='(')
            push(inputString[i]);
        ///operand
        else if(inputString[i] >= '0' && inputString[i] <= '9'){
            outputString[j]=inputString[i];
            j++;
        }
        ///operator
        else if(inputString[i]=='+'||inputString[i]=='-'||
                inputString[i]=='*'||inputString[i]=='/'){
                outputString[j]=',';
                j++;
                while (topp()!='#'&&prec(inputString[i])<=prec(topp())){
                    outputString[j]=pop();
                    j++;
                    outputString[j]=',';
                    j++;
                }
                push(inputString[i]);

        }
        ///closing_parenthesis
        else if(inputString[i]==')'){
            while(topp()!='#'&&topp()!='('){
                outputString[j]=',';
                j++;
                outputString[j]=pop();
                j++;
                }
            if(topp() == '(') pop();
        }
    }
    ///remaining_in_stack
    while(topp()!='#'){
        outputString[j]=',';
        j++;
        outputString[j]=pop();
        j++;
    }
    outputString[j]='\0';
}
/// //////////////////////////////////////////////
bool flag=true;
double arrDouble[50];
int topDouble=-1;

///for double
void pushDouble(double value){
    if(topDouble<50){
        topDouble++;
        arrDouble[topDouble]=value;
    }
}
///for double
double popDouble(){
    double value;
    if(topDouble!=-1){
        value= arrDouble[topDouble];
        topDouble--;
        return value;
    }
}
///
void postfixEvaluation(char* input){
    int n= strlen(input);
    int j=0;
    double value1, value2,value3,answer;
    char theOperator;
    char buffer[20];
    for(int i=0;i<n;i++){
            if(input[i]=='+'||input[i]=='-'||
               input[i]=='*'||input[i]=='/'){
                flag=false;
                theOperator =input[i];
                value3=popDouble();
                value2=popDouble();
                switch(theOperator){
                case '+':
                answer=value2+value3;
                pushDouble(answer);
                break;

                case '-':
                answer=value2-value3;
                pushDouble(answer);
                break;

                case '*':
                answer=value2*value3;
                pushDouble(answer);
                break;

                case '/':
                answer=value2/value3;
                pushDouble(answer);
                break;
                }
            }
            else if(input[i]==','){
                    if(flag){
                        buffer[j]='\0';
                        value1 = atof(buffer);
                        pushDouble(value1);
                        cout<<value1<<endl;
                    j=0;
                    }
            }
            else {
                flag=true;
                buffer[j]=input[i];
                j++;
            }
    }
    cout<<endl;
    cout<<popDouble()<<endl;
}
///
int main (){
    char ar [100];
    push('#');
    gets(ar);
    postfixNotation(ar);
    cout<<outputString<<endl;
    postfixEvaluation(outputString);
    return 0;
}

