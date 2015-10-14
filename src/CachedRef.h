/* 
 * File:   CachedRef.h
 * Author: tom
 *
 * Created on 14 October 2015, 12:46
 */

#ifndef CACHEDREF_H
#define	CACHEDREF_H

#include <map>
#include "fastahack/Fasta.h"


class CachedRef {
    
public:
    
    FastaReference fastaRef;
    map<string, string> chromosomeMap;
    
    CachedRef(FastaReference fastaRef);
    
    string getSequence(string seqname, int start, int length);
       
    
private:
   
    void cacheSeq(string seqname);
    
};

#endif	/* CACHEDREF_H */

