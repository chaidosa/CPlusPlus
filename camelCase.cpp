#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getString(char x)
{
    
    string s(1, x);
 
    return s;  
}

string convert_string(char comb_split, char MVC, string s){
    string result="";
   if(comb_split == 'S'){
       switch (MVC) {
       case 'M':
            result = "";
            for(int i = 0; i < s.length(); ++i){
                if(s[i] == '(' || s[i]==')')
                    break;
                else if(isupper(s[i]))
                {
                    result+=" ";
                    result+=getString((char)tolower(s[i]));
                    
                }
                
                else {
                    result+=getString(s[i]);
                }
            }
            break;
        case 'V':
            result = "";
            for(int i = 0; i < s.length(); ++i){
                if(isupper(s[i]))
                {
                    result+=" ";
                    result+=getString((char)tolower(s[i]));
                }                
                else {
                    result+=getString(s[i]);
                }
            }
            break;
        case 'C':
            result = "";
            result+=getString(tolower(s[0]));
            for(int i = 1; i < s.length(); ++i){
                if(isupper(s[i]))
                {
                    result+=" ";
                    result+=getString((char) tolower(s[i]));
                }                
                else {
                    result+=getString(s[i]);
                }
            }
            break;            
       }
   }
   else {
       switch (MVC) {
       case 'M':
            result = "";
            result+=getString((char)tolower(s[0]));
            for(int i=1; i<s.length();){
                char ch = s[i];
                if(isspace(ch)){
                    i++;
                    result += getString(toupper(s[i]));
                    i++;
                }
                else{
                    result+=getString(s[i]);
                    i++;
                }          
            }
            
            result +="()";
            break;
        case 'V':
            result = "";
            result+=getString(tolower(s[0]));
            for(int i=1; i<s.length();){
                char ch = s[i];
                if(isspace(ch)){
                    ++i;
                    result+=getString(toupper(s[i]));
                    i++;
                }
                else{
                    result+=getString(tolower(s[i]));
                    i++;
                }          
            }
            break;
        case 'C':
            result = "";
            result+=getString(toupper(s[0]));
            for(int i = 1; i < s.length();){
                char ch = s[i];
                if(isspace(ch)){
                    ++i;
                    result+=getString(toupper(s[i]));
                    i++;
                }
                else{
                    result+=getString(s[i]);
                    i++;
                }
            }
            break;    
       }
       
   } 
   
 return result;   
    
}

int main() {
    string data;
    vector<string> vec;
    while(getline(cin, data)) {
        data.erase(remove(data.begin(), data.end(), '\r'), data.end() );
        data.erase(remove(data.begin(), data.end(), '\t'), data.end() );
        data.erase(remove(data.begin(), data.end(), '\n'), data.end() );
        vec.push_back(data);
    }
    for (const auto & e : vec){ 
        char op = e[0];
        char type = e[2];
        string s = e.substr(4);
        cout << convert_string(op, type, s) << "\r\n";
    }
    return 0;
}
