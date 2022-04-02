#include <iostream>;
#include <string>;
using namespace std;
void negation(string mas[],int num,string ch){
  if (ch=="1") mas[num]="0"; else mas[num]="1";
}

void disjuction(int num,string ch1,string ch2,string mas[]){
   if (ch1=="1" || ch2=="1") mas[num]="1"; else mas[num]="0";
}

void move(int num,string mas[],int kol,int sv){
  int i;
   for(i=num;i<kol-sv;i++)
    mas[i]=mas[i+sv];
}

void conjuction(int num,string ch1,string ch2,string mas[]){
  if (ch1=="0" || ch2=="0") mas[num]="0"; else mas[num]="1";
}
int main(){
  int dl,kol,s,num,i,k,l,j,sv;
  string form,ch,itog[100],mas[100],zam[100],ch1,ch2;
 cout<<"Write a formula"<<endl;
 cout<<"^(negation);*(conjuction);+(disjuction)"<<endl;
 cin>>form;
 dl=form.size();
 cout<<"Write values of variables"<<endl;
 s=0;k=0;
 for (i=0;i<dl;i++){
    if (form[i]!='^' && form[i]!='*'  && form[i]!='+' && form[i]!='(' && form[i]!=')'){
	    cin>>itog[k];
	    k++;
	}
	else {
	    itog[k]=form[i];
	    k++;
	}
 }
 kol=0;s=0;
 
 for (i=0;i<k;i++){
	if (itog[i]!="^" && itog[i]!="*" && itog[i]!="+" && itog[i]!="(" && itog[i]!=")"){
        mas[kol]=itog[i];
        kol++;
        if (i!=0 && itog[i-1]=="^"){mas[kol]=itog[i-1];kol++;s--;zam[s]="";}
   }
	    else {if (itog[i]=="+" && zam[s-1]=="*")
		{
	        zam[s-1]="+";mas[kol]="*";kol++;	
		} else{
		    if (itog[i]!=")") {zam[s]=itog[i];s++;} else{
    	    s--;
		   	while(true){
		   	    mas[kol]=zam[s];
				zam[s]="";
				s--;
				kol++;  	
			    if (zam[s]=="(") break;
			 }
			if (zam[s]=="(" && zam[s-1]=="^" && s-1>=0)
			{
				zam[s]="";
				s--;
				mas[kol]=zam[s];
				kol++;
				zam[s]="";
			}
		}
	   }
	  }
  }
		    
 for(i=s-1;i>=0;i--){
    mas[kol]=zam[i];
    kol++;
 }
 for(i=0;i<kol;i++)
    cout<<mas[i];
 for(i=0;i<kol;i++){
    if (mas[i]=="^")
	{   
	    num=i-1;
	    ch=mas[i-1];
	    negation(mas,num,ch);
	    num=i;
	    sv=1;
	    move(num,mas,kol,sv);
	    kol--;
	    i--;
	    cout<<endl;
	    for(j=0;j<kol;j++)	 cout<<mas[j];
	}
    if (mas[i]=="*")
    {
    	num=i-2;
    	ch1=mas[i-1];
	    ch2=mas[i-2];
	    conjuction(num,ch1,ch2,mas);
	    sv=2;
	    num=i-1;
	    move(num,mas,kol,sv);
	    kol=kol-2;
	    i=i-2;
	    cout<<endl;
	    for(j=0;j<kol;j++)	 cout<<mas[j];
	}
    if (mas[i]=="+")
	{
        num=i-2;
        ch1=mas[i-1];
	    ch2=mas[i-2];
	    disjuction(num,ch1,ch2,mas);
	    sv=2;
	    num=i-1;
	    move(num,mas,kol,sv);
	    kol=kol-2;
	    i=i-2;
	    cout<<endl;
	    for(j=0;j<kol;j++)	 cout<<mas[j];
    }
 }
}

