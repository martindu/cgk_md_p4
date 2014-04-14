#include "catalog.h"
#include "query.h"
#include "index.h"

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
    
    int no_of_attributes = attrCnt; //temp variable for number of attributes
    int counter =0;                 //variable used for attribute offset number
    AttrDesc *attrs_temp;
    int no2=0,t=0;
    RID rid;
    
    attrCat->getRelInfo(relation, no2, attrs_temp);
    
    // add attributes to attrCatalog
    if(no2 == attrCnt)
    {
        while (no2)
        {
            char *str;
            strcpy (str,attrs_temp[0].attrName);
            t=0;
            while (no_of_attributes)
            {
                if (strcmp(str, attrList[t].attrName)==0)
                {
                    AttrDesc temp_attr = *new AttrDesc();
                    Record record = *new Record();
                    
                    attrCat->getInfo(relation, attrList[t].attrName,temp_attr);
                    
                    if(attrList[t].attrValue == NULL) //check if it is correct
                    {
                        //print error
                    }
                    
                    record.length = attrList[t].attrLen;
                    record.data = attrList[t].attrValue;
                    
                    /*
                    if (temp_attr.indexed ==1) // if indexed
                    {
                        attrCat->insertEntry(record); // chaangeeeeeee
                    }
                    else */
                    {
                        attrCat->insertRecord(record, rid);
                    }
                    
                    //attrCat->addInfo(temp_attr);
                    
                    counter++;
                }
                no_of_attributes--;
                t++;
            }
            
            no_of_attributes = attrCnt;
            no2--;
        }
        
    }
    else
    {
        //error.print(""); // print the error that number of attributes is not same in relation
    }
    return OK;
}
