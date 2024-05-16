#include <iostream>
#include<cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void game(int count,string secret){
 	string user_num;
 	cin>>user_num;
 	int flag=0,secondflag=0,k=0;
 	while(k<100){
 		// error If the number of digits of the number entered by the user is different
 		if(user_num.size()!=count){
 			cout<<"E1";
 			break;
 		}
 		// error if the user enters anything other than a number
 		else if(user_num.find_first_not_of("0123456789")!=string::npos){
 			cout<<"E2";
 			break;

 		}
 		//if the words are the same it ends the game
 		if(secret==user_num){
 			cout<<"FOUND "<<k+1;
 			break;
 		}
 		flag=0;
 		secondflag=0;
 		for(int a=0;a<count;a++){
 			for(int x=0;x<count;x++){
 				if(secret[a]==user_num[a]){
 					flag++;
 					break;
 				}
 				if(x!=a && secret[x]==user_num[a])
 					secondflag++;
 		}
 		}
 		cout<<flag<<"  " <<secondflag<<endl;
 		cin>>user_num;
 		k++;
 	}

}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	string random;
	int count;
	string compare=argv[1];
	// error If something other than the desired state enters
	if((compare!="-r" && compare!="-u") || (argv[2]==NULL)){
		cout<<"E0";
	}
	else if(compare=="-r"){
		count=atoi(argv[2]);
		if(count<=0 || count>9){
			cout<<"E0";
		}
		else{
		random = string(count, ' ');
		//throws random number
		random[0] = 1+rand() % 9 + '0';
		int j,i;
	for (i = 1; i < count; i++) {
        do {
            random[i] = rand() % 9 + '0';
            for (j = 0; j < i; j++) {
                if (random[i] ==random[j]) {
                    break;
                }
            }
        } while (j < i);
    }
    game(count,random);
	}
}

	else if(compare=="-u"){
		count=strlen((argv[2]));
		random=argv[2];
		int flag=0;
		int error=0;
		//checks if the numbers are the same
		for(int i=0;i<count;i++){
			for(int y=0;y<i;y++){
				if(random[i]==random[y]){
				flag++;
				if(flag==3){
					error=-1;
					break;
				}
				}
			}
		}
		//error If something other than the desired state enters
		if(random.find_first_not_of("0123456789")!=string::npos || (argv[2][0]=='0' && count!=1) || error==-1){
			cout<<"E0";
		}
		else{
		game(count,random);
	}
	}
 	 

	
	return 0;
}