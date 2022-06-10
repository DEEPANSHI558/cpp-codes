#include<bits/stdc++.h>
using namespace std;
bool isVerticalPossible(char a[11][11],string word,int row,int col){
    if(row+word.length()-1<10) return false;
    for(int i=row,j=0;i<word.length();i++,j++){
        if(a[i][col]=='+'||(a[i][col]!='-'&&a[i][col]!=word[j])) 
        return false;
    }
    return true;
}
void fillVertical(char a[11][11], string word, int row, int col){
    for(int i=row,j=0;i<word.length();i++,j++){
        a[i][col]=word[j];
    }
}
void removeVertical(char a[11][11], string word, int row, int col){
    for(int i=row;i<word.length();i++){
        if((col+1<10&&a[i][col+1]!='-'&&a[i][col+1]!='+')||(col-1>=0&&a[i][col-1]!='-'&&a[i][col-1]!='+')){
            continue;
        }
        a[i][col]='-';
    }
}
void fillHorizontal(char a[11][11], string word, int row, int col){
    for(int i=col,j=0;i<word.length();i++,j++){
        a[row][i]=word[j];
    }
}
void removeHorizontal(char a[11][11], string word, int row, int col){
    for(int i=col;i<word.length();i++){
       
        a[row][i]='-';
    }
}
bool isHorizontalPossible(char a[11][11],string word,int row,int col){
    if((col+word.length()-1)<10) return false;
    for(int i=col,j=0;i<col+word.length();i++,j++){
        if(a[row][i]=='+'||(a[row][i]!='-'&&a[row][i]!=word[j])){
           return false;
        } 
    }
    return true;
}
bool crossword(char a[11][11],vector<string> words, int index){
    if(index==words.size()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]=='-'||a[i][j]==words[index][0])
            {
                if(isVerticalPossible(a,words[index],i,j))
                {
                    fillVertical(a,words[index],i,j);
                    if(crossword(a,words,index+1))
                     return true;
                    removeVertical(a,words[index],i,j);
                    
                }      
                if(isHorizontalPossible(a,words[index],i,j))
                {
                    fillHorizontal(a,words[index],i,j);
                    if(crossword(a,words,index+1)) 
                    return true;
                    removeHorizontal(a,words[index],i,j);

                }
            }
        }
    }
	return false;
}

int main(){
    char a[11][11];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>a[i][j];
        }
    }
    string s;
    cin>>s;
    vector<string> v;
    string word="";
    for(int i=0;i<s.length();i++){
        if(s[i]==';'){
            v.push_back(word);
            word="";
            continue;
        }
        word+=s[i];
    }
    crossword(a,v,0);
    return 0;
}