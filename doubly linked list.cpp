#include<iostream>
using namespace std;

class node{
	public:
		node*next;
		int data;
		node*previous;
		
};
node *head =NULL;

void insertatbeg(int n)
{
    node*p= new node;
	p->next= NULL;
    p->data= n;
	p->previous= NULL;
	
	if(head==NULL){
		head=p;
	}
	else{
		p->next= head;
		head->previous=p;
		head=p;
	}

}
void insertatend(int n){
	node*p= new node;
	p->next= NULL;
    p->data= n;
	p->previous= NULL;
	node*temp= head;
	while(temp->next!=NULL){
		temp=temp->next;
	} 
	p->previous=temp;
	temp->next= p;
}
void insertatanypos(int n, int pos){
	 node * p= new node;
	 p->next= NULL;
	 p->data= n;
	 p->previous= NULL;
	 
	 node*temp= head;
	 int i=1;
	 while(i<pos-1){
	 	temp=temp->next;
	 	i++;
	 }
	 if(temp->next==NULL)
	 {
	 	p->previous= temp;
	 	temp->next =p;
	 }
	 else{
	 	p->next= temp->next;
	 	p->previous= temp;
	 	temp->next->previous;
	 	temp->next=p;
	 	
	 }
}
void deleteatbeg(){
	head=head->next;
	delete(head->previous);
	head->previous= NULL;
}
void deleteatend(){
	node * temp= head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->previous->next=NULL;
	delete(temp);
}

void deleteatanypos(int pos){
	node*temp= head;
	int i= 1;
	while(i<pos)
	{temp=temp->next;
	i++;
	}
	temp->previous->next=temp->next;
	temp->next->previous=temp->previous;
	temp->next=NULL;
	temp->previous=NULL;
	delete(temp);
}
void traversal()
{
	node*temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;
		
	}
	
}
int main(){
	int val,ch, pos;

           while(1)
{
           cout<<"enter your choice:"<<endl<<"1. Insert at beginning"<<endl<<"2.Traversal"<<endl<<"3. Insert at end"<<endl
		   <<"4. Insert at any position."<<endl<<"5. Delete at beginning"<<endl<<"6.Delete at end"<<endl<<"7.Delete at any position"<<endl;
           cin>>ch;
           switch(ch)
		  {
	
	case 1: cout<<"enter the values to be inserted"<<"\n";
	        cin>>val;
	        insertatbeg(val);
	        break;
    case 2: traversal(); 
            break;
    case 3: cout<<"enter the valye to be inserted"<<"\n";
	        cin>>val;
			insertatend(val);
            break;
    case 4: cout<<"enter the position"<<endl;
            cin>>pos;
            cout<<"enter the value to be inserted"<<"\n";
            cin>>val;
            insertatanypos(val,pos);
            break;
    case 5: deleteatbeg();
            break;
    case 6: deleteatend();
            break;
    case 7: cout<<"enter the position."<<"\n";
            cin>>pos;
	        deleteatanypos(pos);
            break;
    case 8: exit(0);
    
    default: "Error! Wrong choice"<<"\n";   
     
} 

}
	return 0;

}


