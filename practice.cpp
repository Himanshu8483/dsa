// #include <iostream>
// #include<map>
// using namespace std;
// bool panagram(string &s){
//     map<char, bool>alpha;
//     // for(char ch:s)
//     for(int i=0; i<s.length(); i++){
//         char ch = s[i];
//         if(isalpha(ch)){
//             alpha[tolower(ch)] = true;
//         }
//     }
//     return (alpha.size()==26);
// }
// int main(){
//     string s= "The quick brown fox jumps over the lazy dog";
//     if(panagram(s)){
//         cout<<"It is Panagram String";
//     }
//     else{
//         cout<<"It is not Panagram String";
//     }
// }
// #include <iostream>
// #include<map>
// using namespace std;
// bool panagram(string &s){
//     map<char, bool>alpha;
//     // for(char ch:s)
//     for(int i=0; i<s.length(); i++){
//         char ch = s[i];
//        if(ch>='A' && ch<='Z'){
//         ch = ch+ ('a'-'A');
//        }
//        if(ch>='a' && ch<='z'){
//         alpha[ch]=true;
//        }
//     }
//     return (alpha.size()==26);
// }
// int main(){
//     string s= "The quick brown fox jumps over the lazy dog";
//     if(panagram(s)){
//         cout<<"It is Panagram String";
//     }
//     else{
//         cout<<"It is not Panagram String";
//     }
// }