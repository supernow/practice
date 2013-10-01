#include<iostream>
using namespace std; 
struct BinaryTree
{
  char a;
  struct BinaryTree *Left,*Right;
  BinaryTree(char c='\0')
  {
    a=c;
    Left=NULL;
    Right=NULL;
  }
};

struct record
{
  int a;
  BinaryTree *Bi;
  record()
  {
    a=0;
    Bi=NULL;
  }
};


class traverse
{
private:
  string a;
  string b;
public:
  traverse(string aa="",string bb="")
    :a(aa),b(bb)
  {}
  BinaryTree * build();
  int find(char c)//find the location of c in the string b;
  {
    int i=0;
    while(b[i]!=c)
      {
	i++;
      }
    return i;
  }
  bool before(char a,char b)
  {
    return find(a)>find(b);
  }
  int find2(char c,record *q)
  {
    int i=find(c);
    while((*(q+i)).a==0)
      {
	--i;
      }
    return i;
  }
};
BinaryTree* traverse::build()
{
  record *re=new record[a.size()];
  BinaryTree *bi=new BinaryTree(a[0]);
  (re+find(a[0]))->a=1;
  (re+find(a[0]))->Bi=bi;
  BinaryTree *first=bi;
  for(int i=1;i<a.size();++i)
    {
      bi=new BinaryTree(a[i]);
      if(before(a[i-1],a[i]))
	{
	  (*(re+find(a[i-1]))).Bi->Left=bi;
	}
      else
	{
	  (*(re+find2(a[i],re))).Bi->Right=bi;
	}
      (*(re+find(a[i]))).a=1;
      (*(re+find(a[i]))).Bi=bi;
    }
  return first;
}
int order(BinaryTree *q)
{
  if(q->Left)order(q->Left);
  if(q->Right)order(q->Right);
  cout<<q->a;
}
int main()
{
  traverse tr("ABDHECFG","HDBEAFCG");
  BinaryTree *q=tr.build();
  order(q);
}





