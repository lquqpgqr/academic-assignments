
#include<bits/stdc++.h>
using namespace std;


#define MAX_INPUT 1000000
#define KW_COUNT 12
char main_buffer[MAX_INPUT];

char total_map[1000][100];
char token_name[1000][100];
char token_type[1000][100];
int token_count=0;
int token_in_line[1000];


char kw[KW_COUNT][100] =
{
    "int","return","if","char",
    "double","else","float","for",
    "void","int","long","return"
};

char datatype[KW_COUNT][100] =
{
    "int","char",
    "double","float",
    "long"
};



///hash func begin
#define NAME_SIZE 20
#define TABLE_SIZE 30

typedef struct{
    char name[NAME_SIZE];
    char id_type[NAME_SIZE];
    char data_type[NAME_SIZE];
    char scope[NAME_SIZE];
    char value[NAME_SIZE];
}symbol_t;

symbol_t hash_table[TABLE_SIZE];

unsigned int _hash(char name[],char scope[]){
    char ns[20];
    strcpy(ns,name);
    strcat(ns,scope);
    //cout<<ns<<endl;
    int length=strlen(ns);
    unsigned hash_value=0;
    for(int i=0;i<length;i++){
        hash_value = hash_value+ns[i];
        hash_value = hash_value*ns[i]%TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        strcpy(hash_table[i].name,"~");
        strcpy(hash_table[i].id_type,"~");
        strcpy(hash_table[i].data_type,"~");
        strcpy(hash_table[i].scope,"~");
        strcpy(hash_table[i].value,"~");
    }
}

void hash_table_print(){
    cout<<"Symbol Table"<<endl;
    for(int i=0; i<TABLE_SIZE;i++){
        if(strcmp(hash_table[i].name,"~")!=0){
            
                cout<<" "<<i<<"\t\t"<<hash_table[i].name<<"\t\t";
                cout<<hash_table[i].id_type<<"\t\t";
                cout<<hash_table[i].data_type<<"\t\t";
                cout<<hash_table[i].scope<<"\t\t";
                cout<<hash_table[i].value<<endl;

            



        }
    }
}

bool hash_table_insert(char name[],char id_type[],char data_type[],char scope[],char value[]){
    //cout<<name<<" "<<scope;
    int index = _hash(name,scope);

    for(int i =0;i<TABLE_SIZE;i++){
        int _try =(i+index)%TABLE_SIZE;

        if(strcmp(hash_table[_try].name,"~")==0){

            strcpy(hash_table[_try].name,name);
            strcpy(hash_table[_try].id_type,id_type);
            strcpy(hash_table[_try].data_type,data_type);
            strcpy(hash_table[_try].scope,scope);
            strcpy(hash_table[_try].value,value);
            //cout<<hash_table[_try].name<<" "<<hash_table[_try].scope<<" "<<scope<<endl;
            return true;


        }
    }
    cout<<hash_table[index].name<<"Hash";
    return false;
}


bool hash_table_lookup(char name[],char scope[]){
    int index = _hash(name,scope);
    //cout<<"lookup: "<<name<<" "<<scope<<endl;
    for(int i=0;i<TABLE_SIZE;i++){
        int _try =(index+i)%TABLE_SIZE;
        if(strcmp(hash_table[_try].name,name)==0 &&
            strcmp(hash_table[_try].scope,scope)==0){
            //cout<<"true"<<endl;
            return true;
            }
    }
    //cout<<"false"<<endl;
    return false;

}

int hash_table_get(char name[],char scope[]){
    int index = _hash(name,scope);
    for(int i=0;i<TABLE_SIZE;i++){
        int _try =(index+i)%TABLE_SIZE;
        if(strcmp(hash_table[_try].name,name)==0 &&
            strcmp(hash_table[_try].scope,scope)==0){
                //cout<<_try<<endl;
            return _try;
            }

       }return 0;
}


bool hash_table_update(char name[],char scope[],char value[]){
    int index = _hash(name,scope);
    for(int i=0;i<TABLE_SIZE;i++){
        int _try =(index+i)%TABLE_SIZE;
        if(strcmp(hash_table[_try].name,"~")!=0 &&
        strcmp(hash_table[_try].name,name)==0 &&
        strcmp(hash_table[_try].scope,scope)==0){
            strcpy(hash_table[_try].value,value);
            return true;
            }

       }return false;

}





/// hash function end




void remove_comment(){
    
    bool single_flag=false, multi_flag=false;
    char extra_buffer[MAX_INPUT];
    int j = 0;
    for(int i = 0; i < strlen(main_buffer) ; i++ ){
        if(main_buffer[i] == '/' && main_buffer[i+1] == '*' ){
            multi_flag=true;
            while(multi_flag){
                i++;
                if(main_buffer[i] == '*' &&  main_buffer[i+1] == '/'){
                    multi_flag = false;
                    i++;
                }
            }
        }
        else if(main_buffer[i] == '/' && main_buffer[i+1] == '/'){
            single_flag=true;
            while(single_flag){
                i++;
                if(main_buffer[i] == '\n'){
                    single_flag = false;
                }
            }
        }
        else{
            extra_buffer[j] = main_buffer[i];
            j++;
        }

    }
    extra_buffer[j] = '\0';
    strcpy(main_buffer,extra_buffer);

}
///////////////////////////////////////////////////////////////////////////////////////////
bool is_op(char c){
    bool flag= false;
    if(c=='+' || c=='-' || c=='*' || c=='/'|| c == '=' || c == '!' ||c=='<'||c=='>'||c=='&') flag=true;
    else{flag=false;}
    return flag;
}

bool is_sep(char c){
    bool flag= false;
    //if(c=='\'' || c==',' || c==';') flag=true;
    if( c==',' || c==';') flag=true;
    else{flag=false;}
    return flag;
}

bool is_par(char c){
    bool flag= false;
    if(c=='(' || c==')' || c=='{'||c=='}' || c=='[' || c==']') flag=true;
    else flag=false;
    return flag;
}

bool is_num(char nbuffer[]){
    char c=nbuffer[0];
    bool flag1= false,flag2=false,flag3=false;

    if((c>='0' && c<='9') ||c=='.'){
        if(c=='.') flag2=true;
        else flag1=true;
        for(int i=1;i<strlen(nbuffer);i++){
            c=nbuffer[i];
            if(c=='.' && flag2==true){
                flag1=false;
                break;
            }else if(c=='.' && flag2==false &&flag3==false){
                flag3=true;
                flag2=true;
            }else if(c=='.' && flag2==false &&flag3==true){
                flag1=false;
                break;
            }else if(c>='0' && c<='9'){
                flag1=true;
                flag3=false;
            }else if(c=='\0'&&flag3==false){
                flag1=true;
                break;
            }else{
                flag1=false;
                break;
            }
        }
    }else flag1=false;

    return flag1;
}

bool is_kw(char nbuffer[]){
    bool flag1=false,flag2=false;

    for(int i=0;i<8;i++){
        for(int j=0;j<strlen(nbuffer);j++){
            if(kw[i][j]==nbuffer[j]){
                flag1=true;}
            else{ flag1=false; break;}
        }if(flag1==true)break;
    }
    return flag1;
}

bool is_id(char nbuffer[]){
    if (!((nbuffer[0] >= 'a' && nbuffer[0] <= 'z') || (nbuffer[0] >= 'A' && nbuffer[1] <= 'Z')|| nbuffer[0] == '_'))
        return false;

    for (int i = 1; i < strlen(nbuffer); i++) {
        if (!((nbuffer[i] >= 'a' && nbuffer[i] <= 'z') || (nbuffer[i] >= 'A' && nbuffer[i] <= 'Z') || (nbuffer[i] >= '0' && nbuffer[i] <= '9') || nbuffer[i] == '_'))
            return false;
    }

    return true;
}


///////////////////////////////////////////////////////////////////////////////////////////////


int line_no=0;
void proper_shape(){
    char extra_buffer[MAX_INPUT];
    int j = 0,buffer_length= strlen(main_buffer);
    ///
    ///adding spaces between tokens
    for(int i = 0; i < buffer_length; i++){
        if(is_sep(main_buffer[i]) || is_op(main_buffer[i]) || is_par(main_buffer[i])){
            extra_buffer[j++] = ' ';
            extra_buffer[j++] = main_buffer[i];
            extra_buffer[j++] = ' ';
        }
        else{
            extra_buffer[j++] = main_buffer[i];
        }
    }
    extra_buffer[j] = '\0';
    strcpy(main_buffer , extra_buffer);
    ///

    ///
    ///seperating lines
    char temp_line[10000],temp_line2[10000];
    j=0;
    bool flag=true;
    buffer_length= strlen(main_buffer);
    for(int i=0; i<buffer_length; i++){
        
        if(main_buffer[i]=='\n'){
            ///
            ///removing exrtra space
            int n=0;
            for(int m=0;m<j;m++){
                if(flag==true && temp_line[m]==' '){
                    continue;
                }else if(flag==false && temp_line[m]==' '){
                    temp_line2[n]=temp_line[m];
                    flag=true;
                    n++;
                }else{
                    temp_line2[n]=temp_line[m];
                    flag=false;
                    n++;
                }
            }

            ///

            ///
            ///copying single line to a 2d array
            strcpy(total_map[line_no],temp_line2);
            line_no++;
            j=0;
            memset(temp_line,'\0',10000);
            memset(temp_line2,'\0',10000);
            ///

        }else{
            temp_line[j]=main_buffer[i];
            j++;
        }
            
        
    }
    ///


}


void create_token(){
    char buffer[10000];
    memset(buffer,'\0',10000);
    for(int i=0;i<line_no;i++){
        
        int k=0;
        for(int j=0;j<strlen(total_map[i]);j++){
            if(total_map[i][j]==' '){
                buffer[k]='\0';
                if(is_kw(buffer))strcpy(token_type[token_count],"kw");
                
                else if(is_op(buffer[0]))strcpy(token_type[token_count],"op");
                else if(is_sep(buffer[0]))strcpy(token_type[token_count],"sep");
                else if(is_par(buffer[0]))strcpy(token_type[token_count],"par");

                else if(is_num(buffer))strcpy(token_type[token_count],"num");

                else if(is_id(buffer))strcpy(token_type[token_count],"id");
                

                else strcpy(token_type[i],"un");

                strcpy(token_name[token_count],buffer);
                
                token_in_line[token_count]=i;

                token_count++;
                k=0;
                memset(buffer,'\0',10000);

            }else{
                buffer[k]=total_map[i][j];
                k++;

            }
        }

    }

}

int error_line[1000];
char error_type[1000][100];

/*


*/

bool has_datatype(int pos){
    char datatypes[6][10]={"int","float","double","char","long"};
    //cout<<total_map[pos-1]<<endl;
    for(int i=0;i<6;i++){
        if(strcmp(token_name[pos],datatypes[i])==0){

             return true;
        }
    }
    return false;

}



void detect_error(){
    int ec=0, if_count=0,paran_count=0;
    bool equal_sign_flag;
    
   
    char scope[50];

    //memset(alt_token_name,-1,50);
    strcpy(scope,"global");
    char temp[20];
    for(int i=0;i<line_no;i++){
        for(int j=0;j<token_count;j++){
            
            ///tokens in a line
            if(token_in_line[j]==i){
                ///handle specific token
                if(strcmp(token_type[j],"kw")==0 ||  strcmp(token_type[j],"sep")==0){
                    ///
                    ///handle ; in for
                    if(strcmp(token_name[j],"for")==0){
                        int sem_count=0;
                        while(true){
                            if(sem_count==2) break;
                            else{
                                j++;
                                if(strcmp(token_name[j],";")==0) sem_count++;
                            }
                        }
                        continue;
                    }
                    ///
                    ///handle if else
                    else if(strcmp(token_name[j],"if")==0||strcmp(token_name[j],"else")==0){
                        if(strcmp(token_name[j],"if")==0)if_count++;
                        else {
                            if(if_count<=0){
                                error_line[ec]=i;
                                strcpy(temp,token_type[j]);
                                strcat(temp," unmatched ");
                                strcat(temp,token_name[j]);
                                strcpy(error_type[ec],temp);
                                j++;
                                ec++;
                                memset(temp,'\0',20);
                            }
                            if_count--;
                            
                        }
                    }
                    ///
                    else if(strcmp(token_type[j],token_type[j+1])==0){
                    error_line[ec]=i;
                    strcpy(temp,token_type[j]);
                    strcat(temp," Duplicate token ");
                    strcat(temp,token_name[j]);
                    strcpy(error_type[ec],temp);
                    j++;
                    ec++;
                    memset(temp,'\0',20);
                    }

                }
                /// paranthesis {} check
                else if(strcmp(token_type[j],"par")==0){
                    if(strcmp(token_name[j],"{")==0)paran_count++;
                        else if(strcmp(token_name[j],"}")==0){
                            if(paran_count<=0){
                                error_line[ec]=i;
                                strcpy(temp,token_type[j]);
                                strcat(temp," unmatched ");
                                strcat(temp,token_name[j]);
                                strcpy(error_type[ec],temp);
                                j++;
                                ec++;
                                memset(temp,'\0',20);
                            }
                            paran_count--;
                            
                        }
                }

                ///  check id
                else if(strcmp(token_type[j],"id")==0 ){
                    //check_function
                    if(strcmp(token_name[j+1],"(")==0){
                        
                        //is_being_defined
                        if(strcmp(token_type[j-1],"kw")==0){
                            if(hash_table_lookup(token_name[j],"global")==false){
                                hash_table_insert(token_name[j],"func",token_name[j-1],"global","~");
                                
                                
                                memset(scope,'\0',20);
                                strcpy(scope,token_name[j]);
                                

                            }else{
                                error_line[ec]=i;
                                strcpy(temp,token_type[j]);
                                strcat(temp," duplicate function ");
                                strcat(temp,token_name[j]);
                                strcpy(error_type[ec],temp);
                                j++;
                                ec++;
                                memset(temp,'\0',20);

                            }
                        }
                    }
                    ///variable
                    else{
                        
                        if(strcmp(token_name[j+1],"=")==0){
                            equal_sign_flag=true;
                        }
                        else {
                            equal_sign_flag=false;
                            }


                        //is_being_defined
                        //ekhane problem
                        if(has_datatype(j-1)){
                            if(hash_table_lookup(token_name[j],scope)==false){
                                if(equal_sign_flag) hash_table_insert(token_name[j],"var",token_name[j-1],scope,token_name[j+2]);
                                else  hash_table_insert(token_name[j],"var",token_name[j-1],scope,"~");
                                
                            }else{
                                error_line[ec]=i;
                                strcpy(temp,token_type[j]);
                                strcat(temp," duplicate variable ");
                                strcat(temp,token_name[j]);
                                strcpy(error_type[ec],temp);
                                j++;
                                ec++;
                                memset(temp,'\0',20);

                            }
                        }else{
                            if(hash_table_lookup(token_name[j],scope)==true){
                                if(equal_sign_flag)
                                hash_table_update(token_name[j],scope,token_name[j+2]);
                            }
                            else if(hash_table_lookup(token_name[j],"global")==true){
                                if(equal_sign_flag)
                                hash_table_update(token_name[j],scope,token_name[j+2]);
                            }
                            else{
                                error_line[ec]=i;
                                strcpy(temp,token_type[j]);
                                strcat(temp," has no defination ");
                                strcat(temp,token_name[j]);
                                strcpy(error_type[ec],temp);
                                j++;
                                ec++;
                                memset(temp,'\0',20);

                            }
                        }

                    }


                }

                
                
                
            }
            ///
            
        }

    }
    cout<<endl;
    hash_table_print();
    cout<<endl;
    cout<<"Simple Syntex Error Detection:"<<endl;
    for(int i=0;i<ec;i++){
        cout<<"line: "<<error_line[i]+1<<" "<<error_type[i]<<endl;
    }

}




int main(){
    FILE *p1;
    
    int buffer_counter=0;
    char c;
    
    p1=fopen("input.c","r");
    if (p1 == NULL) {
        printf("Error! opening file");
    }else{
        while((c = fgetc(p1)) != EOF){
            main_buffer[buffer_counter] = c;
            buffer_counter++;
        }
    }
	fclose(p1);


    cout<<"input file: "<<endl;
    cout<<main_buffer<<endl;
    remove_comment();
    
    
    cout<<"after deleting comment";
    //cout<<main_buffer<<endl;
    
    proper_shape();
    cout<<" and adding line number"<<endl;
    
    
    for(int i=0;i<=line_no;i++){
        cout<<i+1<<"\t"<<total_map[i]<<endl;
    }
    
    create_token();


    cout<<"after tokenizing: "<<endl;
    for(int i=0;i<line_no;i++){
        cout<<i+1<<"\t";
        for(int j=0;j<token_count;j++){
            if(token_in_line[j]==i){
                cout<<"["<<token_type[j]<<"]"<<"  "<<"["<<token_name[j]<<"]"<<"  ";
            }
        }cout<<endl;

    }
    
    
    
    init_hash_table();

    detect_error();

    
    

    return 0;
}