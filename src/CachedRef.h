/* 
 * File:   CachedRef.h
 * Author: tom
 *
 * Created on 14 October 2015, 12:46
 */

#ifndef CACHEDREF_H
#define	CACHEDREF_H

#include <map>
#include "Fasta.h"

using namespace std;

class CachedRef {
    
public:
    
    FastaReference* fastaRef;
    
    CachedRef(FastaReference& fastaRef);
    ~CachedRef(void);
    
    string getSequence(string seqname, int start, int length);
       
    
private:
   
    map<string, string>* chromosomeMap;
    
    void cacheSeq(string seqname);
    
};

#endif	/* CACHEDREF_H */

