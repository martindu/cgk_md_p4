#include "catalog.h"
#include "query.h"
#include "index.h"

/*
 * Selects records from the specified relation.
 *
 * Returns:
 * 	OK on success
 * 	an error code otherwise
 */
Status Operators::Select(const string & result,      // name of the output relation
	                 const int projCnt,          // number of attributes in the projection
		         const attrInfo projNames[], // the list of projection attributes
		         const attrInfo *attr,       // attribute used inthe selection predicate 
		         const Operator op,         // predicate operation
		         const void *attrValue)     // literal value in the predicate
{
	int numAtts;
	AttrDesc* attArray; //delete when done
	attrCat->getRelInfo(attr->relName, numAtts, attArray);
	
	int len = 0;
	const AttrDesc pNames[projCnt];
	for (int i =0; i< projCnt; i++){
		AttrDesc* temp = new AttrDesc();
		attrCat->getInfo(attr->relName, projNames[i].attrName, *temp);
		pNames[i] = *temp;
		len+=temp->attrLen;
	}
	const int reclen = len;
	
	AttrDesc* attrDesc = new AttrDesc();
	attrCat->getInfo(attr->relName, attr->attrName, *attrDesc);
	
	
	
	
	
	//if equality predicate and has an index
	//
	if (op == EQ && attrDesc->indexed) {
		Operators::IndexSelect(result,projCnt,
                              pNames, attrDesc,   
                              op, attrValue, reclen);
                              
          //error check
     }
                              
     else {
     Operators::ScanSelect(result, projCnt, 
                             pNames, attrDesc, 
                            op, attrValue, reclen);
                            
     	//error check
     }
	
return OK;
}