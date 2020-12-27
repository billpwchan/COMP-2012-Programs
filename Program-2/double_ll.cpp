class Double_LL
{
    Double_LL *prior, *next;
    void insert(Double_LL*);
    ...
};

void Double_LL::insert(Double_LL *x)
{
     x->next = next; x->prior = this;
     next->prior = x; next = x; 
}
