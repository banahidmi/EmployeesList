#include<iostream>

using namespace std;
class Employee{
public:
	
  Employee *left,*right,*par; 
  int regnum,dept,phone; 
  char color;
  
  Employee(int regnum,int dept,int phone,Employee*l=0,Employee*r=0,Employee*pa=0,char color='r'){
    this->regnum=regnum;
    this->dept=dept;
    this->phone=phone;
    left=l;
    right=r;
    par=pa;
    this->color=color;
  }

};

class RedBlackTree{

public:

  Employee *root;
  Employee *nil;// leaf is a special node called NIL

  RedBlackTree(){
    nil=new Employee(0,0,0);
    nil->color='b';
    root=nil;
  }

  

  void InsertNode(int x,int y,int z){

    Employee *p,*prev=nil,*q;
    if(root==nil){

        p=new Employee(x,y,z,nil,nil,nil,'b');
		root=p;
		
		}

    else{

      p=new Employee(x,y,z,nil,nil,nil,'r');

      q=root;

      while(q!=nil){
	   prev=q;
       if(x<q->regnum)
       q=q->left;
	   else
	   q=q->right;
       }

      p->par=prev;

      if(x<prev->regnum){
	  prev->left=p;
	  }

      else{

        prev->right=p;
    }

    }

    SolveDoubleRedProblem(p);

  }

   void LeftRotate(Employee *x){

    Employee *y;
    y= x->right;
    x->right=y->left;
    if(y->left!=nil)
     y->left->par=x;

    y->par= x->par;

    if(x->par==nil)

      root =y;

    else if (x==x->par->left)

      x->par->left=y;

    else

      x->par->right = y;

    y->left=x;

    x->par=y;

  }
  
  void RightRotate(Employee *x){

    Employee *y;
    y= x->left;
    x->left=y->right;
    if(y->right!=nil)

      y->right->par=x;

    y->par= x->par;

    if(x->par==nil)

      root =y;

    else if (x==x->par->right)

      x->par->right=y;

    else

      x->par->left = y;

    y->right=x;

    x->par=y;

  }

  void SolveDoubleRedProblem(Employee *t) {

    Employee *u;

    if(root==t)

      {

        t->color='b';

        return;

      }

    while(t->par!=nil&&t->par->color=='r')

      {

        Employee *g=t->par->par;

        if(g->left==t->par)

          {

            if(g->right!=nil)

              {

                u=g->right;

                if(u->color=='r')

                  {

                    t->par->color='b';

                    u->color='b';

                    g->color='r';

                    t=g;

                  }

              }

            else

              {

                if(t->par->right==t)

                  {

                    t=t->par;

                    LeftRotate(t);

                  }

                t->par->color='b';

                g->color='r';

                RightRotate(g);

              }

          }

        else

          {

            if(g->left!=nil)

              {

                u=g->left;

                if(u->color=='r')

                  {

                    t->par->color='b';

                    u->color='b';

                    g->color='r';

                    t=g;

                  }

              }

            else

              {

                if(t->par->left==t)

                  {

                    t=t->par;

                    RightRotate(t);

                  }

                t->par->color='b';

                g->color='r';

                LeftRotate(g);

              }

          }

        root->color='b';

      }

  }


  Employee* searchin(int x){

    int f=0;

    Employee*p=root;

    while(p!=0){

        if(x==p->regnum){
		f=1;
		break;
		}

        else if(x<p->regnum){

            p=p->left;

          }

        else{
            p=p->right;
		 }
		 }

    if(f==1)

      return p;

  }

  void displayout(Employee *t){
    if(t!=nil){
cout<<"Department id is: "<<t->dept<<". ";
cout<<"Internal Phone number is: "<<t->phone; }

  }


};

int main(){

RedBlackTree list;
list.InsertNode(1001,51,6467);//insertation of employees
list.InsertNode(1002,43,2359);
list.InsertNode(1010,34,4342);
list.InsertNode(1008,21,6761);
list.InsertNode(2001,45,2345);
list.InsertNode(2006,23,6862);

int regnum;
char check;
char cont='y';


while(cont=='y' || cont=='Y'){
cout<<"Enter Employee's Registration Number: ";
cin>>regnum;
if(list.searchin(regnum)){
	list.displayout(list.searchin(regnum));//displaying the employee variables
}
else{//if the employee was not in the list of redblacktree
	cout<<"Employee not found !\n";
	cout<<"Do you want to add this employee to the system ?";
	cin>>check;
    if(check=='y'|| check=='Y'){
	int id,phonenum;
    cout<<"What is the Department id and Internal phone number?:";
    cin>>id>>phonenum;
    list.InsertNode(regnum,id,phonenum); //inserting the new e,ployee information
    cout<<"Added Successfully.";
	}}
	
	cout<<"\nContinue?(y/n):";
    cin>>cont;
    }
cout<<"Bye";	
}

 
