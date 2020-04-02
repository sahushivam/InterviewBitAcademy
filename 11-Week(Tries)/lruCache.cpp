struct Node{
    int data;
    int key;
    Node* prev;
    Node* next;
};
map<int,Node*>check;
int cnt=0,capacity;
Node* head=NULL;
Node* tail=NULL;

void addnode(int x,int key)
    {
        Node* newnode=new Node();
        newnode->data=x;
        newnode->key=key;
        check[key]=newnode;
        if(head==NULL) //if head is null set the curr node to head
        {
            head=newnode;
            head->next=NULL;
            head->prev=NULL;
            tail=newnode;
        }
        else                    //make curr as head and attach curr->next =head , curr=head;
        {
            newnode->next=head;
            head->prev=newnode;
            newnode->prev=NULL;
            head=newnode;
        }
    cnt++;
    }
void removelast()
{
    if(head==tail)
    {
        check[tail->key]=NULL;//similar as map.erase(key)
        head=NULL;
        tail=NULL;
        cnt--;
    }
    else
    {
        check[tail->key]=NULL; //similar as map.erase(key)
        Node* pr=tail->prev; //remove tail node as set tail->prev as tail
        pr->next=NULL;
        tail=pr;
        cnt--;
    }
}
void removenode(Node* t) //comes in handy when the key is already present in the map
{
    Node* pt=t;
    if(pt->key==tail->key)
    {
        removelast(); //if it last remove the last node
    }
    else if(pt->key==head->key) //if it head then remove the head and set head->next=head
    {
        check[pt->key]=NULL;
        head=pt->next;
        head->prev=NULL;
        cnt--;
    }
    else
    {       
        Node* sprev=pt->prev;
        Node* snx=pt->next;
        check[pt->key]=NULL;
        sprev->next=snx;
        snx->prev=sprev;
        cnt--;
    }

}
LRUCache::LRUCache(int N)
{
      head=NULL;
      tail=NULL;
     check.clear();
     cnt=0;
     capacity=N;
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    if(cnt<capacity && check[x]==NULL)
    {
        addnode(y,x);
    }
    else if(cnt<=capacity && check[x]!=NULL)
    {
        removenode(check[x]);
        addnode(y,x);
    }
    else if(cnt==capacity && check[x]==NULL)
    {
        removelast();
        addnode(y,x);
    }

}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
        if(check[x]==NULL)
            return -1;
        int ans=check[x]->data;
        removenode(check[x]);
        addnode(ans,x);
        return ans;
        
}

