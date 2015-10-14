#include "CachedRef.h"

namespace vcflib {
    
    
    CachedRef::CachedRef(FastaReference fastaRef) {
        this->fastaRef = fastaRef;
    }
    
    CachedRef::cacheSeq(string seqname){
        string sequence = fastaRef.getSequence(seqname);
        chromosomeMap.insert(std::map<string, string>::value_type(seqname, sequence));
    }
    
    CachedRef::getSequence(string seqname, int start, int length){
        
        if(chromosomeMap.find(seqname) != chromosomeMap.end()){
            cacheSeq(seqname);
        }
        
        string chrom_seq = chromosomeMap.find(seqname);
        
        length = min(length, chrom_seq.length - start);
        if (start < 0 || length < 1) {
            //cerr << "Empty sequence" << endl;
            return "";
        }
        
        string s = chrom_seq.substr(start-1, length);        
        return s;
    }
    
    
}