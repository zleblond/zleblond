
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
class InventoryItem
{
private:
string desc; // The item desc
int iitemno;// item number
float cost; // The item cost
float tcost;//total cost
int quantity; // Number of units on hand
public:
InventoryItem()
{
desc="";
iitemno=0;
cost=0.0;
tcost=0.0;
quantity=0;
}

InventoryItem(string desc,int num, float c, int u)
{
desc= desc;
iitemno=num;
cost = c;
quantity = u;
}
  
void setIitemno(int num)
{
iitemno=num;
}

int getIitemno()
{
return iitemno;
}


void setdesc(string des )
{ 
    desc= des; 
}

string getdesc()
{ 
    return desc; 
}

void setCost(float co)
{
cost=co;
settcost();
}
float getCost() const
{ 
    return cost;
}
void settcost()
{
tcost=cost*quantity;
}
float gettcost()
{
return tcost;
}
void setQuantity(int qu)

{
quantity=qu;
}
int getquantity() const
{ 
    return quantity; 
}
};


#endif /* INVENTORYITEM_H */

