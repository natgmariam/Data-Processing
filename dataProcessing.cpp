//
//Description: using functions, class, linked list to clear up a
//geabage file that contains info in to matching set  
//Input: user infputs a txt file containiaing a list of 
//bools, ints, stringsm chars, to be organized  
//Output: the output shows a 3 by 3 out file, that has all 
//the datat types grouped, such as the ints together, the strings 
//and on 

#include "dataProcessing.h"
using namespace std;

// ******************************
// * Global Helper Functions
// ********************************

// ---------------------
// isInteger
//    returns true if the string
//    parameter is an integer
//---------------------- **
bool isInteger(string s){
    // If length is 0
    if(s.length() == 0){ return false; }
    // If first char is not '-' or a digit
    if(s[0] != '-' && (s[0] < 48 || s[0] > 57)){ return false; }
    // For all chars
    for(unsigned int i = 1; i < s.length(); i++){
        // If not a digit
        if(s[i] < 48 || s[i] > 57){
            return false;
        }
    }
    // Succesfully made it through
    return true;
}

// ---------------------
// isChar
//    returns true if the string
//    parameter is a char
//---------------------- **
bool isChar(string s){
    // If length is 1
    if(s.length() == 1){
        // Return (is this a not digit?)
        return (s[0] < 48 || s[0] > 57);
    }
    return false;
}

// ---------------------
// isDouble
//    returns true if the string
//    parameter is a double
//---------------------- **
bool isDouble(string s){
    // If length is 0
    if(s.length() == 0){ return false; }
    // If first char is not '-' or a digit
    if(s[0] != '-' && (s[0] < 48 || s[0] > 57)){ return false; }
    
    bool foundDecimal = false;
    // For all chars
    for(unsigned int i = 1; i < s.length(); i++){
        // If not a digit or a decimal
        if((s[i] < 48 || s[i] > 57) && s[i] != '.'){
            return false;
        }
        // If a decimal
        if(s[i] == '.'){
            // If already found a decimal
            if(foundDecimal){
                return false;
            }
            foundDecimal = true;
        }
    }
    // Succesfully made it through
    return true;
}

// ---------------------
// isBool
//    returns true if the string
//    parameter is a bool
//---------------------- **
bool isBool(string s){
    return (s == string("true") || s == string("false")); 
}

// ---------------------
// stob
//   convert string to bool
//---------------------- **
bool stob(string s){
    if(s == string("true")){
        return true;
    }
    else if(s == string("false")){
        return false;
    }
    cout << "ERROR: Tried to convert something that is not a bool." << endl;
    exit(1);
    return false;
}

// ---------------------
// getDataType
//    <your comments here>
//---------------------- **
unsigned int getDataType(string garbage){ //done 
    // YOUR CODE HERE 
    if(isInteger(garbage)==true){
        return INT; //returns int after chechking 
    }
    else if(isChar(garbage)==true){
        return CHAR; //returns char 
    }
    else if(isDouble(garbage)==true){
        return DOUBLE; //returns double 
    }
    else if(isBool(garbage)==true){
        return BOOL; //returns bool after check 
    }
    else
    return STRING; // Students may want to replace



}

// ******************************
// * dataElementBase
// ********************************

// ---------------------
// param constructor dataElementBase
//    <your comments here>
//---------------------- **
dataElementBase::dataElementBase(unsigned short dt){ //done
    // YOUR CODE HERE
    dataType=dt;
    // garbagePile *temp=new garbagePile();
    // dataElementBase current=new dataElementBase(); 
    // current.dataType=dt; //new data eleement 
    // temp.head=current; 
    
}

// ---------------------
// copy constructor dataElementBase
//    <your comments here>
//---------------------- **
dataElementBase::dataElementBase(const dataElementBase& copy){ //done
    // YOUR CODE HERE
    
    this->dataType=copy.dataType; //asignee data type of the copy to this data type  
    this->next=nullptr;
    this->prev=nullptr;
}

// ---------------------
// assignment operator overload dataElementBase
//    <your comments here>
//---------------------- **
void dataElementBase::operator=(const dataElementBase& copy){
    // YOUR CODE HERE
    //delete dataType;
    //dataType = NULL; 
    //if(this != copy.dataType){
    // if(head!=nullptr){
    //this->dataType=*new unsigned short; 
    this->dataType=copy.dataType; //assigne the copy 
    // this->next=nullptr;
    // this->prev=nullptr;
    // }
    // const dataElementBase *temp=nullptr;
    // this->dataType =copy.dataType;   
    // while (temp!=nullptr)
    // {
    // this->dataType=dataElementBase::deepCopyDataElement( temp  );
    // this->next=nullptr;
    // this->prev=nullptr;
    // temp=temp->next; 
    // }
    
}

// ---------------------
// destructor dataElementBase
//    Virtual destructor that does nothing.

//    It must be here to call the dataElement
//    destructor, which in turn will deallocate
//    any data from a class (like string). 
//---------------------- **
dataElementBase::~dataElementBase(){}

// ---------------------
// getDataType
//    return dataType of dataElement
//---------------------- **
unsigned short dataElementBase::getDataType() const{
    return this->dataType;
}

// ---------------------
// getNext
//    return link to next dataElement
//---------------------- **
dataElementBase *dataElementBase::getNext() const{
    return next;
}

// ---------------------
// getPrev
//    return link to previous dataElement
//---------------------- **
dataElementBase *dataElementBase::getPrev() const{
    return prev;
}

// ---------------------
// link
//    <your comments here>
//---------------------- **
void dataElementBase::link(dataElementBase *node){
    // YOUR CODE HERE
    this->next=node; 
    if(node!=nullptr)
    {
    next->prev=this; //moving this back to a node before
    }

}

// ---------------------
// compare
//    Function is used to compare 
//      2 dataElements. Must be called
//      like this: deb1->compare(deb2)
//
//      The pointer is required to call getData
//      the return pointer must be casted to
//      the correct type, then compared. 
//---------------------- **
short dataElementBase::compare(dataElementBase *deb){
    if(deb == nullptr){
        cout << "ERROR: Tried to compare nullptr." << endl;
    }
    // If the dataTypes are not equal
    if(dataType < deb->dataType){
        return LESSTHAN;
    }
    if(dataType > deb->dataType){
        return GREATERTHAN;
    }
    // Datatypes are equal 
    switch(dataType){
        case(INT):{
            if(*(static_cast<int*>(this->getData())) < *(static_cast<int*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<int*>(this->getData())) > *(static_cast<int*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(CHAR):{
            if(*(static_cast<char*>(this->getData())) < *(static_cast<char*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<char*>(this->getData())) > *(static_cast<char*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(DOUBLE):{
            if(*(static_cast<double*>(this->getData())) < *(static_cast<double*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<double*>(this->getData())) > *(static_cast<double*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(BOOL):{
            if(*(static_cast<bool*>(this->getData())) < *(static_cast<bool*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<bool*>(this->getData())) > *(static_cast<bool*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(STRING):{
            if(*(static_cast<string*>(this->getData())) < *(static_cast<string*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<string*>(this->getData())) > *(static_cast<string*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
    }
    return EQUAL;
}

// ---------------------
// getNewDataElement
//    <your comments here>
//---------------------- **
dataElementBase* dataElementBase::getNewDataElement(unsigned short dataType, string data){
    // YOUR CODE HERE
    
    //recive aa data type and conver it into new data eleements to match 
    switch(dataType){
        case (INT):
        return new dataElement<int>(dataType, stoi(data));
        break; 
        
        case (CHAR)://treat it as an array, string arry to get the char
        return new dataElement<char>(dataType, data[0]);
        break;
        
        case (DOUBLE):
        return new dataElement<double>(dataType, stod(data));
        break; 

        case (BOOL):
        return new dataElement<bool>(dataType, stob(data));
        break; 

        case (STRING):
        return new dataElement<string>(dataType, data);
        break; 

        default:
        return nullptr; 
    }
     // Students may want to replace
}

// ---------------------
// deepCopyDataElement
//    <your comments here> almost finshed 
//---------------------- **
dataElementBase* dataElementBase::deepCopyDataElement(dataElementBase *deb){
    // YOUR CODE HERE
    //check in the datatype is a mathc and return it ususing static allocation 
    if(deb!= nullptr){
        
        switch(deb->dataType){
            case (INT):
                return new dataElement<int>(INT,*(static_cast<int*>(deb->getData())));
                break;  
            
            case (CHAR):
                return new dataElement<char>(CHAR,*(static_cast<char*>(deb->getData())));
                break; 

            case (DOUBLE):
                return new dataElement<double>(DOUBLE,*(static_cast<double*>(deb->getData())));
                break; 

            case (BOOL):
                return new dataElement<bool>(BOOL,*(static_cast<bool*>(deb->getData())));
                break; 
            
            case (STRING):
                return new dataElement<string>(STRING,*(static_cast<string*>(deb->getData())));
                break; 
        }
    }
    return nullptr;
}

// ---------------------
// swap
//    <your comments here>
//---------------------- **
void dataElementBase::swap(dataElementBase* A, dataElementBase* B){//redo 
    // YOUR CODE HERE            //left=A        //right=B
    dataElementBase* tempAn =A->next;
    dataElementBase* tempBn=B->next;
    dataElementBase *tempAp=A->prev;
    dataElementBase *tempBp=B->prev; 
    
    // if(A->next==nullptr || A->prev == nullptr 
    //|| B->next ==nullptr || B->prev==nullptr) 
    //     return;
        //if the data procedes one another 
    if(A->next == B && B->prev ==A){
        if(A->prev != nullptr)
            A->prev->next=B;
        if(B->next != nullptr)
            B->next->prev=A;
        B->next=A; //set b next to a 
        A->prev=B; //set a prev to b 
        B->prev=tempAp;  //swap the top two 
        A->next =tempBn; 
    }//consiton what comes before is your cuurent point 
    else if (A->prev == B && B->next ==A){
        if(B->prev != nullptr)
            B->prev->next=A;
        if(A->next != nullptr)
            A->next->prev=B;
        A->next=B; //set a next to b 
        B->prev=A; //set b prev to A
        A->prev=tempBp; //swap whats above 
        B->next =tempAn;
    }
    else{ //to cehchck if they are adjasent too one another and null 
        if(A->prev != nullptr)
            A->prev->next=B;
        if(B->next != nullptr)
            B->next->prev=A; 
        if(A->next != nullptr)
            A->next->prev=B;
        if(B->prev != nullptr)
            B->prev->next=A; 
        A->next=tempBn; //if adjecent move forward 
        A->prev=tempBp; 
        B->next=tempAn;
        B->prev=tempAp;
    }
    
}

// ******************************
// * dataElement
// ********************************

// ---------------------
// param constructor dataElement
//    constructor to initliaze the data
//    must inline a call to the dataElementBase ctor.
//---------------------- **
template<typename t>
dataElement<t>::dataElement(unsigned short dt, t d) : dataElementBase(dt){
    data = d;
}

// ---------------------
// getData
//    return a void pointer 
//    to the data
//---------------------- **
template<typename t>
void* dataElement<t>::getData(){
    return static_cast<void*>(&data);
}

// ---------------------
// printElement
//    print out the data
//---------------------- **
template<typename t>
void dataElement<t>::printElement(ostream& out) const{
    out << data;
}

// ******************************
// * garbagePile
// ********************************

// ---------------------
// default constructor garbagePile
//    <your comments here>
//---------------------- **
garbagePile::garbagePile(){
    // YOUR CODE HERE
    head=nullptr;
    tail=nullptr; 
    size=0; 
}

// ---------------------
// copy constructor garbagePile
//    <your comments here>
//---------------------- **
garbagePile::garbagePile(const garbagePile &copy){
    // YOUR CODE HERE
    head=nullptr;
    tail=nullptr;
    size=0; 
    *this=copy; //copy is assigned to this 


}

// ---------------------
// operator assignment overload
//    <your comments here>
//---------------------- **
void garbagePile::operator=(const garbagePile &copy){
    // YOUR CODE HERE
    
    if(head!=nullptr){
        clearGarbagePile(); 
    }
    size=1; 
    dataElementBase *temp=dataElementBase::deepCopyDataElement(copy.head); //
    head=temp; //pointers same location 
    dataElementBase *current=copy.head; //int a something to hold copy head 
    dataElementBase *prev=nullptr; //
   //you checking to make sure its not the last node 
    while(current!=copy.tail){ 
        current=current->getNext(); //this is to move forward node
        prev=temp; //copying and moving in the function 
        temp=dataElementBase::deepCopyDataElement(current);
        prev->link(temp); 
        size++;
    }
    tail=temp; 
}

// ---------------------
// destructor for garbagePile
//    <your comments here>
//---------------------- **
garbagePile::~garbagePile(){
    // YOUR CODE HERE
    this->clearGarbagePile(); 
}

// ---------------------
// addItem
//    <your comments here>
//---------------------- **
void garbagePile::addItem(string garbage){
    // YOUR CODE HERE
    size+=1; 
    //get data and convert it to temp using function 
    dataElementBase *temp=dataElementBase::getNewDataElement(getDataType(garbage),garbage);  
    if(head==nullptr){//contion to chehck if head is null 
        head=temp;
        tail=temp; 
    }
    else{
    size++; //increase the size 
    tail->link(temp); //using link function add to tail 
    tail=temp; //then previous temp is now tail 
    }
}

// ---------------------
// operator[]
//    <your comments here>
//---------------------- **
dataElementBase *garbagePile::operator[](unsigned int index){
    // YOUR CODE HERE
    //head is assigned to temp and nodes that come next 
    dataElementBase *temp=this->head;
     for(unsigned int i=0; i<index; i++){
        temp=temp->getNext(); 
    }
    
    return temp; 
}

// ---------------------
// clearGarbagePile
//    <your comments here>
//---------------------- **
void garbagePile::clearGarbagePile(){
    // YOUR CODE HERE
    if(!head) { //if not head set tail ot null and return 
        size = 0;
        tail = nullptr;
        return; 
    }
    //from head on down, all elements assigned to head 
    dataElementBase *temp = head->getNext();
    delete head; //delete head 
    head = temp;
    temp = nullptr;
    clearGarbagePile(); //recursive 
    
    // if(head==nullptr) 
    //     return;
    // else{
    //     dataElementBase *temp=head->getNext();
     //from head on down, assigned to temp 
    //     delete head; //delete head 
    //     size=size-1; //range of dletion
    //     head=temp; //assign first head as temp
    //     clearGarbagePile(); //recall function 
    // }
}

// ---------------------
// sort
//    <your comments here>
//---------------------- **
void garbagePile::sort(){
    // YOUR CODE HERE
    //bubble sort irterates through list using nested loop 
    for(unsigned int i=0; i <size-1; i++){
        for(unsigned int j=0; j<(size-i-1); j++){
            dataElementBase* left= (*this)[j]; 
            dataElementBase* right= (*this)[j+1];//declare left and right 
            if(left != nullptr && right != nullptr){
                if((left->compare(right)) == GREATERTHAN){//compare 
                    dataElementBase::swap(left, right); //swap 
                    if(left==head){ //first is eq head 
                        head=right; //right is head 
                    } 
                    if(right==tail){ //right eq tail 
                        tail=left; //tail is left 
                    }
                
                }
            }
        }

    }
}

// ---------------------
// operator<<
//    <your comments here>
//---------------------- **
ostream& operator<<(ostream& out, garbagePile gp){
    // YOUR CODE HERE
    int num=1;
    unsigned int linkedList=0; 
    int size=gp.size+1; //modify size 
    if(gp.head==nullptr){ //maake sure there are vlaues 
        return out; 
    }
    while(linkedList < gp.size){ 
        gp[linkedList]->printElement(out);//print out the data 
        if(num+1 != size){
            out<<" , ";
        }
        if(num % 3 ==0){ //end ones 3 elements per line 
            out<<endl; 
        }
        num++; //incremant through list 
        linkedList++;
    }
    // unsigned int newSize = (gp.size/3);
    // dataElementBase* temp=gp.head;
    // int sizeMod= (gp.size % 3); 
    // if(gp.head==nullptr){
    //     return out; 
    // }
    // //gp..size is to only print 3 a line 
    // for(unsigned int i = 0; i< newSize; i++){
    //     for(unsigned int j= 0; j < 3; j++){
    //         temp->printElement(out);
    //         out<<" , "; 
    //         temp=temp->getNext(); //move to next set 
    //     }
    //     out<<endl; 
    // }
    // //condition to =only have 3 a line 
    // if( sizeMod!=0 ){ //for the rest 
    //    if(sizeMod == 2){ //when 2 elements are left 
    //         temp->printElement(out);
    //         out<<" , "; 
    //         temp=temp->getNext();
    //    }
    //     temp->printElement(out);  //last elements 
    // }

    return out;
}

// ---------------------
// operator>>
//    <your comments here>
//---------------------- **
istream& operator>>(istream& in, garbagePile &gp){//done
    // YOUR CODE HERE
    string garbage; 
    //gp.addItem(garbage); 
    getline(in, garbage); //takes in file 
    gp.addItem(garbage); //adds elements 
    return in;
}
