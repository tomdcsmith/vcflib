#include "CachedRef.h"

CachedRef::CachedRef(FastaReference& fastaRef) {
    this->fastaRef = fastaRef;
}

CachedRef::~CachedRef(void)
{}

void CachedRef::cacheSeq(string seqname){
    string sequence = fastaRef.getSequence(seqname);
    chromosomeMap.insert(std::map<string, string>::value_type(seqname, sequence));
}

string CachedRef::getSequence(string seqname, int start, int length){
    
    if(chromosomeMap.find(seqname) == chromosomeMap.end()){
        cacheSeq(seqname);
    }
    
    string chrom_seq = chromosomeMap.find(seqname)->second;
    
    length = min(length, static_cast<int>(chrom_seq.length()) - start);
    if (start < 0 || length < 1) {
        //cerr << "Empty sequence" << endl;
        return "";
    }
    
    string s = chrom_seq.substr(start, length);        
    return s;
}