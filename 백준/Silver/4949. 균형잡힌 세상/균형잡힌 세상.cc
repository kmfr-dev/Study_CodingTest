#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true)
    {
        stack<char> Stack;
        
        string Str;
        getline(cin, Str);
        
        if(Str == ".")
            break;
        
        bool IsError = false;
        
        for(int i = 0; i < Str.length(); ++i)
        {
            char CurrentChar = Str[i];
            
            if(CurrentChar == '(')
                Stack.push(Str[i]);
            
            else if(CurrentChar == ')')
            {
                if(Stack.empty())
                {
                    IsError = true;
                    break;
                }
                
                else
                {
                    if(Stack.top() == '(')
                        Stack.pop();
                    else
                    {
                        IsError = true;
                        break;
                    }
                }
            }
            
            else if(CurrentChar == '[')
                Stack.push(Str[i]);
            
            else if(CurrentChar == ']')
            {
                if(Stack.empty())
                {
                    IsError = true;
                    break;
                }
                
                else
                {
                   if(Stack.top() == '[')
                       Stack.pop();
                   else
                   {
                       IsError = true;
                       break;
                   }
                }
            }
        }
        
        if(!IsError && Stack.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
 
    return 0;
}