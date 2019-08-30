#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int N,M;
struct book{
	int id;
	string title,author,publisher,year;
	vector<string> keywords;
	bool operator < (const book &other) const{
		return id<other.id;
	}
}; 
book B[10007];
void query(char c,string s){
	bool found = false;
	if(c=='1'){
		for(int i=0;i<N;i++){
			if(B[i].title==s){
				printf("%07d\n",B[i].id);
				found = true;
			}
		}
	}
	else if(c=='2'){
		for(int i=0;i<N;i++){
			if(B[i].author==s){
				printf("%07d\n",B[i].id);
				found = true;
			}
		}
	}
	else if(c=='3'){
		for(int i=0;i<N;i++){
			for(int j=0;j<B[i].keywords.size();j++){
				if(B[i].keywords[j]==s){
					printf("%07d\n",B[i].id);
					found = true;
					break;
				}
			}
		}
	}
	else if(c=='4'){
		for(int i=0;i<N;i++){
			if(B[i].publisher==s){
				printf("%07d\n",B[i].id);
				found = true;
			}
		}
	}
	else if(c=='5'){
		for(int i=0;i<N;i++){
			if(B[i].year==s){
				printf("%07d\n",B[i].id);
				found = true;
			}
		}
	}
	if(!found) cout<<"Not Found"<<endl;
}
int main(void){
	cin>>N;
	string s;
	for(int i=0;i<N;i++){
		cin>>B[i].id;getchar();
		getline(cin,s);
		B[i].title=s;
		getline(cin,s);
		B[i].author=s;
		getline(cin,s);
		string word="";
		for(int j=0;j<s.size();j++){
			if(s[j]!=' '){
				word+=s[j];
			}
			else if(s[j]==' '&&!word.empty()){
				B[i].keywords.push_back(word);
				word = "";				
			}
		}
		if(!word.empty()) B[i].keywords.push_back(word);
		getline(cin,s);
		B[i].publisher=s;
		getline(cin,s);
		B[i].year=s;
	}
	sort(B,B+N);
	cin>>M;getchar();
	char c;
	while(M--){
		cin>>c;cin.get();cin.get(); 
		getline(cin,s);
		cout<<c<<": "<<s<<endl;
		query(c,s);
	}
	return 0;
} 
