#include "catalog.h"
#include "query.h"
#include "index.h"

/*
 * Inserts a record into the specified relation
 *
 * Returns:
 * 	OK on success
 * 	an error code otherwise
 */

//check if the relation is present in the list or not
//check if attribute is present in the attribute list or not
//check if the datatype is the same for attributes
//how do you implement attrValue

/*
Datatype check_value_type(attrInfo &a)
{
    if (*a.attrValue ==) {
        <#statements#>
    }

}

*/


Status Updates::Insert(const string& relation,      // Name of the relation
                       const int attrCnt,           // Number of attributes specified in INSERT statement
                       const attrInfo attrList[])   // Value of attributes specified in INSERT statement
{
    /* Your solution goes here */
    
    int no_of_attributes = attrCnt; //temp variable for number of attributes
    int counter =0;                 //variable used for attribute offset number
    RelDesc attributes_checker = *new RelDesc();
    AttrDesc *attrs_temp;
    int no2=0,t=0;
    
    attrCat->getRelInfo(relation, no2, attrs_temp);
    
    
    //if(relCat->getInfo(relation, attributes_checker) == OK &&
      // attributes_checker.attrCnt == attrCnt)
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
                    strcpy(temp_attr.relName, attrList[t].relName);
                    strcpy(temp_attr.attrName, attrList[t].attrName);
                    temp_attr.attrOffset = counter;
                    temp_attr.attrType = attrList[t].attrType;
                    temp_attr.attrLen = attrList[t].attrLen;
                    temp_attr.indexed = false;
                    attrCat->addInfo(temp_attr);
                    counter++;
                }
                no_of_attributes--;
                t++;
            }
            
            no_of_attributes= attrCnt;
        }
    
        //add relation to relationCatalog
        RelDesc temp_rel = *new RelDesc();
        
        strcpy(temp_rel.relName, attrList[0].relName);
        temp_rel.attrCnt=counter;
        temp_rel.indexCnt =0;
        
        relCat->addInfo(temp_rel);
    }
    else
    {
        //error.print(""); // print the error
    }
    return OK;
}
