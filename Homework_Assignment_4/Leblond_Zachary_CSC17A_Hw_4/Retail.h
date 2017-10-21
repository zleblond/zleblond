
#ifndef RETAIL_H
#define RETAIL_H
class RetailItem
{
private :
string description;
int unitsOnHand;
float price;
public:
RetailItem( string str, int unit, float pr );
void describeItem();
};

RetailItem :: RetailItem( string str, int unit, float pr ) // constructor
{
description = str;
unitsOnHand = unit;
price = pr;
}

void RetailItem :: describeItem() // describe an item
{
cout<<"Description "<<description;
cout<<" Unit available "<<unitsOnHand;
cout<<" Price of the item "<<price<<endl;
}


#endif /* RETAIL_H */

