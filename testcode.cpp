#include<iostream>
using namespace std;
struct node
{
    string timestamp;
    int data;
    int  nodeNumber;
    node *next;
    node *link;
};
int num=0;
node *head=NULL;
int main()
{

    int choice;
    string t;
    int dt;

    label: cout<<"1.parent node"<<"\n";
    cout<<"2. child node\n";
    cout<<"3. display th list\n";


    cin>>choice;

    if(choice==1)
    {
     cout<<"enter data";
     cin>>t;
     cin>>dt;

         node *temp=new node;
         temp->timestamp=t;
         temp->data=dt;
         temp->nodeNumber=++num;
         temp->link=NULL;
         temp->next=NULL;

         if(head==NULL)
         {
             head=temp;
         }
         else
         {
             node *t=head;
             while(t->next==NULL)
             {
                 t=t->next;
             }

             t->next=temp;

         }

    }
    else if (choice ==2)
    {
        int pos;
      cout<<"enter position on which you want to enter child";
      cin>>pos;
        pos--;
         node *o=head;
         while(pos!=0)
            o=o->next;
         pos--;

          int sum=o->data;
           cout<<"enter data";
           cin>>t;
           cin>>dt;

         node *temp=new node;
         temp->timestamp=t;
         temp->data=dt;
         temp->nodeNumber=++num;
         temp->next=NULL;
         temp->link=NULL;

         node *y=o;
         if(y->link==NULL)
         {
             if(sum-dt<0)
                cout<<"data cannot be inserted";
             else
             y->link=temp;

         }
         else
         {
             while(y->link!=NULL)
             {
                 y=y->link;
                 sum=sum-(y->data);

             }
             if(sum-dt<0)
             {
                 cout<<"cannot be inserted";

             }
             else
             y=y->link=temp;


         }
    }
    else if (choice ==3)
    {
        if(head==NULL)
            cout<<" no data";
        else
        {
            node *t=head;
            while(t!=NULL)
            {
                cout<<t->data<<"->";
                if(t->link!=NULL)
                {
                    node *z=t;
                    z=z->link;
                    while(z!=NULL)
                    {
                        cout<<z->data<<"->";
                        z=z->link;

                    }
                }
            cout<<"\n\n";
            t=t->next;
            }
        }

    }

char chh;
cout<<"enter y to continue";
cin>>chh;
if(chh=='y')
    goto label;

    return 0;
}
