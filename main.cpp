#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int prec(char);

int main() {
    stack<char>st;
    string input,output;
    cin >> input;
    st.push('s');//start
    int i=0;

    
    //cout<<input[6]<<endl;
    while (input[i]!='\0') {
        if(input[i]!='+'&&input[i]!='-'&&input[i]!='*'&&input[i]!='/'&&input[i]!='('&&input[i]!=')'){
            
            output += input[i];
        }
        else if(input[i]=='('){
                        st.push('(');
                }
        else if(input[i] == ')'){
            while (st.top()!='(') {
                    output+=st.top();
                    st.pop();
                }
            st.pop();//pop 掉'('
                
        }
        else{
            
             if(prec(input[i])> prec(st.top()) && input[i]!=')' ){    //stack內的優先順序<現在的值
               // cout << prec(input[i])<<"  " <<prec(st.top())<<endl;
                st.push(input[i]);
            }

          
            else{
                while (prec(input[i])<=prec(st.top())) {
                    output += st.top();
                    st.pop();
                }
                st.push(input[i]);
            }
        }
       /* cout << input[i];
        cout<< "  ST:";
            cout <<st.top()<< " ";
        
       cout << endl;*/
        i++;
    }
    
    while (st.top()!='s') {
        output += st.top();
        st.pop();
    }
    cout << output<<endl;


    return 0;
}

int prec(char c){
    int n;
    
    //if(c==')')
      //  n = 19;
    
    if (c=='+'||c=='-')
        n = 12;
    else if (c=='*'||c=='/')
        n = 13;
    else
        n = 0;
             
    return n;

    
}
