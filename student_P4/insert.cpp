
#include "catalog.h"
#include "query.h"
#include "index.h"
#include <cstring>

/*
 * Inserts a record into the specified relation
 *
 * Returns:
 *  OK on success
 *  an error code otherwise
 */



//check if no value is specified for value?
//check if the datatype is the same for attributes
//should all records go to heapfile or some should go to index file too ? //insertEntry


Status Updates::Insert(const string& relation,      // Name of the relation
                       const int attrCnt,           // Number of attributes specified in INSERT statement
                       const attrInfo attrList[])   // Value of attributes specified in INSERT statement
{
    /* Your solution goes here */
    
    int counter =0;                 //variable used for attribute offset number
    AttrDesc *attrs_temp;
    RelDesc *rel_temp;
    int no2=0,t=0, j=0,k=0;
    int indexed_attributes=0;
                //char *str;
    
    attrCat->getRelInfo(relation, no2, attrs_temp);
    cout<< "numner of attributes -> "<< no2<<endl;
    
    // add attributes to attrCatalog
    if(no2 == attrCnt)
    {
        while (j < no2)
        {                                              
            char *str;                                                         
            strcpy (str,attrs_temp[j].attrName);                                                                     
            while (k< no2)
            {       	 
               if (strcmp(str, attrList[k].attrName)==0)
              {
                    AttrDesc temp_attr = *new AttrDesc();
                    Record record = *new Record();
                    RID rid;
                    
                    attrCat->getInfo(relation, attrList[k].attrName,temp_attr);
                    if(attrList[t].attrValue == "NULL") //check if it is correct
                    {
                        //print error
                    }
                    
                    record.length = temp_attr.attrLen;
                    memcpy(&record.data, &attrList[k].attrValue, record.length+1);
                     
                  // cout<<record.length <<"   record len \n";
                  // cout<< attrList[k].attrValue <<"   record data \n";
                                                             
                    attrCat->insertRecord(record, rid);
                    attrCat->addInfo(temp_attr);                   
                   // attrCat->getRecord(rid, record);
                   break;
                }

                k++;
                            cout <<"Below K value is "<<k<<endl;
            }

            k = 0;
            j++;
            cout <<"Below J value is "<<j<<endl;
        }
  	
  	        
  
                                            
    }
    else
    {
        //error.print(""); // print the error that number of attributes is not same in relation
    }
    
    return OK;
}
